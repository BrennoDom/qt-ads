# PVOID_TO_ITCUKNOWN

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. PVOID\_TO\_ITCUKNOWN

# PVOID\_TO\_ITCUKNOWN

![28165387](/tcplclib_tc3_module/1033/Images/png/1899484043__Web.png)

This conversion function converts a pointer to VOID to an interface pointer of the type ITcUnknown.

## Interface

**Parameter**

```
VAR_INPUT  
   pVoid : PVOID;  
END_VAR
```

**Return value**

```
VAR_OUTPUT  
    PVOID_TO_ITCUKNOWN : ITcUknown;  
END_VAR
```

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
