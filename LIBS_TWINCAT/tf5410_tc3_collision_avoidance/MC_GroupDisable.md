# MC_GroupDisable

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_GroupDisable

![32345284](/tf5410_tc3_collision_avoidance/1033/Images/png/1427880715__Web.png)

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 22672102 | 2722332 | 24500989 |

This function block disables the group. After successful execution, the group changes its state to GroupDisabled (see [State diagrams](ms-xhelp:///?Id=beckhoff-2851-4318-9268-42575faccf68)).

|  |  |
| --- | --- |
| Note | |
| Disabling a group in motion results in an immediate stop.  When axes stop suddenly, the permissible deceleration limits are likely to be exceeded. Depending on the drive hardware, this could lead to current peaks and runtime errors. Before executing MC\_GroupDisable, use [MC\_GroupHalt](ms-xhelp:///?Id=beckhoff-566e-4ff0-ad1a-6d96006303b6) or [MC\_GroupStop](ms-xhelp:///?Id=beckhoff-0c51-44ab-b6ec-0d02026e7a10) to avoid this situation. | |

## 19182316 VAR\_INPUT

```
VAR_INPUT  
    Execute  : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |

## 38423121 10263773 VAR\_IN\_OUT

```
VAR_IN_OUT  
   AxesGroup             : AXES_GROUP_REF;   
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AxesGroup | AXES\_GROUP\_REF | Reference to a group of axes (see [Cyclic group interface](ms-xhelp:///?Id=beckhoff-64fb-4654-848c-3c33fe50f412)). |

## 25265097 VAR\_OUTPUT

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
