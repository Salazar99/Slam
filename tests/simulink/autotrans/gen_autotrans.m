function gen_autotrans(outdir, nruns, seed)
% Traces of the Simulink example sldemo_autotrans (Modeling an Automatic Transmission
% Controller) for SLAM: the ManeuversGUI Signal Editor is replaced by two root inports
% driven by seeded random piecewise-constant throttle [0,100] and brake [0,325]
% (ARCH-COMP AT input ranges), one control point every 5 s, 30 s per run.
% Logged signals are resampled to a fixed 0.1 s grid; one CSV per run, no time column.
%   matlab -batch "gen_autotrans('C:\...\out\autotrans', 40, 1)"
if nargin < 1, outdir = fullfile(pwd, 'out', 'autotrans'); end
if nargin < 2, nruns = 40; end
if nargin < 3, seed = 1; end
dt = 0.1; T = 30;
openExample('simulink_automotive/ModelingAnAutomaticTransmissionControllerExample', ...
            'supportingFile', 'sldemo_autotrans');
mdl = 'sldemo_autotrans'; load_system(mdl);

% ManeuversGUI (Throttle, Brake) -> root inports with the same signal names
src = [mdl '/ManeuversGUI'];
ph = get_param(src, 'PortHandles'); pos = get_param(src, 'Position');
dsts = cell(1, 2); names = cell(1, 2);
for k = 1:2
    l = get_param(ph.Outport(k), 'Line');
    dsts{k} = get_param(l, 'DstPortHandle'); names{k} = get_param(l, 'Name');
    delete_line(l);
end
delete_block(src);
for k = 1:2
    y = pos(2) + 60 * (k - 1);
    b = add_block('simulink/Sources/In1', [mdl '/' names{k}], 'Position', [pos(1) y pos(1) + 30 y + 14]);
    op = get_param(b, 'PortHandles');
    for d = reshape(dsts{k}, 1, [])
        add_line(mdl, op.Outport(1), d, 'autorouting', 'on');
    end
    set_param(get_param(op.Outport(1), 'Line'), 'Name', names{k});
end
set_param(mdl, 'LoadExternalInput', 'on');

if ~exist(outdir, 'dir'), mkdir(outdir); end
rng(seed);
t = (0:dt:T)';
tc = 0:5:T;
for r = 1:nruns
    br = (rand(size(tc)) < 0.25) .* 325 .* rand(size(tc));
    thr = 100 * rand(size(tc)); thr(br > 0) = 0;          % no throttle while braking
    u = [interp1(tc, thr, t, 'previous', 'extrap'), interp1(tc, br, t, 'previous', 'extrap')];
    in = Simulink.SimulationInput(mdl);
    in = in.setExternalInput([t u]);
    in = in.setModelParameter('StopTime', num2str(T));
    out = sim(in);
    L = out.get(get_param(mdl, 'SignalLoggingName'));
    speed = sig(L, 'VehicleSpeed', t, 'linear');
    rpm = sig(L, 'EngineRPM', t, 'linear');
    gear = sig(L, 'ShiftLogic', t, 'previous');
    M = [u, speed, rpm, gear];
    assert(all(isfinite(M(:))) && size(M, 1) == numel(t), 'bad trace %d', r);
    f = fopen(fullfile(outdir, sprintf('run%02d.csv', r)), 'w');
    fprintf(f, 'double throttle, double brake, double speed, double rpm, double gear\n');   % SLAM needs typed headers
    fprintf(f, '%.4f,%.4f,%.4f,%.4f,%d\n', M');
    fclose(f);
end
close_system(mdl, 0);
fprintf('wrote %d runs of %d samples (dt %.2f s) to %s\n', nruns, numel(t), dt, outdir);
end

function x = sig(L, key, t, method)
% Logged signal by name, or by source block for the unnamed gear output of ShiftLogic.
for i = 1:L.numElements
    e = L.getElement(i);
    if strcmp(e.Name, key) || endsWith(e.BlockPath.getBlock(1), ['/' key])
        [tt, k] = unique(e.Values.Time);
        d = squeeze(e.Values.Data);
        x = interp1(tt, double(d(k)), t, method, 'extrap');
        return
    end
end
error('signal %s not logged', key);
end
