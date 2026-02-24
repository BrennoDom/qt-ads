# MC_SetCoordinateTransform

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_SetCoordinateTransform

![15361866](/tf5410_tc3_collision_avoidance/1033/Images/png/5537582859__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 4039073 | 36351665 | 58729529 |

Enables a reference system.

Executed movements use the coordinate system that was set after the command was successfully executed, which is indicated by `Done = TRUE`.

When changing the reference system, a conveyor belt can be decoupled.

|  |  |
| --- | --- |
| 58803715 | Use case for changing the reference system  The `MC` group can be decoupled by using `MC_SetCoordinateTransform` and changing the reference system. |

## 59471393 VAR\_INPUT

```
VAR_INPUT  
    Execute        : BOOL;  
    CoordTransform : MC_COORD_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| CoordTransform | MC\_COORD\_REF | Reference to a coordinate system (see [MC\_COORD\_REF](ms-xhelp:///?Id=beckhoff-4b73-4754-8e44-b9cd9d370e00)). |

## 65480490 52453505 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup      : AXES_GROUP_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| **AxesGroup** | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)). |

## 2319502 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done           : BOOL;  
    Busy           : BOOL;  
    Active         : BOOL;  
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorId        : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time, one of the outputs `Done`, `CommandAborted` or `Error` is set. |
| Active | BOOL | `Active` indicates that the command is being executed. If the command was in the queue, it becomes active as soon as an executed command is completed. |
| CommandAborted | BOOL | This output becomes `TRUE` if the command was interrupted by another command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development Environment | Target System Type | PLC Libraries to be Linked |
| --- | --- | --- |
| TwinCAT V3.1.4022.25 TF5400 Advanced Motion Pack V3.1.6.03 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
