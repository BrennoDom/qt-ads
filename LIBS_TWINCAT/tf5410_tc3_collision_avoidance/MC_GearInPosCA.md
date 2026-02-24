# MC_GearInPosCA

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GearInPosCA

![3997487](/tf5410_tc3_collision_avoidance/1033/Images/png/8991721739__Web.png)

This function block couples a slave axis to a master axis. The set values always form the source for the master values. Collision avoidance has higher priority than axis coupling. The slave axis can be decoupled by sending a motion command using the buffer mode BufferMode `mcAborting`.

## 35977388 VAR\_INPUT

```
VAR_INPUT  
    Execute             : BOOL;  
    ContinuousUpdate    : BOOL;  
    RatioNumerator      : MC_LREAL := 1;  
    RatioDenumerator    : UINT := 1;  
    MasterSyncPosition  : MC_LREAL := MC_INVALID;  
    SlaveSyncPosition   : MC_LREAL := MC_INVALID;  
    SyncStrategy        : MC_SYNC_STRATEGY := mcSyncStrategyLate;  
    SyncMode            : MC_SYNC_MODE;  
    MasterStartDistance : MC_LREAL := MC_IGNORE;  
    Velocity            : MC_LREAL := MC_INVALID;  
    Acceleration        : MC_LREAL := MC_DEFAULT;  
    Deceleration        : MC_LREAL := MC_DEFAULT;  
    Jerk                : MC_LREAL := MC_DEFAULT;  
    Gap                 : MC_LREAL := MC_DEFAULT;  
    BufferMode          : MC_BUFFER_MODE := mcAborting;  
    Options             : ST_GearInPosCAOptions;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| ContinuousUpdate | BOOL | In this version, continuous updating is only available for the Gap. |
| RatioNumerator | MC\_LREAL | A gearing factor can be set by entering integer values at the `RatioNumerator` and `RatioDenumerator` inputs or by entering a decimal value for the `RatioNumerator` and leaving the `RatioDenumerator` unchanged (the default value is `1`). The gearing factor is entered as a factor, e.g. a value of `0.8` means that the slave velocity is `0.8 * master axis velocity` (or `80%` of the master axis velocity). The value for the factor is not limited, it could be greater than `1.0` or negative. |
| RatioDenumerator | UINT | Denominator for the gearing factor. |
| MasterSyncPosition | MC\_LREAL | This input is of type `LREAL`. Position of the master at which the slave is `InSync` and has the correct gear ratio. |
| SlaveSyncPosition | MC\_LREAL | This input is of type LREAL. Position of the slave at which it is InSync with the correct gear ratio. |
| SyncStrategy | MC\_SYNC\_STRATEGY | Defines the strategy that the slave uses for synchronization (see [MC\_SYNC\_STRATEGY](ms-xhelp:///?Id=beckhoff-44db-4745-9002-25d30a379650)). The default strategy is `mcSyncStrategyLate.` |
| SyncMode  (available from V3.1.10.1) | MC\_SYNC\_MODE | Defines the direction in which the SlaveSync position is to be interpreted, see [MC\_SYNC\_MODE](ms-xhelp:///?Id=beckhoff-e50c-4cdb-b274-b128a81d2853). |
| MasterStartDistance | MC\_LREAL | If a positive value is set, the slave axis will not start synchronization until the master position is greater than or equal to the master position (MasterSyncPosition – MasterStartDistance). If a negative value is set, the synchronization will not start until the master position is less than or equal to (MasterSyncPosition – MasterStartDistance).  If MasterStartDistance is not set, the slave starts synchronization as soon as the function block gives the Active signal. The exact behavior of the slave axis during the synchronization phase depends on the SyncStrategy. |
| Velocity | MC\_LREAL | Maximum velocity of the slave axis during the synchronization phase. The velocity is limited by the maximum velocity of the slave axis. If no value is entered, an error occurs because there is no default velocity. |
| Acceleration | MC\_LREAL | Maximum acceleration of the slave axis during the synchronization phase. The acceleration is limited by the maximum acceleration of the slave axis. If no value is entered, the default acceleration of the slave axis is used. |
| Deceleration | MC\_LREAL | Maximum deceleration of the slave axis during the synchronization phase. The deceleration is limited by the maximum deceleration of the slave axis. If no value is entered, the default deceleration of the slave axis is used. |
| Jerk | MC\_LREAL | Maximum jerk of the axis during the synchronization phase. If no value is entered, the default jerk of the slave axis is used. The jerk is not limited. |
| Gap | MC\_LREAL | This value determines the minimum gap to the predecessor for Collision Avoidance. If no value is entered, the default value of the group is used.  Note When using geo-compensation, special attention must be paid to the distance. In terms of position and dynamics the mover distance for Collision Avoidance always relates to the offset path geometry. Since the distance refers to the offset path when using geo-compensation, adjacent movers in the curves can collide if it is set too low. Ensure an adequate distance. |
| BufferMode | MC\_BUFFER\_MODE | In this version only `mcAborting` and `mcBuffered` are available (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-697d-490e-b719-bb5939f3f414)). |
| Options | ST\_GearInPosCAOptions | The `Options` can be used to influence the synchronization profile of the slave, in addition to the `SyncStrategy` (from V3.1.2.47) (see [ST\_GearInPosCAOptions](ms-xhelp:///?Id=beckhoff-dfb7-4eea-8762-2deabb22447e)). |

|  |  |
| --- | --- |
| 55361044 | The axis does not reach the target velocity, acceleration or deceleration  The values for velocity, acceleration or deceleration may be automatically limited to the maximum axis velocity, acceleration and deceleration. Check the parameters Maximum Dynamics and Default Dynamics of the axis. It is also possible that the values of Maximum Dynamics are smaller than the Default Dynamics. |

## 28487350 55059565 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Master   : AXIS_REF;  
    Slave    : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Master | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |
| Slave | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 25774041 VAR\_OUTPUT

```
VAR_OUTPUT  
    StartSync     : BOOL;  
    InSync        : BOOL;  
    Busy          : BOOL;  
    Active        : BOOL;  
    CommandAborted: BOOL;  
    Error         : BOOL;  
    ErrorId       : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| StartSync | BOOL | This output is set when the slave actively starts synchronization and reset when the slave is InSync. |
| InSync | BOOL | This output becomes `TRUE` when the slave is synchronized. If the dynamics of the slave axis is too low to follow the movement of the master axis, the output `InSync` could be reset to `FALSE`, after which the slave axis starts synchronizing again. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time one of the outputs `CommandAborted` or `Error` is set. |
| Active | BOOL | If `Active` is `TRUE`, the function block controls the axis. |
| CommandAborted | BOOL | This output becomes `TRUE` if the command was interrupted by another command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the ADS error documentation or in the NC error documentation (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
