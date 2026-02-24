# Data type ST_CamScalingData

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type ST\_CamScalingData

# Data type ST\_CamScalingData

The structure *ST\_CamScalingData* contains information for scaling a cam plate and is used with the function block [MC\_CamIn\_V2](ms-xhelp:///?Id=beckhoff-b46a-4343-a1d4-b2c35fe9a410).

```
TYPE ST_CamScalingData :  
STRUCT  
   (* scaling of the X axis of the cam (master scaling) *)  
   MasterScalingMode  : MC_CamScalingMode;  
   MasterRelative     : BOOL;  
   MasterOffset       : LREAL;  
   MasterScaling      : LREAL := 1.0;  
  
   (* scaling of the Y axis of the cam (slave scaling) *)  
   SlaveScalingMode   : MC_CamScalingMode;  
   SlaveRelative      : BOOL;  
   SlaveOffset        : LREAL;  
   SlaveScaling       : LREAL := 1.0;  
END_STRUCT  
END_TYPE
```

|  |  |
| --- | --- |
| **MasterScalingMode** | [Scaling mode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) for the master position of the cam plate |
| **MasterRelative** | If TRUE the cam plate operates relative to the current master position at the time of activation. |
| **MasterOffset** | Master offset for orientation of the cam plate in the axis coordinate system. *MasterOffset* takes effect in absolute mode from the master axis position 0 and in relative mode from the current position at the time of activation. |
| **MasterScaling** | Scaling of the master position of the cam plate. Default is 1.0 |
| **SlaveScalingMode** | [Scaling mode](ms-xhelp:///?Id=beckhoff-ec0d-401b-8d43-f6039df26ed1) for the slave position of the cam plate |
| **SlaveRelative** | If TRUE the cam plate operates relative to the current slave position at the time of activation. |
| **SlaveOffset** | Slave offset for orientation of the cam plate in the axis coordinate system. *SlaveOffset* takes effect in absolute mode from the slave axis position 0 and in relative mode from the current position at the time of activation. |
| **SlaveScaling** | Scaling of the slave position of the cam plate. Default is 1.0 |

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
