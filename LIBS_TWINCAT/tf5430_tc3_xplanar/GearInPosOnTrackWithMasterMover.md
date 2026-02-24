# GearInPosOnTrackWithMasterMover

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# GearInPosOnTrackWithMasterMover

GearInPosOnTrackWithMasterMover commandFeedback  MC\_PlanarFeedbackGearInPosOnTrackWithMasterMovertrackTrail  MC\_PlanarTrackTrailmasterSyncPosition  LREALslaveSyncPosition  LREALconstraint  DynamicConstraint\_PathXYoptions  ST\_GearInPosOnTrackWithMasterMoverOptions↔masterMover  MC\_PlanarMover↔masterSyncPositionTrack  MC\_PlanarTrack↔slaveSyncPositionTrack  MC\_PlanarTrack

Initiates a GearInPos movement along a specified trail, in which the master setpoints are provided by another PlanarMover.

## Syntax

Definition:

```
METHOD GearInPosOnTrackWithMasterMover  
VAR_INPUT  
    commandFeedback         : MC_PlanarFeedbackGearInPosOnTrackWithMasterMover;  
    trackTrail              : MC_PlanarTrackTrail;  
    masterSyncPosition      : LREAL;  
    slaveSyncPosition       : LREAL;  
    constraint              : DynamicConstraint_PathXY;  
    options                 : ST_GearInPosOnTrackWithMasterMoverOptions;  
END_VAR  
VAR_IN_OUT  
    masterMover             : MC_PlanarMover;  
    masterSyncPositionTrack : MC_PlanarTrack;  
    slaveSyncPositionTrack  : MC_PlanarTrack;  
END_VAR
```

## 64466590 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedbackGearInPosOnTrackWithMasterMover](ms-xhelp:///?Id=beckhoff-b66b-4cde-ad9f-f416ff17f575) | The command specific feedback object for the command. |
| trackTrail | [MC\_PlanarTrackTrail](ms-xhelp:///?Id=beckhoff-f67e-403d-818d-3f43f251b5d7) | Track trail determining along which tracks the GearInPos movement is allowed to proceed. |
| masterSyncPosition | LREAL | Position of the master axis at which the slave is inSync. |
| slaveSyncPosition | LREAL | Arc length on track given by slaveSyncPositionTrackOID at which the slave is inSync. Possibly interpreted in modulo fashion, depending on options. |
| constraint | DynamicConstraint\_PathXY | Constraint on maximal dynamics during the movement (V,A,D,J). |
| options | [ST\_GearInPosOnTrackWithMasterMoverOptions](ms-xhelp:///?Id=beckhoff-fd0a-47f3-ba93-2d6f6d325b03) | Options for the movement. |

## 43328398 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| masterMover | [MC\_PlanarMover](ms-xhelp:///?Id=beckhoff-17ff-49fc-b7b2-ab81fc3dce87) | Master mover being followed. |
| masterSyncPositionTrack | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | Track on which the master is inSync. |
| slaveSyncPositionTrack | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | Track on which the slave is inSync. |
