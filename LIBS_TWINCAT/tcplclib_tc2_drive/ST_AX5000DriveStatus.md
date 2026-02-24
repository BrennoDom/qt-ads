# ST_AX5000DriveStatus

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-b866-4606-bb24-fbdcfcba7424)
4. ST\_AX5000DriveStatus

# ST\_AX5000DriveStatus

```
TYPE ST_AX5000DriveStatus :  
STRUCT  
    bStatusCmdValProcessing : BOOL;  
    bRealTimeStatusBit1     : BOOL;  
    bRealTimeStatusBit2     : BOOL;  
    bDrvShutdownBitC1D      : BOOL;  
    bChangeBitC2D           : BOOL;  
    bChangeBitC3D           : BOOL;  
    bNotReadyToPowerUp      : BOOL;  
    bReadyForPower          : BOOL;  
    bReadyForEnable         : BOOL;  
    bEnabled                : BOOL;  
    iActOpModeParNum        : UINT;  
    eActOpMode              : E_AX5000_DriveOpMode;  
    iReserved               : UINT;  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
