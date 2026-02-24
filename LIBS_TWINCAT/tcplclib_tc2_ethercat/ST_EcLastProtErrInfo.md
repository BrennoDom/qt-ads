# ST_EcLastProtErrInfo

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcLastProtErrInfo

# ST\_EcLastProtErrInfo

The structure ST\_EcLastProtErrInfo contains additional error information relating to the most recent EtherCAT mailbox protocol error.

```
TYPE ST_EcSlaveState:  
STRUCT  
    ownAddr : ST_AmsAddr;   
    orgAddr : ST_AmsAddr;  
    errCode : UDINT;          
    binDesc : ARRAY[0..MAX_STRING_LENGTH] OF BYTE;  
END_STRUCT  
END_TYPE
```

**ownAddr:** Own AMS address (address of the communication device that queries the error information).

**orgAddr:** AMS address of the error originator (address of communication device that has triggered or caused the protocol error).

**errCode**: [Mailbox protocol error number](ms-xhelp:///?Id=beckhoff-c2ec-46fa-9a45-053fe0607642) (SoE, CoE, FoE error code).

**binDesc**: Additional error information as binary data. The additional error information is device-specific and can include a string or binary data, for example.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
