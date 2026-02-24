# MC_GroupEnable

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GroupEnable

![26059286](/tf5410_tc3_collision_avoidance/1033/Images/png/1427882635__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 33206990 | 30427456 | 5411655 |

This function block enables the group. If it is successful and all axes are ready, the group is then in the GroupStandby state (see [State diagrams](ms-xhelp:///?Id=beckhoff-2851-4318-9268-42575faccf68)).

|  |  |
| --- | --- |
| 48704899 | An **MC group** can only be enabled once all axes have been added to the group. |

## 35690909 VAR\_INPUT

```
VAR_INPUT  
    Execute    : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |

## 52782726 5282487 VAR\_IN\_OUT

```
VAR_IN_OUT  
    AxesGroup  : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see[Cyclic group interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)) |

## 47542385 VAR\_OUTPUT

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
