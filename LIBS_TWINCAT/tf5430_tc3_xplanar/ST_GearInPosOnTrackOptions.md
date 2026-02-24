# ST_GearInPosOnTrackOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_GearInPosOnTrackOptions

Options for the "GearInPosOnTrack" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_GearInPosOnTrackOptions :  
STRUCT  
    gap                              : LREAL;  
    inSyncToleranceDistance          : LREAL;  
    directionSlaveSyncPosition       : MC_DIRECTION;  
    moduloToleranceSlaveSyncPosition : LREAL;  
    allowedSlaveSyncDirections       : MC_SYNC_DIRECTIONS;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| gap | LREAL | 200.0 | Minimal distance to next Planar Mover on track. |
| inSyncToleranceDistance | LREAL | 0.0 | Tolerance in absolute value of position difference to master axis for inSync flag. |
| directionSlaveSyncPosition | [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-ee04-4125-b357-222e1abbc081) | MC\_DIRECTION.mcDirectionNonModulo | Direction in which the slave sync position is approached. |
| moduloToleranceSlaveSyncPosition | LREAL | 0.0 | Tolerance "window" for slave sync position. |
| allowedSlaveSyncDirections | [MC\_SYNC\_DIRECTIONS](ms-xhelp:///?Id=beckhoff-6992-428c-8d40-08670f9fab2d) | MC\_SYNC\_DIRECTIONS.Positive | Directions in which the slave is allowed to move while in synchronizing phase. |
