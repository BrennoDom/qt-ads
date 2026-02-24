# XFC_MT_TRIGGER_REF

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_MT\_TRIGGER\_REF

```
TYPE XFC_MT_TRIGGER_REF :  
STRUCT  
    Signal          : BOOL;      
    FreeRun         : BOOL;      
    EncoderIndex    : UINT;      
    ModuloPositions : BOOL;      
    ModuloFactor    : LREAL := 360.0;  
END_STRUCT  
END_TYPE
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| Signal | BOOL | Current state of the digital input signal. The current state must be supplied here. |
| FreeRun | BOOL | If FreeRun is TRUE, the input is latched continuously. In the case of the function block XFC\_EL1258\_TouchProbe, the input Execute must then remain TRUE. No edge at Execute is required in order to record the next new position value. |
| EncoderIndex | UINT | If more than one encoder is connected to the axis, the encoder index [0 – 9] can be defined here. The first encoder has the index 0. |
| ModuloPositions | BOOL | If ModuloPositions is TRUE, all positions are interpreted as modulo. The parameter ModuloFactor is used for calculating the modulo cycle. |
| ModuloFactor | LREAL | ModuloFactor indicates the length of a modulo cycle in the positioning unit of the axis and is only used if ModuloPositions is TRUE. |
