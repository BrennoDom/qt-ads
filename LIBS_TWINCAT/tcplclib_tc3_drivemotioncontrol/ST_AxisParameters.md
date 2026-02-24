# ST_AxisParameters

## Library
tcplclib_tc3_drivemotioncontrol

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
2. [Data types](ms-xhelp:///?Id=beckhoff-6026-4a24-928a-c60b12336bae)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-6b3d-418f-93da-0bb0ed053a4a)
4. ST\_AxisParameters

# ST\_AxisParameters

This data type contains basic necessary axis parameters.

```
TYPE ST_AxisParameters :  
STRUCT  
    EncoderScalingFactor    : LREAL := 360.0/4096.0;  // Default for 360° and 4096 increments per revolution  
    MaxVelocity             : LREAL := 3600.0;       // Default for 10 revolutions per second  
  
    ModuloFactor            : LREAL := 360.0;  
END_STRUCT  
END_TYPE
```

Formula for calculating the parameters:

![50789581](/tcplclib_tc3_drivemotioncontrol/1033/Images/png/8978903947__Web.png)

|  |  |
| --- | --- |
| 54453050 | Motor speed Limitation  "Motor speed limitation" depends on the configured voltage and the motor used. For the servo terminals, this value can be read from CoE object 0x8011:1B, for example. |

[TwinCAT 3 | PLC Library: Tc3\_DriveMotionControl](ms-xhelp:///?Id=beckhoff-9642-4f70-a3aa-5117d509112d)
