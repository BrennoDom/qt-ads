# CAMSWITCH_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# CAMSWITCH\_REF

The data type CAMSWITCH\_REF refers to a data structure with cam parameters for a digital cam controller [MC\_DigitalCamSwitch](ms-xhelp:///?Id=beckhoff-e466-4ae9-8b40-db813e9b946d).

```
TYPE CAMSWITCH_REF :  
STRUCT  
    NumberOfSwitches : UDINT;   
    pSwitches        : POINTER TO MC_CamSwitch;   
    SizeOfSwitches   : UDINT;   
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| NumberOfSwitches | UDINT | Number of array elements used. Can be less than the maximum number. |
| pSwitches | POINTER TO MC\_CamSwitch | Pointer to the digital cam array. |
| SizeOfSwitches | UDINT | Maximum size of the digital cam array. |

The actual data structure for parameterization of a digital cam controller is usually an ARRAY OF [MC\_CamSwitch](ms-xhelp:///?Id=beckhoff-07b5-478f-882b-1ce1053737a7). [CAMSWITCH\_REF](ms-xhelp:///?Id=beckhoff-d6d3-4335-b4f0-5c376cb2aebe) refers to this structure via a pointer and clearly defines the size of the structure and the number of actual cams.

A variable of type CAMSWITCH\_REF is initialized as illustrated in the following example:

```
VAR  
    CamSwitchArray : ARRAY[1..3] OF MC_CamSwitch;  
    CamSwitchRef   : CAMSWITCH_REF;  
END_VAR
```

```
(* real number of defined digital cams *)  
CamSwitchRef.NumberOfSwitches := 1; (* 1..3 *)  
(* pointer to the digital cam data array *)  
CamSwitchRef.pSwitches        := ADR(CamSwitchArray);  
(* maximum size of the digital cam data array *)  
CamSwitchRef.SizeOfSwitches   := SIZEOF(CamSwitchArray);
```

## Example with two cam tracks

![4243749](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/gif/462172555__en-US__Web.gif)
