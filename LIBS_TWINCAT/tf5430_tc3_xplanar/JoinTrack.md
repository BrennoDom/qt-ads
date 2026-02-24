# JoinTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# JoinTrack

JoinTrack commandFeedback  MC\_PlanarFeedbackconstraint  IPlcDynamicConstraintoptions  ST\_JoinTrackOptions↔targetTrack  MC\_PlanarTrack

Initiates a direct movement to the specified track. At the end of the movement the mover joins the track.

## Syntax

Definition:

```
METHOD JoinTrack  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    constraint      : IPlcDynamicConstraint;  
    options         : ST_JoinTrackOptions;  
END_VAR  
VAR_IN_OUT  
    targetTrack     : MC_PlanarTrack;  
END_VAR
```

## 7793840 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
| options | [ST\_JoinTrackOptions](ms-xhelp:///?Id=beckhoff-9796-47bc-8115-3316cb2f8c8f) | Options for the movement. |

## 3035698 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| targetTrack | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | Target track for the movement. |
