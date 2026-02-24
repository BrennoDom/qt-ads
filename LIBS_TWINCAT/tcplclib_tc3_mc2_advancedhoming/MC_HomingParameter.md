# MC_HomingParameter

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_HomingParameter

```
TYPE MC_HomingParameter :  
STRUCT  
    Stored  : BOOL;  
    Nc      : MC_HomingParameterNcGeneral;  
    Drive   : MC_HomingParameterDriveGeneral;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| Stored | BOOL | This flag signals that the required parameters that are to be modified have been successfully read and are available for reconstruction at the end of the procedure. |
| Nc | MC\_HomingParameterNcGeneral | Structure that contains the stored and modified parameter values of the NC axis |
| Drive | MC\_HomingParameterDriveGeneral | Structure that contains the stored and modified parameter values of the hardware axis controller.  This structure must be made available to and passed through all homing function blocks when programming your own homing sequence. Parameters are backed up in advance, modified by the function blocks and restored upon completion of the procedure. |
