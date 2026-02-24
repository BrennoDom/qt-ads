# ULARGE_TO_ULINT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ULARGE\_TO\_ULINT

![52522275](/tcplclib_tc2_utilities/1033/Images/png/9007200188744331__Web.png)

The function converts a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)) into a TwinCAT 3 unsigned 64-bit number (“native” type).

## FUNCTION ULARGE\_TO\_ULINT: ULINT

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
