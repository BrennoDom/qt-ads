# State diagram

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. State diagram

# State diagram

The following state diagram defines the behavior of an axis.

![20885750](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8880906507__Web.png)

|  |  |
| --- | --- |
| Note 1 | From undefined state in which an error occurs. |
| Note 2 | From undefined state if MC\_Power.Enable = FALSE. The axis has no fault. |
| Note 3 | MC\_Reset and MC\_Power*.*Status = FALSE |
| Note 4 | MC\_Reset and MC\_Power.Status = TRUE and MC\_Power.Enable = TRUE |
| Note 5 | MC\_Power*.*Status = TRUE and MC\_Power.Enable = TRUE |
| Note 6 | MC\_Stop.Done = TRUE and MC\_Stop.Execute = FALSE |

Motion commands are always processed sequentially. All commands operate in the described state diagram.

The axis is always in one of the defined states. Each motion command that causes a transition changes the state of the axis and thus the motion profile. The state diagram is an abstraction layer that reflects the real axis state, comparable to the process image for I/O points. The axis state changes immediately when the command is issued.

The state diagram refers to single axes.

The "Disabled" state is the default state of an axis. In this state can the axis cannot be moved through a function block. When the MC\_Power function block is called with Enable = TRUE, the axis changes to the "Standstill" state or, in the event of an error, to "ErrorStop" state. If the function block MC*\_*Power is called with Enable = FALSE, the status changes to "Disabled".

The purpose of "ErrorStop" state is to stop the axis and then block further commands, until a reset was triggered. The "Error" state transition only refers to actual axis errors and not to execution errors of a function block. Axis errors can also be displayed at the error output of a function block.

Function blocks that are not listed in the state diagram influence the status of the axis.

The "Stopping" state indicates that the axis is in a stop ramp. After the complete stop the state does not change to "Standstill" until MC\_Stop is called with Execute = FALSE. Otherwise the axis remains locked for further motion commands.

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
