# ST_GearInPosOnTrackWithMasterMoverOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_GearInPosOnTrackWithMasterMoverOptions

Options for the "GearInPosOnTrackWithMasterMover" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_GearInPosOnTrackWithMasterMoverOptions :  
STRUCT  
    gap                               : LREAL;  
    inSyncToleranceDistance           : LREAL;  
    directionSlaveSyncPosition        : MC_DIRECTION;  
    moduloToleranceSlaveSyncPosition  : LREAL;  
    directionMasterSyncPosition       : MC_DIRECTION;  
    moduloToleranceMasterSyncPosition : LREAL;  
    allowedSlaveSyncDirections        : MC_SYNC_DIRECTIONS;  
    followMover                       : BOOL;  
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
| directionMasterSyncPosition | [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-ee04-4125-b357-222e1abbc081) | MC\_DIRECTION.mcDirectionNonModulo | Direction in which the master sync position is approached. |
| moduloToleranceMasterSyncPosition | LREAL | 0.0 | Tolerance "window" for master sync position. |
| allowedSlaveSyncDirections | [MC\_SYNC\_DIRECTIONS](ms-xhelp:///?Id=beckhoff-6992-428c-8d40-08670f9fab2d) | MC\_SYNC\_DIRECTIONS.Positive | Directions in which the slave is allowed to move while in synchronizing phase. |
| followMover | BOOL | FALSE | If true, the slave PlanarMover will proceed to follow the master PlanarMover after the latter has traversed the masterSyncPosition. In this case the PlanarTrackTrail describes the slave's path towards the masterSyncPosition. If false, the slave moves exclusively on the PlanarTrackTrail specified. |
