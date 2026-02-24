# MC_GroupReadStatus

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_GroupReadStatus

MC\_GroupReadStatus Enable  BOOL↔AxesGroup  Reference To AXES\_GROUP\_REFBOOL  ValidBOOL  BusyBOOL  GroupMovingBOOL  GroupHomingBOOL  GroupErrorStopBOOL  GroupNotReadyBOOL  GroupStandbyBOOL  GroupStoppingBOOL  GroupDisabledBOOL  AllAxesStandingBOOL  ConstantVelocityBOOL  AcceleratingBOOL  DeceleratingBOOL  InPositionBOOL  ErrorUDINT  ErrorId

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 55011311 | 25339754 | 26731201 |

This function block reads the state of an axis group (see State diagrams).

## 39254219 VAR\_INPUT

```
VAR_INPUT  
    Enable      : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enable | BOOL | The command is executed as long as Enable is active. |

## 17743659 25475209 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 27950294 VAR\_OUTPUT

```
VAR_OUTPUT  
    Valid                 : BOOL;  
    Busy                  : BOOL;  
    GroupMoving           : BOOL;  
    GroupHoming           : BOOL;  
    GroupErrorStop        : BOOL;  
    GroupNotReady         : BOOL;  
    GroupStandby          : BOOL;  
    GroupStopping         : BOOL;  
    GroupDisabled         : BOOL;  
    AllAxesStanding       : BOOL;  
    ConstantVelocity      : BOOL;  
    Accelerating          : BOOL;  
    Decelerating          : BOOL;  
    InPosition            : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Valid | Bool | This output indicates that other output values are valid for this function block. |
| Busy | Bool | This output becomes TRUE when the command is started with Enable and remains so as long as the function block executes the command. |
| Error | Bool | This output becomes TRUE if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the[ADS error documentation](ms-xhelp:///?Id=beckhoff-07bc-42ba-bf39-8bb430e44b38)or in the [NC error documentation](ms-xhelp:///?Id=beckhoff-7f1e-487d-a5ed-713a7234d65b) (error codes 0x4nnn and 0x8nnn). |
| GroupMoving | Bool | The group is in the GroupMoving state (see State diagrams). |
| GroupHoming | Bool | The group is in the GroupHoming state (see State diagrams). |
| GroupErrorStop | Bool | The group is in the GroupErrorStop state (see State diagrams). |
| GroupNotReady | Bool | The group is in the GroupNotReady state (see State diagrams). |
| GroupStandby | Bool | The group is in the GroupStandby state (see State diagrams). |
| GroupStopping | Bool | The group is in the GroupStopping state (see State diagrams). |
| GroupDisabled | Bool | The group is in the GroupDisabled state (see State diagrams). |
| AllAxesStanding | Bool | None of the axes in the group move physically (velocity = 0 and acceleration = 0), regardless of whether a Motion Command exists or not. |
| ConstantVelocity | Bool | Not supported. |
| Accelerating | Bool | Not supported. |
| Decelerating | Bool | Not supported. |
| InPosition | Bool | Not supported. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
