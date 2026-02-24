# MC_ReleaseBlocker

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_ReleaseBlocker

![59763787](/tf5410_tc3_collision_avoidance/1033/Images/png/8823268107__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 1003178 | 9028608 | 14148614 |

This function block resolves a blocking job that blocks further execution of the path. A blocking job is inserted into the path with [MC\_BlockerPreparation](ms-xhelp:///?Id=beckhoff-b512-4674-9a24-75c6c44ad991).

With the Superpos blending strategy, the blocker can be resolved before the blocker position is reached. Loops between motion segments surrounding this blocker can be executed if those segments allow it and are still executable at the time the blocking job is released.

## 60228670 VAR\_INPUT

```
VAR_INPUT  
    Execute        : BOOL;  
    BlockerId      : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| BlockerId | UDINT | Id of the blocker. Can be any UDINT >0. |

## 5187119 46684076 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup      : AXES_GROUP_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to an axis group (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)). |

## 17503500 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Error          : BOOL;  
    ErrorId        : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with Execute and remains so as long as the function block executes the command. If Busy becomes FALSE again, the function block is ready for a new command. At the same time one of the outputs Done, CommandAborted (if available) or Error is set. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
