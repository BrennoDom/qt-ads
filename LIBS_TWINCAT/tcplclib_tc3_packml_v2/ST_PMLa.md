# ST_PMLa

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. [Data types](ms-xhelp:///?Id=beckhoff-4be9-468e-8b2f-d15744b645c5)
4. ST\_PMLa

# ST\_PMLa

Collection of all Administration tags of the PackTag structure.

```
TYPE ST_PMLa :   
STRUCT  
    Parameter                 : ARRAY [1..MaxAdminParameters] OF ST_Descriptor;  
    Alarm                     : ARRAY [1..MaxAlarms] OF ST_Alarm;  
    AlarmExtent               : DINT := MaxAlarms;  
    AlarmHistory              : ARRAY [1..MaxHistoryAlarms] OF ST_Alarm;  
    AlarmHistoryExtent        : DINT := MaxHistoryAlarms;  
    StopReason                : ARRAY [1..MaxStopReasons] OF ST_Alarm;  
    StopReasonExtent          : DINT := MaxStopReasons;  
    Warning                   : ARRAY [1..MaxWarnings] OF ST_Alarm;  
    WarningExtent             : DINT := MaxWarnings;  
    ModeCurrentTime           : ARRAY [1..MaxUnitMode] OF DINT;  
    ModeCummulativeTime       : ARRAY [1..MaxUnitMode] OF DINT;  
    StateCurrentTime          : ARRAY [1..MaxUnitMode, 0..MaxMachineState] OF DINT;  
    StateCummulativeTime      : ARRAY [1..MaxUnitMode, 0..MaxMachineState] OF DINT;  
    ProdConsumedCount         : ARRAY [1..MaxConsumedCounts] OF ST_Count;  
    ProdProcessedCount        : ARRAY [1..MaxProductCounts] OF ST_Count;  
    ProdDefectiveCount        : ARRAY [1..MaxProductCounts] OF ST_Count;  
    AccTimeSinceReset         : DINT;  
    MachDesignSpeed           : REAL;  
    StatesDisabled            : DINT;  
    PlcDateTime               : ARRAY [0..6] OF DINT;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
