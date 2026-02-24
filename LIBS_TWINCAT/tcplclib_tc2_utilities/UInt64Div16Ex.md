# UInt64Div16Ex

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Div16Ex

![4323748](/tcplclib_tc2_utilities/1033/Images/png/9007200188723339__Web.png)

The function divides a TwinCAT 2 unsigned 64-bit number (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)) by a 16-bit unsigned number. The result is an unsigned 64-bit number.

## FUNCTION UInt64Div16Ex: T\_ULARGE\_INTEGER

## VAR\_INPUT

```
VAR_INPUT  
    dividend : T_ULARGE_INTEGER;  
    divisor  : WORD;  
END_VAR
```

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    remainder : T_ULARGE_INTEGER;  
END_VAR
```

**remainder**: Residual.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
