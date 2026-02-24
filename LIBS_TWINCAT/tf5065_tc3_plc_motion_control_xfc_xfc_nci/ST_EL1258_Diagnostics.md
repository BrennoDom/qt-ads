# ST_EL1258_Diagnostics

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# ST\_EL1258\_Diagnostics

The data type ST\_EL1258\_Diagnostics contains diagnostic data that can be used for error analysis.

```
TYPE ST_EL1258_Diagnostics :  
STRUCT  
    EventsInInputBuffer:       UDINT;   
    NoOfReceiveEvents:         UDINT;  
    NoOfReceiveEventsRising:   UDINT;   
    NoOfReceiveEventsFalling:  UDINT;  
    NoOfRecordedEventsRising:  UDINT;   
    NoOfRecordedEventsFalling: UDINT;  
    ErrorBufferOverflow:       BOOL;  
    ErrorModuloInput:          BOOL;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| EventsInInputBuffer | UDINT | Counts the events as long as ErrorBufferOverflow is FALSE. |
| NoOfReceiveEvents | UDINT | Number of input events of EL1259. |
| NoOfReceiveEventsRising | UDINT | Number of rising edges of EL1259. |
| NoOfReceiveEventsFalling | UDINT | Number of falling edges of EL1259. |
| NoOfRecordedEventsRising | UDINT | Number of rising edges in the recorded events as long as WindowOnly is FALSE and NoOfReceiveEventsRising = NoOfRecordedEventsRising. |
| NoOfRecordedEventsFalling | UDINT | Number of falling edges in the recorded events as long as WindowOnly is FALSE and NoOfReceiveEventsFalling = NoOfRecordedEventsFalling. |
| ErrorBufferOverflow | BOOL | Indicates that the output buffer of the EL2258 is full. |
| ErrorModuloInput | BOOL | NoOfRecordedEventsRising + NoOfRecordedEvents-Falling = NoOfRecordedEvents. |
