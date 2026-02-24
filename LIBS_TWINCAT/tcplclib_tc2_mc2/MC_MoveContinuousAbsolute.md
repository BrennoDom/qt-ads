# MC_MoveContinuousAbsolute

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_MoveContinuousAbsolute

# MC\_MoveContinuousAbsolute

![11847581](/tcplclib_tc2_mc2/1033/Images/png/9007199325048203__Web.png)

MC\_MoveContinuousAbsolute starts positioning to an absolute target position and monitors the axis movement over the whole travel path. At the target position a constant end velocity is reached, which is maintained. The "InEndVelocity" output is set once the target position was reached. Otherwise, the output "CommandAborted" or, in case of an error, the output "Error" is set.

Once the target position has been reached, the function of the function block is terminated and the axis is no longer monitored.

|  |  |
| --- | --- |
| 39519373 | MC\_MoveContinuousAbsolute is not implemented for high/low speed axes. |

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Position     : LREAL;   
    Velocity     : LREAL;   
    EndVelocity  : LREAL;   
    Acceleration : LREAL;   
    Deceleration : LREAL;   
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_MoveOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Position:** Absolute target position

**Velocity:** Maximum velocity for the movement to the target position (>0).

**EndVelocity:** End velocity to be maintained once the target position has been reached.

**Acceleration:** Acceleration (≥0)   
If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0)   
If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk (≥0)   
At a value of 0, the standard jerk from the axis configuration in the System Manager is applied.

**BufferMode:** Is evaluated if the axis already executes another command (type: [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_MoveContinuousAbsolute becomes active after the current command or aborts it. Transition conditions from the current to the next command are also determined by the BufferMode. A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active.

**Options:** Data structure ([ST\_MoveOptions](ms-xhelp:///?Id=beckhoff-d19a-49e9-9f59-b682be3472f8)), which contains additional, rarely required parameters. The input can normally remain open.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    InEndVelocity  : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**InEndVelocity:** TRUE when the target position has been reached.

The function block remains "Busy" and "Active" until a new command is issued.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time one of the outputs "CommandAborted" or "Error" is set.

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
