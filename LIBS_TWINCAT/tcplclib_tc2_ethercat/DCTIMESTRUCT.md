# DCTIMESTRUCT

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Data types](ms-xhelp:///?Id=beckhoff-8349-4dc5-a3ac-4a7b90d92beb)
3. DCTIMESTRUCT

# DCTIMESTRUCT

Structured TwinCAT distributed clock system time format. The smallest unit is a nanosecond. This data type represents the **number of nanoseconds since 01.01.2000 (GMT)**.

```
TYPE DCTIMESTRUCT :  
STRUCT  
    wYear         : WORD;   
    wMonth        : WORD;  
    wDayOfWeek    : WORD;  
    wDay          : WORD;  
    wHour         : WORD;  
    wMinute       : WORD;  
    wSecond       : WORD;  
    wMilliseconds : WORD;  
    wMicroseconds : WORD;  
    wNanoseconds  : WORD;  
END_STRUCT  
END_TYPE
```

**wYear** : Year: 2000 ~ 2584;

**wMonth** : Month: 1 ~ 12 (January = 1, February = 2 etc.);

**wDayOfWeek** : Day of the week: 0 ~ 6 (Sunday = 0, Monday = 1 etc.);

**wDay** : The day of the month: 1 ~ 31;

**wHour** : Hour: 0 ~ 23;

**wMinute** : Minute: 0 ~ 59;

**wSecond** : Second: 0 ~ 59;

**wMilliseconds** : Millisecond: 0 ~ 999;

**wMicroseconds** : Microsecond: 0 ~ 999;

**wNanoseconds** : Nanosecond: 0 ~ 999;

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
