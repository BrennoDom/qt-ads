# F_ConvExtTimeToDcTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_ConvExtTimeToDcTime

# F\_ConvExtTimeToDcTime

![32843429](/tcplclib_tc2_ethercat/1033/Images/png/2285591691__Web.png)

|  |  |
| --- | --- |
| 27155410 | Outdated function  This function is outdated. Use the function [F\_ConvExtTimeToDcTime64](ms-xhelp:///?Id=beckhoff-5b9c-4f22-9089-c382a399c27e) instead. |

The function `F_ConvExtTimeToDcTime` converts an external time to the TwinCAT distributed clock system time.

## FUNCTION F\_ConvExtTimeToDcTime: T\_DCTIME

```
VAR_INPUT  
   ExtTime           : T_DCTIME;  
   DcToExtTimeOffset : T_LARGE_INTEGER;  
END_VAR
```

**ExtTime:** External time in TwinCAT distributed clock system time format

**DcToExtTimeOffset**: Time offset between the TwinCAT distributed clock system time and an external time.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
