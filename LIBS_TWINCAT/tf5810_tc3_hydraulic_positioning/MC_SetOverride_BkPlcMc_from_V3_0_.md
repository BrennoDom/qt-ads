# MC_SetOverride_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_SetOverride\_BkPlcMc (from V3.0)

# MC\_SetOverride\_BkPlcMc (from V3.0)

![56833109](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854673931__Web.gif)

The function block sets the override of an axis.

|  |  |
| --- | --- |
| 41735936 | This function block only takes effect if the profile type iTcMc\_ProfileCtrlBased is used. |

```
VAR_INPUT  
    Enable:     BOOL;  
    VelFactor:  LREAL;  
END_VAR
```

```
VAR_OUTPUT  
    Enabled:    BOOL;  
    Busy:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Enable**: An active state at this input sets the override of the axis.

**VelFactor**: [1] The new override of the axis.

**Enabled**: This indicates the active state of the function block.

**Busy**: This output is TRUE while the command is being processed.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

If the **Enable** state is active, the value transferred as **VelOverride** is limited to the range 0.0 to 1.0 and entered in **Axis.pStAxParams^.fOverride**. **Enabled** is set to TRUE.

A negative edge at **Enable** clears all outputs.

![40079106](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1599935371__Web.gif)

All velocity changes caused by an override change are limited according to the maximum permitted accelerations and decelerations.

|  |  |
| --- | --- |
| 25167636 | In order to ensure reproducible behavior during the target approach, the override only reduces the travel speed to pStAxParams.fCreepSpeed. Therefore, it is not possible to stop the axis movement through an override of 0.0. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
