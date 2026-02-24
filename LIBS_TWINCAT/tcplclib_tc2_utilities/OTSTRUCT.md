# OTSTRUCT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# OTSTRUCT

Time format for an operating hours counter.

```
TYPE OTSTRUCT :  
STRUCT  
    wWeek         : WORD;  
    wDay          : WORD;  
    wHour         : WORD;  
    wMinute       : WORD;  
    wSecond       : WORD;  
    wMilliseconds : WORD;  
END_STRUCT  
END_TYPE
```

**wWeek**: Number of weeks: 0 ~ 65535;

**wDay**: Number of days: 0 ~ 7;

**wHour**: Number of hours: 0 ~ 23;

**wMinute**: Number of minutes: 0 ~ 59;

**wSecond**: Number of seconds: 0 ~ 59;

**wMilliseconds**: Number of milliseconds: 0 ~ 999;

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
