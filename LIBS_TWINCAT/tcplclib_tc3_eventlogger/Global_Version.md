# Global_Version

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Global\_Version

All libraries have a certain version. This version can be seen in the PLC library repository among others.  
A global constant contains the library version information (of type ST\_LibVersion):

Global\_Version

```
VAR_GLOBAL CONSTANT  
    stLibVersion_Tc3_EventLogger : ST_LibVersion;  
END_VAR
```

To check whether the version you have is the version you need, use the function F\_CmpLibVersion (defined in the Tc2\_System library).
