# DT_TO_FILETIME64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DT\_TO\_FILETIME64

![39940984](/tcplclib_tc2_utilities/1033/Images/gif/35750283__en-US__Web.gif)

The function "DT\_TO\_FILETIME64" can be used to convert a PLC variable in DATE\_AND\_TIME format (DT) to FILETIME format (64 bit).

## FUNCTION DT\_TO\_FILETIME64 : [T\_FILETIME64](ms-xhelp:///?Id=beckhoff-4145-4760-bacf-86b973e5260d)

## VAR\_INPUT

```
VAR_INPUT  
    DTIN  : DT;  
END_VAR
```

**DTIN:** The date and time to be converted, in DATE\_AND\_TIME format.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.44.0 |
