# GearInPosOnTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# GearInPosOnTrack

GearInPosOnTrack commandFeedback  MC\_PlanarFeedbackGearInPosOnTrackmasterAxis  OTCIDtrackTrail  MC\_PlanarTrackTrailmasterSyncPosition  LREALslaveSyncPosition  LREALconstraint  DynamicConstraint\_PathXYoptions  ST\_GearInPosOnTrackOptions↔slaveSyncPositionTrack  MC\_PlanarTrack

Initiates a GearInPos movement along a specified trail.

## Syntax

Definition:

```
METHOD GearInPosOnTrack  
VAR_INPUT  
    commandFeedback        : MC_PlanarFeedbackGearInPosOnTrack;  
    masterAxis             : OTCID;  
    trackTrail             : MC_PlanarTrackTrail;  
    masterSyncPosition     : LREAL;  
    slaveSyncPosition      : LREAL;  
    constraint             : DynamicConstraint_PathXY;  
    options                : ST_GearInPosOnTrackOptions;  
END_VAR  
VAR_IN_OUT  
    slaveSyncPositionTrack : MC_PlanarTrack;  
END_VAR
```

## 52991666 Inputs

| Name | Type | Description |
| --- | --- | --- |
| commandFeedback | [MC\_PlanarFeedbackGearInPosOnTrack](ms-xhelp:///?Id=beckhoff-c948-41d4-9572-53214e346d0a) | The command specific feedback object for the command. |
| masterAxis | OTCID | Master axis being followed. |
| trackTrail | [MC\_PlanarTrackTrail](ms-xhelp:///?Id=beckhoff-f67e-403d-818d-3f43f251b5d7) | Track trail determining along which tracks the GearInPos movement is allowed to proceed. |
| masterSyncPosition | LREAL | Position of the master axis at which the slave is inSync. |
| slaveSyncPosition | LREAL | Arc length on track given by slaveSyncPositionTrackOID at which the slave is inSync. Possibly interpreted in modulo fashion, depending on options. |
| constraint | DynamicConstraint\_PathXY | Constraint on maximal dynamics during the movement (V,A,D,J). |
| options | [ST\_GearInPosOnTrackOptions](ms-xhelp:///?Id=beckhoff-e904-4322-982d-ede53f9299ee) | Options for the movement. |

## 7162954 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| slaveSyncPositionTrack | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | Track on which the slave is inSync. |
