# FB_CoEDriveMoveVelocity

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-5c40-4acf-ad08-589f472d41a7)
4. FB\_CoEDriveMoveVelocity

# FB\_CoEDriveMoveVelocity

FB\_CoEDriveMoveVelocity bEnable  BOOLfVelocity  LREALfAcceleration1  LREALfAcceleration2  LREALfDeceleration1  LREALfDeceleration2  LREALbNegativeDirection  BOOLstOptions  ST\_DriveMoveVelocityOptions↔stCoEDriveIoInterface  Reference To ST\_CoEDriveIoInterfaceBOOL  bInVelocityBOOL  bBusyBOOL  bErrorUDINT  iErrorIDLREAL  fActualVelocity

The FB\_CoEDriveMoveVelocity function block generates a simple three-phase velocity profile (without jerk limitation) that can be used to supply a CoE drive directly. Different accelerations or decelerations can be used below and above a parameterizable velocity threshold. The target velocity can be changed during operation.

The CoE drive must first be enabled via the function block [FB\_CoEDriveEnable](ms-xhelp:///?Id=beckhoff-c6e6-4ad3-a27f-3e197cc0fc2f).

## 59231023 Inputs

```
VAR_INPUT  
    bEnable            : BOOL;  
    fVelocity          : LREAL;  
    fAcceleration1     : LREAL;  
    fAccelaration2     : LREAL;  
    fDeceleration1     : LREAL;  
    fDeceleration2     : LREAL;  
    bNegativeDirection : BOOL;  
    stOptions          : ST_DriveMoveVelocityOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bEnable** | BOOL | Activates the setpoint generation. |
| **fVelocity** | LREAL | Target velocity. fVelocity can be changed during operation. |
| **fAcceleration1** | LREAL | Acceleration 1 is used below the parameterized velocity threshold stOptions. fVelocityThreshold. |
| **fAcceleration2** | LREAL | Acceleration 2 is used above the parameterized velocity threshold stOptions. fVelocityThreshold. |
| **fDeceleration1** | LREAL | Deceleration 1 is used below the parameterized velocity threshold stOptions. fVelocityThreshold. |
| **fDeceleration2** | LREAL | Deceleration 2 is used above the parameterized velocity threshold stOptions. fVelocityThreshold. |
| **bNegativeDirection** | BOOL | bNegativeDirection reverses the direction of travel. |
| **stOptions** | ST\_DriveMoveVelocityOptions | Data structure with additional parameters. |

## 63317164 / 32983569 Inputs/Outputs

```
VAR_IN_OUT  
    stCoEDriveIoInterface : ST_CoeDriveIoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stCoEDriveIoInterface** | ST\_CoeDriveIoInterface | Process image of the CoE drive |

## 28416672 Outputs

```
VAR_OUTPUT  
    bInVelocity     : BOOL;  
    bBusy           : BOOL;  
    bError          : BOOL;  
    iErrorID        : UDINT;  
    fActualVelocity : LREAL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bInVelocity** | BOOL | Target velocity is reached. |
| **bBusy** | BOOL | bBusy is TRUE as long as the function block is active and a setpoint profile is being calculated. |
| **bError** | BOOL | bError becomes TRUE if an error occurs. |
| **iErrorID** | UDINT | Error number |
| **fActualVelocity** | LREAL | Currently reached velocity of the drive. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT 3.1.4024.22 | PC or CX (x86 or x64) | Tc2\_Drive |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
