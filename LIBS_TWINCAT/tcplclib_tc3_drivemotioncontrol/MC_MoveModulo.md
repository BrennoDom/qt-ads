# MC_MoveModulo

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-619b-45f3-96f0-b675ba1121b8)
4. MC\_MoveModulo

# MC\_MoveModulo

![59330872](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873660299__Web.png)

The function block MC\_MoveModulo is used to execute a positioning operation, which refers to the modulo position of an axis. The basis for a modulo rotation is the adjustable parameter "Modulo Factor" of the AXIS\_REF structure (Axis.Parameter.ModuloFactor, e.g. 360°). A distinction is made between three possible start types, depending on the "Direction" input.

* Positioning in positive direction
* Positioning in negative direction
* Positioning along shortest path

## Starting an axis from standstill

If an axis is started from standstill with MC\_MoveModulo , it is possible to specify positions greater than or equal to 360°, in order to perform additional full turns.

## **Special cases**

Particular attention should be paid to the behavior when requesting one or more complete modulo rotations. No movement is performed if the axis is at an exact set position of 90° and is positioned at 90°, for example. If 450° in positive direction is requested, the axis performs one rotation. The behavior can be different following an axis reset, because the reset will cause the current actual position to be adopted as the set position. This means that the axis is no longer exactly at 90°, but slightly below or above this value. These cases will give rise either to a minimum positioning to 90 degrees, or on the other hand a complete rotation.

Depending on the use case, it may be more effective for complete modulo rotations to calculate the desired target position on the basis of the current absolute position, and then to position using the function block [MC\_MoveAbsolute](ms-xhelp:///?Id=beckhoff-9811-4059-a28b-5f9b3da006e3).

See also: [Modulo positioning](ms-xhelp:///?Id=beckhoff-34c7-4f29-b364-9afe88cce2e1)

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Position     : LREAL;   
    Velocity     : LREAL;   
    Acceleration : LREAL;   
    Deceleration : LREAL;   
    Direction    : MC_Direction;  
    Options      : ST_MoveOptions;  
END_VAR 
```

**Execute:** The command is executed with a rising edge.

**Position:** Modulo target position to be used for positioning. If the axis is started from standstill, positions greater than 360° result in additional turns. Negative positions are not permitted.

**Velocity:** Maximum travel velocity (>0).

**Acceleration:** Acceleration (>0)

**Deceleration:** Deceleration (>0)

**Direction:** Positive or negative direction of travel (type: [MC\_Direction](ms-xhelp:///?Id=beckhoff-6e77-4e66-be8f-f38f46a90f29)). If the axis is started during a motion, the direction may not be reversed.

**Options:** Data structure ([ST\_MoveOptions](ms-xhelp:///?Id=beckhoff-2041-4252-90a4-4e988482541f)), which contains additional, rarely required parameters. The input can normally remain unused.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-73e7-420f-a72f-9fc0c9e1b167)

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

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the movement command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** TRUE if the command could not be executed completely. The axis was stopped or the current command was replaced by another Move command.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-73e7-420f-a72f-9fc0c9e1b167)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
