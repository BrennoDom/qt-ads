# F_YearIsLeapYear

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_YearIsLeapYear

![64320678](/tcplclib_tc2_utilities/1033/Images/gif/35859083__en-US__Web.gif)

The function determines whether a year is a leap year.

## FUNCTION F\_YearIsLeapYear: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    wYear : WORD;  
END_VAR
```

**wYear**: Year.

| Return parameter | Description |
| --- | --- |
| TRUE | Changeover year |
| FALSE | No leap year |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
