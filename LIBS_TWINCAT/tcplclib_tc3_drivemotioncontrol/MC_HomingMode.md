# MC_HomingMode

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Homing](ms-xhelp:///?Id=beckhoff-3b23-4663-895d-2e53b7962810)
4. MC\_HomingMode

# MC\_HomingMode

This data type is used to parameterize the function block [MC\_Home](ms-xhelp:///?Id=beckhoff-eea9-48c8-a7a7-c69b475c1cf9).

```
TYPE MC_HomingMode :  
(  
    MC_DefaultHoming       :=0,  (* default homing as defined in the SystemManager encoder parameters *)  
    MC_Direct              :=4,  (* Static Homing forcing position from user reference *)  
    MC_Block               :=6,  (* Homing against hardware parts blocking movement *)  
    MC_ForceCalibration    :=7,  (* set the calibration flag without perfomring any motion or changing the position *)  
    MC_ResetCalibration    :=8   (* resets the calibration flag without perfomring any motion or changing the position *)  
);  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
