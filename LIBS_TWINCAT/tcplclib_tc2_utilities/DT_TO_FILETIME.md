# DT_TO_FILETIME

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# DT\_TO\_FILETIME

![54915211](/tcplclib_tc2_utilities/1033/Images/gif/35750283__en-US__Web.gif)

The function "DT\_TO\_FILETIME" can be used to convert a PLC variable in DATE\_AND\_TIME format (DT) to FILETIME format (64 bit).

## FUNCTION DT\_TO\_FILETIME: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)

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
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
