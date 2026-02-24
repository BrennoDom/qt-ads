# FB_CoEDriveEnable

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-5c40-4acf-ad08-589f472d41a7)
4. FB\_CoEDriveEnable

# FB\_CoEDriveEnable

FB\_CoEDriveEnable bEnable  BOOLbReset  BOOL↔stCoeDriveIoInterface  Reference To ST\_CoEDriveIoInterfaceBOOL  bStatusBOOL  bDriveError

The FB\_CoEDriveEnable function block enables a CoE drive in order to be able to subsequently supply it with setpoints using the function block [FB\_CoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-e3ae-44bf-90c3-921f66b078e1).

## 7025744 Inputs

```
VAR_INPUT  
    bEnable : BOOL;  
    bReset  : BOOL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bEnable** | BOOL | Activates the CoE drive. |
| **bReset** | BOOL | Performs a drive reset in the event of a fault. "Bit 7" is set in the drive control word. |

## 63231703 / 32214417 Inputs/Outputs

```
VAR_IN_OUT  
    stCoeDriveIoInterface : ST_CoeDriveIoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stCoeDriveIoInterface** | ST\_CoeDriveIoInterface | Data structure to which the process image of the CoE drive must be linked. |

## 21494305 Outputs

```
VAR_OUTPUT  
    bStatus     : BOOL;  
    bDriveError : BOOL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bStatus** | BOOL | If bStatus=TRUE, the drive is ready for operation and follows the setpoints. |
| **bDriveError** | BOOL | The drive is in the error state. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT 3.1.4024.22 | PC or CX (x86 or x64) | Tc2\_Drive |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
