# MC_GroupStop

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_GroupStop

![41816140](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1427996555__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 40800942 | 31664161 | 16541999 |

The function block stops the group and all associated axes with a defined deceleration ramp and locks the axis for motion commands. While the group is in the GroupStopping state, no other function block can move an axis of the group (see State diagrams).

The group can only be moved again once the signal *Execute* has been set to FALSE after the velocity is 0.

|  |  |
| --- | --- |
| 14660263 | MC\_GroupStop cancels the active coordinate transformation and deletes all jobs in the queue. |

## 64833508 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
    Deceleration          : MC_LREAL := MC_DEFAULT;  
    Jerk                  : MC_LREAL := MC_DEFAULT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| Deceleration | MC\_LREAL | [mm/s²]. The deceleration can be programmed as a scalar value (>0), or "[Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a)" can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Jerk | MC\_LREAL | [mm/s³]. The jerk can be programmed as a scalar value (>0), or "[Special input values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a)" can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. MC\_IGNORE executes the command with unlimited jerk. |

## 46630661 17022773 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 18987236 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done                  : BOOL;  
    Busy                  : BOOL;  
    Active                : BOOL;  
    CommandAborted        : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Done | BOOL | Becomes TRUE when the group has been stopped and has come to a standstill. The group remains in the GroupStopping state while *Execute* is TRUE, at least until the axes have come to a stop. The group is then in the GroupStandby state (see State diagrams). |
| Busy | BOOL | Becomes TRUE when the command is started with *Execute* and remains so as long as the command is executed. If *Busy* becomes FALSE again, the group is ready for a new command. After the group is stopped, *Busy* remains TRUE until the group is released with *Execute*=FALSE. |
| Active | BOOL | Indicates that the function block controls the group. After the group is stopped, *Active* remains TRUE until the group is released with Execute=FALSE. |
| CommandAborted | BOOL | The command is aborted by deactivating MC\_Power of at least one axis of the group or if the group is deactivated during the command. |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
