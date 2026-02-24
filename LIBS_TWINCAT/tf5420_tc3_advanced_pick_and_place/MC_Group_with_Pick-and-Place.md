# MC Group with Pick-and-Place

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC Group with Pick-and-Place

The MC Group connects axes in order to execute a multi-dimensional motion.

|  |  |
| --- | --- |
| 56760689 | The use of "MC Group Coordinated Motion" is recommended for new projects. |

![41084157](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/1509097099__Web.png)

## Axis conventions

Tab: Parameter (Init). Three axis conventions can be set.

The axis conventions define how the axes are interpreted in the axis group. They define the dimension of the axis group and thus the number of axes that need to be added, as well as the way in which each of the added axes is interpreted.

| Parameter | Value | Type | Description |
| --- | --- | --- | --- |
| Axes Convention | mcAxesConv2DCartesianXY | `MC.MC_AXES_CONVENTION` | A 2D group consisting of `X`, `Y`. The order of the translatory axes in the configuration determines the order of translation. |
| Axes Convention | mcAxesConv3DCartesianXYZ | `MC.MC_AXES_CONVENTION` | A 3D group consisting of `X`, `Y`, `Z`. The order of the translatory axes in the configuration determines the order of translation. |
| Axes Convention | mcAxesConv4DCartesianXYZC | `MC.MC_AXES_CONVENTION` | A 4D group consisting of `X`, `Y`, `Z` and a rotary axis around `Z` (`C`). The order of the translatory and rotary axes in the configuration determines the order of translation and rotation. |

## Axis group parameters of the pick-and-place kernel

![34213098](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8898358155__Web.png)

Tab: Parameter (Init).

| Parameter | Unit | Type | Description |
| --- | --- | --- | --- |
| NET Cycle Time Divisor |  | `UINT` | Improves accuracy on the basis of temporal discretization. |
| Time Override Ramp Time | `S` | `LREAL` | Ramp time for override change from 0 % to 100 %. |

The pick-and-place setpoint generator was specially developed for the requirements of pick-and-place applications. It is intended for motions where the precise path dynamics are not so important, but where the user wishes to get from one point to another as quickly as possible. It is therefore permissible for the algorithm to violate restrictions in the path dynamics within the tolerance sphere. Axis restrictions are never violated.
