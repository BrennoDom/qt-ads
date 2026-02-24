# MC_ActivateTrack

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_ActivateTrack

![60453091](/tf5410_tc3_collision_avoidance/1033/Images/png/8991609355__Web.png)

This function block activates a track as a reference system, which can then be used in various motion function blocks for positioning. The XTS track object must be created under the XTS Processing Unit and is then selected via the Object Id. The XTS tracks are configured via the XTS Configurator (see [XTS documentation](https://infosys.beckhoff.com/index.php?content=../content/1031/xts_software/index.html&id=325510458286519059) for more information). ObjectID 0 can be used to reactivate the absolute reference system.

## 7206911 VAR\_INPUT

```
VAR_INPUT  
    Execute   : BOOL;  
    TrackId   : OTCID;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Execute | BOOL | The command is triggered by a rising edge at this input. |
| TrackId | OTCID | Object ID of the active track reference system. |

## 64862199 46888886 VAR\_IN\_OUT

```
VAR_IN_OUT  
    Axis                  : AXIS_REF;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Axis | AXIS\_REF | Reference to an axis (see [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)). |

## 19346796 VAR\_OUTPUT

```
VAR_OUTPUT  
    Done                  : BOOL;  
    Busy                  : BOOL;  
    Error                 : BOOL;  
    ErrorId               : UDINT;  
END_VAR
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Done | BOOL | This output becomes `TRUE` when the command was successfully executed. |
| Busy | BOOL | This output becomes `TRUE` when the command is started with `Execute` and remains so as long as the function block executes the command. If `Busy` becomes `FALSE` again, the function block is ready for a new command. At the same time one of the outputs, `Done`, `CommandAborted` or `Error` is set. |
| Error | BOOL | This output becomes `TRUE` if an error has occurred during command execution. |
| ErrorId | UDINT | Contains the command-specific error code of the last executed command. Details of the error code can be found in the ADS error documentation or in the NC error documentation (error codes 0x4nnn and 0x8nnn). |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
