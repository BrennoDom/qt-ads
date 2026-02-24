# MC_TrackConveyorBelt

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_TrackConveyorBelt

![20875522](/tf5410_tc3_collision_avoidance/1033/Images/png/5537580299__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 53661974 | 13195723 | 51652651 |

The function block `Mc_TrackConveyorBelt` enables a reference system that is in motion. It synchronizes the `AxesGroup` with the `ConveyorBelt` in terms of velocity.

Synchronization with a position requires a motion command.

The function block thus helps to synchronize with an object that moves in a straight line through space. Example: products moving on a conveyor belt or other transport system.

The origin of the conveyor belt is parameterized with a coordinate system (`CoordTransform`). `X` is the conveying direction. The detected object position (`InitialObjectPos`) and the corresponding touch probe position (`MasterRefPos`) are entered in the function block.

Synchronization dynamics can be entered in the function block.

Movements executed after `Active = TRUE` are synchronized with the conveyor belt.

Execution of `MC_TrackConveyorBelt` with another instance causes direct synchronization with a second conveyor belt.

When changing the reference system, a conveyor belt can be decoupled.

|  |  |
| --- | --- |
| 62220677 | Use case for changing the reference system  The `MC` group can be decoupled by using `MC_TrackConveyorBelt` and changing the reference system. The reference system can be changed with `MC_SetCoordinateTransform`. |

## 23115188 VAR\_INPUT

```
VAR_INPUT  
    Execute                           : BOOL;  
    CoordTransform                    : MC_COORD_REF;  
    InitialObjectPos                  : POINTER TO MC_LREAL;  
    InitialObjectPosCount             : UDINT;  
    MasterRefPos                      : MC_LREAL;  
    Velocity                          : MC_LREAL := MC_DEFAULT;  
    Acceleration                      : MC_LREAL := MC_DEFAULT;  
    Deceleration                      : MC_LREAL := MC_DEFAULT;  
    Jerk                              : MC_LREAL := MC_DEFAULT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| CoordTransform | MC\_COORD\_REF | Reference to a coordinate system (see [MC\_COORD\_REF](ms-xhelp:///?Id=beckhoff-4b73-4754-8e44-b9cd9d370e00)). |
| InitialObjectPos | POINTER TO MC\_LREAL | Pointer to array `[1..InitialObjectPosCount]`. |
| InitialObjectPosCount | UDINT | Dimension of the `InitialObjectPos` vector. |
| MasterRefPos | MC\_LREAL | Touch probe position. |
| Velocity | MC\_LREAL | Velocity for synchronization. The velocity must exceed the conveyor belt velocity. The velocity is limited by the maximum axis velocity. |
| Acceleration | MC\_LREAL | Used in the Conveyor Tracking object. The acceleration for synchronization. The acceleration must exceed the value `1.0`. The acceleration is limited by the maximum axis acceleration. If no value is entered, the default axis acceleration is used. |
| Deceleration | MC\_LREAL | Used in the Conveyor Tracking object. The deceleration for synchronization. The deceleration must exceed the value `1.0`. The deceleration is limited by the maximum axis deceleration. If no value is entered, the default axis deceleration is used. |
| Jerk | MC\_LREAL | The jerk for synchronization. The jerk must exceed the value `100.0`. If no value is entered, the default axis jerk is used. The maximum jerk is not limited. |

## 6710104 60390938 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup                         : AXES_GROUP_REF;  
    ConveyorBelt                      : AXIS_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)). |
| ConveyorBelt | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | Reference to an axis. Reference to the conveyor axis. |

## 6647531 VAR\_OUTPUT

```
VAR_OUTPUT  
    InSync                : BOOL;  
    Busy                  : BOOL;  
    Active                : BOOL;  
    CommandAborted        : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| InSync | BOOL | The output `InSync` becomes `TRUE` for the first time when the slave is synchronized with the velocity. If the slave dynamics is too low to follow the master movement, the output `InSync` could be reset to `FALSE`, after which the slave axis starts synchronizing again.  Note Velocity synchronization: Active and InSync - the function block MC\_TrackConveyorBelt synchronizes the AxesGroup with the velocity of the ConveyorBelt axis. The function block uses the given parameters for Acceleration, Deceleration and Jerk. When this synchronization movement begins, Active is set to TRUE. When the velocity of the ConveyorBelt is reached, InSync is set to TRUE. The synchronization status is continuously monitored and indicated with InSync.  Note Conveyor movement, default tracking behavior and InSync - once the output signal InSync has been set, there are two options to maintain synchronization. mcTrackingBehaviorDynLimited - this behavior is the default (MC\_Default) tracking behavior. The AxesGroup maintains velocity synchronization with the ConveyorBelt using the given parameters for Acceleration, Deceleration and Jerk. – mcTrackingBehaviorStayInSync - the AxesGroup maintains the velocity synchronization with the ConveyorBelt with unlimited parameters for Acceleration, Deceleration and Jerk.  Note Position synchronization: MasterRefPos and InitialObjectPos - the function blocks MC\_TrackConveyorBelt and MC\_MovePath should be used together for flexible synchronization with a moving target position. After MC\_TrackConveyorBelt.Active is set to TRUE, InitialObjectPos and the distance to MasterRefPos are appended to the next call to MC\_MovePath. MC\_TrackConveyorBelt.InSync = TRUE and MC\_MovePath.Done = TRUE indicate that the synchronized position has been reached. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `BUSY` becomes `FALSE` again, the function block is ready for a new command. At the same time, one of the outputs `CommandAborted` or `Error` is set. |
| Active | BOOL | If `Active` is `TRUE`, the function block controls the group. |
| CommandAborted | BOOL | This output becomes `TRUE` if the command was interrupted by another command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development Environment | Target System Type | PLC Libraries to be Linked |
| --- | --- | --- |
| TwinCAT V3.1.4022.25 TF5400 Advanced Motion Pack V3.1.6.03 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
