# Data type MC_MotionFunctionPoint

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type MC\_MotionFunctionPoint

# Data type MC\_MotionFunctionPoint

```
TYPE MC_MotionFunctionPoint :  
STRUCT  
   PointIndex          : MC_MotionFunctionPoint_ID;  
   FunctionType        : MC_MotionFunctionType;  
   PointType           : MC_MotionPointType;  
   RelIndexNextPoint   : MC_MotionFunctionPoint_ID;  
   MasterPos           : LREAL; (* X *)  
   SlavePos            : LREAL; (* Y *)  
   SlaveVelo           : LREAL; (* Y' *)  
   SlaveAcc            : LREAL; (* Y'' *)  
   SlaveJerk           : LREAL; (* Y''' *)  
END_STRUCT  
END_TYPE
```

The data structure *MC\_MotionFunctionPoint* describes an interpolation point of a motion function. A motion function is a one-dimensional list (array) of type *MC\_MotionFunctionPoint*.

**PointIndex**: Absolute index of this interpolation point within the motion function. The point index of all interpolation points must increase strictly monotonously and must have no gaps and be greater than 0.

**FunctionType**: Type [MC\_MotionFunctionType](ms-xhelp:///?Id=beckhoff-1a9a-4aed-bd7e-de7471b50d0b) of the mathematical function between this and the subsequent interpolation point

**PointType**: Type [MC\_MotionPointType](ms-xhelp:///?Id=beckhoff-49fd-4546-9c4b-ebc7b288d451) of this interpolation point.

**RelIndexNextPoint**: Relative reference to the subsequent interpolation point (usually 1).

**MasterPos**: Position of the master axis at this interpolation point

**SlavePos**: Position of the slave axis at this interpolation point

**SlaveVelo**: Velocity of the slave axis at this interpolation point

**SlaveAcc**: Acceleration of the slave axis at this interpolation point

**SlaveJerk**: Jerk of the slave axis at this interpolation point

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
