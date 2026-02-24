# MC_SYNC_MODE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_SYNC\_MODE

```
(* Defines the direction of the synchronization position of modulo axes. *)  
TYPE MC_SYNC_MODE :  
(  
    mcSyncModeNonModulo         := 0, (* SyncSlavePosition is interpreted as absolute position. *)  
    mcSyncModePositive          := 1, (* Synchronizes in positive direction. *)  
    mcSyncModeNegative          := 3 (* Synchronizes in negative direction. *)  
)  
END_TYPE
```

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 58447079 | 56261663 | 36592919 |

The value defines the direction in which synchronization is to be performed. The SyncMode specification is only effective if a modulo coordinate system has been defined for the axis. This can be a closed XTS track or a closed CA group, for example. The value is ignored if there is only one mathematical solution for reaching the synchronous position.

**mcSyncModeNonModulo:** The SlaveSyncPosition is always interpreted as an absolute position.

**mcSyncModePositive:** The slave axis synchronizes itself in positive direction of movement.

**mcSyncModeNegative:** The slave axis synchronizes itself in negative direction of movement.

## Requirements

| Development environment | Target platform | PLC libraries  to include |
| --- | --- | --- |
| TwinCAT V3.1.4024.7  TF5400 Advanced Motion Pack V3.1.10.1 | PC or  CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
