# MC_MovePath

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_MovePath

![37253141](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1428000395__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 66842817 | 64714441 | 45559064 |

The MC\_MovePath function block executes a movement defined in the PathData table by [MC\_MoveLinearAbsolutePreparation](ms-xhelp:///?Id=beckhoff-2ed6-42e1-90a2-a4a27171b040).

|  |  |
| --- | --- |
| 7378398 | Re-triggering of an FB instance during motion  It is possible to execute different motion commands with one instance of this function block. However, the outputs of the function block only indicate the last command executed. The user loses the ability to diagnose for the previously sent motion commands. Re-triggering of a function block is therefore not recommended. |

## 66405588 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |

## 60779388 10143581 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup             : AXES_GROUP_REF;  
    PathData              : MC_PATH_DATA_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see Cyclic group interface). |
| PathData | MC\_PATH\_DATA\_REF | Table containing the segments of a path. The table is written by [MC\_MoveLinearAbsolutePreparation](ms-xhelp:///?Id=beckhoff-2ed6-42e1-90a2-a4a27171b040) and executed by [MC\_MovePath](ms-xhelp:///?Id=beckhoff-33b6-48b3-b766-e02fd42bf25f) (see [MC\_PATH\_DATA\_REF](ms-xhelp:///?Id=beckhoff-db53-4190-b062-b31e45596782)). |

## 24183370 VAR\_OUTPUT

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

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. This means that the last command defined by the reference variable PathData was executed successfully. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with Execute and remains so as long as the function block executes the command. If Busy becomes `FALSE` again, the function block is ready for a new command. At the same time one of the outputs Done, CommandAborted (if available) or Error is set. |
| Active | BOOL | If Active is `TRUE`, the FB controls the axis. |
| CommandAborted | BOOL | This output becomes `TRUE` if the command was interrupted by another command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
