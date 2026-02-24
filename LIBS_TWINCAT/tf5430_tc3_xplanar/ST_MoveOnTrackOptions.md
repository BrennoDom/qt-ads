# ST_MoveOnTrackOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_MoveOnTrackOptions

Options for the "MoveOnTrack" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_MoveOnTrackOptions :  
STRUCT  
    gap             : LREAL;  
    direction       : MC_DIRECTION;  
    additionalTurns : UDINT;  
    moduloTolerance : LREAL;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| gap | LREAL | 200.0 | Minimal distance to next Planar Mover on track. |
| direction | [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-ee04-4125-b357-222e1abbc081) | MC\_DIRECTION.mcDirectionNonModulo | Direction in which the target is approached. |
| additionalTurns | UDINT | 0 | Addition turns to move in modulo movement (positive or negative). |
| moduloTolerance | LREAL | 0.0 | Tolerance "window" in modulo movement. |
