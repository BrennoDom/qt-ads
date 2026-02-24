# UINT64_TO_STRING

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UINT64\_TO\_STRING

![15039305](/tcplclib_tc2_utilities/1033/Images/gif/36003083__en-US__Web.gif)

The function converts a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)) into string.

## FUNCTION UINT64\_TO\_STRING: STRING(21)

## VAR\_INPUT

```
VAR_INPUT  
    in : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
