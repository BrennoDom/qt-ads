# ST_EcMasterStatistic

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcMasterStatistic

# ST\_EcMasterStatistic

```
TYPE ST_EcMasterStatistic :  
STRUCT  
    nSysTime              : UDINT;  
    nCycFrameCnt          : UDINT;  
    nCycFrameMissedCnt    : UDINT;  
    nQueuedFrameCnt       : UDINT;  
    nQueuedFrameMissedCnt : UDINT;  
END_STRUCT  
END_TYPE
```

**nSysTime**: System time in µs

**nCycFrameCnt**: Number of cyclic EtherCAT frames

**nCycFrameMissedCnt**: Number of lost cyclic EtherCAT frames

**nQueuedFrameCnt**: Number of acyclic EtherCAT frames

**nQueuedFrameMissedCnt**: Number of lost acyclic EtherCAT frames

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
