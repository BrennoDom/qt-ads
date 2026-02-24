# F_GetWeekOfTheYear

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetWeekOfTheYear

![55475379](/tcplclib_tc2_utilities/1033/Images/gif/35833483__en-US__Web.gif)

The function returns the calendar week number for a specified date according to the DIN 1355 / ISO 8601 standard.

* The first calendar week is defined as the first week that contains a **minimum of four days of the new year (DIN 1355 / ISO 8601)**;
* The calendar weeks start on a Monday. Each calendar week contains 7 days;
* The returned value in the first calendar week has the number 1;
* 29, 30 and 31 December may belong to the first calendar week of the following year;
* 1, 2 and 3 January may belong to the last calendar week of the previous year;

## FUNCTION F\_GetWeekOfTheYear: WORD

## VAR\_INPUT

```
VAR_INPUT  
    in : DT;  
END_VAR
```

**in**: The date whose calendar week is to be determined.

**Example:**

```
PROGRAM MAIN  
VAR  
    dtNow      : DT := DT#2008-03-17-12:00;  
    weekOfYear : WORD;  
END_VAR
```

```
weekOfYear := F_GetWeekOfTheYear(dtNow);
```

The result is 12.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
