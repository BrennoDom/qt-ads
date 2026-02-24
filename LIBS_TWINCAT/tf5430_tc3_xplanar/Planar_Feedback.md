# Planar Feedback

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar Feedback

The MC Planar Feedback is a PLC software object that bundles all the status information for a command that is given by the user to a mover, track, group or other Planar component.

This ranges from the sending of the command by the user to the processing of the command by the components and from the subsequent acceptance (or possibly rejection) to the execution and termination of the command. The user can track all of this using a feedback object if he so desires.

To do this, he must transfer a feedback object in the PLC as the first argument when the command method is called. Subsequently, whenever the user triggers the feedback object (or calls its update method), he can retrieve the current command state.

In order for a Planar Feedback to be used, it must be declared in the PLC. The Planar Feedback has no fixed equivalent in a TCOM object on the Motion Control side. From there, it receives the information directly from the corresponding TCOM object (e.g. Planar mover), which executes the corresponding command. Therefore, feedback does not need to be created, parameterized or linked separately in the MC project.

Further Information

* [Example "Creating a Planar mover and Planar Feedback"](ms-xhelp:///?Id=beckhoff-2eb6-4057-90a5-d2a201758722)
* [Example "Planar motion components: averting collision"](ms-xhelp:///?Id=beckhoff-b1e5-49a9-894e-219caa9f5a64)
* [Specialized feedback types](ms-xhelp:///?Id=beckhoff-5c5d-478b-a7f6-e675a14487cb)
