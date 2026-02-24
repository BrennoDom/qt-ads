# MC_ReadTrackPositions

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_ReadTrackPositions

![30639779](/tf5410_tc3_collision_avoidance/1033/Images/png/8989070859__Web.png)

This function block returns the current XTS track and XTS part target positions with the corresponding object IDs. The axis must be in a CA group for the function block to supply valid values. If no track is activated for the axis, the current absolute setpoints are returned with track/PartId = 0.

## 7322556 VAR\_INPUT

```
VAR_INPUT  
    Enable : BOOL;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Enable | BOOL | The command is executed as long as Enable is active. |

## 65903005 56256135 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis                  : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Axis | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 36543171 VAR\_OUTPUT

```
VAR_OUTPUT  
    Valid                 : BOOL;  
    Busy                  : BOOL;  
    TrackPosition         : LREAL;  
    TrackId               : OTCID;  
    PartPosition          : LREAL;  
    PartId                : OTCID;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Valid | BOOL | This output indicates that other output values are valid for this function block. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time one of the outputs, `Done`, `CommandAborted` or `Error` is set. |
| TrackPosition | LREAL | Position in the active track reference system. |
| TrackId | OTCID | Object ID of the active track reference system. |
| PartPosition | LREAL | Position on the current XTS part. |
| PartId | OTCID | Object ID of the current XTS part. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the ADS error documentation or in the NC error documentation (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
