# Library version

## Library
tcplclib_tc2_dataexchange

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
2. [Global constants](ms-xhelp:///?Id=beckhoff-3aac-470f-99af-136ef2b24027)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_DataExchange : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_DataExchange**: Version information of Tc2\_DataExchange (type: ST\_LibVersion)

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in the Tc2\_System library).

|  |  |
| --- | --- |
| 48361012 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

[TwinCAT 3 | PLC Library: Tc2\_DataExchange](ms-xhelp:///?Id=beckhoff-4780-4855-9ac6-06a7601e6f09)
