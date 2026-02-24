# F_ConvTcTimeToExtTime64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Distributed Clocks](ms-xhelp:///?Id=beckhoff-19d8-44e5-833e-bd9fc4eb27e8)
3. [DCTIME64 and ULINT](ms-xhelp:///?Id=beckhoff-e560-4c02-a664-0d00df184ca7)
4. F\_ConvTcTimeToExtTime64

# F\_ConvTcTimeToExtTime64

![66750478](/tcplclib_tc2_ethercat/1033/Images/png/2285594251__Web.png)

The function `F_ConvTcTimeToExtTime64` converts the TwinCAT distributed clock system time to an external time.

## FUNCTION F\_ConvTcTimeToExtTime64: T\_DCTIME64

```
VAR_INPUT  
   TcTime            : T_DCTIME64;  
   DcToTcTimeOffset  : ULINT;  
   DcToExtTimeOffset : ULINT;  
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
