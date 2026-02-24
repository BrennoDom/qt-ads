# ST_EcSlaveScannedData

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcSlaveScannedData

# ST\_EcSlaveScannedData

The structure `ST_EcSlaveScannedData` contains the EtherCAT configuration data of a scanned EtherCAT slave device.

```
TYPE ST_EcSlaveConfigData:  
STRUCT  
    nEntries        : WORD;  
    nAddr           : WORD;  
    stSlaveIdentity : ST_EcSlaveIdentity;  
    ndlStatusReg    : WORD;  
END_STRUCT  
END_TYPE
```

**nEntries:** used internally

**nAddr:** Address of an EtherCAT slave

**stSlaveIdentity:** Identity of an EtherCAT slave (see [ST\_EcSlaveIdentity](ms-xhelp:///?Id=beckhoff-793a-4ef2-9893-e6e8ec2917af))

**ndlStatusReg:** Link status of an EtherCAT slave from ESC register 0110/0111hex or 272/273dec. Status 0 is displayed if the slave cannot be reached or is offline. The port number <=> socket/Ebus contact assignment can be found in the respective device documentation. Unless described otherwise, port 0 is the left-hand Ebus contact of an EL/ES terminal or the RJ45 socket of an EP box, port 1 is the right-hand outgoing Ebus contact/RJ45 socket.

The bit meanings are:

| Bit | Meaning |
| --- | --- |
| 1 | internal use |
| 2 | internal use |
| 3 | internal use |
| 4 | physical link on Port 0 0: no link, 1: Link detected |
| 5 | physical link on Port 1 0: no link, 1: Link detected |
| 6 | physical link on Port 2 0: no link, 1: Link detected |
| 7 | physical link on Port 3 0: no link, 1: Link detected |
| 8 | Loop Port 0 0: Open, 1: Closed |
| 9 | Communication on Port 0 0: no stable communication, 1: Communication established |
| 10 | Loop Port 1 0: Open, 1: Closed |
| 11 | Communication on Port 1 0: no stable communication, 1: Communication established |
| 12 | Loop Port 2 0: Open, 1: Closed |
| 13 | Communication on Port 2 0: no stable communication, 1: Communication established |
| 14 | Loop Port 3 0: Open, 1: Closed |
| 15 | Communication on Port 3 0: no stable communication, 1: Communication established |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
