# Monitoring

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Monitoring

![20074930](/tf50x0_tc3_nc_ptp/1033/Images/png/3260132619__Web.png)![46456648](/tf50x0_tc3_nc_ptp/1033/Images/png/3260129419__Web.png)![15456653](/tf50x0_tc3_nc_ptp/1033/Images/png/3260158219__Web.png)

## Position Lag Monitoring

When position lag monitoring is performed, the Position Lag Error is monitored, and if prescribed limits of position and time are exceeded, a runtime error is thrown.

Position Lag Error = Actual Position - Current Setpoint Position.

The Position Lag Monitoring parameters can be set at MOTION | NC-Task 1 SAF | Axes | Axis 1 | Parameter.

Alternatively, the Position Lag Monitoring parameters can be set at MOTION | NC-Task 1 SAF | Axes | Axis 1 | Ctrl | Parameter.

Analogously, for different identfiers.

`TRUE`: Position Lag Monitoring is activated.

`FALSE`: Position Lag Monitoring is not activated.

## Maximum Position Lag Value and Maximum Position Lag Filter Time

The Maximum Position Lag Value is the upper boundary for the permitted position lag error not to be exceeded for a time longer than the Maximum Position Lag Filter Time when the Position Lag Monitoring is activated. Otherwise, the NC axis will be stopped instantaneously by a zero voltage output and the NC axis will be placed into the logical “error” state throwing the error `0x4550`.

![4892154](/tf50x0_tc3_nc_ptp/1033/Images/png/3260132619__Web.png)![44029393](/tf50x0_tc3_nc_ptp/1033/Images/png/3260129419__Web.png)![60720217](/tf50x0_tc3_nc_ptp/1033/Images/png/3260161419__Web.png)

[5][6][7][8][9][1][2][3][4]

## Position Range Monitoring

|  |  |
| --- | --- |
| [1] | * Nominal value of the target position. |

|  |  |
| --- | --- |
| [2] | * Position Range Window. |

|  |  |
| --- | --- |
| [3] | * Position Range Window. |

|  |  |
| --- | --- |
| [4]  *Position Range* *Monitoring* | Variable `Axis.Status.InPositionArea`:   * If the parameter “Position Range Monitoring” is set on `TRUE` and … * … if the actual position resides within this range [4], * then the variable `Axis.Status.InPositionArea` is set on `TRUE`. |

|  |  |
| --- | --- |
| 9611044 | NC-Online: “In Pos. Range” – `Axis.Status.InPositionArea`  The value of variable `Axis.Status.InPositionArea` corresponds to the state of the checkbox “In Pos. Range” within the group box “Status (phys.)” of the NC-Online dialog. If the variable `Axis.Status.InPositionArea` is set on `TRUE`, the checkbox “In Pos. Range” is checked. |

## Target Position Monitoring

|  |  |
| --- | --- |
| [5] | * Nominal value of the target position. |

|  |  |
| --- | --- |
| [6] | * Target Position Window. |

|  |  |
| --- | --- |
| [7] | * Target Position Window. |

|  |  |
| --- | --- |
| [8], [9]  *Target Position* *Monitoring* | Target position:   * If the parameter “Target Position Monitoring” is set on `TRUE` and … * … if the actual position resides for at least the duration “Target Position Monitoring Time” [9] uninterruptedly until actual time within this range [8], * then the variable `Axis.Status.InTargetPosition` is set on `TRUE`. |

|  |  |
| --- | --- |
| 19390540 | NC-Online: “In Target Pos.” – `Axis.Status.InTargetPosition`  The value of the variable `Axis.Status.InTargetPosition` corresponds to the state of the checkbox “In Target Pos.” within the group box “Status (phys.)” of the NC-Online dialog. If the variable `Axis.Status.InTargetPosition` is set on `TRUE`, the checkbox “In Target Pos.” is checked. |

![40297137](/tf50x0_tc3_nc_ptp/1033/Images/png/3260132619__Web.png)![27129916](/tf50x0_tc3_nc_ptp/1033/Images/png/3260129419__Web.png)![42842654](/tf50x0_tc3_nc_ptp/1033/Images/png/3362558859__Web.png)

## In-Target Alarm

`FALSE`: The In-Target Alarm is not activated.

`TRUE`: The In-Target Alarm is activated.

## In-Target Timeout

When the In-Target Alarm is activated and the axis does not stay within the Target Position Window for the In-Target Timeout time, the NC axis reports the error `0x435C`. Thereby, time measurement is started when the axis has reached its nominal position.

![50039568](/tf50x0_tc3_nc_ptp/1033/Images/png/3260132619__Web.png)![47702931](/tf50x0_tc3_nc_ptp/1033/Images/png/3260129419__Web.png)![26673201](/tf50x0_tc3_nc_ptp/1033/Images/png/3362562059__Web.png)

## Motion Monitoring

Motion Monitoring checks whether an axis is actually moving while it is executing a motion command. This makes it possible, for example, to detect the mechanical blocking of an axis at an early stage.

The parameter is set to TRUE to activate Motion Monitoring, otherwise no monitoring takes place.

## Motion Monitoring Window

The Motion Monitoring Window defines the distance that the encoder (actual position) should be expected to travel during one cycle of the NC SAF task. Here a value/distance/length of some encoder increments can be set.

## Motion Monitoring Time

Monitoring starts as soon as the axis executes a motion command and ends when the axis comes to a logical standstill. If its actual position does not change by more than the Motion Monitoring Window in at least one NC cycle during the Motion Monitoring Time, the NC axis outputs the error `0x435D`.
