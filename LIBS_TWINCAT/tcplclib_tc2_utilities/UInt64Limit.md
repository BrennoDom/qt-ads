# UInt64Limit

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Limit

![48172185](/tcplclib_tc2_utilities/1033/Images/gif/35974283__en-US__Web.gif)

Limitation. The result is a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## FUNCTION UInt64Limit: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    ui64min : T_ULARGE_INTEGER;  
    ui64in  : T_ULARGE_INTEGER;  
    ui64max : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
