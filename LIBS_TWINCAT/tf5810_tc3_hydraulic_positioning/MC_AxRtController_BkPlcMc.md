# MC_AxRtController_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtController\_BkPlcMc

# MC\_AxRtController\_BkPlcMc

![10143581](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9041912075__Web.gif)

This function block contains the standard position controller of the axis.

If necessary, a function block of the significantly more complex type [MC\_AxRtPosPiControllerEx\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-feba-4c4e-afbf-2a4ddc9e9d94) can be used instead of this function block.

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Axis:** A variable of the type Axis\_Ref\_BkPlcMc is to be transferred here.

## Structure of the controller

![24183370](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9041782795__Web.gif)

|  |  |
| --- | --- |
| 16323738 | The Ti parameter is used by this controller as Ki. A value of 0.0 disables the I component. Increasing values generate increasingly strong reactions of the I component. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
