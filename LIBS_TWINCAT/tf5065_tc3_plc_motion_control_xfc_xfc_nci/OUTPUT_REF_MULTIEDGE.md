# OUTPUT_REF_MULTIEDGE

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# OUTPUT\_REF\_MULTIEDGE

The data type OUTPUT\_REF\_MULTIEDGE contains data describing the state of a digital output. In addition to the switching state it contains time stamps for state changes. The data type is used in conjunction with terminals that allow multiple switching operations per PLC cycle by means of multi-timestamp.

```
TYPE OUTPUT_REF_MULTIEDGE :   
STRUCT   
    SwitchEvent : ARRAY [0..TCMC2_XFC_MAXINDEXOFMULTIEDGEOUTPUTEVENTS] OF ST_SwitchEvent;   
END_STRUCT   
END_TYPE  
  
TYPE ST_SwitchEvent :   
STRUCT   
    ID       : UDINT;   
    Valid    : BOOL;       (* time value is valid *)   
    Level    : BOOL;       (* next level of the digital signal *)   
    Position : LREAL;   
    DcTime   : T_DCTIME32; (* time when the digital output changes *)   
    Duration : DINT;   
END_STRUCT   
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| ID | UDINT | Internal ID of the switching edge |
| Valid | BOOL | Valid is TRUE if the DcTime timestamp is valid. |
| Level | BOOL | Current switching state of the digital output |
| Position | LREAL | Switching position of the switching operation |
| DcTime | T\_DCTIME32 | Time of the next change of state (distributed clock TimeStamp) |
| Duration | DINT | Not used |
