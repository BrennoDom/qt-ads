# Encoder Evaluation

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Encoder Evaluation

![12483231](/tf50x0_tc3_nc_ptp/1033/Images/png/3460178571__Web.png)![45240216](/tf50x0_tc3_nc_ptp/1033/Images/png/3460216971__Web.png)![4508766](/tf50x0_tc3_nc_ptp/1033/Images/png/3460220171__Web.png)

## Invert Encoder Counting Direction

If set `TRUE`, the parameter Invert Encoder Counting Direction inverts the counting direction of the encoder.

* `FALSE`: The polarity of the axis movement agrees with the counting direction of the acquisition hardware.
* `TRUE`: The polarity of the axis movement is opposite to the counting direction of the acquisition hardware.

|  |  |
| --- | --- |
| 40578897WARNING | |
| Risk of Unexpected Movements  If the encoder counting direction and the motor polarity do not match with each other, the axis will make unexpected movements. | |

![29665754](/tf50x0_tc3_nc_ptp/1033/Images/png/3460178571__Web.png)![65665194](/tf50x0_tc3_nc_ptp/1033/Images/png/3460216971__Web.png)![54115834](/tf50x0_tc3_nc_ptp/1033/Images/png/3460232971__Web.png)

## Scaling Factor Numerator and Scaling Factor Denominator (default: 1.0)

The scaling factor is subdivided into a numerator and a denominator. It converts displacement increments into axis positions or calculates a user unit out of encoder increments.

![17280459](/tf50x0_tc3_nc_ptp/1033/Images/png/3460178571__Web.png)![21306406](/tf50x0_tc3_nc_ptp/1033/Images/png/3460216971__Web.png)![57539933](/tf50x0_tc3_nc_ptp/1033/Images/png/3460229771__Web.png)

## Position Bias

The position bias is an offset used for absolute encoders to align their position within the machine coordinate system and thus to specify the machine-dependent zero point. Thereby, the position bias offset value is added to the encoder position to determine the axis position.

![48097351](/tf50x0_tc3_nc_ptp/1033/Images/png/3460178571__Web.png)![30222983](/tf50x0_tc3_nc_ptp/1033/Images/png/3460216971__Web.png)![3571397](/tf50x0_tc3_nc_ptp/1033/Images/png/3460223371__Web.png)

## Modulo Factor (e.g. 360.0°)

The value of the Modulo Factor (e.g. 360.0°) is the value to calculate modulo turns and modulo positions out of the absolute axis position. For rotating axes the Modulo Factor is the “distance” represented by one rotation. For instance, 360.0° should be entered here, if the actual rotational value is acquired in degrees.

## Tolerance Window for Modulo Start

The Tolerance Window for Modulo Start should be big enough to allow backward movements, if a modulo forward command is running inside the window area. Vice versa, the Tolerance Window for Modulo Start should be big enough to allow forward movements, if a modulo backward command is running inside the window area.

## Additional Information: Modulo Positioning

Following

* [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc) or  
  https://infosys.beckhoff.com/content/1033/tcplclib\_tc2\_mc2/index.html

you can find further Notes on Modulo Positioning.

![32142578](/tf50x0_tc3_nc_ptp/1033/Images/png/3460740491__Web.png)![20847751](/tf50x0_tc3_nc_ptp/1033/Images/png/3460743691__Web.png)![53412038](/tf50x0_tc3_nc_ptp/1033/Images/png/3460746891__Web.png)

## Encoder Mask (maximum encoder value)

The encoder mask defines the number of allowed increments until the feedback value flows over. Thereby, the increments are not the real encoder increments.

## Encoder Sub Mask (absolute range maximum value)

The encoder submask defines the number of increments per motor turn.

![10946294](/tf50x0_tc3_nc_ptp/1033/Images/png/3460178571__Web.png)![31407785](/tf50x0_tc3_nc_ptp/1033/Images/png/3460216971__Web.png)![14234617](/tf50x0_tc3_nc_ptp/1033/Images/png/3460226571__Web.png)

## Noise level of simulation encoder

Setting a level this parameter creates artificial noise for the simulation axis to make it appear more realistic.

![61002694](/tf50x0_tc3_nc_ptp/1033/Images/png/3460740491__Web.png)![12153337](/tf50x0_tc3_nc_ptp/1033/Images/png/3460743691__Web.png)![42271171](/tf50x0_tc3_nc_ptp/1033/Images/png/3460752011__Web.png)

## Reference System

Use the Reference System parameter to select how the encoder values should be interpreted:

| Mode | Physical feedback type | Feedback overflows | Adjustment of the position to a defined travel range when switching on |
| --- | --- | --- | --- |
| INCREMENTAL | Incremental or absolute value encoder | Overflows of the encoder position are also counted | The position is not initialized when switching on, and homing is required |
| INCREMENTAL (singleturn absolute) | Single-turn absolute value encoder | Overflows of the encoder position are also counted. | The position is not initialized when switching on, and homing is required. |
| ABSOLUTE | Multi-turn absolute value encoder | An overflow of the encoder count value leads to an error. | The position is accepted unchanged by the encoder system when it is switched on. |
| ABSOLUTE MULTITURN RANGE (with single overflow) | Multi-turn absolute value encoder | Only one overflow of the encoder count value may occur over the travel distance between the end positions, and the total travel distance must be smaller than the multi-turn count range of the encoder. This overflow is taken into account in the actual position. A further overflow leads to an error. | The position is initialized at power-on such that it is within the end positions. |
| ABSOLUTE SINGLETURN RANGE (with single overflow) | Single-turn absolute value encoder | Only one overflow of the encoder count value may occur over the travel distance between the end positions, and the total travel distance must be smaller than the single-turn count range of the encoder. This overflow is taken into account in the actual position. A further overflow leads to an error. | The position is initialized at power-on such that it is within the end positions. |
| ABSOLUTE (modulo) with retain data | Multi-turn absolute value encoder | Overflows of the encoder position are also counted. After switching on, the position is reset to the basic range of the absolute encoder (modulo). | If no end positions are defined, the initial position is reduced to the basic cycle of the absolute encoder. If both end positions are activated, the position is restored directly from the retain data. |

| Mode | Correction of a mechanical displacement in the switched-off state up to half the absolute value range | Software end positions | Persistent data |
| --- | --- | --- | --- |
| INCREMENTAL |  |  |  |
| INCREMENTAL (singleturn absolute) | A shift of the encoder system in the switched-off state by a maximum of half the counting range can be compensated. |  |  |
| ABSOLUTE | A shift of the encoder system in the switched-off state by a maximum of half the counting range can be compensated. |  |  |
| ABSOLUTE MULTITURN RANGE (with single overflow) | A shift of the encoder system in the switched-off state by a maximum of half the counting range can be compensated. | For this operation mode, end positions must be selected in the parameters. |  |
| ABSOLUTE SINGLETURN RANGE (with single overflow) | A shift of the encoder system in the switched-off state by a maximum of half the counting range can be compensated. | For this operation mode, end positions must be selected in the parameters. The maximum travel distance corresponds to one encoder revolution. |  |
| ABSOLUTE (modulo) with retain data | A shift of the encoder system in the switched-off state by a maximum of half the counting range can be compensated. |  | For this operation mode, persistent NC data is a requirement. Therefore this data must be parameterized for the NC-SAF task and for the axis. |
