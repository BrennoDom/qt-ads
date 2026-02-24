# ST_JoinTrackOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_JoinTrackOptions

Options for the "JoinTrack" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_JoinTrackOptions :  
STRUCT  
    useOrientation : BOOL;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| useOrientation | BOOL | TRUE | If true, the target orientation is also reached at the end of the movement. |
