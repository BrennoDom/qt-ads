# ST_EcSlaveStateBitsEx

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcSlaveStateBitsEx

# ST\_EcSlaveStateBitsEx

The structure `ST_EcSlaveStateBitsEx` contains the EtherCAT status and the link status of an EtherCAT slave device.

```
TYPE ST_EcSlaveStateBitsEx:  
STRUCT  
    bInit      : BOOL;  
    bPreop     : BOOL;  
    bBootStrap : BOOL;  
    bSafeOp       : BOOL;  
    bOp           : BOOL;  
    bError        : BOOL;  
    bInvVPRS      : BOOL;  
    bInitCmdError : BOOL;  
    bDisabled     : BOOL;  
    bLinkNotPresent  : BOOL;  
    bLinkWithoutComm : BOOL;  
    bLinkMissing     : BOOL;  
    bAdditionalLink  : BOOL;  
    bPortA : BOOL;  
    bPortB : BOOL;  
    bPortC : BOOL;  
    bPortD : BOOL;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
