# Library version

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Global constants](ms-xhelp:///?Id=beckhoff-2df3-4ec9-be65-4fa48e73e713)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_System : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_System** : Version number of the Tc2\_System library (type: ST\_LibVersion).

To check whether the version you have is the version you need, use the function [F\_CmpLibVersion](ms-xhelp:///?Id=beckhoff-3a79-45f1-b062-a28fb12c9064).

All other options for comparing library versions, which you may know from TwinCAT 2, are outdated.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
