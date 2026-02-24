# ST_IndraDriveCsDriveStatus

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [IndraDrive Cs](ms-xhelp:///?Id=beckhoff-aad7-4312-ad09-5757e62b4866)
4. ST\_IndraDriveCsDriveStatus

# ST\_IndraDriveCsDriveStatus

```
TYPE ST_IndraDriveCsDriveStatus :  
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
    eActOpMode              : E_IndraDriveCs_DriveOpMode;  
    iReserved               : UINT;  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
