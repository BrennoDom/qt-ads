# MC_DEFAULT_GAP_CONTROL_MODE

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_DEFAULT\_GAP\_CONTROL\_MODE

The [Gap Control Mode](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973) specifies the behavior of the Collision Avoidance. Following modes are available:

```
TYPE MC_DEFAULT_GAP_CONTROL_MODE :  
(  
    mcGapCtrlModeStandard              := 16#1,  
    mcGapCtrlModeFast                  := 16#2  
)  
END_TYPE
```

## Examples

**Example mcGapCtrlModeStandard:**

:   Configuration with four axes (mover) in the CA Group. The [Rail Length](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973) is 3000mm and the rail is closed (e.g. XTS-system).
:   The first axis in line (blue) is standing at position 0.0mm, the remaining three axes are lined up behind with a respective gap of 100mm.
:   The Gap Control Mode is set to mcGapCtrlModeStandard.

:   1. MC\_MoveAbsoluteCA is issued to all axes to the Position 3000mm, the Gap is 100mm. All Axes have the same dynamics (Velocity, Acceleration, Deceleration, Jerk).

:   The axes fan out characteristically during the acceleration phase, such that a collision during the motion command is prevented. The first axis (blue) reaches the target position, the remaining axes line up successively with the configured [Default Gap](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973).

![21153717](/tf5410_tc3_collision_avoidance/1033/Images/png/1539507339__Web.png)

**Example mcGapCtrlModeFast:**

:   Configuration with four axes (mover) in the CA Group. The RailLength is 3000mm and the rail is closed (XTS-system).
:   The first axis in line (blue) is standing at position 0.0mm. The remaining three axes are lined up behind with a respective gap of 100mm.
:   The Gap Control Mode is set to mcGapCtrlModeFast

:   1. MC\_MoveAbsoluteCA is issued to all axes to the Position 3000mm, the Gap is 100mm. All Axes have the same dynamics (Velocity, Acceleration, Deceleration, Jerk).

:   All Axes move at the same time and with the full dynamics. The gap between the axes is kept nearly constant. The first axis reached the target position, the rest lines up behind.

![56165728](/tf5410_tc3_collision_avoidance/1033/Images/png/1539875211__Web.png)
