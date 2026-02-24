# MC_HaltCA

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_HaltCA

![51954348](/tf5410_tc3_collision_avoidance/1033/Images/png/5537587979__Web.png)

This function block commands a single axis to stop with Collision Avoidance.

## 64935954 VAR\_INPUT

```
VAR_INPUT  
    Execute               : BOOL;  
    Deceleration          : MC_LREAL := MC_DEFAULT;  
    Jerk                  : MC_LREAL := MC_DEFAULT;  
    Gap                   : MC_LREAL := MC_DEFAULT;  
    Options               : ST_HaltCAOptions;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| Deceleration | MC\_LREAL | The deceleration is limited by the maximum axis deceleration. If no value is entered, the default axis deceleration is used. |
| Jerk | MC\_LREAL | If no value is entered, the default axis jerk is used. The jerk is not limited. |
| Gap | MC\_LREAL | This value determines the minimum gap to the predecessor for Collision Avoidance. If no value is entered, the default value of the group is used.  When using geo-compensation, special attention must be paid to the distance. Since the distance refers to the offset path when using geo-compensation, adjacent movers in the curves can collide if it is set too low. |
| Options | ST\_HaltCAOptions | For more information about the available options (from V3.1.2.47) see the documentation for [ST\_HaltCAOptions](ms-xhelp:///?Id=beckhoff-d249-4cfc-b9d5-739c1715ec56). |

|  |  |
| --- | --- |
| 47552675 | The axis does not stop fast enough  The given deceleration could be automatically limited to the maximum axis deceleration. Check the parameters Maximum Dynamics and Default Dynamics of the axis. It is also possible that the values of Maximum Dynamics are below the Default Dynamics. |

## 25320898 26561495 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis                  : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Axis | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 37726867 VAR\_OUTPUT

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
| Done | BOOL | This output becomes TRUE when the command was successfully executed. |
| Busy | BOOL | This output becomes TRUE when the command is started with Execute and remains so as long as the function block executes the command. If Busy becomes FALSE again, the function block is ready for a new command. At the same time one of the outputs, Done, CommandAborted or Error is set. |
| Active | BOOL | If Active is TRUE, the function block controls the axis. |
| CommandAborted | BOOL | This output becomes TRUE if the command was interrupted by another command. |
| Error | BOOL | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the ADS error documentation or in the NC error documentation (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
