# OUTPUT_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# OUTPUT\_REF

The data type OUTPUT\_REF contains data describing the state of a digital output. In addition to the switching state it contains time stamps for state changes.

```
TYPE OUTPUT_REF :  
STRUCT  
    Level                : BOOL;       (* current level of the digital output *)  
  
    NextStateChangeValid : BOOL;       (* time value NextStateChange is valid *)  
    NextStateChange      : T_DCTIME32; (* time of next state change - current level will be inverted *)  
  
    NextOnTimeValid      : BOOL;       (* time value NextOnTime is valid *)  
    NextOnTime           : T_DCTIME32; (* time when the digital output is turned ON next time *)  
  
    NextOffTimeValid     : BOOL;       (* time value NextOffTime is valid *)  
    NextOffTime          : T_DCTIME32; (* time when the digital output is turned OFF next time *)  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| Level | BOOL | Current switching state of the digital output |
| NextStateChangeValid | BOOL | NextStateChangeValid is TRUE, if the time stamp NextStateChange is valid. |
| NextStateChange | T\_DCTIME32 | Time of the next change of state (distributed clock TimeStamp) |
| NextOnTimeValid | BOOL | NextOnTimeValid is TRUE, if the time stamp NextOnTime is valid. |
| NextOnTime | T\_DCTIME32 | Time of the next positive switching edge (distributed clock TimeStamp) |
| NextOffTimeValid | BOOL | NextOffTimeValid is TRUE, if the time stamp NextOffTime is valid. |
| NextOffTime | T\_DCTIME32 | Time of the next negative switching edge (distributed clock TimeStamp) |
