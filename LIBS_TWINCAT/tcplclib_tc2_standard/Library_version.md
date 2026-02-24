# Library version

## Library
tcplclib_tc2_standard

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
2. [Global constants](ms-xhelp:///?Id=beckhoff-a28f-4934-abfd-539cb7903a55)
3. Library version

# Library version

All libraries have a specific version. This version is shown in the PLC library repository too.  
A global constant contains the library version information:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
     stLibVersion_Tc2_Standard : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_Standard**: version information of the Tc2\_standard library (type: ST\_LibVersion).

To compare the existing version to a required version use the function F\_CmpLibVersion.

|  |  |
| --- | --- |
| 30364973 | All other possibilities known from TwinCAT2 libraries to query a library version are obsolete! |

[TwinCAT 3 | PLC Library: Tc2\_Standard](ms-xhelp:///?Id=beckhoff-498a-4e2c-a861-2ffa4b1740a3)
