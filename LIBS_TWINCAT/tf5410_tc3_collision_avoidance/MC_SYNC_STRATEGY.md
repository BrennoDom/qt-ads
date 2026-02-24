# MC_SYNC_STRATEGY

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_SYNC\_STRATEGY

The data type MC\_SYNC\_STRATEGY defines the synchronization profile of the slave for e.g. a MC\_GearInPosCA-command.

```
TYPE MC_SYNC_STRATEGY :  
(  
    mcSyncStrategyLate              := 16#1,  
    mcSyncStrategySlow              := 16#2,  
    mcSyncStrategyEarly             := 16#3  
)  
END_TYPE
```

| TF5410 TwinCAT 3 Motion Collision Avoidance | TF5420 TwinCAT 3 Motion Pick-and-Place | |
| --- | --- | --- |
| MC Group with Pick-and-Place | MC Group Coordinated Motion |
| 60900816 | 11236435 | 34019058 |

## Examples:

The boundary conditions in the following examples are equal:

* The master motion is equal
* The MasterStartDistance is equal.
* The distances (MasterSyncPosition – current master position) and (SlaveSyncPosition – current slave position) are in all three examples equal.
* The slave dynamics are equal.
* Configuration with one axis in the CA Group, one PTP axis as master.
* A motion command is issued to the master

**Example 1: mcSyncStrategyLate**

The slave starts the synchronization as late as possible and with full dynamics (according to the input values velocity, acceleration, deceleration, jerk). It reaches the SlaveSyncPosition just in time with the correct gear ratio. The user has to take care that the master does not accelerate once the slave signals StartSync, since the synchronization profile is already planned with the maximal slave dynamic. The slave cannot violate its dynamic restrictions and therefore cannot compensate any master acceleration, this situation will result in an error at the FB.

:   1. Issue command MC\_GearInPosCA to axis. The Command becomes active while the master is still accelerating.

:   The slave starts synchronizing as late as possible and with full dynamics, and reached the SlaveSyncPosition when the master reached the MasterSyncPosition (black x-Cursor).

![37736068](/tf5410_tc3_collision_avoidance/1033/Images/png/1539883403__Web.png)

**Example 2: mcSyncStrateySlow**

The slave starts its sync in motion as soon as the master passes (MasterSyncPosition - MasterStartDistance) in the right direction if a MasterStartDist was set, otherwise as soon as the FB is Active. The dynamics of the slave is reduced such that the slave reaches the SlaveSyncPos with the correct gear ratio just in time when the master reaches the MasterSyncPos.The slave can compensate an acceleration of the master once StartSync is set, but only until the slave reaches its maximum dynamics.

:   1. Issue command MC\_GearInPosCA to axis. The Command becomes active while the master is still accelerating.

:   The slave starts synchronizing as soon as MC\_GearInPosCA is Active. The dynamic is reduced such that the slave reaches the SlaveSyncPosition at the same time the master reaches the MasterSyncPosition (black x-Cursor).

|  |  |
| --- | --- |
| 4080300 | Synchronizing on a standing master can lead to a high load if mcSyncStrategySlow is used.  It is best to use mcSyncStrategyEarly in this case. |

![36722706](/tf5410_tc3_collision_avoidance/1033/Images/png/1539885963__Web.png)

**Example 3: mcSyncStrategyEarly**

The slave starts synchronization immediately (if a MasterStartDistance is set: immediately after it was passed) and with full dynamics. The slave signals earlier InSync than demanded by the SlaveSyncPosition, but it is still guaranteed that demanded offset between master and slave (MasterSyncPosition – SlaveSyncPosition) is reached with the correct gear ratio. This strategy can synchronize on a standing master and is best suited if the master velocity is not constant. The slave will constantly try to synchronize. If the boundary conditions do not allow the slave to be InSync at the SlaveSyncPosition, this will not result in an error but the slave constantly tries to synchronize to the master.

:   1. Issue command MC\_GearInPosCA to axis. The Command becomes active while the master is still accelerating.

:   The slave starts synchronizing as soon as MC\_GearInPosCA is Active and with full dynamics. The slave is InSync as soon as possible, but still reaches the SlaveSyncPosition at the same time the master reaches the MasterSyncPosition (black x-Cursor).

![62068903](/tf5410_tc3_collision_avoidance/1033/Images/png/1540362123__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT V3.1.4018.26  TF5400 Advanced Motion Pack V3.1.1.17 | PC or CX (x86 or x64) | Tc3\_McCollisionAvoidance, Tc3\_McCoordinatedMotion, Tc2\_MC2 |
