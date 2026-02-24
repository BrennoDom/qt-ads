# F_GetVersionTcEtherCAT

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [[Obsolete]](ms-xhelp:///?Id=beckhoff-3f6f-48eb-89c4-97726ad36093)
3. F\_GetVersionTcEtherCAT

# F\_GetVersionTcEtherCAT

![58033516](/tcplclib_tc2_ethercat/1033/Images/png/57329419__Web.png)

|  |  |
| --- | --- |
| 52539597 | Outdated function  This function is outdated. Use the global structure instance stLibVersion\_Tc2\_EtherCAT instead |

This function can be used to read PLC library version information.

## FUNCTION F\_GetVersionTcEtherCAT : UINT

```
VAR_INPUT  
    nVersionElement : INT;  
END_VAR
```

**nVersionElement** : Version element to be read. Possible parameters:

* 1 : major number;
* 2 : minor number;
* 3 : revision number;

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
