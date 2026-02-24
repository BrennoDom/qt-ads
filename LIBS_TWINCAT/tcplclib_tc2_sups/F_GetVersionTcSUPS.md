# F_GetVersionTcSUPS

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Functions](ms-xhelp:///?Id=beckhoff-4f14-49c3-a80b-94ce47e6aec0)
3. [[Obsolete]](ms-xhelp:///?Id=beckhoff-92f0-4989-a14d-c4553511bc67)
4. F\_GetVersionTcSUPS

# F\_GetVersionTcSUPS

![19281542](/tcplclib_tc2_sups/1033/Images/gif/30523019__en-US__Web.gif)

This function is obsolete and should not be used. Please use the global constant [stLibVersion\_Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-dd65-4370-a99a-9edf6f49c8ee) to read the PLC library version information.

## FUNCTION F\_GetVersionTcSUPS: UINT

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

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86),  1-Second UPS | Tc2\_SUPS (Version: 3.3.3.0) |

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
