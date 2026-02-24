# F_GetCurExtTime

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [[obsolete]](ms-xhelp:///?Id=beckhoff-f3bb-4110-b24d-c9129772b5f3)
4. [[outdated DCTIME and T\_LARGE\_INTEGER]](ms-xhelp:///?Id=beckhoff-d3df-4f17-b490-c93b45508d82)
5. F\_GetCurExtTime

# F\_GetCurExtTime

![23279683](/tcplclib_tc2_ethercat/1033/Images/png/2285089547__Web.png)

|  |  |
| --- | --- |
| 8190559 | Outdated function  This function is outdated. Use the function [F\_GetCurExtTime64](ms-xhelp:///?Id=beckhoff-c590-41bc-9a1e-82ecdb678ae8) instead. |

The function returns the external time in TwinCAT distributed clock system time format ([T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77)).

## FUNCTION F\_GetCurExtTime: T\_DCTIME

```
VAR_INPUT  
   DcToExtTimeOffset : T_LARGE_INTEGER;  
   DcToTcTimeOffset  : T_LARGE_INTEGER;  
END_VAR
```

**DcToExtTimeOffset**: Time offset between the TwinCAT distributed clock system time and an external time

**DcToTcTimeOffset**: Time offset between the TwinCAT distributed clock system time and the TwinCAT system time

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
