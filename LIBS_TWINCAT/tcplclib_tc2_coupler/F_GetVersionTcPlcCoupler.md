# F_GetVersionTcPlcCoupler

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [[obsolete functions]](ms-xhelp:///?Id=beckhoff-8ce7-41aa-a96a-52675c52fa70)
3. F\_GetVersionTcPlcCoupler

# F\_GetVersionTcPlcCoupler

This function is obsolete and should not be used any longer. Use the global constant [stLibVersion\_Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-5cf0-4c66-bd86-259f2c15d56e) to read version information from the plc library.

![24019444](/tcplclib_tc2_coupler/1033/Images/gif/9007199297386507__Web.gif)

This function reads version information from the plc library.

## FUNCTION F\_GetVersionTcPlcCoupler : UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement** : Version element, that is to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

## Requirements

| Development environment | Target system type | PLC libraries to include (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Coupler (IO) |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
