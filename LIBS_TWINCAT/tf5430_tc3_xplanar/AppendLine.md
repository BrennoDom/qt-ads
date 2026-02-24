# AppendLine

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AppendLine

AppendLine commandFeedback  MC\_PlanarFeedback↔start  PositionXYC↔end  PositionXYC

Appends a line to the Planar Track.

## Syntax

Definition:

```
METHOD AppendLine  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR  
VAR_IN_OUT  
    start           : PositionXYC;  
    end             : PositionXYC;  
END_VAR
```

## 4742722 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |

## 42684506 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| start | PositionXYC | Start position of the line. |
| end | PositionXYC | End position of the line, this position is the new endpoint of the Planar Track. |
