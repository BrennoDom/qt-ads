# MC_MoveModulo

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-4120-4cf1-ab1b-35a13a0a1cec)
4. MC\_MoveModulo

# MC\_MoveModulo

![6584502](/tcplclib_tc2_mc2/1033/Images/png/9007199325032203__Web.png)

The function block MC\_MoveModulo is used to execute a positioning operation, which refers to the modulo position of an axis. A modulo rotation is based on the adjustable axis parameter modulo factor (e.g. 360°). A distinction is made between three possible start types, depending on the "Direction" input.

* Positioning in positive direction
* Positioning in negative direction
* Positioning along shortest path

Motion commands can be applied to coupled slave axes, if this option was explicitly activated in the axis parameters. A motion command such as MC\_MoveModulo then automatically leads to decoupling of the axis, after which the command is executed. In this case the only available BufferMode is "Aborting".

## Starting an axis from standstill

If an axis is started from standstill with MC\_MoveModulo , it is possible to specify positions greater than or equal to 360°, in order to perform additional full turns. The same applies to a start with the BufferMode "MC\_Buffered".

## Starting an axis during motion

If an axis is already in motion, certain special considerations apply. The direction of movement cannot be reversed by MC\_MoveModulo, i.e. the target can only be reached in the current direction. The user is not able to specify the number of additional turns. The system automatically calculates how the axis can be moved to the target position on the shortest possible path.

The error output must be analyzed, because under certain conditions an oriented stop is not possible. For example, a standard stop may have been triggered just before, or an oriented stop would cause an active software limit switch to be exceeded. For all fault conditions, the axis is stopped safely, but it may subsequently not be at the required oriented position.

## **Special cases**

Particular attention should be paid to the behavior when requesting one or more complete modulo rotations. If the axis is located at an exact set position, such as 90 degrees, and if positioning to 90 degrees is required, no movement is carried out. If required to turn 450 degrees in a positive direction, it will perform just one rotation. The behavior can be different following an axis reset, because the reset will cause the current actual position to be adopted as the set position. The axis will then no longer be exactly at 90 degrees, but will be a little under or over. These cases will give rise either to a minimum positioning to 90 degrees, or on the other hand a complete rotation.

Depending on the particular case, it may be more effective for complete modulo rotations to calculate the desired target position on the basis of the current absolute position, and then to position using the function block [MC\_MoveAbsolute](ms-xhelp:///?Id=beckhoff-d758-42c5-8d7b-c56658edbc31).

|  |  |
| --- | --- |
| 59260526 | Modulo positioning and absolute positioning are available for all axes, irrespective of the modulo setting in the TwinCAT System Manager. For each axis, the current absolute position "SetPos" can be read from the cyclic axis interface data type [NCTOPLC\_AXIS\_REF](ms-xhelp:///?Id=beckhoff-00d5-42b3-9ded-9a9f62e7df27). |

See also: [Notes on modulo positioning](ms-xhelp:///?Id=beckhoff-7468-4b2f-9792-bee9563a5a6e)

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Position     : LREAL;   
    Velocity     : LREAL;   
    Acceleration : LREAL;   
    Deceleration : LREAL;   
    Jerk         : LREAL;  
    Direction    : MC_Direction;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_MoveOptions;  
END_VAR 
```

**Execute:** The command is executed with a positive edge.

**Position:** Modulo target position to be used for positioning. If the axis is started from standstill, positions greater than 360° result in additional turns. Negative positions are not permitted.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (≥0)   
If the value is 0, the standard acceleration from the axis configuration in the System Manager is used.

**Deceleration:** Deceleration (≥0)   
If the value is 0, the standard deceleration from the axis configuration in the System Manager is used.

**Jerk:** Jerk (≥0)   
At a value of 0, the standard jerk from the axis configuration in the System Manager is applied.

**Direction:** Positive or negative direction of travel (type: [MC\_Direction](ms-xhelp:///?Id=beckhoff-d26f-4561-922b-f593d61b8fcd)). If the axis is started during a motion, the direction may not be reversed.

**BufferMode:** Is evaluated if the axis already executes another command (see [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_MoveModulo becomes active after the current command or aborts it. Transition conditions from the current to the next command are also determined by the BufferMode. A second function block is always required to use the BufferMode. It is not possible to trigger a move function block with new parameters while it is active.

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
| 63582688 | * "Target Position Monitoring" is activated (standard case): If the logical positioning end has been reached (the NC setpoint generation is ended and the HasJob bit is FALSE) AND the InTargetPosition bit has afterwards become TRUE, then the Done output is set to TRUE.  * "Position Range Monitoring" is activated ("Target Position Monitoring" is not active): If the logical positioning end has been reached (the NC setpoint generation is ended and the HasJob bit is FALSE) AND the InPositionArea bit has afterwards become TRUE, then the Done output is set to TRUE.  * Neither "Target Position Monitoring" nor "Position Range Monitoring" is activated: The Done output is set immediately when the logical positioning end is reached (the NC setpoint generation is ended and the HasJob bit is FALSE). |

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
