# ST_EcSlaveIdentity

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcSlaveIdentity

# ST\_EcSlaveIdentity

The structure `ST_EcSlaveIdentity` contains the EtherCAT identity data of an EtherCAT slave device.

```
TYPE ST_EcSlaveIdentity :  
STRUCT  
    vendorId    : UDINT;  
    productCode : UDINT;  
    revisionNo  : UDINT;  
    serialNo    : UDINT;  
END_STRUCT  
END_TYPE
```

**vendorId:** Vendor-ID of the slave device.

**productCode:** Product code of the slave device.

**revisionNo:** Indicates the revision number of the slave device.

**serialNo:** Indicates the serial number of the slave device.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
