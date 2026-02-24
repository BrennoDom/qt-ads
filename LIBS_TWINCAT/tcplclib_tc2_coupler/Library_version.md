# Library version

## Library
tcplclib_tc2_coupler

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
2. [Global Constants](ms-xhelp:///?Id=beckhoff-8e46-4755-b8fe-904853202864)
3. Library version

# Library version

All libraries have a specific version. This version is shown in the PLC library repository too.  
A global constant contains the library version information:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_Coupler    : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_Coupler** : version information of the Tc2\_Coupler library (type: ST\_LibVersion).

To compare the existing version to a required version the function F\_CmpLibVersion (defined in Tc2\_System library) is offered.

|  |  |
| --- | --- |
| 14848410 | All other possibilities known from TwinCAT2 libraries to query a library version are obsolete! |

[TwinCAT 3 | PLC Library: Tc2\_Coupler](ms-xhelp:///?Id=beckhoff-c77d-4fd1-84ef-dd6cbc3c5ab5)
