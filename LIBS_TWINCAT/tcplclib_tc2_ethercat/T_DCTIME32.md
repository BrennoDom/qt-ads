# T_DCTIME32

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. T\_DCTIME32

# T\_DCTIME32

32-bit TwinCAT distributed clock system time format. The smallest unit is a nanosecond.

This 32-bit DC system time is formed from the full absolute 64-bit DC system time ([T\_DCTIME](ms-xhelp:///?Id=beckhoff-27de-43e4-9ec2-613239202c77)) by using only the lowest-order 32 bits. This means the property of an absolute unique time is lost, and it is assumed that this 32-bit time is only used within a narrow time window of ± 2,147 seconds around the current system time, to ensure that it is unambiguous. There are many applications in which this assumption is possible.  
If this assumption is violated, errors may occur in the interpretation and further processing of this time.

```
TYPE T_DCTIME32 : UDINT;  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
