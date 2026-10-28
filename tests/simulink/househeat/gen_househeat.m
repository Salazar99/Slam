function gen_househeat(outdir, nruns, seed)
% Traces of the Simulink example sldemo_househeat (Thermal Model of a House) for SLAM.
% Per run: random average outdoor temperature in [30, 60] F and daily variation amplitude in
% [5, 20] F; set point fixed at 70 F (thermostat relay: heater on below 65 F, off above 75 F).
% 48 h per run, logged signals resampled to 1 min; typed CSV header for SLAM; no time column.
%   matlab -batch "gen_househeat('C:\...\out\househeat', 20, 1)"
if nargin < 1, outdir = fullfile(pwd, 'out', 'househeat'); end
if nargin < 2, nruns = 20; end
if nargin < 3, seed = 1; end
dt = 60; T = 172800;
openExample('simulink_general/sldemo_househeatExample', 'supportingFile', 'sldemo_househeat');
mdl = 'sldemo_househeat'; load_system(mdl);
names = {'Tindoors', 'Toutdoors', sprintf('blower\ncmd'), 'HeatCost'};
cols = {'tin', 'tout', 'heater', 'cost'};
d = fullfile(outdir, 'traces');
if ~exist(d, 'dir'), mkdir(d); end
t = (0:dt:T)';
rng(seed);
for r = 1:nruns
    in = Simulink.SimulationInput(mdl);
    in = in.setBlockParameter([mdl '/Avg Outdoor Temp'], 'Value', num2str(30 + 30 * rand, 4), ...
                              [mdl '/Daily Temp Variation'], 'Amplitude', num2str(5 + 15 * rand, 4));
    out = sim(in);
    L = out.get(get_param(mdl, 'SignalLoggingName'));
    M = zeros(numel(t), numel(names));
    for k = 1:numel(names), M(:, k) = sig(L, names{k}, t, k == 3); end
    assert(all(isfinite(M(:))), 'bad trace %d', r);
    f = fopen(fullfile(d, sprintf('run%02d.csv', r)), 'w');
    fprintf(f, '%s\n', strjoin(strcat('double', {' '}, cols), ', '));   % SLAM needs typed headers
    fprintf(f, [repmat('%.5g,', 1, numel(cols) - 1) '%.5g\n'], M');
    fclose(f);
end
close_system(mdl, 0);
fprintf('wrote %d runs of %d samples (dt %d s) to %s\n', nruns, numel(t), dt, d);
end

function x = sig(L, key, t, discrete)
% Logged signal by name, also inside bus-valued elements (Temperatures.Tindoors, ...).
for i = 1:L.numElements
    v = L.getElement(i).Values;
    if isstruct(v) && isfield(v, key), ts = v.(key);
    elseif ~isstruct(v) && strcmp(L.getElement(i).Name, key), ts = v;
    else, continue
    end
    [tt, k] = unique(ts.Time);
    dd = squeeze(ts.Data);
    if discrete, m = 'previous'; else, m = 'linear'; end
    x = interp1(tt, double(dd(k)), t, m, 'extrap');
    return
end
error('signal %s not logged', strrep(key, newline, ' '));
end
