# AddTrack

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# AddTrack

AddTrack ↔track  MC\_PlanarTrack

Adds a track to the TrackTrail. The track should start at the end vertex of the currently last track.

## Syntax

Definition:

```
METHOD AddTrack  
VAR_IN_OUT  
    track : MC_PlanarTrack;  
END_VAR
```

## 10238520 In/Outputs

| Name | Type | Description |
| --- | --- | --- |
| track | [MC\_PlanarTrack](ms-xhelp:///?Id=beckhoff-5a3b-4ca2-80dd-8d28b67380a1) | The track to be added to the end of the TrackTrail. |
