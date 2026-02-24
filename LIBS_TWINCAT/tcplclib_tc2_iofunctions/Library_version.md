# Library version

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Global constants](ms-xhelp:///?Id=beckhoff-a393-4921-afe7-6c1018464007)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_IoFunctions : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_IoFunctions**: Version number of the Tc2\_IoFunctions library (type: ST\_LibVersion).

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in Tc2\_System library).

|  |  |
| --- | --- |
| 23387474 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | All IO devices | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
