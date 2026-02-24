# F_GetDayOfWeek

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_GetDayOfWeek

![59793748](/tcplclib_tc2_utilities/1033/Images/gif/35830283__en-US__Web.gif)

The function returns the number of the weekday according to DIN 1355 / ISO 8601. According to this standard the weekdays are numbered as follows: Monday = 1, Tuesday = 2, ... Sunday = 7.

## FUNCTION F\_GetDayOfWeek: WORD

## VAR\_INPUT

```
VAR_INPUT  
    in : DT;  
END_VAR
```

**in**: The date whose weekday number is to be determined.

**Example:**

```
PROGRAM MAIN  
VAR  
    dtFirst   : DT := DT#2008-01-01-00:00;  
    dayOfWeek : WORD;  
END_VAR
```

```
dayOfWeek := F_GetDayOfWeek(dtFirst);
```

The result is 2 (Tuesday)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
