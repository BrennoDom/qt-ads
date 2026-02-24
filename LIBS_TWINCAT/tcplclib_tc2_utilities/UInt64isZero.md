# UInt64isZero

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64isZero

![65004788](/tcplclib_tc2_utilities/1033/Images/gif/35990283__en-US__Web.gif)

The function returns TRUE if the TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)) has the value zero.

## FUNCTION UInt64isZero: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    ui64 : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
