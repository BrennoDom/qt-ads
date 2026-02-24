# MC_Halt

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-7ffe-4e9a-b17d-c6d5be097acd)
3. [Point to point motion](ms-xhelp:///?Id=beckhoff-619b-45f3-96f0-b675ba1121b8)
4. MC\_Halt

# MC\_Halt

![49614245](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873652619__Web.png)

MC\_Halt stops an axis with a defined braking ramp.

In contrast to [MC\_Stop](ms-xhelp:///?Id=beckhoff-bba4-4c3f-9dbd-4b986c3444cc), the axis is not locked against further movement commands. The axis can therefore be started by another command after the stop.

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;   
    Deceleration : LREAL;   
    Options      : ST_MoveOptions;   
END_VAR
```

**Execute:** The command is executed with a rising edge.

**Deceleration:** Deceleration   
If the value is ≤ 0, the deceleration parameterized with the last Move command is used. For safety reasons MC\_Halt and [MC\_Stop](ms-xhelp:///?Id=beckhoff-bba4-4c3f-9dbd-4b986c3444cc) cannot be executed with weaker dynamics than the currently active travel command. The parameterization is adjusted automatically, if necessary.

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

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** Becomes TRUE, if the command could not be fully executed. The running command may have been followed by a Move command.

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

## Requirements

| Development environment | PLC libraries to include |
| --- | --- |
| TwinCAT 3.1.4024.11 | Tc3\_DriveMotionControl |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
