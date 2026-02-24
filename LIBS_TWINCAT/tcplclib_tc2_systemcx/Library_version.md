# Library version

## Library
tcplclib_tc2_systemcx

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
2. [Global constants](ms-xhelp:///?Id=beckhoff-d1fe-41c7-9959-12b66bc98ebd)
3. Library version

# Library version

All libraries have a specific version. This version is inter alia shown in the PLC library repository too.  
A global constant contains the library version information:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_SystemCX : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_SystemCX**: version information of the Tc2\_SystemCX library (type: ST\_LibVersion).

To compare the existing version to a required version the function F\_CmpLibVersion (defined in Tc2\_System library) is offered.

|  |  |
| --- | --- |
| 18826965 | All other possibilities known from TwinCAT 2 to query a library version are obsolete! |

[TwinCAT 3 | PLC Library: Tc2\_SystemCX](ms-xhelp:///?Id=beckhoff-b6aa-4d30-a149-d8e2b64ec5d0)
