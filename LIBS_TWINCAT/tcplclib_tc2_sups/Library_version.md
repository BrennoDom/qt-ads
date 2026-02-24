# Library version

## Library
tcplclib_tc2_sups

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
2. [Global constants](ms-xhelp:///?Id=beckhoff-50f9-440d-ad28-51d0c510c973)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_SUPS : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_SUPS**: Version information of the Tc2\_SUPS library (type: ST\_LibVersion)

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in the Tc2\_System library).

|  |  |
| --- | --- |
| 39316155 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

[TwinCAT 3 | PLC Lib: Tc2\_SUPS](ms-xhelp:///?Id=beckhoff-26a2-4da1-bec6-c56c81740683)
