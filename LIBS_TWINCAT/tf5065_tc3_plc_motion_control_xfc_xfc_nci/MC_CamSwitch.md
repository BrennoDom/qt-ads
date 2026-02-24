# MC_CamSwitch

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# MC\_CamSwitch

The data type MC\_CamSwitch contains all parameters of a digital cam for a digital cam controller [MC\_DigitalCamSwitch](ms-xhelp:///?Id=beckhoff-e466-4ae9-8b40-db813e9b946d).

```
TYPE MC_CamSwitch :  
STRUCT  
    FirstOnPosition : LREAL;  
    LastOnPosition  : LREAL;  
    AxisDirection   : E_CamSwitchDirection;  
    CamSwitchMode   : E_CamSwitchMode;  
    Duration        : LREAL;  
END_STRUCT  
END_TYPE
```

The data structure for parameterization of a digital cam controller is usually an ARRAY OF MC\_CamSwitch. A further structure [CAMSWITCH\_REF](ms-xhelp:///?Id=beckhoff-d6d3-4335-b4f0-5c376cb2aebe) refers to this structure.

| Name | Type | Description |
| --- | --- | --- |
| FirstOnPosition | LREAL | First position from which the cam is switched on. |
| LastOnPosition | LREAL | Last position up to which the cam is switched on. The cam function is inverted, if LastOnPosition < FirstOnPosition. LastOnPositionis is not used for time cams. |
| AxisDirection | [E\_CamSwitchDirection](ms-xhelp:///?Id=beckhoff-b0c4-4203-8122-6c56b697fbe3) | AxisDirection defines in which axis travel direction the digital cam is active (positive, negative or both directions). |
| CamSwitchMode | [E\_CamSwitchMode](ms-xhelp:///?Id=beckhoff-17dc-465c-b990-1dcc83565333) | Digital cam type (position cam, time cam or brake cam). |
| Duration | LREAL | Duration defines the switch-on time of the cam in [s] and is only used for time cams. |

```
TYPE E_CamSwitchDirection :  
(  
    CAMSWITCHDIRECTION_BOTH,     (* digital cam will work in both directions *)  
    CAMSWITCHDIRECTION_POSITIVE, (* digital cam is just working in positive direction *)  
    CAMSWITCHDIRECTION_NEGATIVE  (* digital cam is just working in negative direction *)  
);  
END_TYPE
```

```
TYPE E_CamSwitchMode :  
(  
    CAMSWITCHMODE_POSITION, (* position cam *)  
    CAMSWITCHMODE_TIME,     (* time cam *)  
    CAMSWITCHMODE_BREAK     (* break cam *)  
);  
END_TYPE
```
