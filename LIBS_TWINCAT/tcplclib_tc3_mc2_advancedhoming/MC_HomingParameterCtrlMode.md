# MC_HomingParameterCtrlMode

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_HomingParameterCtrlMode

```
TYPE MC_HomingParameterCtrlMode :  
(  
    HOMINGPARAMETERCTRLMODE_READ,  
    HOMINGPARAMETERCTRLMODE_PREPARE,  
    HOMINGPARAMETERCTRLMODE_RESTORE  
) UDINT;  
END_TYPE
```

| Name | Description |
| --- | --- |
| HOMINGPARAMETERCTRLMODE\_READ | This function block reads all relevant parameters of the NC axis and the hardware axis controller. |
| HOMINGPARAMETERCTRLMODE\_PREPARE | This function block modifies all relevant parameters of the NC axis and the hardware axis controller.  The parameters to be modified must be written to the parameter structure beforehand. |
| HOMINGPARAMETERCTRLMODE\_RESTORE | This function block restores the backed-up parameters of the NC axis and the hardware axis controller.  The requirement is that the parameters have been successfully read beforehand. |
