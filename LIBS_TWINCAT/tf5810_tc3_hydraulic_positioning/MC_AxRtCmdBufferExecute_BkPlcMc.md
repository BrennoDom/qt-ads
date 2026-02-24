# MC_AxRtCmdBufferExecute_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtCmdBufferExecute\_BkPlcMc

# MC\_AxRtCmdBufferExecute\_BkPlcMc

![18826965](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9041962251__Web.gif)

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

## Behavior of the function block

If the axis is equipped with a command buffer via an MC\_AxUtiStandardInit() function block, positioning commands such as MC\_MoveAbsolute\_BkPlcMc are entered in this buffer.

If iTcMc\_ProfileCtrlBased is set as the setpoint generator, a function block of this type must be called cyclically so that these commands are forwarded to the axis and actively processed.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
