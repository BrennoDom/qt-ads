# Library version

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Global Constants](ms-xhelp:///?Id=beckhoff-3eeb-404d-b7dd-4b854a97648d)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc3_IPCDiag : ST_LibVersion;  
END_VAR
```

In order to check whether you are using the library version that you need, the function F\_CmpLibVersion (defined in Tc2\_System library) is available to you.

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
