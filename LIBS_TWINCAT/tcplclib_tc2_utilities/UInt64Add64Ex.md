# UInt64Add64Ex

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Add64Ex

![10224153](/tcplclib_tc2_utilities/1033/Images/gif/35926283__en-US__Web.gif)

The function adds two TwinCAT 2 unsigned 64-bit numbers (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). The result is an unsigned 64-bit number.

## FUNCTION UInt64Add64Ex: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    augend : T_ULARGE_INTEGER;  
    addend : T_ULARGE_INTEGER;  
END_VAR
```

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    bOV    : BOOL;(* TRUE => arithmetic overflow, FALSE => no overflow *)  
END_VAR
```

**bOV**: Arithmetic overflow. TRUE => overflow, FALSE => no overflow.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
