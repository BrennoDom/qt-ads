# MC_RemoveAxisFromGroup

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_RemoveAxisFromGroup

![10656503](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1428002315__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 28799665 | 57870399 | 51071544 |

This function block removes an axis from the axis group.

|  |  |
| --- | --- |
| 56990719 | From V3.1.10.1, axes in the GroupMoving state can be added to and removed from a **CA group**. If a moving axis is added to a group, the command is rejected with an error message (a change of the group state with a moving axis is also rejected). |

|  |  |
| --- | --- |
| 43154428 | Axes can only be added to an **MC group** if EnableRequested is FALSE, e.g. in the GroupDisabled state. |

|  |  |
| --- | --- |
| 52845536 | Success of the function block  The function block always returns DONE if the axis no longer belongs to the group. This means that DONE is returned even if the axis was not in the group before the function block was called. |

## 5847780 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
    IdentInGroup          : IDENT_IN_GROUP_REF;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| IdentInGroup | IDENT\_IN\_GROUP\_REF | Defines the interpretation of the axis to be added to the group. For multidimensional motions, this can be the Cartesian interpretation. The global variables (e.g. MCS\_X) must be used. For Collision Avoidance the function UDINT\_TO\_IDENTINGROUP must be used. |

|  |  |
| --- | --- |
| 52630025 | Use of integer values for the input IdentInGroup  The use of integer values for the input IdentInGroup is NOT supported and may lead to incompatibility with future releases. If integer values are used, it may no longer be possible to build the project. We recommend using [global variables](ms-xhelp:///?Id=beckhoff-f9b9-42c9-b78d-9fcb08c26c63) (e.g. MCS\_X) or the conversion function [UDINT\_TO\_IDENTINGROUP](ms-xhelp:///?Id=beckhoff-51e0-4922-8e57-997279beac86). |

## 3908185 35173667 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 48127554 VAR\_OUTPUT

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

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
