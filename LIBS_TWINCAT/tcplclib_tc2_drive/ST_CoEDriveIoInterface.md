# ST_CoEDriveIoInterface

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-d730-4dec-8474-8785da774c32)
4. ST\_CoEDriveIoInterface

# ST\_CoEDriveIoInterface

Data structure for mapping the process image of a CoE drive to use the function blocks [FB\_CoEDriveEnable](ms-xhelp:///?Id=beckhoff-c6e6-4ad3-a27f-3e197cc0fc2f) and [FB\_CoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-e3ae-44bf-90c3-921f66b078e1).

```
TYPE ST_CoEDriveIoInterface :  
STRUCT  
    iControl      : UINT;  
    iStatus       : UINT;  
    iCmdVelo      : DINT;  
    iActVelo      : DINT;  
    stAdsAddr     : ST_AmsAddr;  
    iChannel      : BYTE;  
    eStateMachine : E_CoEDriveEnableState;  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
