# Rapid Traverse

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Rapid Traverse

|  |  |
| --- | --- |
| Command | `G0` |
| Cancellation | `G1`, `G2` or `G3` |

* Rapid traverse is used to position the tool quickly, and is not to be used for machining the workpiece. With G0 the axes are moved with linear interpolation as fast as possible. The velocity is calculated with MIN (Rapid Traverse Velocity (G0), Reference Velocity, Maximum Velocity).
* If a number of axes are to be driven in rapid traverse the velocity is determined by that axis that requires the most time for its movement.
* An accurate stop (`G60`) is cancelled with `G0`.
* The rapid traverse velocity is set for each axis individually at “MOTION | NC-Task 1 SAF | Axes | Axis 1 | NCI Parameter | Rapid Traverse Velocity (`G0`)”.
