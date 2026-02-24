# GuidsEqualByVal

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# GuidsEqualByVal

![33223577](/tcplclib_tc2_utilities/1033/Images/png/9007200188542219__Web.png)

This function compares two GUID values.

## FUNCTION GuidsEqualByVal: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    guidA : GUID;  
    guidB : GUID;  
END_VAR
```

| Return value | Meaning |
| --- | --- |
| FALSE | guidA <> guidB |
| TRUE | guidA = guidB |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
