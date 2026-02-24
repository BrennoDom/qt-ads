# MC_FunctionGeneratorTB_BkPlcMc (from V3.0.31)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [FunctionGenerator](ms-xhelp:///?Id=beckhoff-15b1-4364-95d9-9bfef4a56b92)
5. MC\_FunctionGeneratorTB\_BkPlcMc (from V3.0.31)

# MC\_FunctionGeneratorTB\_BkPlcMc (from V3.0.31)

![56669285](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854768779__Web.gif)

The function block updates a time base for one or several [function generators](ms-xhelp:///?Id=beckhoff-c220-4046-af00-f126004a753d).

```
VAR_INPUT  
    CycleTime:      LREAL;  
END_VAR
```

```
VAR_INOUT  
    stTimeBase:     ST_FunctionGeneratorTB_BkPlcMc;  
END_VAR
```

**CycleTime:** The cycle time of the calling task.

**stTimeBase:** A structure with the parameters of the time base of one or several [function generators](ms-xhelp:///?Id=beckhoff-dcf9-46b9-a79a-60bb71ea0118).

## Behaviour of the function block

If **stTimeBase.Freeze** is not set, **stTimeBase.CurrentTime** is updated with **CycleTime** and **stTimeBase.CurrentRatio** is determined. **stTimeBase.Frequency** is taken into account.

To change the operating frequency, an [MC\_FunctionGeneratorSetFrq\_BkPlcMc](ms-xhelp:///?Id=beckhoff-b325-4204-a66a-f21961dd38a2)() function block should be used.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
