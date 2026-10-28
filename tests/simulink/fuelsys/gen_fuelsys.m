function gen_fuelsys(outdir, nruns, seed)
% Traces of the Simulink example sldemo_fuelsys (Model a Fault-Tolerant Fuel Control System)
% for SLAM. Per run: random engine speed (constant, 2000-4000 rpm) and a random throttle
% profile (mask parameters rep_seq_t/rep_seq_y of 'Throttle Command': 3 points, values in
% [8, 25] deg, period 2-8 s, repeated), 30 s. Inputs whose nominal run drives the MAP reading out
% of its validity range (map > max_press = 0.95, which latches the controller's MAP-failure mode)
% are redrawn, so nominal runs are fault-free operation (the number redrawn is printed).
% Nominal runs go to <outdir>/traces; the same inputs with one sensor failed (the model's
% built-in fault switches ego_sw, map_sw, speed_sw, throttle_sw set to 0) go to
% <outdir>/faulty/<switch>. Logged signals resampled to 0.1 s; the first 2 s (engine start-up,
% AFR rising from 0) are dropped; typed CSV header for SLAM.
%   matlab -batch "gen_fuelsys('C:\...\out\fuelsys', 20, 1)"
if nargin < 1, outdir = fullfile(pwd, 'out', 'fuelsys'); end
if nargin < 2, nruns = 20; end
if nargin < 3, seed = 1; end
dt = 0.1; T = 30; T0 = 2;
openExample('simulink_automotive/ModelingAFaultTolerantFuelControlSystemExample', ...
            'supportingFile', 'sldemo_fuelsys');
mdl = 'sldemo_fuelsys'; load_system(mdl);
hws = get_param(mdl, 'ModelWorkspace');
for v = {'min_throt', 'max_throt', 'min_speed', 'max_speed', 'min_press', 'max_press'}
    fprintf('%s = %s\n', v{1}, mat2str(getVariable(hws, v{1})));
end
tc = [mdl sprintf('/Throttle\nCommand')];
switches = {'none', 'ego_sw', 'map_sw', 'speed_sw', 'throttle_sw'};
names = {'throttle', 'speed', 'map', 'ego', 'air_fuel_ratio', 'fuel'};
cols = {'throttle', 'speed', 'map', 'ego', 'afr', 'fuel'};
t = (0:dt:T)';
rng(seed);
redrawn = 0;
for r = 1:nruns
  while true
    es = 2000 + 2000 * rand;                       % rpm
    y = 8 + 17 * rand(1, 3);
    ts = [0, sort(2 + 6 * rand(1, 2))];
    for s = 1:numel(switches)
        in = Simulink.SimulationInput(mdl);
        in = in.setModelParameter('StopTime', num2str(T));
        in = in.setVariable('engine_speed', es, 'Workspace', mdl);
        in = in.setBlockParameter(tc, 'rep_seq_y', mat2str(y, 4), tc, 'rep_seq_t', mat2str(ts, 4));
        if s > 1, in = in.setVariable(switches{s}, 0, 'Workspace', mdl); end
        out = sim(in);
        L = out.get(get_param(mdl, 'SignalLoggingName'));
        M = zeros(numel(t), numel(names));
        for k = 1:numel(names), M(:, k) = sig(L, names{k}, t); end
        assert(all(isfinite(M(:))), 'bad trace %d %s', r, switches{s});
        if s == 1 && max(M(:, 3)) > getVariable(hws, 'max_press'), break; end   % redraw inputs
        if s == 1, d = fullfile(outdir, 'traces'); else, d = fullfile(outdir, 'faulty', switches{s}); end
        if ~exist(d, 'dir'), mkdir(d); end
        f = fopen(fullfile(d, sprintf('run%02d.csv', r)), 'w');
        fprintf(f, '%s\n', strjoin(strcat('double', {' '}, cols), ', '));   % SLAM needs typed headers
        fprintf(f, [repmat('%.5g,', 1, numel(cols) - 1) '%.5g\n'], M(t >= T0 - 1e-9, :)');
        fclose(f);
    end
    if s == numel(switches), break; end
    redrawn = redrawn + 1;
  end
end
close_system(mdl, 0);
fprintf('redrawn inputs: %d\n', redrawn);
fprintf('wrote %d runs x %d variants of %d samples (dt %.2f s) to %s\n', nruns, numel(switches), nnz(t >= T0 - 1e-9), dt, outdir);
end

function x = sig(L, key, t)
for i = 1:L.numElements
    e = L.getElement(i);
    if strcmp(e.Name, key)
        [tt, k] = unique(e.Values.Time);
        d = squeeze(e.Values.Data);
        x = interp1(tt, double(d(k)), t, 'linear', 'extrap');
        return
    end
end
error('signal %s not logged', key);
end
