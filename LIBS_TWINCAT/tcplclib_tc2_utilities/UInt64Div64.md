# UInt64Div64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Div64

![38913734](/tcplclib_tc2_utilities/1033/Images/gif/35942283__en-US__Web.gif)

The function divides two TwinCAT 2 unsigned 64-bit numbers (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). The result is an unsigned 64-bit number.

## FUNCTION UInt64Div64: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    dividend  : T_ULARGE_INTEGER;  
    divisor   : T_ULARGE_INTEGER;  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
