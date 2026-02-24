# ST_PortAddr

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_PortAddr

# ST\_PortAddr

The structure `ST_PortAddr` contains EtherCAT topology information for EtherCAT slave device. EtherCAT slave devices typically have 2 to 4 ports.

```
TYPE ST_PortAddr:  
STRUCT  
    portA :UINT;  
    portB :UINT;  
    portC :UINT;  
    portD :UINT;  
END_STRUCT  
END_TYPE
```

**portA:** Address of the previous EtherCAT slave at port A of the current EtherCAT slave

**portB:** Address of the optional subsequent EtherCAT slave at port B of the current EtherCAT slave

**portC:** Address of the optional subsequent EtherCAT slave at port C of the current EtherCAT slave

**portD:** Address of the optional subsequent EtherCAT slave at port D of the current EtherCAT slave

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
