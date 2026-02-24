# T_DCTIME

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. T\_DCTIME

# T\_DCTIME

|  |  |
| --- | --- |
| 3094327 | Outdated data type  This data type is outdated. Use the data type [T\_DCTIME64](ms-xhelp:///?Id=beckhoff-61c0-4c24-9dad-22f122397674) instead. |

The data type `T_DCTIME` represents the distributed clock system time (abbreviated as DC time) as a linear 64-bit integer value. The time is expressed in nanoseconds since 1.1.2000 UTC.  
The data type is represented as two 32-bit DWORD variables, so that it can easily be processed in the PLC. Operations (addition and subtraction of times) can be executed with ui64 functions from the Tc2\_Utilities library.

```
TYPE T_DCTIME : T_ULARGE_INTEGER;  
END_TYPE
```

| Useful distributed clock system time constants | Description |
| --- | --- |
| EC\_DCTIME\_DELTA\_OFFSET | Number of 100-nanosecond ticks between 01.01.1601 and 01.01.2000. This is the difference between the Windows file time and the distributed clock system time. |
| EC\_DCTIME\_DATEDELTA\_OFFSET | Number of days that have passed between the year zero and 1 January 2000 |
| EC\_DCTIME\_TICKSPERMSEC | Number of distributed clock system time nanoseconds per millisecond |
| EC\_DCTIME\_TICKSPERSEC | Number of distributed clock system time nanoseconds per second |
| EC\_DCTIME\_TICKSPERDAY | Number of distributed clock system time nanoseconds per day |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
