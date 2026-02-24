# MC_LREAL/Special Input Values

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# MC\_LREAL/Special Input Values

Data type MC\_LREAL, is equivalent to data type LREAL. However, there exist a few additional values that have a special signification.

| Value | Signification | Example |
| --- | --- | --- |
| MC\_DEFAULT | The input is executed with default value for this input. | Acceleration, Deceleration, Jerk for all motion commands |
| MC\_MAXIMUM | The command is executed with maximum value for this input. | Generally, from software version 3.1.4.4 on for specific motion commands the value `MC_MAXIMUM` can be assigned to the inputs `Velocity`, `Acceleration`, `Deceleration` and `Jerk`. For more detailed information refer to the particular documentation of the function block the input intended to be supplied with the `MC_MAXIMUM` value belongs to. |
| MC\_IGNORE | The input is ignored. | MC\_GearInPosCA.MasterStartDistance |
| MC\_INVALID | The input must be set by the user, there exists no default or maximum value, nor can the input be ignored. | MC\_MoveAbsoluteCA.Position |
