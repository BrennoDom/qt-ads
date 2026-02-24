# ST_EcCrcError

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. ST\_EcCrcError

# ST\_EcCrcError

Structure containing the CRC error counters of the individual ports (A, B and C) of an EtherCAT slave device.

```
TYPE ST_EcCrcError :  
STRUCT  
    portA : UDINT;  
    portB : UDINT;  
    portC : UDINT;  
END_STRUCT  
END_TYPE
```

**portA:** CRC error counter of Port A

**portB:** CRC error counter of Port B

**portC:** CRC error counter of Port C

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
