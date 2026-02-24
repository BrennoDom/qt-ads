# MoveOnTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MoveOnTrack

MoveOnTrack commandFeedback  MC\_PlanarFeedbacktargetTrack  MC\_PlanarTracktargetPositionOnTrack  LREALconstraint  DynamicConstraint\_PathXYoptions  ST\_MoveOnTrackOptions

Initiates a movement on the track to the specified position and returns command ID.

## Syntax

Definition:

```
METHOD MoveOnTrack  
VAR_INPUT  
    commandFeedback       : MC_PlanarFeedback;  
    targetTrack           : MC_PlanarTrack;  
    targetPositionOnTrack : LREAL;  
    constraint            : DynamicConstraint_PathXY;  
    options               : ST_MoveOnTrackOptions;  
END_VAR
```

## 65540286 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedback](ms-xhelp:///?Id=beckhoff-ad16-40d3-a9c8-f233f20a5661) | The feedback object for the command. |
| targetTrack | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | Target track for the movement. If none is specified, this defaults to the current track. |
| targetPositionOnTrack | LREAL | Target position on the target track. |
| constraint | DynamicConstraint\_PathXY | Constraint on maximal dynamics during the movement (V,A,D,J). |
| options | [ST\_MoveOnTrackOptions](ms-xhelp:///?Id=beckhoff-5f58-4097-a3d2-9e32db9bdf4e) | Options for the movement. |
