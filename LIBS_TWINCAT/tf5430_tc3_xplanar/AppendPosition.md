# AppendPosition

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AppendPosition

AppendPosition commandFeedback  MC\_PlanarFeedback↔position  PositionXYC

Appends a position to the Planar Track.

## Syntax

Definition:

```
METHOD AppendPosition  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR  
VAR_IN_OUT  
    position        : PositionXYC;  
END_VAR
```

## 43140785 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |

## 52722752 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| position | PositionXYC | Position that is the new endpoint of the Planar Track. |
