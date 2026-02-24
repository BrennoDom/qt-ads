# LeaveTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# LeaveTrack

LeaveTrack commandFeedback  MC\_PlanarFeedbackconstraint  IPlcDynamicConstraintoptions  ST\_LeaveTrackOptions↔targetPosition  PositionXYC

Initiates a direct movement to the specified position. At the beginning of the movement the track is left.

## Syntax

Definition:

```
METHOD LeaveTrack  
VAR_INPUT  
    commandFeedback : MC_PlanarFeedback;  
    constraint      : IPlcDynamicConstraint;  
    options         : ST_LeaveTrackOptions;  
END_VAR  
VAR_IN_OUT  
    targetPosition  : PositionXYC;  
END_VAR
```

## 27321283 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| constraint | IPlcDynamicConstraint | Dynamic constraints for this movement. |
| options | [ST\_LeaveTrackOptions](ms-xhelp:///?Id=beckhoff-9b33-4494-9497-ccdc52f0047a) | Options for the movement. |

## 44564956 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| targetPosition | PositionXYC | Target position for the movement. |
