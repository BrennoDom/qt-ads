# General rules for MC function blocks

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. General rules for MC function blocks

# General rules for MC function blocks

The rules described below apply to all MC function blocks. They ensure a defined processing by the PLC program.

## Exclusivity of the outputs

The outputs "Busy", "Done", "Error" and "CommandAborted" are mutually exclusive, i.e. only one of these outputs can be TRUE on a function block at the same time. When the "Execute" input becomes TRUE, one of the outputs must become TRUE. At the same time, however, only one of the outputs "Active", "Done", "Error" and "CommandAborted" can be TRUE.

An exception is the motion command [MC\_Stop](ms-xhelp:///?Id=beckhoff-bba4-4c3f-9dbd-4b986c3444cc)*.* This sets the "Done" output to TRUE as soon as the axis is stopped. Nevertheless, the "Busy" and "Active" outputs remain TRUE because the axis is locked. The axis is unlocked and the "Busy" and "Active" outputs set to FALSE only after the "Execute" input is set to FALSE.

## Initial state

If the function block is not active, the outputs "Done", "Error", "ErrorID" and "CommandAborted" are reset with a falling edge at input "Execute". However, the falling edge at input "Execute" does not affect the command execution.

If the "Execute" input is already reset during command execution, this ensures that one of the outputs is set at the end of the command for a PLC cycle. Only then are the outputs reset.

If the "Execute" input is triggered more than once during the execution of a command, the function block does not provide any feedback, nor does it execute any further commands.

## Input parameters

The input parameters become active with a rising edge. To change the parameters, the command must be retriggered after it has finished. If an input parameter is not passed to the function block, the last value passed to this function block remains valid. Meaningful values should be parameterized at the first call.

## Position and Distance

The "Position" input designates a defined value within a coordinate system. The "Distance" input, on the other hand, is a relative dimension, i.e. the distance between two positions. "Position" and "Distance" are specified in technical units, e.g. mm or °, according to the axis scaling.

## Dynamic parameters

The dynamic parameters for Move functions are specified in technical units with second as time base. For example, if an axis is scaled in millimeters, the parameters have the following units:

|  |  |
| --- | --- |
| Velocity | mm/s |
| Acceleration | mm/s2 |
| Deceleration | mm/s2 |

## Error handling

All function blocks have two error outputs for indicating errors during command execution. The "Error" output indicates the error and the "ErrorID" output contains a supplementary error number. The outputs "Done" and "InVelocity" indicate successful command execution and are not set if the "Error" output is TRUE.

Errors of different type are signaled at the function block output. The error type is not specified explicitly. It depends on the unique and global error number.

## Error types

* Function block errors only concern the function block, not the axis (e.g. incorrect parameterization). Function block errors do not have to be reset explicitly. They are reset automatically when the "Execute" input is reset.
* Communication errors (e.g. the function block cannot address the axis) usually indicate incorrect configuration or parameterization. A Reset is not possible. The function block can be retriggered after the configuration has been corrected.
* In many cases, drive errors (controller) can be reset via the motion command [MC\_Reset](ms-xhelp:///?Id=beckhoff-4930-455a-b236-c5815ef9d98d).

## Behavior of the Done output

The output "Done" (or alternatively "InVelocity") is set if a command was executed successfully.

## Behavior of the CommandAborted output

The output "CommandAborted" is set if a command is interrupted.

## Behavior of the Busy output

The "Busy" output indicates that the function block is active. The function block can only be triggered by a rising edge at the "Execute" input if the "Busy" output is FALSE. "Busy" is immediately set with the positive edge at the "Execute" input and is not reset until the command has been successfully or unsuccessfully terminated. As long as the "Busy" output is TRUE, the function block must be called cyclically in order to be able to execute the command.

## Behavior of the Active output

The "Active" output of a function block indicates that the function block has control over the axis.

## Option input

Many function blocks have an "Options" input with a data structure containing additional, infrequently required options. In many cases the options are not required to perform the basic function of the function block, so that the input can remain unused. The user only has to occupy the Options data structure in cases where the documentation explicitly refers to certain options.

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
