# MC_AxRtMoveChecking_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Runtime](ms-xhelp:///?Id=beckhoff-6898-463a-a8a2-80cf35a5250d)
5. MC\_AxRtMoveChecking\_BkPlcMc (from V3.0)

# MC\_AxRtMoveChecking\_BkPlcMc (from V3.0)

![8289053](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854810123__Web.gif)

The function block monitors the response of an axis.

```
VAR_INPUT  
     Enable:       BOOL;  
     MinDistance:  LREAL;  
     Filter:       LREAL;  
END_VAR
```

```
VAR_OUPUT  
     Triggered:    BOOL;  
     Timeout:      BOOL;  
END_VAR
```

```
VAR_INOUT  
     Axis:         Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: TRUE at this input activates the monitoring.

**MinDistance**: [mm] The required minimum distance must be transferred here.

**Filter**: [s] The measuring time must be specified here.

**Triggered**: This output indicates that the axis was set to error state.

**Timeout**: This output indicates that monitoring was triggered.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block continuously checks whether the axis has travelled at least a **MinDistance** within **Filter** in the direction that matches the required motion. If this is not the case, **timeout** is indicated. If **Enable** is TRUE, the axis is set to error state **dwTcHydErrCdNotMoving** = 16#435D = 17245. This is indicated through **Triggered**.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
