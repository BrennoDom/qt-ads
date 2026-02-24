# Library version

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [Constants](ms-xhelp:///?Id=beckhoff-8c57-465e-a61b-d1685692b31b)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_EtherCAT : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_EtherCAT**: Version information of the Tc2\_EtherCAT library (type: ST\_LibVersion)

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in the Tc2\_System library).

|  |  |
| --- | --- |
| 27848947 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
