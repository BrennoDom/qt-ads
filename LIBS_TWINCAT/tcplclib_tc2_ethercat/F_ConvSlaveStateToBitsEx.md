# F_ConvSlaveStateToBitsEx

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvSlaveStateToBitsEx

# F\_ConvSlaveStateToBitsEx

![35259143](/tcplclib_tc2_ethercat/1033/Images/png/3260277643__Web.png)

The function `F_ConvSlaveStateToBitsEx` returns the EtherCAT slave state as structure[ST\_EcSlaveStateBitsEx](ms-xhelp:///?Id=beckhoff-949e-4307-9d69-ccf750c75409).

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
