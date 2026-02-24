# Int64IsZero

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Int64IsZero

![9109783](/tcplclib_tc2_utilities/1033/Images/gif/36031883__en-US__Web.gif)

The function returns TRUE if the TwinCAT 2 signed 64-bit number (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)) has the value zero.

## FUNCTION Int64isZero: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    i64 : T_LARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
