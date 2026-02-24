# F_ConvProductCodeToString

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Conversion Functions](ms-xhelp:///?Id=beckhoff-c72d-4c13-9be6-b8070ce06bef)
3. F\_ConvProductCodeToString

# F\_ConvProductCodeToString

![57123120](/tcplclib_tc2_ethercat/1033/Images/png/57291019__Web.png)

The function `F_ConvProductToString` returns the product code as string, e.g. 'EL6731-0000-0017'. From version 3.3.8.0 of the Tc2\_EtherCAT library this function also supports ELM and EPP slaves such as 'EPP4374-0002-0018' and 'ELM3704-0001-0016'.

## VAR\_INPUT

```
VAR_INPUT  
    stSlaveIdentity : ST_EcSlaveIdentity;  
END_VAR
```

**stSlaveIdentity**: Slave identity, which can be read with [FB\_EcGetSlaveIdentity](ms-xhelp:///?Id=beckhoff-b5e6-450b-824a-1b31f01ba2c4).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
