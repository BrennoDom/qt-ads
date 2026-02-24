# MC_AxisStates

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-6b3d-418f-93da-0bb0ed053a4a)
4. MC\_AxisStates

# MC\_AxisStates

This data type describes the operating states according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-c86f-4d23-ae31-7fa54570529d).

```
TYPE MC_AxisStates :  
(  
    MC_AXISSTATE_UNDEFINED,  
    MC_AXISSTATE_DISABLED,  
    MC_AXISSTATE_STANDSTILL,  
    MC_AXISSTATE_ERRORSTOP,  
    MC_AXISSTATE_STOPPING,  
    MC_AXISSTATE_HOMING,  
    MC_AXISSTATE_DISCRETEMOTION,  
    MC_AXISSTATE_CONTINOUSMOTION   
);  
END_TYPE
```

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-73e7-420f-a72f-9fc0c9e1b167).

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
