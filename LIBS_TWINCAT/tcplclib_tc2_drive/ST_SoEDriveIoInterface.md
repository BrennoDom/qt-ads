# ST_SoEDriveIoInterface

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SimplePlcMotion](ms-xhelp:///?Id=beckhoff-d730-4dec-8474-8785da774c32)
4. ST\_SoEDriveIoInterface

# ST\_SoEDriveIoInterface

Data structure for mapping the process image of a SoE drive to use the function blocks [FB\_SoEDriveEnable](ms-xhelp:///?Id=beckhoff-a6d1-4fb1-b4e1-c33b7688077d) and [FB\_SoEDriveMoveVelocity](ms-xhelp:///?Id=beckhoff-4850-4b6e-8ac5-f3d3df3419aa).

```
TYPE ST_SoEDriveIoInterface :  
STRUCT  
    iMasterControlWord      : WORD;  
    iVelocityCommandValue   : DINT;   
    iDriveStatusWord        : WORD;  
    iVelocityFeedbackValue  : DINT;  
    iState                  : UINT;  
    stAdsAddr               : ST_AmsAddr;  
    iChannel                : BYTE;  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
