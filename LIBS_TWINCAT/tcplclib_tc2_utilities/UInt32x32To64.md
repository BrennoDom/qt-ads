# UInt32x32To64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt32x32To64

![11784733](/tcplclib_tc2_utilities/1033/Images/gif/35932683__en-US__Web.gif)

The function multiplies two unsigned 32-bit numbers. The result is a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## FUNCTION UInt32x32To64: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    ui32a : DWORD;  
    ui32b : DWORD;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
