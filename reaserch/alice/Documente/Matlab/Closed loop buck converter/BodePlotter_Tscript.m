%% Loop gain bode plotter using linearization tool
% requires Simulink Control Design toolbox
%
%
model = 'syncbuck_CL'; % set to file name of simulink model. Must have i/o points set within this model
io = getlinio(model)  % get i/o signals of model
op = operspec(model)
op = findop(model,op)  % calculate model operating point
ssm = linearize(model,op,io)  % compute state space model of linearized system
%
%
%ltiview('bode',-ssm)   % send linearized model to LTI Viewer tool
margin(-ssm) % show loop-gain magnitude and phase responses and calculate fc, PM and GM
%