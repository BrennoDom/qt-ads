# AXIS_REF

```
TYPE AXIS_REF :
STRUCT
    PlcToNc      : PLCTONC_AXIS_REF;
    NcToPlc      : NCTOPLC_AXIS_REF;
    ADS          : ST_AdsAddress;
    Status       : ST_AxisStatus;
    DriveAddress : ST_DriveAddress;
END_STRUCT
END_TYPE
```