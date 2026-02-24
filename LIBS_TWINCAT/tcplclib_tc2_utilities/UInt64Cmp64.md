# UInt64Cmp64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# UInt64Cmp64

![22850037](/tcplclib_tc2_utilities/1033/Images/gif/35951883__en-US__Web.gif)

The function compares two TwinCAT 2 unsigned 64-bit numbers (“legacy” type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

## FUNCTION UInt64Cmp64: DINT

## VAR\_INPUT

```
VAR_INPUT  
    ui64a : T_ULARGE_INTEGER;  
    ui64b : T_ULARGE_INTEGER;  
END_VAR
```

| Return parameter | Description |
| --- | --- |
| -1 | ui64a less than *ui64b* |
| 0 | ui64a identical to *ui64b* |
| 1 | ui64a greater than *ui64b* |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
