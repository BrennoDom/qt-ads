# FB_EcExtSyncCheck

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. FB\_EcExtSyncCheck

# FB\_EcExtSyncCheck

![65337958](/tcplclib_tc2_ethercat/1033/Images/png/2285567243__Web.png)

|  |  |
| --- | --- |
| 51170717 | Outdated function block  This function block is outdated. Use the function block [FB\_EcExtSyncCheck64](ms-xhelp:///?Id=beckhoff-ae9c-45b2-8762-9794a3308487) instead. |

The function block `FB_EcExtSyncCheck` checks whether the internal and external clocks are synchronous. See function block [FB\_EcExtSyncCalcTimeDiff](ms-xhelp:///?Id=beckhoff-642c-4315-ac1a-4d07f0697346).

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
