# Position and Velocity Scaling

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Position and Velocity Scaling

![57610085](/tf50x0_tc3_nc_ptp/1033/Images/png/3468214411__Web.png)![48728718](/tf50x0_tc3_nc_ptp/1033/Images/png/3468320011__Web.png)![35905280](/tf50x0_tc3_nc_ptp/1033/Images/png/3468326411__Web.png)

## Output Scaling Factor (Position)

Habitually, the drive parameter Output Scaling Factor (Position) does not evoke an effect. In principle, to avoid to infer its future use the user should not change the default value `1.0` of this parameter.

The positional output scaling is already set by the encoder input scaling. Regularly, the positional input scaling equals the positional output scaling for a drive. For this reason, the drive parameter Output Scaling Factor (Position) is currently not evaluated. Instead, solely the encoder parameters Scaling Factor Numerator and Scaling Factor Denominator do the scaling work and have to be adjusted for accurate scaling.

## Output Scaling Factor (Velocity)

When a drive controler operates in velocity precontrol mode, the NC output value has to be scaled. To do this scaling there are two possibilities whose choice depends on the type of the employed drive controller.

1. Analog drive controllers, e.g. supplied by a ±10V terminal:
2. This type of drive controllers is scaled applying the Reference Velocity parameter.
3. Digital drive controllers to those an absolute digital velocity setpoint value is transferred, e.g. *CANopen DS402*:
4. This type of drive controllers is scaled applying the Output Scaling Factor (Velocity) parameter.

Following, a tabular comparison shows, when the Reference Velocity parameter or the Output Scaling Factor (Velocity) parameter has to be applied.

|  |  |  |
| --- | --- | --- |
| Drive Type | Scaling with Reference Velocity | Scaling with Output Scaling Factor (Velocity) |

|  |  |  |
| --- | --- | --- |
| M2400\_DAC1 | x |  |

|  |  |  |
| --- | --- | --- |
| M2400\_DAC2 | x |  |

|  |  |  |
| --- | --- | --- |
| M2400\_DAC3 | x |  |

|  |  |  |
| --- | --- | --- |
| M2400\_DAC4 | x |  |

|  |  |  |
| --- | --- | --- |
| KL4XXX | x |  |

|  |  |  |
| --- | --- | --- |
| KL4XXX\_NONLINEAR | x |  |

|  |  |  |
| --- | --- | --- |
| TWOSPEED | x |  |

|  |  |  |
| --- | --- | --- |
| STEPPER | x |  |

|  |  |  |
| --- | --- | --- |
| SERCOS |  | x |

|  |  |  |
| --- | --- | --- |
| KL5051 | x |  |

|  |  |  |
| --- | --- | --- |
| AX2000\_B200 |  | x |

|  |  |  |
| --- | --- | --- |
| SIMO611U |  | x |

|  |  |  |
| --- | --- | --- |
| UNIVERSAL | x |  |

|  |  |  |
| --- | --- | --- |
| NCBACKPLANE | x |  |

|  |  |  |
| --- | --- | --- |
| CANOPEN\_LENZE |  | x |

|  |  |  |
| --- | --- | --- |
| DS402\_MDP742 |  | x |

|  |  |  |
| --- | --- | --- |
| AX2000\_B900 | x |  |

|  |  |  |
| --- | --- | --- |
| AX2000\_B310 | x |  |

|  |  |  |
| --- | --- | --- |
| AX2000\_B100 | x |  |

|  |  |  |
| --- | --- | --- |
| KL2531 |  | x |

|  |  |  |
| --- | --- | --- |
| KL2532 |  | x |

|  |  |  |
| --- | --- | --- |
| TCOM\_DRV |  | x |

|  |  |  |
| --- | --- | --- |
| MDP\_733 |  | x |

|  |  |  |
| --- | --- | --- |
| MDP\_703 | x | (x)\* |

\*Also possible, but should be regularly left on the value `1.0`.

![54712068](/tf50x0_tc3_nc_ptp/1033/Images/png/3468214411__Web.png)![22646572](/tf50x0_tc3_nc_ptp/1033/Images/png/3468320011__Web.png)![2492560](/tf50x0_tc3_nc_ptp/1033/Images/png/3468323211__Web.png)

## Output Delay (Velocity)

The output of the velocity value can be delayed by the Output Delay (Velocity) time.

![22433040](/tf50x0_tc3_nc_ptp/1033/Images/png/3458575371__Web.png)![570775](/tf50x0_tc3_nc_ptp/1033/Images/png/3458578571__Web.png)![5136981](/tf50x0_tc3_nc_ptp/1033/Images/png/3458456971__Web.png)

## Minimum Drive Output Limitation [-1.0 … 1.0]

To limit velocity and thus to protect hardware a lower output limit can be set for driving the axis. If just a part of the output data type is valid it is necessary to limit the minimum output value. The Minimum Drive Output Limitation is a directionally dependend limitation of the total output. The value `1.0` corresponds to unlimited output of 100%. Typically, using this parameter one refers to a velocity output signal for the drive in connection with position control. In exceptional cases the application of this parameter may refer to a torque value or a current value.

## Maximum Drive Output Limitation [-1.0 … 1.0]

To limit velocity and thus to protect hardware an upper output limit can be set for driving the axis. If just a part of the output data type is valid it is necessary to limit the maximum output value. The Maximum Drive Output Limitation is a directionally dependend limitation of the total output. The value `1.0` corresponds to unlimited output of 100%. Typically, using this parameter one refers to a velocity output signal for the drive in connection with position control. In exceptional cases the application of this parameter may refer to a torque value or a current value.
