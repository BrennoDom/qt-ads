# ST_PowerStepperStruct

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-a949-4038-af4c-900da2b41d28)
4. ST\_PowerStepperStruct

# ST\_PowerStepperStruct

```
TYPE ST_PowerStepperStruct :  
STRUCT  
    DestallDetectMode   : E_DestallDetectMode;  
    DestallMode         : E_DestallMode;  
    DestallEnable       : BOOL;  
    StatusMonEnable     : BOOL;  
    Retries             : INT;  
    Timeout             : TIME;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
