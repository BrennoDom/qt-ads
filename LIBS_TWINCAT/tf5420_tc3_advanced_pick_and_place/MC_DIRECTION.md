# MC_DIRECTION

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC\_DIRECTION

```
(* Defines the direction of the movement (e.g. for a modulo axis). *)  
TYPE MC_DIRECTION :  
(  
    mcDirectionNonModulo        := 0, (* Position is interpreted as absolute position. *)  
    mcDirectionPositive         := 1, (* Moves in positive direction. *)  
    mcDirectionShortestWay      := 2, (* The direction of movement depends on whether the positive direction of movement or the negative direction of movement is the shortest distance from the target position. *)  
    mcDirectionNegative         := 3 (* Moves in negative  
                                       direction. *)  
)  
END_TYPE
```

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 37029065 | 64826129 | 46564252 |

MC\_DIRECTION is used to specify the direction of movement during modulo positioning. Modulo positioning is only applicable to periodic systems. For open systems such as open tracks, only the value `mcDirectionNonModulo` is accepted.

**mcDirectionNonModulo:** The position is always interpreted as an absolute position.

**mcDirectionPositive:** Positive direction of movement

**mcDirectionNegative:** Negative direction of movement

**mcDirectionShortestWay:** The direction of movement depends on whether the positive direction or the negative direction has the shortest distance to the target position.

|  |  |
| --- | --- |
| 16425092 | In combination with the Tc2\_MC2 or Tc3\_Mc3Definitions library it is possible that the data type cannot be resolved unambiguously (ambiguous use of name 'MC\_Direction'). In this case the namespace must be specified when using the data type (Tc3\_Mc3PlanarMotion.MC\_DIRECTION or Tc3\_Mc3Definitions.MC\_DIRECTION or Tc2\_MC2.MC\_DIRECTION). |

## Requirements

| Development environment | Target platform | PLC libraries  to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or  CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
