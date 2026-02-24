# MC_TRACK_REF_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_TRACK\_REF\_BkPlcMc (from V3.0)

# MC\_TRACK\_REF\_BkPlcMc (from V3.0)

```
TYPE TRACK_REF_BkPlcMc:  
STRUCT  
    Track:          ARRAY [ciBkPlcMc_TrackRef_MinIdx..ciBkPlcMc_TrackRef_MaxIdx] OF MC_TRACK_REFTYPE_BkPlcMc;  
END_STRUCT  
END_TYPE  
  
TYPE MC_TRACK_REFTYPE_BkPlcMc:  
STRUCT  
    OnCompensation: LREAL;  
    OffCompensation:LREAL;  
    Hysteresis:     LREAL;  
END_STRUCT  
END_TYPE
```

**OnCompensation**: The switch-on dead time to be compensated in seconds.

**OffCompensation**: The switch-off dead time to be compensated in seconds.

**Hysteresis**: The axis must have moved away from the switching point by this distance before reaching of the switching point is evaluated again.

If a positive value is specified as dead time compensation, signaling is delayed. A negative value leads to leading signaling.

|  |  |
| --- | --- |
| 27950294 | The time cannot be adhered to precisely, if the controlling parameter changes with a fluctuating rate. If this controlling parameter is an actual axis position, the actual axis velocity must be constant. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
