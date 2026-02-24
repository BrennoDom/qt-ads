# F_ARGCPY

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_ARGCPY

![36686634](/tcplclib_tc2_utilities/1033/Images/gif/36134283__en-US__Web.gif)

This function copies the value of a variable of type T\_Arg into another variable and supplies the number of successfully copied data bytes as return parameter.

## FUNCTION F\_ARGCPY: UDINT

## VAR\_INPUT

```
VAR_INPUT  
    typeSafe : BOOL;  
END_VAR
```

**typeSafe**: If TRUE => identical types can be compared (type-safe comparison). FALSE => different types can be compared (type-independent comparison).

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    dest : T_Arg;  
    src  : T_Arg;  
END_VAR
```

**dest:** Target variable for the copy operation (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

**src:** Source variable for the copy operation (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

| Return parameter | Meaning |
| --- | --- |
| 0 | Incorrect parameter values. Type, length or value of *dest* or *src* == 0 |
| > 0 | If successful, the number of bytes copied. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
