# Global_Version

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Global Constants](ms-xhelp:///?Id=beckhoff-f4ee-451e-9a56-4fa6547e748d)
3. Global\_Version

# Global\_Version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc2_MDP : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc2\_MDP**: Version number of the Tc2\_MDP library (type: ST\_LibVersion).

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in Tc2\_System library).

|  |  |
| --- | --- |
| 53044787 | All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
