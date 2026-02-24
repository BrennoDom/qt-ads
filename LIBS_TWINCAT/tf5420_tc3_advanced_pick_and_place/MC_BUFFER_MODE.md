# MC_BUFFER_MODE

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_BUFFER\_MODE

The data type MC\_BUFFER\_MODE is used to specify how successive travel commands are to be processed. At least two function blocks are required for buffer mode to have an effect.

```
TYPE MC_BUFFER_MODE :  
(  
    mcAborting                        := 16#0,  
    mcBuffered                        := 16#1,  
    mcBlendingLow                     := 16#12,  
    mcBlendingPrevious                := 16#13,  
    mcBlendingNext                    := 16#14,  
    mcBlendingHigh                    := 16#15  
) UINT;  
END_TYPE
```

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 24632334 | 20364417 | 49062032 |

**Example**:

In the following example, a move command is used to move a group from position P0 to P1 and then to P2. The reference point for the different velocity profiles is always P1. The mode specifies the velocity v1 or v2 at this point.

![38905106](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/9007199325099403__en-US__Web.png)

Since the speed of the first command is lower than the second, the modes BlendingLow/BlendingPrevious and BlendingHigh/BlendingNext have the same result.

If the speed of the second command is lower than the first the modes BlendingLow/BlendingNext and BlendingHigh/BlendingPrevious are equivalent.

![14601642](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/18014399559118475__en-US__Web.png)

## Combinations of buffer mode and transition mode

Note Buffer mode and transition mode are merely combined using TF5420.

The following table shows possible combinations of transition mode and buffer mode and its effect.

| TM/BM | mcAborting | mcBuffered | mcBlendingPrevious | Other |
| --- | --- | --- | --- | --- |
| **mcTransModeNone** | Previous command is aborted immediately. New movement is started. Velocity in transition is 0. This combination is only allowed for the 1st segment of a path. | Stop at the end of previous command. Subsequently next command is executed. | Not allowed | Not allowed |
| **mcTransModeCornerDistance**  new from V3.1.10.1, only compatible with MC Group Coordinated Motion | Blending from active segment to first segment of new command. The intersection point of the segments is defined by the distance needed to stop on the active segment. This combination is only allowed for the 1st segment of a path. | Not allowed | Blending from last programmed command to new command | Not allowed |
| **mcTransModeCornerDistanceAdvanced** | Blending from active segment to first segment of new command. The intersection point of the segments is defined by the distance needed to stop on the active segment. This combination is only allowed for the 1st segment of a path. | Not allowed | Blending from last programmed command to new command | Not allowed |
| **Other** | Not allowed | Not allowed | Not allowed | Not allowed |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCoordinatedMotion, Tc2\_MC2 |
