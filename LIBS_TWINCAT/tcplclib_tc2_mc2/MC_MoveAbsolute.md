# MC_MoveAbsolute

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_MoveAbsolute

# MC\_MoveAbsolute

![13317766](/tcplclib_tc2_mc2/1033/Images/png/9007199325022603__Web.png)

MC\_MoveAbsolute starts positioning to an absolute target position and monitors the axis movement over the whole travel path. The "Done" output is set once the target position has been reached. Otherwise, the output "CommandAborted" or, in case of an error, the output "Error" is set.

MC\_MoveAbsolute is predominantly used for linear axis systems. For modulo axes the position is not interpreted as a modulo position, but as an absolute position in continuous absolute coordinate system. Alternatively, the function block [MC\_MoveModulo](ms-xhelp:///?Id=beckhoff-dbe7-4239-bf28-d7dbf3a3eb65) can be used for modulo positioning.

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as MC\_MoveAbsolute then automatically leads to decoupling of the axis, after which the command is executed. In this case the only available BufferMode is "Aborting".

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Position     : LREAL;   
    Velocity     : LREAL;   
    Acceleration : LREAL;   
    Deceleration : LREAL;   
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_MoveOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Position:** Absolute target position to be used for positioning.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (≥0)   
If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0)   
If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk (≥0)   
At a value of 0, the standard jerk from the axis configuration in the System Manager is applied.

**BufferMode:** Is evaluated if the axis already executes another command (type: [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_MoveAbsolute becomes active after the current command or aborts it. Transition conditions from the current to the next command are also determined by the BufferMode. If the command is applied to a coupled slave axis, the only available BufferMode is "Aborting". A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active.

**Options:** Data structure ([ST\_MoveOptions](ms-xhelp:///?Id=beckhoff-d19a-49e9-9f59-b682be3472f8)), which contains additional, rarely required parameters. The input can normally remain open.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**Done:** TRUE when the target position has been reached.

|  |  |
| --- | --- |
| 52751036 | * "Target Position Monitoring" is activated (standard case): If the logical positioning end has been reached (the NC setpoint generation is ended and the HasJob bit is FALSE) AND the InTargetPosition bit has afterwards become TRUE, then the Done output is set to TRUE.  * "Position Range Monitoring" is activated ("Target Position Monitoring" is not active): If the logical positioning end has been reached (the NC setpoint generation is ended and the HasJob bit is FALSE) AND the InPositionArea bit has afterwards become TRUE, then the Done output is set to TRUE.  * Neither "Target Position Monitoring" nor "Position Range Monitoring" is activated: The Done output is set immediately when the logical positioning end is reached (the NC setpoint generation is ended and the HasJob bit is FALSE). |

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

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
