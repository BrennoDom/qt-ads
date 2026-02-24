# MC_SYNC_DIRECTIONS

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_SYNC\_DIRECTIONS

Directions in which a slave is allowed to move during synchronizing phase.

## Syntax

Definition:

```
TYPE MC_SYNC_DIRECTIONS :  
(  
    Invalid  := 0,  
    Positive := 1,  
    Negative := 2,  
    Both     := 3  
)UINT;  
END_TYPE
```

## Values

| Name | Description |
| --- | --- |
| Invalid | Indicates invalid information, e.g. no connection or component not yet ready. |
| Positive | Movement is allowed only in positive direction while synchronizing. |
| Negative | Movement is allowed only in negative direction while synchronizing. |
| Both | Movement is allowed in any direction while synchronizing. |
