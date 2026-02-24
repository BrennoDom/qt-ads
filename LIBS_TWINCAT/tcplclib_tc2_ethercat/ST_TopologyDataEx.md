# ST_TopologyDataEx

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_TopologyDataEx

# ST\_TopologyDataEx

The structure `ST_TopologyDataEx` contains information on EtherCAT topology and hot-connect groups.

```
TYPE ST_TopologyDataEx:  
STRUCT  
   nOwnPhysicalAddr  :  UINT;  
   nOwnAutoIncAddr   :  UINT;  
   stPhysicalAddr    :  ST_PortAddr;  
   stAutoIncAddr     :  ST_PortAddr;  
   aReserved1        :  ARRAY [0..3] OF UDINT;  
   nStatusBits       :  DWORD;  
   nHCSlaveCountCfg  :  UINT; (*nStatusBits.0 = TRUE: DcSupprt;.1 = TRUE: DC64Supprt; .2=TRUE: SlavePresent following hot connect info requires runtime >= TC 2.11 R3 B2246 nStatusBits.3 = TRUE: HotConnectGroupStart; .4 = HotConnectSlave; .5 = TRUE: HotCOnnectInvalidB; .6 = TRUE: HotConnectInvalidC; .7 = TRUE: HotConnectInvalidD*)  
   nHCSlaveCountAct  :  UINT;  
   aReserved2        :  ARRAY [0..4] OF UDINT;  
END_STRUCT  
END_TYPE
```

**nOwnPhysicalAddr**: Dedicated physical EtherCAT address of the EtherCAT slave device

**nOwnAutoIncAddr**: Dedicated auto-increment EtherCAT address of the EtherCAT slave device

**stPhysicalAddr**: Physical address information of the EtherCAT slave devices at port A…D

**stAutoIncAddr**: Auto-increment address information of the EtherCAT slave devices at port A…D

**aReserved1**: reserved

**nStatusBits**:   
nStatusBits.0 = TRUE: Distributed clocks are supported  
nStatusBits.1 = TRUE: Distributed clocks are supported (64 bit)  
nStatusBits.2 = TRUE: Slave is present  
nStatusBits.3 = TRUE: Slave is start node of a Hot Connect group  
nStatusBits.4 = TRUE: Slave is in a Hot Connect group  
nStatusBits.5 = TRUE: Hot-connect is invalid at port B  
nStatusBits.6 = TRUE: Hot-connect is invalid at port C  
nStatusBits.7 = TRUE: Hot-connect is invalid at port D

**nHCSlaveCountCfg**: Configured number of hot-connect group devices

**nHCSlaveCountAct**: Found number of hot-connect group devices

**aReserved2**: reserved

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
