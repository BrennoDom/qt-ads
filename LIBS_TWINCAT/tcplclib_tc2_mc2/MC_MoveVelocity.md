# MC_MoveVelocity

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_MoveVelocity

# MC\_MoveVelocity

![17322790](/tcplclib_tc2_mc2/1033/Images/png/9007199325045003__Web.png)

MC\_MoveVelocity starts a continuous movement with specified velocity and direction. The movement can be stopped through a Stop command.

The InVelocity output is set once the constant velocity is reached. Once constant velocity has been reached, the block function is complete, and no further monitoring of the movement takes place. If the command is aborted during the acceleration phase, the output "CommandAborted" or, in the event of an error, the output "Error" is set.

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as MC\_MoveAbsolute then automatically leads to decoupling of the axis, after which the command is executed. In this case the only available BufferMode is "Aborting".

## Inputs

```
VAR_INPUT  
    Execute      : BOOL; (* B *)  
    Velocity     : LREAL; (* E *)  
    Acceleration : LREAL; (* E *)  
    Deceleration : LREAL; (* E *)  
    Jerk         : LREAL; (* E *)  
    Direction    : MC_Direction := MC_Positive_Direction; (* E *)  
    BufferMode   : MC_BufferMode; (* E *)  
    Options      : ST_MoveOptions; (* V *)  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (≥0)   
If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0)   
If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk (≥0)   
At a value of 0, the standard jerk from the axis configuration in the System Manager is applied.

**Direction:** Positive or negative direction of travel (type: [MC\_Direction](ms-xhelp:///?Id=beckhoff-d26f-4561-922b-f593d61b8fcd))

**BufferMode:** Is evaluated if the axis already executes another command (type: [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_MoveVelocity becomes active after the current command or aborts it. Transition conditions from the current to the next command are also determined by the BufferMode. If the command is applied to a coupled slave axis, the only available BufferMode is "Aborting". A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active.

**Options:** Data structure ([ST\_MoveOptions](ms-xhelp:///?Id=beckhoff-d19a-49e9-9f59-b682be3472f8)), which contains additional, rarely required parameters. The input can normally remain open.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    InVelocity     : BOOL; (* B *)  
    Busy           : BOOL; (* E *)  
    Active         : BOOL; (* E *)  
    CommandAborted : BOOL; (* E *)  
    Error          : BOOL; (* B *)  
    ErrorID        : UDINT; (* E *)  
END_VAR
```

**InVelocity:** After the axis acceleration, the InVelocity output assumes the value TRUE once the requested target velocity has been reached. The InVelocity output remains TRUE until the axis velocity is changed by another command. As soon as a velocity deviation is determined, the output signals FALSE.

|  |  |
| --- | --- |
| 21687383 | InVelocity and Override  If the override value is changed, the InVelocity output signals the value FALSE. At the same time, after a change in velocity, the CommandAborted output assumes the value TRUE and the function block no longer displays the status "busy". |

|  |  |
| --- | --- |
| 60968721 | InVelocity during a velocity overlay with MC\_MoveSuperimposed  A change in velocity due to the function block MC\_MoveSuperimposed is permitted and does not lead to a cancellation of the activity of the function block. Although the velocity changes, the InVelocity output remains TRUE because the total velocity is made up of the basic velocity, which has not changed, and a velocity superimposed on this basic velocity (Superposition). |

The function block remains "Busy" and "Active" until a new command is issued.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the function block is active. If "Busy" is FALSE, the function block is ready for a new order. At the same time one of the outputs "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** TRUE if the command could not be executed completely. The axis was stopped or the current command was replaced by another Move command.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
