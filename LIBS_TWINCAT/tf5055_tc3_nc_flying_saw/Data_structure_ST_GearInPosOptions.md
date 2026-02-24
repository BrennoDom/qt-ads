# Data structure ST_GearInPosOptions

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Data types](ms-xhelp:///?Id=beckhoff-76b6-43c9-91cb-f1d97c3c996e)
3. Data structure ST\_GearInPosOptions

# Data structure ST\_GearInPosOptions

```
TYPE ST_GearInPosOptions :  
STRUCT  
    PositionLimitMin:              LREAL ;  
(* will additionally be checked if GearInSync_CheckMask_OptionalMinPos is set to TRUE *)  
    PositionLimitMax:              LREAL ;  
(* will additionally be checked if GearInSync_CheckMask_OptionalMaxPos is set to TRUE *)  
END_STRUCT  
END_TYPE
```

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
