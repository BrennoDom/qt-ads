# UInt64Mul64Ex

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Mul64Ex

![43080504](/tcplclib_tc2_utilities/1033/Images/gif/35939083__en-US__Web.gif)

The function multiplies two TwinCAT 2 unsigned 64-bit numbers (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)). The result is an unsigned 64-bit number.

## FUNCTION UInt64Mul64Ex: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    multiplicand  : T_ULARGE_INTEGER;  
    multiplier    : T_ULARGE_INTEGER;  
END_VAR
```

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    bOV : BOOL;(* TRUE => Arithmetic overflow, FALSE => no overflow *)  
END_VAR
```

**bOV**: Arithmetic overflow. TRUE => overflow, FALSE => no overflow.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
