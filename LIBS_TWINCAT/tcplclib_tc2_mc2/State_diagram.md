# State diagram

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. State diagram

# State diagram

The following state diagram defines the behavior of an axis in situations where several function blocks are simultaneously active for this axis. The combination of several function blocks is useful for generating more complex motion profiles or for dealing with exceptional situations during program execution.

![26571327](/tcplclib_tc2_mc2/1033/Images/gif/70182411__en-US__Web.gif)

|  |  |
| --- | --- |
| Note 1 | From any state in which an error occurs |
| Note 2 | From any state if MC\_Power.Enable = FALSE and the axis has no error |
| Note 3 | MC\_Reset and MC\_Power*.*Status = FALSE |
| Note 4 | MC\_Reset and MC\_Power.Status = TRUE and MC\_Power.Enable = TRUE |
| Note 5 | MC\_Power*.*Status = TRUE and MC\_Power.Enable = TRUE |
| Note 6 | MC\_Stop.Done = TRUE and MC\_Stop.Execute = FALSE |

Motion commands are always processed sequentially. All commands operate in the described state diagram.

The axis is always in one of the defined states. Each motion command that causes a transition changes the state of the axis and thus the motion profile. The state diagram is an abstraction layer that reflects the real axis state, comparable to the process image for I/O points. The axis state changes immediately when the command is issued.

The state diagram refers to single axes. Multi-axis blocks such as MC\_CamIn or MC\_GearIn influence the states of several axes, which can always be traced back to individual axis states of the axes involved in the process. For example, a cam plate master can be in "Continous Motion" state, while the associated slave is in "Synchronized Motion" state. Coupling of a slave has no influence on the state of the master.

The "Disabled" state is the default state of an axis. In this state can the axis cannot be moved through a function block. When the MC\_Power function block is called with Enable = TRUE, the axis changes to the "Standstill" state or, in the event of an error, to "ErrorStop" state. If the function block MC*\_*Power is called with Enable = FALSE, the status changes to "Disabled".

The purpose of "ErrorStop" state is to stop the axis and then block further commands, until a reset was triggered. The "Error" state transition only refers to actual axis errors and not to execution errors of a function block. Axis errors can also be displayed at the error output of a function block.

Function blocks that are not listed in the state diagram do not affect the state of the axis (MC\_ReadStatus, MC\_ReadAxisError, MC\_ReadParameter, MC\_ReadBoolParameter, MC\_WriteParameter, MC\_WriteBoolParameter, MC\_ReadActualPosition and MC\_CamTableSelect).

The "Stopping" state indicates that the axis is in a stop ramp. The state changes after the complete stop after "Standstill".

Motion commands such as MC\_MoveAbsolute that lead out of the "Synchronized Motion" state are possible only if they are explicitly permitted in the axis parameters. Uncoupling commands such as MC\_GearOut are possible independent of that.

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
