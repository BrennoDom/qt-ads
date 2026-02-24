# UINT64_TO_LREAL

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UINT64\_TO\_LREAL

![38953736](/tcplclib_tc2_utilities/1033/Images/gif/35999883__en-US__Web.gif)

The function converts a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)) into a floating-point number of type LREAL.

## FUNCTION UINT64\_TO\_LREAL: LREAL

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
