# MC_AxUtiPT2_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Filters](ms-xhelp:///?Id=beckhoff-389e-4cef-894c-4e355003dfea)
6. MC\_AxUtiPT2\_BkPlcMc (from V3.0)

# MC\_AxUtiPT2\_BkPlcMc (from V3.0)

![18390601](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854846603__Web.gif)

The function block calculates a second-order low-pass.

```
VAR_INPUT  
     fInput:       LREAL:=0.0;  
     fCycletime:   LREAL:=0.001;  
     fTheta:       LREAL:=1.0;  
     fT0:          LREAL:=1.0;  
END_VAR
```

```
VAR_OUTPUT  
     fOutput:      LREAL;  
     bError:       BOOL;  
     nErrorId:     UDINT;  
END_VAR
```

**fInput**: The raw value of the parameter to be filtered.

**fCycletime**: [s] The cycle time of the calling PLC task.

**fTheta**: The attenuation.

**fT0**: The filter time constant.

**fOutput**: The filtered value.

**bError**: This output indicates problems with the transferred parameters.

**nErrorId**: In the event of an error, coded information about the type of problem is reported here.

## Behavior of the function block

With each call the function block checks the transferred parameters. If an invalid value is detected, the function block responds with **bError** and a corresponding value in **nErrorId**. Otherwise, the internal variables are updated with **fInput,** and the filtered value is returned as **fOutput**.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
