# Int64Cmp64

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Int64Cmp64

![14197042](/tcplclib_tc2_utilities/1033/Images/gif/36022283__en-US__Web.gif)

The function compares two TwinCAT 2 signed 64-bit numbers (“legacy” type: [T\_LARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-3d0c-4b6a-95f9-eef4d2da39b1)).

## FUNCTION Int64Cmp64: DINT

## VAR\_INPUT

```
VAR_INPUT  
    i64a : T_LARGE_INTEGER;  
    i64b : T_LARGE_INTEGER;  
END_VAR
```

| Return parameter | Description |
| --- | --- |
| -1 | i64a less than *i64b* |
| 0 | i64a identical to *i64b* |
| 1 | i64a greater than *i64b* |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
