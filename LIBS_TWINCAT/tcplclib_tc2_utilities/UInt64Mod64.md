# UInt64Mod64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Mod64

![19587461](/tcplclib_tc2_utilities/1033/Images/gif/35948683__en-US__Web.gif)

Modulo division of a TwinCAT 2 unsigned 64-bit number by another number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). The result is an unsigned 64-bit number.

## FUNCTION UInt64Mod64: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    dividend : T_ULARGE_INTEGER;  
    divisor  : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
