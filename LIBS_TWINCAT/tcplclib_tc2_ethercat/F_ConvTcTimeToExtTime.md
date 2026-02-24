# F_ConvTcTimeToExtTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_ConvTcTimeToExtTime

# F\_ConvTcTimeToExtTime

![66288034](/tcplclib_tc2_ethercat/1033/Images/png/2285572619__Web.png)

|  |  |
| --- | --- |
| 59721402 | Outdated function  This function is outdated. Use the function [F\_ConvTcTimeToExtTime64](ms-xhelp:///?Id=beckhoff-282d-4e62-b685-e2144f2e3205) instead. |

The function `F_ConcTcTimeToExtTime` converts the TwinCAT distributed clock system time to an external time.

## FUNCTION F\_ConvTcTimeToExtTime: T\_DCTIME

```
VAR_INPUT  
   TcTime            :  T_DCTIME;  
   DcToTcTimeOffset  :  T_LARGE_INTEGER;  
   DcToExtTimeOffset :  T_LARGE_INTEGER;  
END_VAR
```

**TcTime:** TwinCAT system time in distributed clock format

**DcToTcTimeOffset**: Time offset between the TwinCAT distributed clock system time and the TwinCAT system time

**DcToExtTimeOffset**: Time offset between the TwinCAT distributed clock system time and an external time

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
