# PATH_CAMSWITCH_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# PATH\_CAMSWITCH\_REF

The data type PATH\_CAMSWITCH\_REF refers to a data structure with cam parameters for a digital cam controller MC\_PathDigitalCamSwitch\_MultiEdge.

```
TYPE PATH_CAMSWITCH_REF :  
STRUCT  
    NumberOfSwitches : UDINT;   
    pSwitches        : POINTER TO MC_PathCamSwitch;   
    SizeOfSwitches   : UDINT;   
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| NumberOfSwitches | UDINT | Number of array elements used, can be less than the maximum number. |
| pSwitches | POINTER TO [MC\_PathCamSwitch](ms-xhelp:///?Id=beckhoff-b2b6-4ebe-b52f-d4160e897971) | Pointer to an array of switches, transferred with ADR. |
| SizeOfSwitches | UDINT | Maximum size of the array. |

The actual data structure for parameterization of a digital cam controller is usually an ARRAY OF [MC\_PathCamSwitch](ms-xhelp:///?Id=beckhoff-b2b6-4ebe-b52f-d4160e897971). PATH\_CAMSWITCH\_REF refers to this structure via a POINTER and clearly defines the size of the structure and the number of cams that were actually used.

A variable of type PATH\_CAMSWITCH\_REF is initialized as illustrated in the following example:

```
VAR  
    CamSwitchArray   : ARRAY[1..3] OF MC_PathCamSwitch;  
    CamSwitchRef     : PATH_CAMSWITCH_REF;  
END_VAR  
  
(* real number of defined digital cams *)  
CamSwitchRef.NumberOfSwitches := 1; (* 1..3 *)  
(* pointer to the digital cam data array *)  
CamSwitchRef.pSwitches        := ADR(CamSwitchArray);  
(* maximum size of the digital cam data array *)  
CamSwitchRef.SizeOfSwitches   := SIZEOF(CamSwitchArray);
```
