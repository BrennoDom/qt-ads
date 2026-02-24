# TIMESTRUCT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# TIMESTRUCT

Time in system time format.

```
TYPE TIMESTRUCT  
STRUCT  
   wYear         : WORD;  
   wMonth        : WORD;  
   wDayOfWeek    : WORD;  
   wDay          : WORD;  
   wHour         : WORD;  
   wMinute       : WORD;  
   wSecond       : WORD;  
   wMilliseconds : WORD;  
END_STRUCT  
END_TYPE
```

**wYear**: The year: 1970 ~ 2106;

**wMonth**: The month: 1 ~ 12 (January = 1, February = 2 etc.);

**wDayOfWeek**: The day of the week: 0 ~ 6 (Sunday = 0, Monday = 1 etc.);

**wDay**: The day of the month: 1 ~ 31;

**wHour**: Hour: 0 ~ 23;

**wMinute**: Minute: 0 ~ 59;

**wSecond**: Second: 0 ~ 59;

**wMilliseconds**: Millisecond: 0 ~ 999;

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
