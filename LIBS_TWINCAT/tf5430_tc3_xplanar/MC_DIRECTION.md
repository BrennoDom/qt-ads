# MC_DIRECTION

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# MC\_DIRECTION

Indicates the movement direction of the Planar Mover on a Planar Track.

## Syntax

Definition:

```
TYPE MC_DIRECTION :  
(  
    mcDirectionNonModulo   := 0,  
    mcDirectionPositive    := 1,  
    mcDirectionShortestWay := 2,  
    mcDirectionNegative    := 3  
)UINT;  
END_TYPE
```

## Values

| Name | Description |
| --- | --- |
| mcDirectionNonModulo | The Planar Mover moves to the absolute value of the target position. Depending on the current position, this may induce forward or backward movement. On looped tracks, multiple passes are possible. |
| mcDirectionPositive | The Planar Mover moves to the target position in a forward direction. No backward movement is allowed. |
| mcDirectionShortestWay | The Planar Mover takes the shortest way to the target position. May induce forward or backward movement. |
| mcDirectionNegative | The Planar Mover moves to the target position in a backward direction. No forward movement is allowed. |

|  |  |
| --- | --- |
| 19134881 | In combination with the Tc2\_MC2 library it is possible that the data type cannot be resolved uniquely (ambiguous use of name 'MC\_Direction'). In this case you have to specify the namespace when using the data type (Tc3\_Mc3PlanarMotion.MC\_DIRECTION, Tc3\_Mc3Definitions.MC\_DIRECTION or Tc2\_MC2.MC\_DIRECTION). |
