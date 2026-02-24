# Library version

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Global constants](ms-xhelp:///?Id=beckhoff-3523-41b4-adb4-e48ca13c8994)
3. Library version

# Library version

All libraries have a certain version. The version is indicated in the PLC library repository, for example. A global constant contains the information about the library version:

**Global\_Version**

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc3_DriveMotionControl : ST_LibVersion;  
END_VAR
```

**stLibVersion\_Tc3\_DriveMotionControl**: Version information of the Tc3\_DriveMotionControl library (type: ST\_LibVersion).

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in the Tc2\_System library).

|  |  |
| --- | --- |
| 20315403 | Compare versions  All other options for comparing library versions, which you may know from TwinCAT 2, are outdated! |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
