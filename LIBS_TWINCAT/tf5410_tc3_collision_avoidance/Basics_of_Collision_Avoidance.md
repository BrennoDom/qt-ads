# Basics of Collision Avoidance

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Basics of Collision Avoidance

:   All objects (CA Group and all axes) must be created, parameterized and linked (see "Configuration", "[CA Group Parameterization](ms-xhelp:///?Id=beckhoff-db68-4aa8-b9c7-ce918ad20973)").
:   This example uses the default values for all gap control parameters and 10 axes in the group. All axes are mounted on a closed rail (XTS) with a length of 3000 mm. The position of the axes (movers) is arbitrary, the default gap which is parameterized in the group is not observed:

![30087318](/tf5410_tc3_collision_avoidance/1033/Images/png/1537634059__Web.png):   1. All axes must be added to the group (see examples in [MC\_AddAxisToGroup](ms-xhelp:///?Id=beckhoff-df68-43f9-9587-82ddf8974a7a)).
:   The order of the axes for the collision avoidance is determined by their actual position on the rail.
:   If the positions of the axes are equal (e.g. for simulation axes), the order in that the axes are added to the group is essential. In this case, the axis that was added last is the first axis in the group.
:   The "IdentInGroup" has no relevance for the order used for collision avoidance.
:   2. Enable Group (see [MC\_GroupEnable](ms-xhelp:///?Id=beckhoff-264b-4399-b507-d6543ee7460b)).
:   The GroupState is now mcGroupStateStandby (see [MC\_GroupReadStatus](ms-xhelp:///?Id=beckhoff-e176-45cf-b301-563a6d518851) or [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)), the GroupAxesCount is 10 (see [Cyclic Group Interface](ms-xhelp:///?Id=beckhoff-d971-4c2c-bc13-01a1eba0d39b)).
:   The position of the axes (movers) has not changed, the gap is still not observed.
:   3. Issue "[MC\_MoveAbsoluteCA](ms-xhelp:///?Id=beckhoff-6454-4164-b2f9-0b8845f57f91)" for all axes (movers) to the same position (2500 mm).

:   The first mover that is the mover with the largest absolute position, here mover 1, reaches the target position at 2500 mm. The other movers line up, each keeping the gap to its forerunner. The forerunner of the first mover is the last one (since the group parameter Rail Is Ring is set to TRUE).

![2350413](/tf5410_tc3_collision_avoidance/1033/Images/png/1537640715__Web.png)
