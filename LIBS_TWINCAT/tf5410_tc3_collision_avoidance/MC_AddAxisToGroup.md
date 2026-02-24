# MC_AddAxisToGroup

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_AddAxisToGroup

![66373591](/tf5410_tc3_collision_avoidance/1033/Images/png/1427878795__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 60491410 | 7551780 | 857158 |

This function block adds an axis to a group.

|  |  |
| --- | --- |
| 7714425 | From V3.1.10.1, axes in the GroupMoving state can be added to and removed from a **CA group**. If a moving axis is added to a group, the command is rejected with an error message (a change of the group state with a moving axis is also rejected). |

|  |  |
| --- | --- |
| 2320967 | Axes can only be added to an **MC group** if EnableRequested is FALSE, e.g. in the GroupDisabled state. |

## 20888703 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
    IdentInGroup          : IDENT_IN_GROUP_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| IdentInGroup | IDENT\_IN\_GROUP\_REF | Defines the interpretation of the axis to be added to the group. For multi-dimensional motions, this can be the Cartesian interpretation. The [IDENT\_IN\_GROUP\_REF](ms-xhelp:///?Id=beckhoff-ede2-46d7-9ee0-7c0526b88aa2) (e.g. MCS\_X) must be used. For Collision Avoidance the function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-4e24-46b0-ba59-5c9ff8c98bdb) must be used.  Note The use of integer values for the input IdentInGroup is NOT supported and may lead to incompatibility with future releases. If integer values are used, it may no longer be possible to build the project. We recommend using global variables (e.g. MCS\_X) or the conversion function UDINT\_TO\_IDENTINGROUP. |

## 53780604 14263389 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup             : AXES_GROUP_REF;  
    Axis                  : AXIS_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)). |
| Axis | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 61261645 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done                  : BOOL;  
    Busy                  : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes TRUE when the command was successfully executed. |
| Busy | BOOL | This output becomes TRUE when the command is started with Execute and remains so as long as the function block executes the command. If Busy becomes FALSE again, the function block is ready for a new command. At the same time one of the outputs Done, CommandAborted (if available) or Error is set. |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the [ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38) or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Example for TwinCAT 3 Motion Pick-and-Place

**Multidimensional movements**

|  |  |
| --- | --- |
| 14483900 | Multidimensional movements are only applicable when TF5420 is used. |

```
VAR_GLOBAL CONSTANT  
    cAxesCount           : UINT := 4;  
END_VAR   
VAR  
    stGroupRef            : AXES_GROUP_REF; // link to MC Group  
    stAxis                : ARRAY[1..cAxesCount] OF AXIS_REF;  
    fbAddAxis             : ARRAY[1..cAxesCount] OF MC_AddAxisToGroup;  
    i                     : UINT;  
END_VAR
```

```
fbAddAxis[1].IdentInGroup := MCS_X; //X-Axis  
fbAddAxis[2].IdentInGroup := MCS_Y; //Y-Axis  
fbAddAxis[3].IdentInGroup := MCS_Z; //Z-Axis  
fbAddAxis[4].IdentInGroup := MCS_C1;//1st rotation is C-rotation (around Z-Axis)  
  
FOR i:=1 TO cAxesCount DO  
    fbAddAxis[i](  
    AxesGroup:=stGroupRef,   
    Axis := stAxis[i],   
    Execute := TRUE);  
END_FOR
```

## Example for TF5410 TwinCAT 3 Motion Collision Avoidance

**PTP with Collision Avoidance**

|  |  |
| --- | --- |
| 63246244 | PTP with Collision Avoidance is only applicable when TF5410 is used. |

```
VAR_GLOBAL CONSTANT  
    cAxesCount            : UDINT:=10;  
END_VAR   
VAR  
    stGroupRef            : AXES_GROUP_REF; // link to CA Group  
    stAxis                : ARRAY[1..cAxesCount] OF AXIS_REF;  
    fbAddAxis             : ARRAY[1..cAxesCount] OF MC_AddAxisToGroup;  
    i                     : UDINT;  
END_VAR
```

```
FOR i:=1 TO cAxesCount DO  
    fbAddAxis[i](  
        AxesGroup:=stGroupRef,   
        Axis := stAxis[i],   
        IdentInGroup := UDINT_TO_IDENTINGROUP(i),  
        Execute := TRUE);  
END_FOR
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
