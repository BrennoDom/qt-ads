# MC_AxUtiSlewRateLimitter_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Utilities](ms-xhelp:///?Id=beckhoff-05d5-4e7a-847c-eea5a0277852)
5. [Filters](ms-xhelp:///?Id=beckhoff-389e-4cef-894c-4e355003dfea)
6. MC\_AxUtiSlewRateLimitter\_BkPlcMc (from V3.0)

# MC\_AxUtiSlewRateLimitter\_BkPlcMc (from V3.0)

![31297682](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854849035__Web.gif)

The function block generates a rise-limited ramp.

```
VAR_INPUT  
    fInput:       LREAL:=0.0;  
    fCycletime:   DINT:=0;  
    fMaxRate:     DINT:=0;  
END_VAR
```

```
VAR_OUTPUT  
    fOutput:      LREAL:=0.0;  
    bError:       BOOL:=FALSE;  
    nErrorId:     UDINT:=0;  
END_VAR
```

**fInput**: The raw value of the parameter to be filtered.

**fCycletime**: [s] The cycle time of the calling PLC task in seconds.

**fMaxRate**: The magnitude of the maximum permitted rate of change at the output as change per second.

**fOutput**: [1/s] The filtered value.

**bError**: This output indicates problems with the transferred parameters.

**nErrorId**: In the event of an error, coded error information is output here.

## Behavior of the function block

With each call the function block checks the transferred values for **fCycletime** and **fMaxRate**. If the values are incorrect, the system responds with **bError** and coded information in **nErrorId**. Otherwise, the difference between **Input** and **Output** is determined with each call. If the magnitude of this difference is less than or equal to **fMaxRate \* fCycletime**, the value of **Input** is used directly as **fOutput**. Otherwise, **fOutput** is changed by **fMaxRate \* fMaxRate**. The sign is selected automatically.

|  |  |
| --- | --- |
| 13243689 | The value for fCycletime must be ≥ 0.001. Negative values are not permitted for fMaxRate. |

**Input** will usually be a value, which is determined and filtered based on the cycle of the axis blocks. [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c).[ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fCycletime can be used for **fCycletime** here.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
