# F_ConvTcTimeToDcTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_ConvTcTimeToDcTime

# F\_ConvTcTimeToDcTime

![43072099](/tcplclib_tc2_ethercat/1033/Images/png/2285575179__Web.png)

|  |  |
| --- | --- |
| 52104579 | Outdated function  This function is outdated. Use the function [F\_ConvTcTimeToDcTime64](ms-xhelp:///?Id=beckhoff-da0f-4bd9-a106-7e67854839c7) instead. |

The function F\_ConvTcTimeToDcTime64 converts the TwinCAT system time to the TwinCAT distributed clock system time.

## FUNCTION F\_ConvTcTimeToDcTime: T\_DCTIME

```
VAR_INPUT  
   TcTime           : T_DCTIME;  
   DcToTcTimeOffset : T_LARGE_INTEGER;  
END_VAR
```

**TcTime:** TwinCAT system time in TwinCAT distributed clock system time format

**DcToTcTimeOffset**: Time offset between the TwinCAT distributed clock system time and the TwinCAT system time.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
