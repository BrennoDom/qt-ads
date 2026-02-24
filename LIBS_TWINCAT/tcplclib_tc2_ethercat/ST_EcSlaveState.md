# ST_EcSlaveState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcSlaveState

# ST\_EcSlaveState

The structure `ST_EcSlaveState` contains the EtherCAT status and the link status of an EtherCAT slave device.

```
TYPE ST_EcSlaveState:  
STRUCT  
    deviceState :BYTE;  
    linkState   :BYTE;  
END_STRUCT  
END_TYPE
```

**deviceState:** EtherCAT status of a slave. The status can adopt one of the following values:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Init state |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Pre-operational state |
| EC\_DEVICE\_STATE\_BOOTSTRAP | 0x03 | Bootstrap state |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Safe-operational state |
| EC\_DEVICE\_STATE\_OP | 0x08 | Operational state |

In addition, the following bits can be set:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_ERROR | 0x10 | State machine error in the EtherCAT slave |
| EC\_DEVICE\_STATE\_INVALID\_VPRS | 0x20 | Invalid vendor ID, product code, revision number or serial number |
| EC\_DEVICE\_STATE\_INITCMD\_ERROR | 0x40 | Error during sending of initialization commands. |
| EC\_DEVICE\_STATE\_DISABLED | 0x80 | Slave is disabled |

**linkState:** Link status of an EtherCAT slave. The Link status can consist of an ORing of the following bits.

| Constant | Value | Description |
| --- | --- | --- |
| EC\_LINK\_STATE\_OK | 0x00 |  |
| EC\_LINK\_STATE\_NOT\_PRESENT | 0x01 | No EtherCAT communication with the EtherCAT slave |
| EC\_LINK\_STATE\_LINK\_WITHOUT\_COMM | 0x02 | Error at port X (specified through EC\_LINK\_STATE\_PORT\_A/B/C/D). The port has a link, but no communication is possible via this port. |
| EC\_LINK\_STATE\_MISSING\_LINK | 0x04 | Missing link at port X (specified through EC\_LINK\_STATE\_PORT\_A/B/C/D). |
| EC\_LINK\_STATE\_ADDITIONAL\_LINK | 0x08 | Additional link at port X (specified through EC\_LINK\_STATE\_PORT\_A/B/C/D). |
| EC\_LINK\_STATE\_PORT\_A | 0x10 | Port 0 |
| EC\_LINK\_STATE\_PORT\_B | 0x20 | Port 1 |
| EC\_LINK\_STATE\_PORT\_C | 0x40 | Port 2 |
| EC\_LINK\_STATE\_PORT\_D | 0x80 | Port 3 |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
