# Modulo positioning

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Modulo positioning

The modulo positioning can be applied to closed linear axes as well as to rotary axes. TwinCAT does not distinguish between these types. A modulo axis has a consecutive absolute position in the range ±∞. The modulo position of the axis is simply a piece of additional information about the absolute axis position. Modulo positioning represents the required target position in a different way. As opposed to absolute positioning, in which the user clearly specifies the target, the absolute target position is formed from the following parameters in modulo positioning:

* Modulo target position
* Modulo Factor
* Tolerance Window
* Direction, see [MC\_DIRECTION](ms-xhelp:///?Id=beckhoff-418a-4b63-be81-71a6f23a1ae0)
* (Additional Turns, see [ST\_MoveAbsoluteCAOptions](ms-xhelp:///?Id=beckhoff-99e1-49c8-9293-0bfff325f298))

## Modulo Factor

The modulo positioning basically refers to an adjustable Modulo Factor, which is set in the TwinCAT Engineering. The axis and its use must be observed here, for example:

* If a PTP axis is used, the Modulo Factor of the axis encoder applies; details in the Notes on the modulo positioning of a PTP axis.  
  ![21749220](/tf5410_tc3_collision_avoidance/1033/Images/png/10358625675__Web.png)

* If, for example, a mover is used on an XTS system in a CA group, the Rail Length set in the CA group applies.  
  ![61525259](/tf5410_tc3_collision_avoidance/1033/Images/png/10358628619__Web.png)

* If an XPlanar mover is used, its "C-axis" modulo can be positioned. Here, the Modulo Factor is set as "C coordinated modulus" in the Init parameters of the XPlanar mover.

**Modulo Tolerance Window**

The Modulo Tolerance Window defines a position window around the current modulo set position of the axis. The window width corresponds to twice the specified value (set position ± tolerance value) and is specified in the TwinCAT Engineering:

* In the case of a PTP axis or an axis in a CA group, the Tolerance Window is defined in the axis encoder  
  ![16856419](/tf5410_tc3_collision_avoidance/1033/Images/png/10358623115__Web.png)

* In the case of the C-axis of an XPlanar mover, the Tolerance Window is defined in the Init parameters of the XPlanar mover.

The positioning of an axis is always referenced to its current actual position. Unintentional revolutions may be performed if the actual position and the target position are very close to each other, for example, if the actual position is minimally greater than the target position and `Direction = mcDirectionPositive` was selected. This can occur in particular if the actual position is determined inaccurately (e.g. on account of incorrect positioning due to the axis stalling, or due to the finite resolution of the encoder). In order to avoid this, a tolerance window for modulo positioning can be set. If the distance between the start and target positions is less than or equal to the Tolerance Window, then the target position is driven to by the shortest route (as with `Direction = mcDirectionShortestWay`), i.e. also contrary to the `direction` specified.

![17490046](/tf5410_tc3_collision_avoidance/1033/Images/png/10358620171__Web.png)

## Examples

* Modulo Factor = 100
* Tolerance Window = 1

| **Parameter Direction** | **Absolute Startposition** | **Target position** | **Parameter**  **Additional Turns** | **Relative path** | **Absolute end position** | **Modulo end position** |
| --- | --- | --- | --- | --- | --- | --- |
| mcDirectionPositive | 110 | 10 | 0 | 0 | 110 | 10 |
| mcDirectionPositive | 110.9 | 10 | 0 | -0.9 | 110 | 10 |
| mcDirectionPositive | 112 | 10 | 0 | 98 | 110 | 10 |
| mcDirectionPositive | 95 | 10 | 0 | 15 | 110 | 10 |
| mcDirectionPositive | 110 | 110 | 0 | ERROR: INVALID TARGET POSITION | | |
|  |  |  |  |  |  |  |
| mcDirectionPositive | 110 | 10 | 3 | 300 | 410 | 10 |
| mcDirectionPositive | 110.9 | 10 | 3 | 299.1 | 410 | 10 |
| mcDirectionPositive | 112 | 10 | 3 | 398 | 410 | 10 |
| mcDirectionPositive | 95 | 10 | 3 | 315 | 410 | 10 |
| mcDirectionPositive | 110 | 110 | 3 | ERROR: INVALID TARGET POSITION | | |
|  |  |  |  |  |  |  |
| mcDirectionNegative | 110 | 10 | 0 | 0 | 110 | 10 |
| mcDirectionNegative | 109.9 | 10 | 0 | 0.1 | 110 | 10 |
| mcDirectionNegative | 108 | 10 | 0 | -98 | 10 | 10 |
| mcDirectionNegative | 95 | 10 | 0 | -85 | 10 | 10 |
| mcDirectionNegative | 110 | 110 | 0 | ERROR: INVALID TARGET POSITION | | |
|  |  |  |  |  |  |  |
| mcDirectionNegative | 410 | 10 | 3 | -300 | 110 | 10 |
| mcDirectionNegative | 409.9 | 10 | 3 | -299.9 | 110 | 10 |
| mcDirectionNegative | 408 | 10 | 3 | -398 | 10 | 10 |
| mcDirectionNegative | 495 | 10 | 3 | -385 | 10 | 10 |
| mcDirectionNegative | 410 | 110 | 3 | ERROR: INVALID TARGET POSITION | | |
|  |  |  |  |  |  |  |
| mcDirectionShortestWay | 440 | 50 | 0 | 10 | 450 | 50 |
| mcDirectionShortestWay | 440 | 10 | 0 | -30 | 410 | 10 |
|  |  |  |  |  |  |  |
| mcDirectionShortestWay | 440 | 50 | 1 | ERROR: INVALID ADDITIONAL TURN COUNT | | |

## Further samples

Further examples without the Additional Turns parameter can be found in the [Notes on the modulo positioning](ms-xhelp:///?Id=beckhoff-7468-4b2f-9792-bee9563a5a6e) of a PTP axis.
