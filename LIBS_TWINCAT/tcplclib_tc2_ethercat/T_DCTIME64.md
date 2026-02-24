# T_DCTIME64

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. T\_DCTIME64

# T\_DCTIME64

64-bit TwinCAT distributed clock system time format. The smallest unit is a nanosecond.

```
TYPE T_DCTIME64 : ULINT;  
END_TYPE
```

| Useful distributed clock system time constants | Description |
| --- | --- |
| EC\_DCTIME\_DELTA\_OFFSET64 | Number of 100-nanosecond ticks between 01.01.1601 and 01.01.2000.  This is the difference between the Windows file time and the distributed clock system time. |
| EC\_DCTIME\_DATEDELTA\_OFFSET | Number of days that have passed between the year zero and 1 January 2000 |
| EC\_DCTIME\_TICKSPERMSEC64 | Number of distributed clock system time nanoseconds per millisecond |
| EC\_DCTIME\_TICKSPERSEC64 | Number of distributed clock system time nanoseconds per second |
| EC\_DCTIME\_TICKSPERDAY64 | Number of distributed clock system time nanoseconds per day |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
