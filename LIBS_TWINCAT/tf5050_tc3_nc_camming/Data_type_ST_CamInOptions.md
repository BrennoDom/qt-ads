# Data type ST_CamInOptions

## Library
tf5050_tc3_nc_camming

## Category
Motion Control

1. [TF5050 TC3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
2. [Data type](ms-xhelp:///?Id=beckhoff-61cc-4984-82a9-77a1e817705f)
3. Data type ST\_CamInOptions

# Data type ST\_CamInOptions

Data of type *ST\_CamInOptions* can optionally be transferred to the function block [MC\_CamIn](ms-xhelp:///?Id=beckhoff-9d6c-4e6e-b012-23819a633f2e).

```
TYPE ST_CamInOptions :  
STRUCT  
   (* ActivationMode defines when and where the cam table will be activated *)  
   (* (only valid if slave is already coupled and cam table will be exchanged) *)  
   ActivationMode          : MC_CamActivationMode := MC_CAMACTIVATION_INSTANTANEOUS;  
   ActivationPosition      : LREAL;  
  
   (* Scaling Modes enable, disable or define the way of scaling the cam table *)  
   MasterScalingMode       : MC_CamScalingMode := MC_CAMSCALING_USERDEFINED;  
   SlaveScalingMode        : MC_CamScalingMode := MC_CAMSCALING_USERDEFINED;  
  
   (* InterpolationType is required for position tables only. *)  
   (* MotionFunctions don't need an InterpolationType *)  
   InterpolationType       : MC_InterpolationType := MC_InterpolationType_Linear;  
END_STRUCT  
END_TYPE
```

[TF5050 | TwinCAT 3 NC Camming](ms-xhelp:///?Id=beckhoff-984d-4c21-9ee9-97aff9b63946)
