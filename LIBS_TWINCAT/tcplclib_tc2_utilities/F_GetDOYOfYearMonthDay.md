# F_GetDOYOfYearMonthDay

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetDOYOfYearMonthDay

![1272826](/tcplclib_tc2_utilities/1033/Images/gif/35823883__en-US__Web.gif)

The function calculates the number of the day in the year.

## FUNCTION F\_GetDOYOfYearMonthDay: WORD

## VAR\_INPUT

```
VAR_INPUT  
    wYear  : WORD;  
    wMonth : WORD;  
    wDay   : WORD;  
END_VAR
```

**wYear**: Year (0 ~ 2999).

**wMonth**: Month (1 ~ 12).

**wDay** : Day (1 ~ 31 ).

| Return parameter | Description |
| --- | --- |
| 0 | Error, wrong wYear, wMonth or wDay parameter value |
| > 0 | No error. Number of the days in the year (1 ~ 366) |

**Example:**

```
PROGRAM P_TEST_DOY  
VAR  
    wYear  : WORD;  
    wDOY   : WORD;  
    wMonth : WORD;  
    wDay   : WORD;  
END_VAR
```

```
wYear := 2009;  
wMonth := 1;  
wDay := 31;  
wDOY := F_GetDOYOfYearMonthDay( wYear, wMonth, wDay );(* wDOY = 31 *)  
  
wYear := 2009;  
wMonth := 2;  
wDay := 1;  
wDOY := F_GetDOYOfYearMonthDay( wYear, wMonth, wDay );(* wDOY = 32 *)  
  
wYear := 2009;  
wMonth := 3;  
wDay := 1;  
wDOY := F_GetDOYOfYearMonthDay( wYear, wMonth, wDay );(* wDOY = 60 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
