# F_ARGCMP

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_ARGCMP

![26445914](/tcplclib_tc2_utilities/1033/Images/gif/36137483__en-US__Web.gif)

This function compares two variables of type T\_Arg and supplies the result of the comparison as return parameter.

## FUNCTION F\_ARGCMP: DINT

## VAR\_INPUT

```
VAR_INPUT  
    typeSafe  : BOOL;  
    arg1      : T_Arg;  
    arg2      : T_Arg;  
END_VAR
```

**typeSafe**: If TRUE => identical types can be compared (type-safe comparison). FALSE => different types can be compared (type-independent comparison).

**arg1**: First variable to be compared (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

**arg2**: Second variable to be compared (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

| Return parameter | Relationship of the first different byte (type, length, value) in the first and second variable |
| --- | --- |
| -3 | Length of *arg1* less than *arg2* |
| -2 | Type of *arg1* less than *arg2* |
| -1 | Value of *arg1* less than *arg2* |
| 0 | arg1 identical to *arg2* |
| 1 | Value of *arg1* greater than *arg2* |
| 2 | Type of *arg1* greater than *arg2* |
| 3 | Length of *arg1* greater than *arg2* |
| 0xFF | Wrong parameter values, type, length, value of *arg1 or arg2* = 0 |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
