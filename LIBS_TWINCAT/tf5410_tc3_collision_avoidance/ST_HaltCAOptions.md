# ST_HaltCAOptions

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# ST\_HaltCAOptions

```
TYPE ST_HaltCAOptions :  
STRUCT  
    GapControlMode          : MC_GAP_CONTROL_MODE := mcGapControlModeGroupDefault;  
    DynamicsReferenceSystem : OTCID := 0;  
END_STRUCT  
END_TYPE
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| GapControlMode | MC\_GAP\_CONTROL\_MODE | See the description of the data type [MC\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-0e9a-45b7-a3fc-2f744339d69e) for further information. |
| DynamicsReferenceSystem  (From V3.1.6.03) | OTCID | * This input is of type `OTCID` and can therefore refer to a mover template. * For the dynamic reference to the XTS motor path, the input `DynamicsReferenceSystem` can be left open or set to the value zero so that compatibility with earlier versions of this function block is maintained. * For the dynamic reference to the path defined by a mover template object, set `DynamicsReferenceSystem` to its object ID. The dynamics of the motion profile is then restricted to the given path. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
