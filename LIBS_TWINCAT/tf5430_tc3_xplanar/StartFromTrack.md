# StartFromTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# StartFromTrack

StartFromTrack commandFeedback  MC\_PlanarFeedback↔track  MC\_PlanarTrack

Sets the other Planar Tracks endpoint as start point of this Planar Track, transition is smooth. The other Planar Track is blocked for further changes (until it is cleared).

## Syntax

Definition:

```
METHOD StartFromTrack  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
END_VAR  
VAR_IN_OUT  
    track           : MC_PlanarTrack;  
END_VAR
```

## 7759225 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |

## 2724161 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| track | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | The other Planar Track. |
