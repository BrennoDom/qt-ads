# Library version

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_Utilities : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_Utilities**: Version number of the Tc2\_Utilities library (type: ST\_LibVersion).

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in Tc2\_System library).

|  |  |
| --- | --- |
| 51058985 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated. |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
