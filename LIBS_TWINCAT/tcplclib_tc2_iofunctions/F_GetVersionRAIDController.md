# F_GetVersionRAIDController

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Functions](ms-xhelp:///?Id=beckhoff-97b9-4c0a-9286-b660186aa381)
3. [[Obsolete]](ms-xhelp:///?Id=beckhoff-ac69-42f5-8b9b-51a928011c5c)
4. F\_GetVersionRAIDController

# F\_GetVersionRAIDController

This function is obsolete and should not be used. Please use the global constant [stLibVersion\_Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-2917-4128-b1d4-52d5fb6c0e5c) in order to read version information from the PLC library.

This function reads version information from the PLC library.

## FUNCTION F\_GetVersionRAIDController : UINT

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

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | All IO devices | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
