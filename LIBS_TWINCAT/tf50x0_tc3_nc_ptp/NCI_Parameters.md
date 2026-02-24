# NCI Parameters

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# NCI Parameters

![56350302](/tf50x0_tc3_nc_ptp/1033/Images/png/3260142219__Web.png)![37390672](/tf50x0_tc3_nc_ptp/1033/Images/png/3260139019__Web.png)![971734](/tf50x0_tc3_nc_ptp/1033/Images/png/3362581259__Web.png)

## Rapid Traverse Velocity (`G0`)

The Rapid Traverse Velocity is used, when a `G0` interpreter command is running. Look at section [Rapid Traverse](ms-xhelp:///?Id=beckhoff-b2fa-4375-afc8-aec31e7eb8a0) for a short description of the `G0` interpreter command.

![8745607](/tf50x0_tc3_nc_ptp/1033/Images/png/3260142219__Web.png)![11601606](/tf50x0_tc3_nc_ptp/1033/Images/png/3260139019__Web.png)![37305595](/tf50x0_tc3_nc_ptp/1033/Images/png/3264245131__Web.png)![206039](/tf50x0_tc3_nc_ptp/1033/Images/png/3260167819__Web.png)

## Segment Transitions

Segments are geometrical objects. We regard them as curves in terms of differential geometry that are parameterized by their `arc` length.

A segment transition from a segment `S_in` to a segment `S_out` is classified in geometrical terms as type `Ck`. Thereby, `k` is a natural number (including `0`) describing `k` continuous `arc` length differentials for each segment and corresponding `k^th` derivatives at the transition point.

`C0` transitions: Have a knee-point at the transition point.

`C1` transitions: Appear smooth, but are not smooth in dynamic terms. At the segment transition point there is a step change in acceleration.

`C2` transitions: Are dynamically smooth their smoothness merely being restricted by jerk.

`Ck` transitions: Are dynamically smooth.

## Segment Dynamics

Velocity `v`: The segment setpoint velocity `v` changes from `v_in` to `v_out` at the segment transition. At the segment transition the setpoint velocity is always reduced to the lower one of the two values.

Acceleration `a`: At the segment transition the current path acceleration is always reduced to zero.

Jerk `j`: At the segment transition the jerk changes according to the segment transition geometry. This jerk change can cause significant step change in dynamics.

## Velocity Reduction Modes for `C0` Transitions

Several reduction methods are available for `C0` transitions. One of them is the VELOJUMP reduction method. The VELOJUMP reduction method reduces the velocity after permitted step changes in velocity for each axis.

## The VELOJUMP Reduction Method for `C0` Transitions

Basically, `v_link = min(v_in, v_out)`. For the axis `[i]` the permitted absolute step change in velocity is `v_jump[i] = C0[i] * min(A+[i], -A-[i]) * T`. Thereby, `C0[i]` is the reduction factor, `A+[i], A-[i]` are the acceleration or deceleration limits for the axis `[i]` and `T` is the cycle time. The VELOJUMP reduction method ensures that the path velocity at segment transition `v_link` is reduced, whereby the absolute step change in the axis setpoint velocity of axis `[i]` is at most `v_jump[i]`. Nevertheless, `v_min` has priority: If `v_link` is less than `v_min`, `v_link` is set to `v_min`. In case of movement reversal with no programmed stop there will be a step change in axis velocity.

## Velo Jump Factor

The reduction factor `C0[i]` is the Velo Jump Factor.

## Tolerance ball auxiliary axis

Look at section [Tolerance Ball](ms-xhelp:///?Id=beckhoff-a918-4979-ad6a-b7bbe52321d4) for more information.

![1854355](/tf50x0_tc3_nc_ptp/1033/Images/png/3260142219__Web.png)![16689200](/tf50x0_tc3_nc_ptp/1033/Images/png/3260139019__Web.png)![15985080](/tf50x0_tc3_nc_ptp/1033/Images/png/3362565259__Web.png)

## Max. position deviation, aux. axis

Introduced for future enhancements.
