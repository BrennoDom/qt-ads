# FB_EcExtSyncCheck64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64 and ULINT](ms-xhelp:///?Id=beckhoff-e560-4c02-a664-0d00df184ca7)
4. FB\_EcExtSyncCheck64

# FB\_EcExtSyncCheck64

![61151353](/tcplclib_tc2_ethercat/1033/Images/png/2285601931__Web.png)

The function block `FB_EcExtSyncCheck64` checks whether the internal and external clocks are synchronous. See function block [FB\_EcExtSyncCalcTimeDiff64](ms-xhelp:///?Id=beckhoff-3aa3-430c-91f1-0220c786310b).

## VAR\_INPUT

```
VAR_INPUT  
   nSyncWindow       : UDINT;  
   bNotConnected     : BOOL;  
END_VAR
```

**nSyncWindow:** Time window within which the internal and external clock are regarded as synchronous.

**bNotConnected:** TRUE = connection to external clock is interrupted.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
   DcToTcTimeOffset  : T_LARGE_INTEGER;  
   DcToExtTimeOffset : T_LARGE_INTEGER;  
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
   bSynchronized         : BOOL;  
   nTimeDiff             : UDINT;  
   nOffsetFromSyncMaster : DINT;  
END_VAR
```

**bSynchronized:** TRUE = external and internal clock are synchronous

**nTimeDiff**: Current time difference between the two clocks

**nOffsetFromSyncMaster**: Offset to sync master

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
