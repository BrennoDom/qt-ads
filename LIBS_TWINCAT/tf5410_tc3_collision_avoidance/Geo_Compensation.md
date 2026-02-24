# Geo Compensation

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Geo Compensation

‘y’-shift = 0: XTS motor path ‘x’
‘y’-shift = 100
‘y’-shift = 200
‘y’-axis
‘x’-axis
zero point offset along the XTS motor path ‘x’

Starter Kit Geometry.

## Geo Compensation: Motivation

Geo Compensation defines an additional degree-of-freedom:

* A one-dimensional spatial transformation of motion dynamics control.
* Positional motion control always refers to the XTS motor path.

A `y`-axis perpendicular to the XTS motor path coordinate is introduced as an additional dimension. Motion dynamics can be controlled for a predefined path located on this `y`-component of displacement. This path may enable opportunities for enhanced mover motion dynamics.

* Motion dynamics refer to velocity, acceleration, deceleration and jerk behavior along a path.

Generally, dynamical reference can be kept to the XTS motor path, thus leaving the usage of Geo Compensation as an optional opportunity.

## Motivation Example: Center of Gravity

Within many XTS applications heavy tools or products are mounted on the movers. Altogether, a mover and its load form a vehicle. Generally, the vehicle center of gravity does not travel on the XTS motor path. On straight XTS segments XTS motor path velocity and center of gravity path velocity are identical. On curved XTS segments these path velocities differ. This difference leads to an acceleration or deceleration on the center of gravity path while XTS motor path velocity is kept constant. Thus, unintentional forces are at work on the XTS track, especially when curves are entered or left. To avoid some of these forces or to keep their magnitude low the center of gravity could be driven with a nearly constant velocity. This behavior is an example for what Geo Compensation may intend to achieve: As long as a mover and its load are not changed, the center of gravity path can be described and controlled dynamically by adding a radial shift to the XTS motor path. Because this shift points away perpendicularly from the XTS motor path, this shift is called `y`-shift.
