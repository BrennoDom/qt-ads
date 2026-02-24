# MC_GroupHalt

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GroupHalt

![2338313](/tf5410_tc3_collision_avoidance/1033/Images/png/1427884555__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 21044820 | 55185655 | 26908851 |

The MC\_GroupHalt function block stops a group with a defined deceleration ramp. Unlike "[MC\_GroupStop](ms-xhelp:///?Id=beckhoff-0c51-44ab-b6ec-0d02026e7a10)", the group is not locked for further motion commands. Therefore, the group can be restarted by another command during the deceleration ramp or after stopping.

|  |  |
| --- | --- |
| 40853074WARNING | |
| Possible delayed axis stop  If Standby `Gap Control` is active with a CA group and the gap is also less than the minimum, the gap is first extended before the axes can be stopped with an `MC_GroupHalt`.   * Make sure that you actually need the behavior of Standby `Gap Control`; if not, consider disabling it (default setting). * Use an MC\_GroupStop instead of an MC\_GroupHalt if the axes need to be stopped without a delay. | |

|  |  |
| --- | --- |
| Note | |
| MC\_GroupHalt not implemented for MC group with pick-and-place  The MC\_GroupHalt function block is only implemented for the MC Group Coordinated Motion and for PTP movements with Collision Avoidance (CA group). When used with another group type, the command is rejected. | |

|  |  |
| --- | --- |
| 32133347 | Gilt für die MC\_Group: MC\_GroupHalt cancels the active coordinate transformation and deletes all jobs in the queue. |

## 20764673 VAR\_INPUT

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
| Deceleration | MC\_LREAL | [mm/s²]. The deceleration can be programmed as a scalar value (>0), or "[Special input values](ms-xhelp:///?Id=beckhoff-c910-4534-9e5d-a9d58690845e)" can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. |
| Jerk | MC\_LREAL | [mm/s³]. The jerk can be programmed as a scalar value (>0), or "[Special input values](ms-xhelp:///?Id=beckhoff-c910-4534-9e5d-a9d58690845e)" can be used. MC\_DEFAULT executes the command with standard axis values. MC\_MAXIMUM executes the command with the maximum axis values. MC\_IGNORE executes the command with unlimited jerk. |

## 52664332 4216941 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 37952469 VAR\_OUTPUT

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
| Done | BOOL | Becomes TRUE when the group has been stopped and has come to a standstill. Once the group has come to a standstill, the group state becomes GroupStandby (see [State diagrams](ms-xhelp:///?Id=beckhoff-2851-4318-9268-42575faccf68)). |
| Busy | BOOL | This output becomes TRUE when the command is started with Execute and remains so as long as the function block executes the command. If Busy becomes FALSE again, the function block is ready for a new command. At the same time one of the outputs Done, CommandAborted (if available) or Error is set. |
| Active | BOOL | Active indicates that the command is being executed. If the command was in the queue, it becomes active as soon as an executed command is completed. |
| CommandAborted | BOOL | This output becomes TRUE if the command was interrupted by another command. |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
