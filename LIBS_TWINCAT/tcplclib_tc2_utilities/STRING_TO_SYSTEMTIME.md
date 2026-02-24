# STRING_TO_SYSTEMTIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# STRING\_TO\_SYSTEMTIME

![27437792](/tcplclib_tc2_utilities/1033/Images/png/9007199290654475__Web.png)

The function converts a string into the Windows SYSTEMTIME format.

## FUNCTION STRING\_TO\_SYSTEMTIME: [TIMESTRUCT](ms-xhelp:///?Id=beckhoff-a743-45b8-ae0d-5212cada81b1)

## VAR\_INPUT

```
VAR_INPUT  
    in : STRING(23);  
END_VAR
```

**in**: The string to be converted. The string must have the following format: **'YYYY-MM-DD-hh:mm:ss.xxx'**

* YYYY: Year (1601..9999);
* MM: Month (01..12);
* DD: Day (01..31);
* hh: Hour (00..23);
* mm: Minute (00..59);
* ss: Second (00..59);
* xxx: Millisecond (000..999);

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
