# MC_COMPENSATION_TYPE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_COMPENSATION\_TYPE

The data type MC\_COMPENSATION\_TYPE is used to specify which compensation type is to be used.

```
TYPE MC_ COMPENSATION_TYPE:  
(  
    mcTypeInvalidCompensation            := 16#0,  
    mcTypeGeoCompensation                := 16#1,  
)UINT;  
END_TYPE
```

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 3925534 | 35329809 | 49532829 |

## Requirements

| Development environment | Target platform | PLC libraries  to include |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.6.07 | PC or CX (x86 or x64) | Tc3\_McCompensations |
