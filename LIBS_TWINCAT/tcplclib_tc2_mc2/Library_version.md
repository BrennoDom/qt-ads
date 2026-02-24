# Library version

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Global constants](ms-xhelp:///?Id=beckhoff-1594-4885-a160-9413c40ef012)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_MC2 : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_MC2**: version information of the Tc2\_MC2 library (Typ: ST\_LibVersion).

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in Tc2\_System library).

All other options for comparing library versions, which you may know from TwinCAT 2, are outdated.

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
