# MC_TRANSITION_MODE

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_TRANSITION\_MODE

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
|  | MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 37593218 | 2794650 | 25151854 |

The transition mode characterizes how a segment transition is executed.

```
TYPE MC_TRANSITION_MODE :  
(  
    mcTransModeNone                          := 16#1000,  
    mcTransModeStartVelocity                 := 16#1001,  
    mcTransModeConstantVelocity              := 16#1002,  
    mcTransModeCornerDistance                := 16#1003,  
    mcTransModeMaxCornerDeviation            := 16#1004,  
    mcTransModeCornerDistanceAdvanced        := 16#100A  
);  
END_TYPE
```

The following table shows an overview of the implemented transition modes and the number of parameters that have to be defined in TransitionParameterCount.

| Name | TransitionParameterCount | Description |
| --- | --- | --- |
| **mcTransModeNone** | No impact | No blending |
| **mcTransModeCornerDistance**  not compatible with MC Group with Pick-and-Place, available from V3.1.10.1 | 1 | TransitionParameter acts as tolerance ball in which the path may be left. |
| **mcTransModeCornerDistanceAdvanced** | 2 | TransitionParameter act as tolerance ball in which the path may be left. |

## mcTransModeNone

No blending is executed. Stop at segment transition.

## mcTransModeCornerDistance

Blending is executed between the segments. The transition parameters act as tolerance ball in which the programmed path is not followed. The parameter describes the radius on the previous and second segment at which the blending starts and ends.

This mode is only compatible with MC Group Coordinated Motion.

## mcTransModeCornerDistanceAdvanced

Blending is executed between the segments. The transition parameter act as tolerance ball in which the programmed path is not followed. The first parameter describes the radius on the previous segment at which the blending starts (r\_in). The second parameter describes the radius on the following segment (r\_out) which defines a position for which it is guaranteed that the blending is done. The parameter r\_out is a maximum value. The blending can end before r\_out is reached.

Blending (r\_in) is limited to 90% of previous segment. R\_out is not limited.

N10N20N30r\_in(N20)r\_out(N20)r\_in(N30)r\_out(N30)

|  |  |
| --- | --- |
| 25040094 | Recommended Transition Parameter Relation for Blending with MC Group with Pick-and-Place  The graphics sketch a planar movement within two dimensional space. Let two axes be involved in this movement. Assuming that the involved axes exhibit similar dynamics `r_out` should measure at least `2 * r_in`. |

## Combinations of buffer mode and transition mode

|  |  |
| --- | --- |
| 24034261 | Buffer mode and transition mode are combined only when TF5420 is used. |

The following table shows the possible combinations of transition mode and buffer mode and their effect.

| TM/PM | mcAborting | mcBuffered | mcBlendingPrevious | Others |
| --- | --- | --- | --- | --- |
| **mcTransModeNone** | The previous command is cancelled immediately. A new movement is started. The velocity in transition is 0. This combination is only permitted for the first segment of a path. | Stop at the end of the previous command. The next command is then executed. | not permissible | not permissible |
| **mcTransModeCornerDistance**  New from V3.1.10.1, only compatible with MC Group Coordinated Motion | Blending from the active segment to the first segment of the new command. The intersection of the segments is defined by the distance needed to stop on the active segment. This combination is only permitted for the first segment of a path. | not permissible | Blending from the last programmed command to the new command | not permissible |
| **mcTransModeCornerDistanceAdvanced** | Blending from the active segment to the first segment of the new command. The intersection of the segments is defined by the distance needed to stop on the active segment. This combination is only permitted for the first segment of a path. | not permissible | Blending from the last programmed command to the new command | not permissible |
| **Others** | not permissible | not permissible | not permissible | not permissible |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
