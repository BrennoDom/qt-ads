# ST_GearInPosCAOptions

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# ST\_GearInPosCAOptions

The options can be set to specialize the synchronization profile of the slave.

```
TYPE ST_GearInPosCAOptions :  
STRUCT  
    AfterSyncVelocity                : MC_LREAL := MC_DEFAULT;  
    AfterSyncAcceleration            : MC_LREAL := MC_DEFAULT;  
    AfterSyncDeceleration            : MC_LREAL := MC_DEFAULT;  
    AfterSyncJerk                    : MC_LREAL := MC_DEFAULT;  
    MasterVelocityUndershootAllowed  : BOOL := TRUE;  
    MasterVelocityOvershootAllowed   : BOOL := TRUE;  
    MinimalSlavePosition             : MC_LREAL := MC_IGNORE;  
    DirectionReversalAllowed         : BOOL := TRUE;  
    OverrideSlaveDynamicRestrictions : BOOL := FALSE;  
    GapControlMode                   : MC_GAP_CONTROL_MODE := mcGapControlModeGroupDefault;  
    SlaveSyncPositionReferenceSystem : OTCID := 0;  
    DynamicsReferenceSystem          : OTCID := 0;  
END_STRUCT  
END_TYPE
```

| **Name** | **Type** | **Description** |
| --- | --- | --- |
| AfterSyncVelocity  (From V3.1.10.1) | MC\_LREAL | Maximum velocity of the slave axis after it has synchronized for the first time. The velocity is limited by the maximum velocity of the slave axis. If there is no input value, the default value is set (see CA group parameter GearInPosAfterSyncDynamics). |
| AfterSyncAcceleration  (From V3.1.10.1) | MC\_LREAL | Maximum acceleration of the slave axis after it has synchronized for the first time. The acceleration is limited by the maximum acceleration of the slave axis. If there is no input value, the default value is set (see CA group parameter GearInPosAfterSyncDynamics). |
| AfterSyncDeceleration  (From V3.1.10.1) | MC\_LREAL | Maximum deceleration of the slave axis after it has synchronized for the first time. The deceleration is limited by the maximum deceleration of the slave axis. If there is no input value, the default value is set (see CA group parameter GearInPosAfterSyncDynamics). |
| AfterSyncJerk  (From V3.1.10.1) | MC\_LREAL | Maximum jerk of the slave axis after it has synchronized for the first time. The jerk is not limited by other jerk values (a maximum jerk of the axis cannot be configured). If there is no input value, the default value is set (see CA group parameter GearInPosAfterSyncDynamics). |
| MasterVelocityUndershootAllowed | BOOL | This option only affects the synchronization profile and has no effect once the slave is InSync.  TRUE: No restrictions for the profile  FALSE: The slave velocity during the synchronization phase is always greater than or equal to the master velocity. If the slave velocity is lower than the master velocity at the time the command is issued, the slave accelerates with its synchronization dynamics to reach the master velocity as quickly as possible.  MasterVelocityUndershootAllowed and MasterVelocityOvershootAllowed cannot both be set to FALSE. |
| MasterVelocityOvershootAllowed | BOOL | This option only affects the synchronization profile and has no effect once the slave is InSync.  TRUE: No restrictions for the profile.  FALSE: The slave velocity during the synchronization phase is always less than or equal to the master velocity. If the slave velocity is greater than the master velocity at the time the command is issued, the slave decelerates with its synchronization dynamics in order to reach the master velocity.  MasterVelocityUndershootAllowed and MasterVelocityOvershootAllowed cannot both be set to FALSE. |
| MinimalSlavePosition | MC\_LREAL | Absolute minimum position of the slave during the synchronization phase. This option only affects the synchronization profile and has no effect once the slave is In-Sync. |
| DirectionReversalAllowed | BOOL | This option only affects the synchronization profile and has no effect once the slave is InSync.  TRUE: No restrictions for the profile.  FALSE: The direction is determined by the sign of the slave velocity in the SlaveSyncPosition (gear ratio \* master velocity). The slave must not move in the opposite direction. |
| OverrideSlaveDynamicRestrictions | BOOL | This option only affects the synchronization profile and has no effect once the slave is InSync. It only has an effect if the strategies mcSyncStrategyLate or mcSyncStrategySlow are used.  FALSE: The synchronization profile is recalculated each time the master velocity changes. An error may occur if no valid synchronization profile can be generated within the dynamic limits specified in the GearInPosCA function block. In particular, a noisy master signal can lead to such an error (e.g. encoder axis). Furthermore, a high load may result if the master velocity changes frequently, e.g. if the master accelerates or decelerates, or if the master signal is noisy.  TRUE: The synchronization profile is not necessarily recalculated when the velocity of the master changes. Instead, the originally calculated profile is stretched or compressed. This avoids the errors described above (see FALSE). However, this could lead to violation of the dynamic limits specified in the GearInPosCA function block (the maximum axis dynamic limits are not violated). This option can be used for synchronization to a noisy master axis (e.g. encoder axis) and can also reduce the computing time. |
| GapControlMode | MC\_GAP\_CONTROL\_MODE | See the description of the data type [MC\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-0e9a-45b7-a3fc-2f744339d69e) for further information. |
| SlaveSyncPositionReferenceSystem  (From V3.1.6.03) | OTCID | * This input is of type `OTCID` and can therefore refer to a mover template. * For the position reference of a synchronized slave axis to the XTS motor path, the input `SlaveSyncPositionReferenceSystem` can be left open or set to the value zero so that compatibility with earlier versions of this function block is maintained. * For the position reference of a synchronized slave axis to the path defined by a mover template object, set `SlaveSyncPositionReferenceSystem` to its object ID. The position input for the synchronized slave axis is then interpreted according to the offset path. |
| DynamicsReferenceSystem  (From V3.1.6.03) | OTCID | * This input is of type `OTCID` and can therefore refer to a mover template. * For the dynamic reference to the XTS motor path, the input `DynamicsReferenceSystem` can be left open or set to the value zero so that compatibility with earlier versions of this function block is maintained. * For the dynamic reference to the path defined by a mover template object, set `DynamicsReferenceSystem` to its object ID. The dynamics of the motion profile is then restricted to the given path. |

|  |  |
| --- | --- |
| 39903442 | Restricting the synchronization profile could make synchronization impossible for the slave.  If synchronization is impossible, [MC\_GearInPosCA](ms-xhelp:///?Id=beckhoff-2bf6-4f70-9a09-385499e1b775) issues an error. |

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
