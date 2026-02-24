# Coordinate Frame Object

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Coordinate Frame Object

Coordinate Frame Objects can be used to hierarchically build up geometrical translation and rotation relationships. For straight interpretation the `x`-direction of the final element within the hierarchy should point into the conveying direction.

| Parameter | Description | Unit |
| --- | --- | --- |
| Rotation Convention | Convention used for the calculation of rotations. Default is `DIN9300 Z”Y’X` where Rotation `3` is the parameter for `Z”`, Rotation `2` is the parameter for `Y’` and Rotation `1` is the parameter for `X`. |  |
| Definition Direction | Indicates the direction in which the displacement is programmed (from the point of view of the reference system or the MCS). |  |
| Translation `X` | Translation in the `x`-axis direction. | mm |
| Translation `Y` | Translation in the `y`-axis direction. | mm |
| Translation `Z` | Translation in the `z`-axis direction. | mm |
| Rotation `1` | Rotation axis is defined by the Rotation Convention. | ° |
| Rotation `2` | Rotation axis is defined by the Rotation Convention. | ° |
| Rotation `3` | Rotation axis is defined by the Rotation Convention. | ° |
