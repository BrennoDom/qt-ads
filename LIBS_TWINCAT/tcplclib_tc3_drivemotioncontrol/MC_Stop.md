# MC_Stop

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-619b-45f3-96f0-b675ba1121b8)
4. MC\_Stop

# MC\_Stop

![42925989](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873671819__Web.png)

MC\_Stop stops an axis with a defined braking ramp and locks it against other motion commands. The function block is therefore suitable for stops in special situations, in which further axis movements are to be prevented.

At the same time the axis is blocked for other motion commands. The axis can only be restarted once the Execute signal has been set to FALSE after the axis has stopped. A few cycles are required to release the axis after a falling edge of Execute. During this phase the "Busy" output remains TRUE, and the function block has to be called until "Busy" becomes FALSE.

The locking of the axis is canceled with an [MC\_Reset](ms-xhelp:///?Id=beckhoff-4930-455a-b236-c5815ef9d98d).

Alternatively, the axis can be stopped with [MC\_Halt](ms-xhelp:///?Id=beckhoff-678e-4a89-9832-d2d7c152906f) without locking. MC\_Halt is preferable for normal movements.

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;   
    Deceleration : LREAL;   
    Options      : ST_MoveOptions;   
END_VAR
```

**Execute:** The command is executed with a rising edge. The axis is locked during the stop. The axis can only be restarted once the Execute signal has been set to FALSE after the axis has stopped.

**Deceleration:** Deceleration   
If the value is = 0, the deceleration parameterized with the last Move command is used. For safety reasons MC\_Stop and MC\_Halt cannot be executed with weaker dynamics than the currently active motion command. The parameterization is adjusted automatically, if necessary.

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

**Done:** TRUE if the axis has been stopped and is stationary.

**Busy:** TRUE as soon as the command is started with Execute and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. "Busy" remains TRUE as long as the axis is locked. The axis is only unlocked and "Busy" becomes FALSE when Execute is set to FALSE.

**Active:** Indicates that the function block controls the axis. Remains TRUE as long as the axis is locked. The axis is only unlocked and "Active" becomes FALSE when Execute is set to FALSE.

**CommandAborted:** TRUE if the command could not be executed completely.

**Error:** TRUE, if an error occurs

**ErrorID:** If the error output is set, this parameter supplies the error number.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-73e7-420f-a72f-9fc0c9e1b167)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-1610-445d-9b44-15a5aa4e120c))

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
