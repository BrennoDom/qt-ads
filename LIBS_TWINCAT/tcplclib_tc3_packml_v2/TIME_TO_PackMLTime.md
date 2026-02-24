# TIME_TO_PackMLTime

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Function Blocks](ms-xhelp:///?Id=beckhoff-ee52-4b21-b081-24a6fe023487)
4. [Conversion](ms-xhelp:///?Id=beckhoff-019c-4609-b382-7fb0878775d1)
5. [Time](ms-xhelp:///?Id=beckhoff-04b0-495f-a07f-6375fa999883)
6. TIME\_TO\_PackMLTime

# TIME\_TO\_PackMLTime

![42277343](/tcplclib_tc3_packml_v2/1033/Images/png/6301461771__Web.png)

This function converts a time value in TIME format into the PackML-compliant array.

## FUNCTION TIME\_TO\_PackMLTime : ARRAY [0..6] OF DINT;

## VAR\_INPUT

```
VAR_INPUT  
    Input         : TIME;  
END_VAR
```

**Input**: The time value to be converted.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
