# ST_EcSlaveConfigData

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcSlaveConfigData

# ST\_EcSlaveConfigData

The structure `ST_EcSlaveConfigData` contains the EtherCAT configuration data for an EtherCAT slave device.

```
TYPE ST_EcSlaveConfigData:  
STRUCT  
    nEntries        : WORD;  
    nAddr           : WORD;  
    sType           : STRING[15];  
    sName           : STRING[31];  
    nDevType        : DWORD;  
    stSlaveIdentity : ST_EcSlaveIdentity;  
    nMailboxOutSize : WORD;  
    nMailboxInSize  : WORD;  
    nLinkStatus     : BYTE;  
END_STRUCT  
END_TYPE
```

**nEntries:** used internally

**nAddr:** Address of an EtherCAT slave

**sType:** EtherCAT type of a slave

**sName:** Name of an EtherCAT slave

**nDevType:** EtherCAT device type of a slave

**stSlaveIdentity:** Identity of an EtherCAT slave (see [ST\_EcSlaveIdentity](ms-xhelp:///?Id=beckhoff-793a-4ef2-9893-e6e8ec2917af))

**nMailboxOutSize:** Mailbox OutSize of an EtherCAT slave.

**nMailboxInSize:** Mailbox InSize of an EtherCAT slave.

**nLinkStatus:** Link status of an EtherCAT slave.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
