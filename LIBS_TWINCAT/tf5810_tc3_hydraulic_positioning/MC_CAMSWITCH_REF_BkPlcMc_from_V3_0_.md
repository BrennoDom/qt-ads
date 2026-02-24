# MC_CAMSWITCH_REF_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. MC\_CAMSWITCH\_REF\_BkPlcMc (from V3.0)

# MC\_CAMSWITCH\_REF\_BkPlcMc (from V3.0)

A variable of this type is transferred to an [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc) function block.

```
TYPE CAMSWITCH_REF_BkPlcMc:  
STRUCT  
    Switch:     ARRAY [ciBkPlcMc_CamSwitchRef_MinIdx..ciBkPlcMc_CamSwitchRef_MaxIdx] OF MC_CAMSWITCH_REFTYPE_BkPlcMc;  
END_STRUCT  
END_TYPE
```

```
TYPE MC_CAMSWITCH_REFTYPE_BkPlcMc:  
STRUCT  
    TrackNumber:      INT;  
    FirstOnPosition:  LREAL;  
    LastOnPosition:   LREAL;  
    AxisDirection:    INT;  
    CamSwitchMode:    INT;  
    Duration:         LREAL;  
    (* private members, do not touch *)  
    nCurrentState:    SINT:=0;  
    bTriggered:       BOOL:=FALSE;  
    fTimer:           LREAL;  
    (**)  
END_STRUCT  
END_TYPE
```

**TrackNumber**: This is an index in an ARRAY [ciBkPlcMc\_TrackRef\_MinIdx..ciBkPlcMc\_TrackRef\_MaxIdx] OF [MC\_TRACK\_REF\_BkPlcMc](ms-xhelp:///?Id=beckhoff-ee5c-4cd0-a66f-7a08ab2a33b2), which is transferred to a function block of type [MC\_DigitalCamSwitch\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f926-4994-ab22-ff25375bcbfc).

**FirstOnPosition**: [mm] The start of the cam track. For time-controlled cams, this is the trigger position.

**LastOnPosition**: [mm] The end of the cam track. Has no effect for time-controlled cams.

**AxisDirection**: Specifies in which direction of movement the cam becomes active: 0 = both directions, 1 = positive direction, 2 = negative direction.

**CamSwitchMode**: The operating mode of the cam: For displacement-controlled cams enter 0, for time-controlled cams enter 1.

**Duration**: [s] For time-controlled cams enter the switch-on time in seconds.

**nCurrentState**, **bTriggered**, **fTimer**: These elements are runtime variables and must not be influenced or used by the application.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
