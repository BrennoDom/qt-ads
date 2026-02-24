# ST_MoveAbsoluteCAOptions

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# ST\_MoveAbsoluteCAOptions

```
TYPE ST_MoveAbsoluteCAOptions :  
STRUCT  
    GapControlMode          : MC_GAP_CONTROL_MODE := mcGapControlModeGroupDefault;  
    PositionReferenceSystem : OTCID := 0;  
    DynamicsReferenceSystem : OTCID := 0;  
    AdditionalTurns         : UDINT := 0;  
END_STRUCT  
END_TYPE
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| GapControlMode | MC\_GAP\_CONTROL\_MODE | See the description of the data type [MC\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-0e9a-45b7-a3fc-2f744339d69e) for further information. |
| PositionReferenceSystem  (from V3.1.6.03) | OTCID | * This input is of type `OTCID` and can therefore refer to a mover template. * For the position reference to the XTS motor path, the input `PositionReferenceSystem` can be left open or set to the value zero so that compatibility with earlier versions of this function block is maintained. * For the position reference to the path defined by a mover template object, set `PositionReferenceSystem` to its object ID. The position input is then interpreted according to the offset path. |
| DynamicsReferenceSystem  (from V3.1.6.03) | OTCID | * This input is of type `OTCID` and can therefore refer to a mover template. * For the dynamic reference to the XTS motor path, the input `DynamicsReferenceSystem` can be left open or set to the value zero so that compatibility with earlier versions of this function block is maintained. * For the dynamic reference to the path defined by a mover template object, set `DynamicsReferenceSystem` to its object ID. The dynamics of the motion profile is then restricted to the given path. |
| AdditionalTurns  (from V3.1.10.30) | UDINT | * This input is used to command additional full turns. * `AdditionalTurns` may only be used (assume a value > 0) if:  + `Direction = mcDirectionPositive` or + `Direction = mcDirectionNegative` .  * If positioning is performed using modulo, i.e. if `Direction` assumes one of the following three values {`mcDirectionPositive, mcDirectionNegative, ShortestWay`}, from V3.1.10.30 the TargetPosition must be in the `Interval [0, ModuloFaktor]`. This is a departure from previous behavior. Before the introduction of the parameter `AdditionalTurns`, additional turns were commanded by commanding larger target positions than the modulo factor.  **Example:**ModuloFactor = 360, StartPosition = 5; 2 complete turns are to be commanded and moved to position 10:  + Up to V3.1.10.14`:` TargetPosition = 730 + From V3.1.10`.`30`:` TargetPosition = 10, AdditionalTurns = 2  * Furtherdetails in the notes on [Modulo positioning](ms-xhelp:///?Id=beckhoff-b707-4905-b887-f0cfc84eafbd). |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
