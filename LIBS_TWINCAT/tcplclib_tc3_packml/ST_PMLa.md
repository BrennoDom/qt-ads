# ST_PMLa

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. ST\_PMLa

# ST\_PMLa

This is the collection of all administration tags in the PackTag structure.

```
TYPE ST_PMLa :   
STRUCT  
    Alarm                     : ARRAY [1..iMAX_ALARMS] OF ST_Alarm;(* ~ (OPC : 1: enabled for OPC ) *)  
    ModeCurrentTime           : ARRAY [1..iMAX_CURRENT_MODE] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ModeCummulativeTime       : ARRAY [1..iMAX_CUMMULATIVE_MODE] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateCurrentTime          : ARRAY [1..iMAX_CURRENT_MODE, 0..iMAX_CURRENT_STATE] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateCummulativeTime      : ARRAY [1..iMAX_CURRENT_MODE, 0..iMAX_CURRENT_STATE] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    ProdProcessed             : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    DefectProd                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ReworkProd                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ResetTimersCounters       : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    UpstreamMessage           : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    DownstreamMessage         : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    CurrentDownstreamNodeID   : ARRAY [1..iMAX_CURR_NODE_IDS] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    CurrentUpstreamNodeID     : ARRAY [1..iMAX_CURR_NODE_IDS] OF DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
