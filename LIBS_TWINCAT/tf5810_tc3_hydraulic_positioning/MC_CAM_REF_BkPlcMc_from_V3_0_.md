# MC_CAM_REF_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_CAM\_REF\_BkPlcMc (from V3.0)

# MC\_CAM\_REF\_BkPlcMc (from V3.0)

(internal use only).

```
TYPE MC_CAM_REF_BkPlcMc:  
STRUCT  
    pTable:        POINTER TO LREAL:=0;  
    nFirstIdx:     UDINT:=1;  
    nLastIdx:      UDINT:=1;  
    bEquiDistant:  BOOL:=FALSE;  
END_STRUCT  
END_TYPE
```

**pTable**: The address of the curve table.

**nFirstIdx**: The index of the first table row.

**nLastIdx**: The index of the last table row.

**bEquiDistant**: Reserved.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
