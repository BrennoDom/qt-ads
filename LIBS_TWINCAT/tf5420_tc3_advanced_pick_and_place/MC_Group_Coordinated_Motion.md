# MC Group Coordinated Motion

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# MC Group Coordinated Motion

![43589445](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/8897303307__Web.png)

## Parameter (Init)

## Spatial Axis Conventions

There are three axis conventions that can be set.

The axis conventions define how the axes in the axis group are interpreted. In combination with “Additional Axes Count” they define the axis group dimension and therefore the number of axes that have to be added and the way each one of the added axes is interpreted.

| Parameter | Value | Type | Description |
| --- | --- | --- | --- |
| Spatial Axes Convention | mcAxesConv2DCartesianXY | `MC.MC_AXES_CONVENTION` | A 2D group consisting of `X`, `Y`. The order of the translational axes within the configuration defines the translation order. |
| Spatial Axes Convention | mcAxesConv3DCartesianXYZ | `MC.MC_AXES_CONVENTION` | A 3D group consisting of `X`, `Y`, `Z`. The order of the translational axes within the configuration defines the translation order. |
| Spatial Axes Convention | mcAxesConv4DCartesianXYZC | `MC.MC_AXES_CONVENTION` | A 4D group consisting of `X`, `Y`, `Z` and a rotational axis around `Z` (`C`). The order of the translational and rotational axes within the configuration defines the translation and rotation order. |

## Additional Axes Count

Number of axes in the motion group that have no geometrical interpretation. Between 0 and 8 axes of this type can be inserted.

## Blending Strategy

Specifies the blending strategy.

| Parameter | Value | Type | Description |
| --- | --- | --- | --- |
| Blending Strategy | mcBlendingGeo | `MC.MC_BLENDING_STRATEGY` | Blending path is defined geometrically and then run with the dynamics allowed for the path. |
| Blending Strategy | mcBlendingSuperpos | `MC.MC_BLENDING_STRATEGY` | Blending path results dynamically from the superposition of two segments within the blending area. |

## Time-Override Ramp Time

Ramp time for override change from 0 % to 100 %. The time override is superimposed on the actual profile. This can result in higher dynamics in total during the override changes than were parameterized at the group.

## GeoBlending-specific parameters

## Blending Path Type

Defines the geometry that is used for the blending path.

| Parameter | Value | Type | Description |
| --- | --- | --- | --- |
| Blending Path Type | mcBlendingPathTypeIgnore | `MC.MC_BLENDING_PATH_TYPE` | No blending. |
| Blending Path Type | mcBlendingPathTypePoly5 | `MC.MC_BLENDING_PATH_TYPE` | Blending path uses a polynomial of order five. |

##
