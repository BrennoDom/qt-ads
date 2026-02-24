# MC_AxParamDelayedSave_BkPlcMc

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. MC\_AxParamDelayedSave\_BkPlcMc

# MC\_AxParamDelayedSave\_BkPlcMc

![60507121](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9041920011__Web.gif)

The function block triggers a time-delayed writing of the parameter file after a parameter has been changed.

```
VAR_INPUT  
    Delay:     LREAL:=0.0;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

**Delay**: [s] Delay when triggering the parameter backup.

## Behavior of the function block

If one of the function blocks listed below noticeably changes a parameter, a time is reset. This time is increased by the cycle time in every cycle where this is not the case. If it reaches the parameter Delay, the writing of the parameter file is triggered.

* MC\_WriteBoolParameter\_BkPlcMc
* MC\_WriteParameter\_BkPlcMc
* MC\_AxUtiAutoIdent\_BkPlcMc
* MC\_LinTableImportFromAsciFile\_BkPlcMc
* MC\_LinTableImportFromBinFile\_BkPlcMc

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
