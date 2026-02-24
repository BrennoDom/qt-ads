# ST_AX5000_C1D for Class 1 diagnosis

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [AX5000 SoE](ms-xhelp:///?Id=beckhoff-b866-4606-bb24-fbdcfcba7424)
4. ST\_AX5000\_C1D for Class 1 diagnosis

# ST\_AX5000\_C1D for Class 1 diagnosis

```
TYPE ST_AX5000_C1D :  
STRUCT  
    bOverloadShutdown           : BOOL; (* C1D Bit 0 *)  
    bAmplifierOverTempShutdown  : BOOL; (* C1D Bit 1 *)  
    bMotorOverTempShutdown      : BOOL; (* C1D Bit 2 *)  
    bCoolingErrorShutdown       : BOOL; (* C1D Bit 3 *)  
    bControlVoltageError        : BOOL; (* C1D Bit 4 *)  
    bFeedbackError              : BOOL; (* C1D Bit 5 *)  
    bCommunicationError         : BOOL; (* C1D Bit 6 *)  
    bOverCurrentError           : BOOL; (* C1D Bit 7 *)  
    bOverVoltageError           : BOOL; (* C1D Bit 8 *)  
    bUnderVoltageError          : BOOL; (* C1D Bit 9 *)  
    bPowerSupplyPhaseError      : BOOL; (* C1D Bit 10 *)  
    bExcessivePosDiviationError : BOOL; (* C1D Bit 11 *)  
    bCommunicationErrorBit      : BOOL; (* C1D Bit 12 *)  
    bOvertravelLimitExceeeded   : BOOL; (* C1D Bit 13 *)  
    bReserved                   : BOOL; (* C1D Bit 14 *)  
    bManufacturerSpecificError  : BOOL; (* C1D Bit 15 *)  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
