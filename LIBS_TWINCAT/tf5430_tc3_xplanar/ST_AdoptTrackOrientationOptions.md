# ST_AdoptTrackOrientationOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_AdoptTrackOrientationOptions

Options for the "AdoptTrackOrientation" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_AdoptTrackOrientationOptions :  
STRUCT  
    additionalTurns : UDINT;  
    direction       : MC_DIRECTION;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| additionalTurns | UDINT | 0 | Addition turns to move in modulo movement (positive or negative). |
| direction | [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-ee04-4125-b357-222e1abbc081) | MC\_DIRECTION.mcDirectionShortestWay | Direction in which the target is approached. |
