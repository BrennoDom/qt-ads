# F_GetDayOfMonthEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetDayOfMonthEx

![58839532](/tcplclib_tc2_utilities/1033/Images/gif/35836683__en-US__Web.gif)

The function calculates the date of the first, second etc. weekday in a particular month and year (e.g. the date of the second Monday in January 2011 ).

## FUNCTION F\_GetDayOfMonthEx: WORD

## VAR\_INPUT

```
VAR_INPUT  
    wYear  : WORD(1601..30827);  
    wMonth : WORD(1..12);  
    wWOM   : WORD(1..5);  
    wDOW   : WORD(0..6);  
END_VAR
```

**wYear**: year (1601 to 30827).

**wMonth**: month (1 to 12).

**wWOM**: week in month (1 of 5). The value 1 corresponds to week 1, 2 to week 2 and 5 to the last week (even if the month does not have 5 weeks).

**wDOW**: day of the week (0 to 6). 0 = Sunday, 1 = Monday... 6 = Saturday.

| Return parameter | Description |
| --- | --- |
| 0 | Error, wrong or invalid function parameter |
| > 0 | No error. Day of the month |

**Example**:

The example determines the date of the second Monday in August 2011. The result is: 8.

```
PROGRAM P_Dok_F_GetDayOfMonthEx  
VAR  
    wYear   : WORD := 2011;  
    wMonth  : WORD := 8;  
    wWOM    : WORD(1..5) := 2;(* Week of month: 2 = Second week *)  
    wDOW    : WORD(0..6) := 1;(* Day of week 1 = Monday *)  
    wDay    : WORD;(* Day of month *)  
END_VAR
```

```
wDay := F_GetDayOfMonthEx( wYear, wMonth, wWOM, wDOW );
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
