# F_CheckVendorId

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. F\_CheckVendorId

# F\_CheckVendorId

![44915976](/tcplclib_tc2_ethercat/1033/Images/png/57326219__Web.png)

The function `F_CheckVendorId` returns TRUE, if the VendorID is Beckhoff, otherwise FALSE.

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
