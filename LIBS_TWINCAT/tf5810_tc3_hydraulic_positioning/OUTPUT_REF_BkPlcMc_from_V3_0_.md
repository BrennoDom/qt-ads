# OUTPUT_REF_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. OUTPUT\_REF\_BkPlcMc (from V3.0)

# OUTPUT\_REF\_BkPlcMc (from V3.0)

A structure of this type is transferred to function blocks of types [MC\_ReadDigitalOutput\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-4f7e-43c1-94d6-9bafa01240b0), [MC\_WriteDigitalOutput\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-4e0d-49b0-91f7-6fbd02e16d33) and [MC\_DigitalCamSwitch\_BkPlcMc()](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc).

```
TYPE OUTPUT_REF_BkPlcMc:  
STRUCT  
    OutputBits: UDINT:=0;  
END_STRUCT  
END_TYPE
```

**OutputBits**: The outputs addressed via this structure.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
