# Differences between MC2 and MC3

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Differences between MC2 and MC3

This chapter lists differences between MC2 and MC3 (as introduced in TF5400 Advanced Motion Pack).

## Axes

|  | MC2 | MC3 |
| --- | --- | --- |
| Maximum dynamics | The velocity defined in axis parameterization is interpreted as physical maximum value. Acceleration, deceleration and Jerk specified in the axis are default values that only have an effect if no dynamics is specified in FBs. | There are maximum values for velocity, acceleration, deceleration and jerk which limit the values that can be set in FBs. Moreover default dynamics can be selected by user at respective FB input. |

## PLC Library

|  | MC2 | MC3 |
| --- | --- | --- |
| Default values | For dynamics parameters of type LREAL "0" is default value. If "0" is set the default parameters from the axes are used. | The constant MC\_Default is introduced (see [MC\_LREAL/Special Input Values](ms-xhelp:///?Id=beckhoff-aff8-4bc7-b1a4-f5f4b932866a)).  "0" is not interpreted as default value but as a normal value which in case of dynamics can be invalid. |
| Timing of FB outputs | FB returns values that were valid at the start of PLC cycle. | FB returns values that are valid at the moment PLC code is executed. This may lead to timing difference between cyclic interface and FB output. |
| Decoupling | A special function block can be used (e.g. MC\_GearOut/MC\_CamOut) | The slave axis is decoupled by sending another motion command with Buffermode mcAborting. |
