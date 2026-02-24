# UInt64Or

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Or

![66968808](/tcplclib_tc2_utilities/1033/Images/gif/35958283__en-US__Web.gif)

Bitwise OR of two TwinCAT 2 unsigned 64-bit numbers (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). The result is an unsigned 64-bit number.

## FUNCTION UInt64Or: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    ui64a : T_ULARGE_INTEGER;  
    ui64b : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
