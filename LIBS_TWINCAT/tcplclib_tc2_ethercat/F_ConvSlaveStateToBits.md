# F_ConvSlaveStateToBits

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvSlaveStateToBits

# F\_ConvSlaveStateToBits

![63570006](/tcplclib_tc2_ethercat/1033/Images/png/57297419__Web.png)

The function `F_ConvSlaveStateToBits` returns the EtherCAT slave state as structure [TYPE ST\_EcSlaveStateBits](ms-xhelp:///?Id=beckhoff-8c6e-402f-87fd-874e2ab7d0b6).

## VAR\_INPUT

```
VAR_INPUT  
    stEcSlaveState : ST_EcSlaveState;  
END_VAR
```

**stEcSlaveState**: EtherCAT slave state structure (consisting of: deviceState : BYTE; linkState : BYTE;)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
