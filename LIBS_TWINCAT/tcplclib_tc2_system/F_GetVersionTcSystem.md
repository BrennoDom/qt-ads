# F_GetVersionTcSystem

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [[Obsolete]](ms-xhelp:///?Id=beckhoff-e729-4de7-9481-4905b7f6ef80)
4. F\_GetVersionTcSystem

# F\_GetVersionTcSystem

This function is obsolete and should not be used. Please use the global constant [stLibVersion\_Tc2\_System](ms-xhelp:///?Id=beckhoff-dcb6-455b-8fec-cffd17f6c9a2) in order to read version information from the PLC library.

![26649649](/tcplclib_tc2_system/1033/Images/png/31423371__en-US__Web.png)

This function can be used to read PLC library version information.

## FUNCTION F\_GetVersionTcSystem : UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement**: Version element to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
