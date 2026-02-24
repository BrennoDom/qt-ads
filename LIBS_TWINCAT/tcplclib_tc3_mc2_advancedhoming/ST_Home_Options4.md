# ST_Home_Options4

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# ST\_Home\_Options4

```
TYPE MC_Home_Options4 :  
STRUCT  
    DisableDriveAccess      : BOOL;  
    EnableLagErrorDetection : BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| DisableDriveAccess | BOOL | When setting this flag, no modifications are made to the parameters of the hardware controller and the user is responsible for modifying them to an appropriate extent so that the actual referencing process is possible. |
| EnableLagErrorDetection | BOOL | In the step functions the lag error detection is switched off in order to ensure a smooth homing procedure. If it would be purposeful to keep the lag error detection active in an application, this can be achieved by setting this flag. |
