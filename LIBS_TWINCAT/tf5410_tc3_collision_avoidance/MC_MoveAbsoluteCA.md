# MC_MoveAbsoluteCA

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_MoveAbsoluteCA

![8409368](/tf5410_tc3_collision_avoidance/1033/Images/png/8991723659__Web.png)

This function block instructs a single axis to move to the absolute position defined in the function block, based on collision avoidance. Collision avoidance has higher priority than the motion command. Therefore, the axis may slow down or wait while the motion command is executed to avoid a collision. The function block does not output the signal `Done` until the axis has reached its target position.

## 8575450 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
    ContinuousUpdate      : BOOL;  
    Position              : MC_LREAL := MC_INVALID;  
    Velocity              : MC_LREAL := MC_INVALID;  
    Acceleration          : MC_LREAL := MC_DEFAULT;  
    Deceleration          : MC_LREAL := MC_DEFAULT;  
    Jerk                  : MC_LREAL := MC_DEFAULT;  
    Gap                   : MC_LREAL := MC_DEFAULT;  
    BufferMode            : MC_BUFFER_MODE := mcAborting;  
    Direction             : Tc3_Mc3Definitions.MC_DIRECTION;  
    Options               : ST_MoveAbsoluteCAOptions;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| ContinuousUpdate | BOOL | In this version, continuous updating is only available for the `Gap`. |
| Position | MC\_LREAL | Specified absolute target position for the command.  **From V3.1.10.30:**  If positioning is based on modulo (`Direction != mcDirectionNonModulo`), the target position must be in the `interval [0, ModuloFactor]`. Additional turns are commanded via the parameter `ST_MoveAbsoluteCAOptions.AdditionalTurns`.  If the target position is within the `Tolerance Window`, `Direction = mcDirectionPositive` and `Direction = mcDirectionNegative` are ignored for the position without additional turns.  **Up to V3.1.10.14** additional turns are commanded by commanding larger target positions than the `ModuloFaktor`.  Further details in the notes on [Modulo positioning](ms-xhelp:///?Id=beckhoff-b707-4905-b887-f0cfc84eafbd). |
| Velocity | MC\_LREAL | The velocity is limited by the maximum axis velocity. If no value is entered, an error occurs because there is no default velocity. |
| Acceleration | MC\_LREAL | The acceleration is limited by the maximum axis acceleration. If no value is entered, the default axis acceleration is used. |
| Deceleration | MC\_LREAL | The deceleration is limited by the maximum axis deceleration. If no value is entered, the default axis deceleration is used. |
| Jerk | MC\_LREAL | If no value is entered, the default axis jerk is used. The maximum jerk is not limited. |
| Gap | MC\_LREAL | This value determines the minimum gap to the predecessor for Collision Avoidance. If no value is entered, the default value of the group is used.  Note When using geo-compensation, special attention must be paid to the distance. In terms of position and dynamics the mover distance for Collision Avoidance always relates to the offset path geometry. Since the distance refers to the offset path when using geo-compensation, adjacent movers in the curves can collide if it is set too low. Ensure an adequate distance. |
| BufferMode | MC\_BUFFER\_MODE | In this version only `mcAborting` and `mcBuffered` are available (see [MC\_BUFFER\_MODE](ms-xhelp:///?Id=beckhoff-697d-490e-b719-bb5939f3f414)). |
| Direction  (available from V3.1.10.1) | Tc3\_Mc3Definitions.MC\_DIRECTION | Defines the direction of the movement (default mcDirectionNonModulo), see [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-418a-4b63-be81-71a6f23a1ae0). |
| Options | ST\_MoveAbsoluteCAOptions | For more information about the available options (from V3.1.2.47) see the documentation for [ST\_MoveAbsoluteCAOptions](ms-xhelp:///?Id=beckhoff-99e1-49c8-9293-0bfff325f298). |

|  |  |
| --- | --- |
| 10070188 | The axis does not reach the target velocity, acceleration or deceleration  The values for velocity, acceleration or deceleration may be automatically limited to the maximum axis velocity, acceleration and deceleration. Check the parameters Maximum Dynamics and Default Dynamics of the axis. It is also possible that the values of Maximum Dynamics are smaller than the Default Dynamics. |

## 23522831 10378893 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis                  : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Axis | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 26301173 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done                  : BOOL;  
    Busy                  : BOOL;  
    Active                : BOOL;  
    CommandAborted        : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time one of the outputs, `Done`, `CommandAborted` or `Error` is set. |
| Active | BOOL | If `Active` is `TRUE`, the function block controls the axis. |
| CommandAborted | BOOL | This output becomes `TRUE` if the command was interrupted by another command. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the ADS error documentation or in the NC error documentation (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
