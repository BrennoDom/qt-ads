# F_ConvSlaveStateToString

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvSlaveStateToString

# F\_ConvSlaveStateToString

![44346036](/tcplclib_tc2_ethercat/1033/Images/png/57294219__Web.png)

The function `F_ConvSlaveStateToString` returns the EtherCAT slave state as string. For conversion to the string see [F\_ConvStateToString](ms-xhelp:///?Id=beckhoff-9f75-439b-bda5-34efd166bd66).

## VAR\_INPUT

```
VAR_INPUT  
    state : ST_EcSlaveState;  
END_VAR
```

**state**: EtherCAT slave state structure (consisting of: deviceState : BYTE; linkState : BYTE;)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
