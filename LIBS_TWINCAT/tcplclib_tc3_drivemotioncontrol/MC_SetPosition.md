# MC_SetPosition

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-290a-4455-9df4-a3a3057c631c)
3. [Axis functions](ms-xhelp:///?Id=beckhoff-cb3e-4c30-994c-476bbe2bf879)
4. MC\_SetPosition

# MC\_SetPosition

![62215569](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8873669899__Web.png)

MC\_SetPosition sets the current axis position to a parameterizable value.

In absolute mode, the actual position is set to the parameterized absolute Position value. In relative mode, the actual position is offset by the parameterized Position value. In both cases, the set position of the axis is set such that any lag error that may exist is retained. The switch Options.ClearPositionLag can be used to clear the lag error.

Relative mode can be used to change the axis position during the motion.

## Inputs

```
VAR_INPUT  
    Execute  : BOOL;  
    Position : LREAL;   
    Mode     : BOOL; (* RELATIVE=True, ABSOLUTE=False (Default) *)  
    Options  : ST_SetPositionOptions;   
END_VAR
```

**Execute:** The command is executed with a rising edge.

**Position:** Position value to which the axis position is to be set. In absolute mode the actual position is set to this value, in relative mode it is shifted by this value.

**Mode:** The axis position is set to an absolute value set if Mode = FALSE. Otherwise the axis position is changed relative to the specified Position value. Relative mode can be used for changing the position of an axis during motion.

**Options:** Not used at present

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-73e7-420f-a72f-9fc0c9e1b167)

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE if the position was set successfully.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

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
