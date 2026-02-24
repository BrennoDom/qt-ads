# MC_StartMode_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_StartMode\_BkPlcMc (from V3.0)

# MC\_StartMode\_BkPlcMc (from V3.0)

The constants in this list are used for identifying the modes during axis startups.

```
TYPE MC_StartMode_BkPlcMc:  
(  
    MC_StartMode_Absolute:=1,  
    MC_StartMode_Relative,  
    MC_StartMode_RampIn  
);  
END_TYPE
```

**MC\_StartMode\_Absolute**: The set slave position determined by MC\_CamIn\_BkPlcMc is regarded as absolute value.

**MC\_StartMode\_Relative**: The set slave position determined by MC\_CamIn\_BkPlcMc function blocks is regarded as distance from the location of the coupling.

**MC\_StartMode\_RampIn**: Not supported.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
