# GuidsEqual

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. GuidsEqual

# GuidsEqual

![52161898](/tcplclib_tc3_module/1033/Images/png/1906685323__Web.png)

The function GuidsEqual checks two GUID objects for their equality to one another.

## Interface

**Parameter:**

```
VAR_INPUT  
    pGuidA : POINTER TO GUID;  
    pGuidB : POINTER TO GUID;  
END_VAR
```

**pGuidA**: Pointer to GUID object

**pGuidB**: Pointer to GUID object

**Return value:**

```
VAR_OUTPUT  
    GuidsEqual : BOOL;  
END_VAR
```

The method returns TRUE when both arguments are equal.

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
