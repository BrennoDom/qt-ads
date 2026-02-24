# F_GetMaxMonthDays

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetMaxMonthDays

![11455439](/tcplclib_tc2_utilities/1033/Images/gif/35820683__en-US__Web.gif)

The function returns the maximum number of days of the month in a certain month and year.

## FUNCTION F\_GetMaxMonthDays: WORD

## VAR\_INPUT

```
VAR_INPUT  
    wYear  : WORD;  
    wMonth : WORD;  
END_VAR
```

**wYear**: Year.

**wMonth**: Month (1 to 12).

| Return parameter | Description |
| --- | --- |
| 0 | Error, wrong wMonth parameter value |
| > 0 | No error. Maximum number of days of the month. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
