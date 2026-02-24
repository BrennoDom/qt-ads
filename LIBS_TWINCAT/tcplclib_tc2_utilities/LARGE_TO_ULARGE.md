# LARGE_TO_ULARGE

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# LARGE\_TO\_ULARGE

![12037401](/tcplclib_tc2_utilities/1033/Images/gif/36044683__en-US__Web.gif)

The function converts a TwinCAT 2 signed 64-bit number (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)) into a TwinCAT 2 unsigned 64-bit number (“native” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## FUNCTION LARGE\_TO\_ULARGE: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    in : T_LARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
