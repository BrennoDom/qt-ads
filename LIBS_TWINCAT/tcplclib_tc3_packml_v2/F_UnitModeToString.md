# F_UnitModeToString

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [Conversion](ms-xhelp:///?Id=beckhoff-019c-4609-b382-7fb0878775d1)
5. F\_UnitModeToString

# F\_UnitModeToString

![217030](/tcplclib_tc3_packml_v2/1033/Images/png/6302876811__Web.png)

This function returns the name of a Unit Mode as a string.

## FUNCTION F\_UnitModeToString : STRING;

## VAR\_INPUT

```
VAR_INPUT  
    eMode              : DINT;  
END_VAR
```

**eMode**: The Unit Mode for which the name is to be determined.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
