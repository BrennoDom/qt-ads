# SetPosition

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# SetPosition

SetPosition commandFeedback  MC\_PlanarFeedback↔position  PositionXYC

Sets the position of the Planar Mover. Only possible if the Planar Mover is disabled.

## Syntax

Definition:

```
METHOD SetPosition  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR  
VAR_IN_OUT  
    position        : PositionXYC;  
END_VAR
```

## 64180012 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |

## 40749199 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| position | PositionXYC | New position of the Planar Mover. |
