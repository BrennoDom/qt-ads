# CDT_MCTOPLC_PLANAR_MOVER

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# CDT\_MCTOPLC\_PLANAR\_MOVER

Contains the information of the Planar Mover passed from MC to PLC.

## Syntax

Definition:

```
TYPE CDT_MCTOPLC_PLANAR_MOVER :  
STRUCT  
    STD        : CDT_MCTOPLC_PLANAR_MOVER_STD;  
    SET        : CDT_MCTOPLC_PLANAR_MOVER_SET;  
    ACT        : CDT_MCTOPLC_PLANAR_MOVER_ACT;  
    COORDMODE  : CDT_MCTOPLC_PLANAR_MOVER_COORDMODE;  
    SETONTRACK : CDT_MCTOPLC_PLANAR_MOVER_TRACK;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Description |
| --- | --- | --- |
| STD | CDT\_MCTOPLC\_PLANAR\_MOVER\_STD | Mover standard data that is transferred from the Planar Mover to this function block. |
| SET | CDT\_MCTOPLC\_PLANAR\_MOVER\_SET | Mover setpoint data that is transferred from the Planar Mover to this function block. |
| ACT | CDT\_MCTOPLC\_PLANAR\_MOVER\_ACT | Mover actpoint data that is transferred from the Planar Mover to this function block. |
| COORDMODE | CDT\_MCTOPLC\_PLANAR\_MOVER\_COORDMODE | Mover coordinate mode information that is transferred from the Planar Mover to this function block. |
| SETONTRACK | CDT\_MCTOPLC\_PLANAR\_MOVER\_TRACK | Mover busy information that is transferred from the Planar Mover to this function block. |
