function gen_absbrake(outdir, nruns, seed)
% Traces of the Simulink example sldemo_absbrake (Modeling an Anti-Lock Braking System) for
% SLAM. Per run: random initial speed v0 in [15, 40] and road friction (the mu-slip curve
% scaled by [0.4, 1], wet to dry road), ABS on. The run ends when the vehicle stops.
% Logged signals resampled to 0.05 s; typed CSV header for SLAM; no time column.
%   matlab -batch "gen_absbrake('C:\...\out\absbrake', 30, 1)"
if nargin < 1, outdir = fullfile(pwd, 'out', 'absbrake'); end
if nargin < 2, nruns = 30; end
if nargin < 3, seed = 1; end
dt = 0.05;
openExample('simulink_automotive/ModelingAnAntiLockBrakingSystemExample', 'supportingFile', 'sldemo_absbrake');
mdl = 'sldemo_absbrake'; load_system(mdl);
mu0 = evalin('base', 'mu');
names = {'Vs', 'Ww', 'slp', 'Sd'};
cols = {'vs', 'ww', 'slip', 'sd'};
d = fullfile(outdir, 'traces');
if ~exist(d, 'dir'), mkdir(d); end
rng(seed);
for r = 1:nruns
    in = Simulink.SimulationInput(mdl);
    in = in.setVariable('v0', 15 + 25 * rand);
    in = in.setVariable('mu', (0.4 + 0.6 * rand) * mu0);
    in = in.setVariable('ctrl', 1);
    out = sim(in);
    L = out.get(get_param(mdl, 'SignalLoggingName'));
    [~, tend] = sig(L, 'Vs', 0);
    t = (0:dt:tend)';
    M = zeros(numel(t), numel(names));
    for k = 1:numel(names), M(:, k) = sig(L, names{k}, t); end
    assert(all(isfinite(M(:))), 'bad trace %d', r);
    f = fopen(fullfile(d, sprintf('run%02d.csv', r)), 'w');
    fprintf(f, '%s\n', strjoin(strcat('double', {' '}, cols), ', '));   % SLAM needs typed headers
    fprintf(f, [repmat('%.5g,', 1, numel(cols) - 1) '%.5g\n'], M');
    fclose(f);
end
close_system(mdl, 0);
fprintf('wrote %d runs (dt %.2f s) to %s\n', nruns, dt, d);
end

function [x, tend] = sig(L, key, t)
% Logged signal by name, also inside bus-valued elements (yout.Vs, yout.Ww).
for i = 1:L.numElements
    v = L.getElement(i).Values;
    if isstruct(v) && isfield(v, key), ts = v.(key);
    elseif ~isstruct(v) && strcmp(L.getElement(i).Name, key), ts = v;
    else, continue
    end
    [tt, k] = unique(ts.Time);
    dd = squeeze(ts.Data);
    tend = tt(end);
    x = interp1(tt, double(dd(k)), t, 'linear', 'extrap');
    return
end
error('signal %s not logged', key);
end
