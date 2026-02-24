# F_ARGISZERO

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_ARGISZERO

![61744252](/tcplclib_tc2_utilities/1033/Images/gif/36140683__en-US__Web.gif)

This function returns TRUE if one of the T\_Arg member variables has the value zero or was not initialized.

## FUNCTION F\_ARGISZERO: BOOL

## VAR\_INPUT

```
VAR_INPUT  
    arg : T_Arg;  
END_VAR
```

**arg**: Variable to be checked (type : [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
