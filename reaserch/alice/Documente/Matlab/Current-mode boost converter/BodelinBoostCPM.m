%% Bode plotter using linearization tool
% requires simulink control design toolbox
mdl = 'boostCPM4tester'; % set to file name of simulink model. Must have i/o points set within this model
io = getlinio(mdl)  % get i/o signals of mdl
op = operspec(mdl)
op = findop(mdl,op)  % calculate model operating point
lin = linearize(mdl,op,io)  % compute state space model of linearized system
ltiview(lin)   % send linearized model to LTI Viewer tool