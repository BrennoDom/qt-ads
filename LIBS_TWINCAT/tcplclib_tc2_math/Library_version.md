# Library version

## Library
tcplclib_tc2_math

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
2. [Global constants](ms-xhelp:///?Id=beckhoff-1900-4278-87df-72ada0f5531b)
3. Library version

# Library version

All libraries have a specific version. This version is shown in the PLC library repository too.  
A global constant contains the library version information:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_Math : ST_LibVersion;  
END_VAR
```

stLibVersion\_Tc2\_Math: Version number of the Tc2\_Math library (type: ST\_LibVersion).

To compare the existing version to a required version the function F\_CmpLibVersion (defined in Tc2\_System) is offered.

|  |  |
| --- | --- |
| 5486348 | All other possibilities known from TwinCAT2 libraries to query a library version are obsolete! |

[TwinCAT 3 | PLC Library:Tc2\_Math](ms-xhelp:///?Id=beckhoff-c1bf-4c0b-92f1-a78a2d79cc10)
