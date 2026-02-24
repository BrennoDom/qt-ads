# MC_PathCamSwitch

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# MC\_PathCamSwitch

The data type MC\_PathCamSwitch contains all parameters of a digital cam for a digital cam controller [MC\_PathDigitalCamSwitch\_MultiEdge](ms-xhelp:///?Id=beckhoff-43b7-4f8f-84a3-212ffca0bd37).

```
TYPE MC_PathCamSwitch :  
STRUCT  
    FirstOnPosition : LREAL;  
    LastOnPosition  : LREAL;  
    FirstPathId     : UDINT;  
    LastPathId      : UDINT;  
    CamSwitchMode   : E_CamSwitchMode;  
    Duration        : LREAL;  
END_STRUCT  
END_TYPE
```

The data structure for parameterization of a digital cam controller is usually an ARRAY OF MC\_PathCamSwitch. A further structure [PATH\_CAMSWITCH\_REF](ms-xhelp:///?Id=beckhoff-7a6f-4e8d-ac3f-cc987a2662e5) refers to this structure.

| Name | Type | Description |
| --- | --- | --- |
| FirstOnPosition | LREAL | First position from which the cam is switched on. |
| LastOnPosition | LREAL | Last position up to which the cam is switched on. The cam function is inverted, if LastOnPosition < FirstOnPosition. LastOnPositionis is not used for time cams. |
| FirstPathId | UDINT | Unique ID that continually increases over the path and belongs to the relative path until the cam switches on. |
| LastPathId | UDINT | Unique ID that continually increases over the path and belongs to the relative path until the cam switches off. |
| CamSwitchMode | [E\_CamSwitchMode](ms-xhelp:///?Id=beckhoff-17dc-465c-b990-1dcc83565333) | Digital cam type (position cam, time cam or brake cam). |
| Duration | LREAL | Duration defines the switch-on time of the cam in [s] and is only used for time cams. |

```
TYPE E_CamSwitchMode :  
(  
    CAMSWITCHMODE_POSITION, (* position cam *)  
    CAMSWITCHMODE_TIME,     (* time cam *)  
    CAMSWITCHMODE_BREAK     (* break cam *)  
);  
END_TYPE
```
