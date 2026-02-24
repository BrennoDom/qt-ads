# MC_AxRtFollowUp_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. MC\_AxRtFollowUp\_BkPlcMc

# MC\_AxRtFollowUp\_BkPlcMc

![19167756](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9042450315__Web.gif)

The function block updates the offset compensation.

```
VAR_INPUT  
     Enable:       BOOL;  
END_VAR
```

```
VAR_IN_OUT  
     Axis:       AXIS_REF_BkPlcMc;  
END_VAR
```

**Enable**: A TRUE at this input enables the function block.

## Behavior of the function block

If Enable = TRUE, the actual position is copied to all target and set positions. Target velocity, lag error and position controller output are set to 0.0. With a falling edge at Enable, the axis will re-enable the position controller depending on parameters and enables at the current actual position.

The function block should not be enabled for an axis that is performing an active movement or needs to be controlled.

Because the position control is disabled, the axis can drift.

If the axis is to be moved by external actions, the required oil paths must be opened by the application.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
