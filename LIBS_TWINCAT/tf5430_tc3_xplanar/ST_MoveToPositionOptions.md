# ST_MoveToPositionOptions

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# ST\_MoveToPositionOptions

Options for the "MoveToPosition" command of the Planar Mover.

## Syntax

Definition:

```
TYPE ST_MoveToPositionOptions :  
STRUCT  
    useOrientation : BOOL;  
END_STRUCT  
END_TYPE
```

## Parameters

| Name | Type | Default | Description |
| --- | --- | --- | --- |
| useOrientation | BOOL | TRUE | If true, the target orientation is also reached at the end of the movement. |
