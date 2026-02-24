# INT64_TO_LREAL

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# INT64\_TO\_LREAL

![47428342](/tcplclib_tc2_utilities/1033/Images/gif/36038283__en-US__Web.gif)

The function converts a TwinCAT 2 signed 64-bit number (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)) into a floating-point number of type LREAL.

## FUNCTION INT64\_TO\_LREAL: LREAL

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
