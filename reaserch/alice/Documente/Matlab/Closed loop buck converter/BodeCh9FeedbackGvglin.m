%% Bode plotter using linearization tool
% requires simulink control design toolbox
mdl = 'BuckFeedbackExampleCh9PIDGvg'; % set to file name of simulink model. Must have i/o points set within this model
io = getlinio(mdl)  % get i/o signals of mdl
op = operspec(mdl)
op = findop(mdl,op)  % calculate model operating point
lin = linearize(mdl,op,io)  % compute state space model of linearized system
mdl = 'BuckFeedbackExampleCh9GvgOpenLoop'; % set to file name of simulink model. Must have i/o points set within this model
io = getlinio(mdl)  % get i/o signals of mdl
op = operspec(mdl)
op = findop(mdl,op)  % calculate model operating point
lino = linearize(mdl,op,io)  % compute state space model of linearized system
ltiview(lin,lino)   % send linearized model to LTI Viewer tool