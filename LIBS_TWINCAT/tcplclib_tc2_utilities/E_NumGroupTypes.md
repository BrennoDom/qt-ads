# E_NumGroupTypes

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_NumGroupTypes

Numeric number groups. This data type is used by the function block: [FB\_EnumStringNumbers](ms-xhelp:///?Id=beckhoff-8bbb-40cc-b879-0c64a2c3e37b), for example.

```
TYPE E_NumGroupTypes :  
(  
    eNumGroup_Float,  
    eNumGroup_Unsigned,  
    eNumGroup_Signed  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| eNumGroup\_Float | Floating-point numbers |
| eNumGroup\_Unsigned | Unsigned numbers |
| eNumGroup\_Signed | Signed numbers |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
