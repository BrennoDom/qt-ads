# FB_SoEDriveEnable

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-02e8-422c-8be2-5398740f979f)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-5c40-4acf-ad08-589f472d41a7)
4. FB\_SoEDriveEnable

# FB\_SoEDriveEnable

FB\_SoEDriveEnable bEnable  BOOL↔stSoeDriveIoInterface  Reference To ST\_SoEDriveIoInterfaceBOOL  bStatusBOOL  bDriveError

The FB\_SoEDriveEnable function block enables a SoE drive in order to be able to subsequently supply it with setpoints using the function block [FB\_SoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-4850-4b6e-8ac5-f3d3df3419aa).

## 54423456 Inputs

```
VAR_INPUT  
    bEnable : BOOL;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **bEnable** | BOOL | Activates the SoE drive. |

## 20049059 / 46223811 Inputs/Outputs

```
VAR_IN_OUT  
    stSoeDriveIoInterface : ST_SoEDriveIoInterface;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| **stSoeDriveIoInterface** | ST\_SoEDriveIoInterface | Data structure to which the process image of the SoE drive must be linked. |

## 13361120 Outputs

```
VAR_OUTPUT  
    bStatus     : BOOL;  
    bDriveError : BOOL;  
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
