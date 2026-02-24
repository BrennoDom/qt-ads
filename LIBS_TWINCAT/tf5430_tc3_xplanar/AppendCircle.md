# AppendCircle

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AppendCircle

AppendCircle commandFeedback  MC\_PlanarFeedbackclockwise  BOOL↔start  PositionXYC↔end  PositionXYC↔center  PositionXY

Appends a circular arc to the Planar Track.

## Syntax

Definition:

```
METHOD AppendCircle  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    clockwise       : BOOL;  
END_VAR  
VAR_IN_OUT  
    start           : PositionXYC;  
    end             : PositionXYC;  
    center          : PositionXY;  
END_VAR
```

## 48616240 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| clockwise | BOOL | Indicates if the clockwise circle is appended. |

## 34892981 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| start | PositionXYC | Start position of the circular arc. |
| end | PositionXYC | End position of the circular arc, this position is the new endpoint of the Planar Track. |
| center | PositionXY | Center of the circular arc. |
