# MC_HomingParameterDrive

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# MC\_HomingParameterDrive

```
TYPE MC_HomingParameterDrive :  
STRUCT  
    TorqueMaxBipolar  : LREAL;  
    TorqueMaxPositive : LREAL;  
    TorqueMaxNegative : LREAL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| TorqueMaxBipolar | LREAL | Bipolar torque limit value |
| TorqueMaxPositive | LREAL | Torque limit value in the logically positive direction of movement |
| TorqueMaxNegative | LREAL | Torque limit value in the logically negative direction of movement |
