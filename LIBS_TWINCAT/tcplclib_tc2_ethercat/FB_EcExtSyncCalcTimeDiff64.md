# FB_EcExtSyncCalcTimeDiff64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64 and ULINT](ms-xhelp:///?Id=beckhoff-e560-4c02-a664-0d00df184ca7)
4. FB\_EcExtSyncCalcTimeDiff64

# FB\_EcExtSyncCalcTimeDiff64

![44077297](/tcplclib_tc2_ethercat/1033/Images/png/2285617291__Web.png)

The function block `FB_EcExtSyncCalcTimeDiff64` calculates the difference between external and internal time, taking into account the time offsets.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   DcToTcTimeOffset  : ULINT;  
   DcToExtTimeOffset : ULINT;  
   ExtTime           : T_DCTIME64;  
   IntTime           : T_DCTIME64;  
END_VAR
```

**DcToTcTimeOffset**: Time offset between the TwinCAT distributed clock system time and the TwinCAT system time

**DcToExtTimeOffset**: Time offset between the TwinCAT distributed clock system time and an external time

**ExtTime**: External time in TwinCAT distributed clock system time format

**IntTime**: Internal time in TwinCAT distributed clock system time format

## VAR\_OUTPUT

```
VAR_OUTPUT  
   nTimeDiff             : UDINT; (*with difference greater than 32 bit timeDiff = 0xfffffff*)  
   nOffsetFromSyncMaster : DINT; (*less than 32 bit int Offset = 0x80000000, greater than 32 bit int Offset = 0x7FFFFFFF*)  
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
