# FB_EcExtSyncCalcTimeDiff

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. FB\_EcExtSyncCalcTimeDiff

# FB\_EcExtSyncCalcTimeDiff

![6606172](/tcplclib_tc2_ethercat/1033/Images/png/2285570059__Web.png)

|  |  |
| --- | --- |
| 59455556 | Outdated function block  This function block is outdated. Use the function block [FB\_EcExtSyncCalcTimeDiff64](ms-xhelp:///?Id=beckhoff-3aa3-430c-91f1-0220c786310b) instead. |

The function block `FB_EcExtSyncCalcTimeDiff` calculates the difference between external and internal time, taking into account the time offsets.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   DcToTcTimeOffset  : T_LARGE_INTEGER;  
   DcToExtTimeOffset : T_LARGE_INTEGER;  
   ExtTime           : T_DCTIME;  
   IntTime           : T_DCTIME;  
END_VAR
```

**DcToTcTimeOffset**: Time offset between the TwinCAT distributed clock system time and the TwinCAT system time

**DcToExtTimeOffset**: Time offset between the TwinCAT distributed clock system time and an external time

**ExtTime**: External time in TwinCAT distributed clock system time format

**IntTime**: Internal time in TwinCAT distributed clock system time format

## VAR\_OUTPUT

```
VAR_OUTPUT  
   nTimeDiff             :  UDINT; (*with difference greater than 32 bit timeDiff = 0xfffffff*)  
   nOffsetFromSyncMaster :  DINT; (*less than 32 bit int Offset = 0x80000000, greater than 32 bit int Offset = 0x7FFFFFFF*)  
END_VAR
```

**nTimeDiff**: If the difference is less than 32 bit, the time difference is returned. If the difference is greater than 32 bit, 16#FFFFFFFF is returned.

**nOffsetFromSyncMaster**: If the difference is greater than 32 bit and the offset between internal and DC time is less than 32 bit, 16#80000000 is returned.  
If the difference is greater than 32 bit and the offset between internal and DC time is greater than 32 bit, 16#7FFFFFFF is returned.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
