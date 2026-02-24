# MC_HomingMode_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_HomingMode\_BkPlcMc (from V3.0)

# MC\_HomingMode\_BkPlcMc (from V3.0)

The constants in this list are used for identifying the modes during axis homing.

```
TYPE MC_HomingMode_BkPlcMc:  
(  
    MC_DefaultHomingMode_BkPlcMc,  
    MC_AbsSwitch_BkPlcMc,  
    MC_LimitSwitch_BkPlcMc,  
    MC_RefPulse_BkPlcMc,  
    MC_Direct_BkPlcMc,  
    MC_Absolute_BkPlcMc,  
    MC_Block_BkPlcMc,  
    MC_FlyingSwitch_BkPlcMc,  
    MC_FlyingRefPulse_BkPlcMc  
);  
END_TYPE
```

**MC\_DefaultHomingMode\_BkPlcMc**: The referencing method specified in the axis parameters is used.

**MC\_AbsSwitch\_BkPlcMc**: The method iTcMc\_HomingOnIndex is used.

**MC\_LimitSwitch\_BkPlcMc**: not supported.

**MC\_RefPulse\_BkPlcMc**: The method iTcMc\_HomingOnSync is used.

**MC\_Direct\_BkPlcMc**: The method iTcMc\_HomingOnExec is used.

**MC\_Absolute\_BkPlcMc**: not supported.

**MC\_Block\_BkPlcMc**: The method iTcMc\_HomingOnBlock is used.

**MC\_FlyingSwitch\_BkPlcMc**: not supported.

**MC\_FlyingRefPulse\_BkPlcMc**: not supported.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
