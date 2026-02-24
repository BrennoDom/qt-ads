# XFC_TRIGGER_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TRIGGER\_REF

The data type XFC\_TRIGGER\_REF contains the status and parameters of a digital input that is used for the function block [XFC\_TouchProbe](ms-xhelp:///?Id=beckhoff-bb21-4469-9c61-243dc8a706ed).

```
TYPE XFC_TRIGGER_REF :  
STRUCT  
    Signal               : BOOL;   
    TimestampRisingEdge  : T_DCTIME32;  
    TimestampFallingEdge : T_DCTIME32;   
    Edge                 : E_SignalEdge;  
    FreeRun              : BOOL;   
    EncoderIndex         : UINT;  
    ModuloPositions      : BOOL;  
    ModuloFactor         : LREAL := 360.0;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| Signal | BOOL | Current state of the digital input signal. The current state must be supplied here. |
| TimestampRisingEdge | T\_DCTIME32 | Time stamp of the last rising edge of the digital input signal. Only the time stamp of the edge defined via Edge has to be supplied. If the input signal supplies a 64-bit time stamp T\_DCTIME, only the lower 32 bits are supplied. It is therefore important to ensure that the value at the time of the evaluation is not older than 2 seconds. |
| TimestampFallingEdge | T\_DCTIME32 | Time stamp of the last falling edge of the digital input signal. Only the time stamp of the edge defined via Edge has to be supplied. If the input signal supplies a 64-bit time stamp T\_DCTIME, only the lower 32 bits are supplied. It is therefore important to ensure that the value at the time of the evaluation is not older than 2 seconds. |
| Edge | [E\_SignalEdge](ms-xhelp:///?Id=beckhoff-0df5-4d0f-acc4-1d2e3320bc78) | Edge defines the signal edge to be used for the evaluation of the axis position. TYPE E\_SignalEdge : ( RisingEdge, FallingEdge ); END\_TYPE |
| FreeRun | BOOL | If FreeRun is TRUE, the input is latched continuously. In this case the input Execute must remain TRUE in function block [XFC\_TouchProbe](ms-xhelp:///?Id=beckhoff-bb21-4469-9c61-243dc8a706ed). No edge at Execute is required in order to record the next new position value. |
| EncoderIndex | UINT | If more than one encoder is connected to the axis, the encoder index [0 – 9] can be defined here. The first encoder has the index 0. |
| ModuloPositions | BOOL | If ModuloPositions is TRUE, all positions are interpreted as modulo. The parameter ModuloFactor is used for calculating the modulo cycle. |
| ModuloFactor | LREAL | ModuloFactor indicates the length of a modulo cycle in the positioning unit of the axis and is only used if ModuloPositions is TRUE. |
