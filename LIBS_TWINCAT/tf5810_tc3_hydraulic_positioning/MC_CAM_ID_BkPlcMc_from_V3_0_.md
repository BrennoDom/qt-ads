# MC_CAM_ID_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_CAM\_ID\_BkPlcMc (from V3.0)

# MC\_CAM\_ID\_BkPlcMc (from V3.0)

(internal use only).

```
TYPE MC_CAM_ID_BkPlcMc:  
STRUCT  
    stCamRef:       MC_CAM_REF_BkPlcMc;  
    bValidated:     BOOL:=FALSE;  
    bPeriodic:      BOOL:=FALSE;  
    bMasterAbs:     BOOL:=FALSE;  
    bSlaveAbs:      BOOL:=FALSE;  
    bIsChanged:     BOOL:=TRUE;  
END_STRUCT  
END_TYPE
```

**stCamRef**: A copy of the [MC\_CAM\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-6249-4c3b-aefb-f2fdf2745e46) structure.

**bValidated**: Here this structure is identified as valid, if was initialized by a function block of type [MC\_CamTableSelect\_BkPlcMc](ms-xhelp:///?Id=beckhoff-af26-44f2-901d-1b7a99b37e87).

**bPeriodic**: Reserved.

**bMasterAbs**: Specifies whether the data of the master column are absolute or refer to the master position at the time of the coupling.

**bSlaveAbs**: Specifies whether the data of the slave column are absolute or refer to the slave position at the time of the coupling.

**bIsChanged**: Reserved.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
