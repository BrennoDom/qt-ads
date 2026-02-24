# General rules for MC function blocks

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. General rules for MC function blocks

# General rules for MC function blocks

The rules described below apply to all MC function blocks. They ensure a defined processing by the PLC program.

## Exclusivity of the outputs

The outputs "Busy", "Done", "Error" and "CommandAborted" are mutually exclusive, i.e. only one of these outputs can be TRUE on a function block at the same time. When the "Execute" input becomes TRUE, one of the outputs must become TRUE. At the same time, however, only one of the outputs "Active", "Done", "Error" and "CommandAborted" can be TRUE.

An exception is the motion command [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6)*.* This sets the "Done" output to TRUE as soon as the axis is stopped. Nevertheless, the "Busy" and "Active" outputs remain TRUE because the axis is locked. The axis is unlocked and the "Busy" and "Active" outputs set to FALSE only after the "Execute" input is set to FALSE.

## Initial state

If the function block is not active, the outputs "Done", "InGear", "InVelocity", "Error", "ErrorID" and "CommandAborted" are reset with a falling edge at input "Execute". However, the falling edge at input "Execute" does not affect the command execution.

If the "Execute" input is already reset during command execution, this ensures that one of the outputs is set at the end of the command for a PLC cycle. Only then are the outputs reset.

If the "Execute" input is triggered more than once during the execution of a command, the function block does not provide any feedback, nor does it execute any further commands.

## Input parameters

The input parameters become active with a positive edge. To change the parameters the command has to be triggered again once it is completed, or a second instance of the function block must be triggered with new parameters during command execution.

If an input parameter is not passed to the function block, the last value passed to this function block remains valid. A meaningful default value is used for the first call.

## Position and Distance

The "Position" input designates a defined value within a coordinate system. The "Distance" input, on the other hand, is a relative dimension, i.e. the distance between two positions. "Position" and "Distance" are specified in technical units, e.g. mm or °, according to the axis scaling.

## Dynamic parameters

The dynamic parameters for Move functions are specified in technical units with second as timebase. For example, if an axis is scaled in millimeters, the parameters have the following units:

|  |  |
| --- | --- |
| Velocity | mm/s |
| Acceleration | mm/s2 |
| Deceleration | mm/s2 |
| Jerk | mm/s3 |

## Error handling

All function blocks have two error outputs for indicating errors during command execution. The "Error" output indicates the error and the "ErrorID" output contains a supplementary error number. The "Done", "InVelocity", "InGear" and "InSync" outputs indicate successful command execution and are not set if the "Error" output is TRUE.

Errors of different type are signaled at the function block output. The error type is not specified explicitly. It depends on the unique and global error number.

## Error types

* Function block errors only concern the function block, not the axis (e.g. incorrect parameterization). Function block errors do not have to be reset explicitly. They are reset automatically when the "Execute" input is reset.
* Communication errors (the function block cannot address the axis, for example). Communication errors usually indicate incorrect configuration or parameterization. A Reset is not possible. The function block can be retriggered after the configuration has been corrected.
* Axis errors (logical NC axis) usually occur during the motion (e.g. lag error). They cause the axis to switch to error state. An axis error must be reset with the motion command [MC\_Reset](ms-xhelp:///?Id=beckhoff-fdf9-4bca-9932-eec2e9e0399e).
* Drive errors (controller) may cause an axis error, i.e. an error of the logical NC axis. In many cases, axis and drive errors can be reset together via the motion command [MC\_Reset](ms-xhelp:///?Id=beckhoff-fdf9-4bca-9932-eec2e9e0399e). Depending on the drive controller, a separate reset mechanism may be required (e.g. connection of a reset line to the control device).

## Behavior of the Done output

The output "Done" (or alternatively "InVelocity", "InGear", "InSync" etc.) is set if a command was executed successfully. If several function blocks are used for an axis and the running command is interrupted through a further function block, the Done output for the first function block is not set.

## Behavior of the CommandAborted output

The "CommandAborted" output is set if a command is interrupted by another function block.

## Behavior of the Busy output

The "Busy" output indicates that the function block is active. The function block can only be triggered by a rising edge at the "Execute" input if the "Busy" output is FALSE. "Busy" is immediately set with the positive edge at the "Execute" input and is not reset until the command has been successfully or unsuccessfully terminated. As long as the "Busy" output is TRUE, the function block must be called cyclically in order to be able to execute the command.

## Behavior of the Active output

If the axis movement is controlled by several function blocks, the "Active" output of a function block indicates that the axis executes the command. The state Busy = TRUE and Active = FALSE means that the command has not yet been executed or is no longer executed.

## Enable input and Valid output

In contrast to the "Execute" input, the "Enable" input causes an action to be executed continuously and repeatedly, as long as "Enable" is TRUE. For example, the function block [MC\_ReadStatus](ms-xhelp:///?Id=beckhoff-49de-42bc-8e83-8798b6d84282) cyclically updates the status of an axis as long as "Enable" is TRUE. A function block with an "Enable" input indicates through the "Valid" output that the data indicated at the outputs are valid. However, the data can be updated continuously as long as the "Valid" output is TRUE.

## BufferMode

Some function blocks have a "BufferMode" input for controlling the command flow with several function blocks. For example, BufferMode can specify that a command interrupts another command (unbuffered mode) or that the following command is only executed after the previous command (buffered mode). BufferMode can be used to specify the movement transition from one command to the next. This is referred to as "Blending", which specifies the velocity at the transition point.

A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active.

In unbuffered mode a subsequent command leads to termination of a running command. The previous command then sets the output "CommandAborted". In BufferMode a subsequent command waits until a running command is completed. Note that a continuous motion does not allow a buffered follow-on command. Buffered commands always lead immediately to an endless movement being aborted, as in unbuffered operation.

Only one command is buffered while another command is executed. If more than one command is triggered during a running command, then the last-started command to be buffered is rejected with an error (error 0x4292 Buffer Full). However, if the last command is started unbuffered, it becomes active in any case and interrupts the current and an already buffered command.

## BufferModes

* Aborting: Default mode without buffering. The command is executed immediately and interrupts any other command that may be running.
* Buffered: The command is executed once no other command is running on the axis. The previous movement continues until it has stopped. The following command is started from standstill.
* BlendingLow: The command is executed once no other command is running on the axis. In contrast to Buffered the axis does not stop at the previous target, but passes through this position with the lower velocity of two commands.
* BlendingHigh The command is executed once no other command is running on the axis. In contrast to Buffered the axis does not stop at the previous target, but passes through this position with the higher velocity of two commands.
* BlendingNext: The command is executed once no other command is running on the axis. In contrast to Buffered the axis does not stop at the previous target, but passes through this position with the velocity of the last command.
* BlendingPrevious: The command is executed once no other command is running on the axis. In contrast to Buffered the axis does not stop at the previous target, but passes through this position with the velocity of the first command.

See also: [Diagram of the BufferModes](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)

## Optional blending position

Blending in the different BufferModes takes place in each case at the target position of the currently running command. In the case of the motion command [MC\_MoveVelocity](ms-xhelp:///?Id=beckhoff-864d-4654-8253-2e77f5465a26) no target position is defined, and in other cases it may make sense to change the blending position. For this purpose, a blending position can be defined via the "Options" input of the function block (see [Options input](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)), which is then used for the new command. The optional blending position must be located before the target position of the previous command, otherwise the new command will be rejected with an error message (0x4296). If the optional blending position has already been passed, the new command is implemented instantaneously. In other words, the command behaves like an aborting command.

## Option input

Many function blocks have an "Options" input with a data structure containing additional, infrequently required options. To execute the basic function of the function block these options are often not required, so that the input can remain open. The user only has to occupy the Options data structure in cases where the documentation explicitly refers to certain options.

## Slave axes

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as [MC\_MoveAbsolute](ms-xhelp:///?Id=beckhoff-d758-42c5-8d7b-c56658edbc31) then automatically leads to uncoupling of the axis, after which the command is executed. In this case the only available BufferMode is "Aborting".

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
