# MC_HomingMode

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. MC\_HomingMode

# MC\_HomingMode

This data type is used to parameterize the function block [MC\_Home](ms-xhelp:///?Id=beckhoff-6ee1-4cfb-b8c8-8c450b3b93d9).

```
TYPE MC_HomingMode :  
(  
    MC_DefaultHoming,    (* default homing as defined in the SystemManager encoder parameters *)  
    MC_Direct,           (* Static Homing forcing position from user reference *)  
    MC_ForceCalibration, (* set the calibration flag without perfomring any motion or changing the position *)  
    MC_ResetCalibration  (* resets the calibration flag without perfomring any motion or changing the position *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
