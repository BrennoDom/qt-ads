# NcToPlc

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# NcToPlc

The structure is divided in a common data and a group specific data.

## Common

**GroupOID**: TcCOM-Object-Id (OID) of this Group.

**GroupType**: Type of this Group: 0 = Invalid (mcGroupTypeInvalid), 1 = CollisionAvoidance(mcGroupTypeCA), 2 = DXD/CNC (mcGroupTypeDxd).

**GroupStatus**: Contains information about the group status (see [GroupStatus](ms-xhelp:///?Id=beckhoff-892b-44d6-8ea2-407e79e859eb)).

**GroupErrorId**: Current Error Identifier (0 = no error).

**GroupAxesCount**: Number of Axes that are currently part of this Group (e.g. added via MC\_AddAxisToGroup).

## GroupStatus**:**

**State**: See Group State Diagram.

1 = Disabled (mcGroupStateDisabled)  
 2 = Standby (mcGroupStateStandby)  
 3 = Moving (mcGroupStateMoving)  
 4 = Stopping (mcGroupStateStopping)  
 5 = ErrorStop (mcGroupStateErrorStop)  
 6 = Homing (mcGroupStateHoming)  
 7 = NotReady (mcGroupStateNotReady)  
 8 = Suspended (mcGroupStateSuspended)

**Flags**: Additional status information.

*IsEnableRequested*: Defines if group is requested to be enabled or disabled.

## Dxd (multi-dimensional movement)

**PathVelo**: Velocity on path without direction.

**InvokeId**: Segment Id for analysis purpose.

## CM (MC Group Coordinated Motion)

available from V3.1.10.1

**PathVelo:** Absolute value of cartesian speed on the path.

**InvokeId:** Segment Id for analysis purpose.

**IsInBlendingSegment:** Indicates if a blending segment is active.

**RemainingTimeActiveJob:** Remaining time of the current segment.

**RemainingCartesianDistanceActiveJob:** Remaining distance for the current segment.

**ActiveBlockerId:** Id of the active blocker.
