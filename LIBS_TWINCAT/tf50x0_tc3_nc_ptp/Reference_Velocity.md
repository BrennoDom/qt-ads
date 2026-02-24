# Reference Velocity

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Reference Velocity

![25927028](/tf50x0_tc3_nc_ptp/1033/Images/png/3395185419__Web.png)![32016662](/tf50x0_tc3_nc_ptp/1033/Images/png/3395169419__Web.png)![19714506](/tf50x0_tc3_nc_ptp/1033/Images/png/3395195019__Web.png)![43212834](/tf50x0_tc3_nc_ptp/1033/Images/png/3396331019__Web.png)![53371190](/tf50x0_tc3_nc_ptp/1033/Images/png/3395403019__Web.png)![10578662](/tf50x0_tc3_nc_ptp/1033/Images/png/3395406219__Web.png)

At MOTION | NC-Task 1 SAF | Axes | Axis 1 | Drive | Parameter.

Solely Reference Velocity also at MOTION | NC-Task 1 SAF | Axes | Axis 1 | Parameter | Maximum Dynamics.

Analogously, for different identifiers.

## Reference Velocity at Output Ratio [0.0 … 1.0]

*Scaling and Physical Limit*

For analog control the Reference Velocity at a certain Output Ratio matches the analog input control signal with the resulting physical velocity of axis motion. Furthermore, for control via a digital interface, e.g. SoE or CoE, and for analog control the Reference Velocity at Output Ratio `1.0` prescribes a physical velocity limit not to be exceeded by setpoint generation and positional control.

*Proportional Relationship for Analog Control*

When drive controllers with analog inputs for their velocity control are used, the Reference Velocity combines e.g. an input bias value for control with a physical velocity or a number of revolutions per minute of the controlled axis. Comparatively, the analog input bias value may result from a kind of potentionmeter dividing a voltage range for control. Similarly, a controlling current may be applied as an input source. For zero control signal there is zero physical velocity. At a particular Output Ratio there is a corresponding Reference Velocity, thus establishing a proportional relationship. For analog control, e.g. ±10V, the Reference Velocity at Output Ratio `1.0` prescribes the setpoint velocity at the corresponding maximum output of e.g. 10V.

*Pair of Numbers*

Some drive setups may not be put into operation at their upper physical velocity limit corresponding to an Output Ratio of `1.0`. Instead, at a reasonably reduced velocity allocated for first driving experiences the Reference Velocity may be determined at a reduced Output Ratio lower than `1.0`. Thus, the link between controlling input signal and physical velocity of motion is established by a pair of numbers, the Reference Velocity and the Output Ratio adjoined to it. Internally, the scaling calculation is done by TwinCAT and it calculates a Reference Velocity at Output Ratio `1.0`. When for an Output Ratio `1.0` an axis is controlled at its designed upper physical boundary setpoint, it is controlled at its reference velocity.

*Reference Velocity and Maximum Velocity*

The Reference Velocity at Output Ratio `1.0` determines an upper physical limit for velocity control. So far, there is no appropriate way to go faster. On the other hand, the parameter Maximum Velocity establishes an upper limit for velocity control from a logical point of view. So far, there is no intended accomplishment to drive beyond the Maximum Velocity limit, even though this might be physically possible up to the boundary set by the Reference Velocity at Output Ratio `1.0`. The Reference Velocity at Output Ratio `1.0` should not succeed the Maximum Velocity. When the Maximum Velocity exceeds the Reference Velocity at Output Ratio `1.0`, an error message will be thrown. Likewise, at an axis start velocities exceeding the Reference Velocity at Output Ratio `1.0` will be rejected by an NC error. Tacitly, cyclic controller output is limited to the Reference Velocity at Output Ratio `1.0` without throwing an error.

## Minimum Drive Output Limitation [-1.0 … 1.0]

To limit velocity and thus to protect hardware a lower output limit can be set for driving the axis. If just a part of the output data type is valid it is necessary to limit the minimum output value. The Minimum Drive Output Limitation is a directionally dependend limitation of the total output. The value `1.0` corresponds to unlimited output of 100%. Typically, using this parameter one refers to a velocity output signal for the drive in connection with position control. In exceptional cases the application of this parameter may refer to a torque value or a current value.

## Maximum Drive Output Limitation [-1.0 … 1.0]

To limit velocity and thus to protect hardware an upper output limit can be set for driving the axis. If just a part of the output data type is valid it is necessary to limit the maximum output value. The Maximum Drive Output Limitation is a directionally dependend limitation of the total output. The value `1.0` corresponds to unlimited output of 100%. Typically, using this parameter one refers to a velocity output signal for the drive in connection with position control. In exceptional cases the application of this parameter may refer to a torque value or a current value.
