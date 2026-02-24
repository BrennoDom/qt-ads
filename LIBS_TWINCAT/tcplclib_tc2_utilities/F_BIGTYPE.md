# F_BIGTYPE

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# F\_BIGTYPE

![18827362](/tcplclib_tc2_utilities/1033/Images/gif/36118283__en-US__Web.gif)

Help function that returns a structure with information (type: [T\_Arg](ms-xhelp:///?Id=beckhoff-9414-4e02-83ee-fc21ca340682)) on a Struct or Array variable.

## FUNCTION F\_BIGTYPE: T\_Arg

## VAR\_INPUT

```
VAR_INPUT  
    pData : POINTER TO BYTE;  
    cbLen : DWORD;  
END_VAR
```

**pData**: Address pointer (can be determined with the ADR operator).

**cbLen**: Number of bytes occupied in the memory (can be determined with the SIZEOF operator).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
