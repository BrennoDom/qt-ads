# Int64Sub64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Int64Sub64

![64363694](/tcplclib_tc2_utilities/1033/Images/gif/36015883__en-US__Web.gif)

The function subtracts two TwinCAT 2 signed 64-bit numbers (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)). The result is a signed 64-bit number.

## FUNCTION Int64Sub64: T\_LARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    i64a : T_LARGE_INTEGER;  
    i64b : T_LARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
