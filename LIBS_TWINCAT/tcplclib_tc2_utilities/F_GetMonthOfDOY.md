# F_GetMonthOfDOY

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetMonthOfDOY

![35990092](/tcplclib_tc2_utilities/1033/Images/gif/35827083__en-US__Web.gif)

The function calculates the month based on the day number in the year.

## FUNCTION F\_GetMonthOfDOY: WORD

## VAR\_INPUT

```
VAR_INPUT  
    wYear  : WORD;  
    wDOY   : WORD;  
END_VAR
```

**wYear**: Year (0 ~ 2999).

**wDOY**: Number of the day in the specified year whose month is to be determined (1 ~ 366).

| Return parameter | Description |
| --- | --- |
| 0 | Error, wrong wYear or wDOY parameter value. |
| > 0 | No error. Month (1 ~ 12). |

**Example:**

```
PROGRAM P_TEST_DOY  
VAR  
    wYear  : WORD;  
    wDOY   : WORD;  
    wMonth : WORD;  
END_VAR
```

```
wYear   := 2009;  
wDOY    := 31;  
wMonth  := F_GetMonthOfDOY( wYear, wDOY );(* wMonth = 1 *)  
  
wYear   := 2009;  
wDOY    := 32;  
wMonth  := F_GetMonthOfDOY( wYear, wDOY );(* wMonth = 2 *)  
  
wYear   := 2009;  
wDOY    := 60;  
wMonth  := F_GetMonthOfDOY( wYear, wDOY );(* wMonth = 3 *)
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
