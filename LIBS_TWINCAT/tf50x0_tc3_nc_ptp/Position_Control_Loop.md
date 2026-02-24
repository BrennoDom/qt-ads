# Position Control Loop

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Position Control Loop

Via fieldbus a setpoint velocity is transfered to the drive controller. Feeding back via fieldbus the actual axis position is transfered to TwinCAT thus forming a Position Control Loop. Employing this loop positional control can be carried out.

![12633819](/tf50x0_tc3_nc_ptp/1033/Images/png/3457544971__Web.png)![46595510](/tf50x0_tc3_nc_ptp/1033/Images/png/3457548171__Web.png)![16706408](/tf50x0_tc3_nc_ptp/1033/Images/png/3457036171__Web.png)

## Position control: Dead Band Position Deviation

In contrast to position control in the drive device, in TwinCAT Dead Band Position Deviation is only effective for position control if, for example, the velocity interface to the drive is configured. It defines a range in which the controller is inactive. This parameter is a symmetrical window based on the assumption that the position lag error with respect to the position control (position control deviation) within this window is zero. Position control is therefore disabled within the window.

This functionality is required because certain axes and mechanical systems may cause a stationary oscillation around the target position. The parameter can be used to enforce "calm". The parameterizable deviation around the exact target position is accepted.

There are axes that are not capable of position control or have insufficient holding torque around standstill, so that a certain inaccuracy around the target position is accepted.

For other real effects, such as pronounced static friction (with tear-off torque) or pronounced slack, dead band position deviation can also be used to enforce "calm" for an accepted accuracy.

![16139946](/tf50x0_tc3_nc_ptp/1033/Images/png/3457026571__Web.png)![11041789](/tf50x0_tc3_nc_ptp/1033/Images/png/3457029771__Web.png)![32267243](/tf50x0_tc3_nc_ptp/1033/Images/png/3457032971__Web.png)![21969731](/tf50x0_tc3_nc_ptp/1033/Images/png/3457480971__Web.png)![63509856](/tf50x0_tc3_nc_ptp/1033/Images/png/3457484171__Web.png)![34717793](/tf50x0_tc3_nc_ptp/1033/Images/png/3457538571__Web.png)

## Position control: Proportional Factor Kv

The Proportional Factor Kv is the proportional gain factor of the P component of the P-controller. `Output velocity = feed forward velocity + Kv * following error`.

## Position control: Proportional Factor Kv (standstill)

The Proportional Factor Kv (standstill) `Kvs` is the proportional gain factor of the P component of the P-controller, when the axis stands stationarily still. `Output velocity when stationary = feedforward velocity + Kvs * following error`.

## Position control: Proportional Factor Kv (moving)

The Proportional Factor Kv (moving) `Kvf` is the proportional gain factor of the P component of the P-controller, when the axis is moving. `Output velocity when moving = feedforward velocity + Kvf * following error`.

![44024689](/tf50x0_tc3_nc_ptp/1033/Images/png/3457480971__Web.png)![60677888](/tf50x0_tc3_nc_ptp/1033/Images/png/3457484171__Web.png)![9230088](/tf50x0_tc3_nc_ptp/1033/Images/png/3457541771__Web.png)

## Position control: Velocity threshold V dyn [0.0 … 1.0]

A PP controller uses two P constants

* Kv (standstill) `Kvs` and
* Kv (moving) `Kvf`

and a velocity threshold vdyn to define a function for a velocity dependent `kv` factor. When the value of the quotient “setpoint velocity / reference velocity” resides within the velocity threshold interval [- vdyn … + vdyn] the gain factor of the P-controller is linearly interpolated from the proportional factor Kv (moving) `Kvf` towards the proportional factor Kv (standstill) `Kvs` at zero velocity. The diagram below illustrates the connections.

![15961928](/tf50x0_tc3_nc_ptp/1033/Images/gif/3617724683__Web.gif)

The sample is parameterized with `Kvs = 50`, `Kvf = 10` and `v_dyn = 0.2`.

![9439626](/tf50x0_tc3_nc_ptp/1033/Images/png/3457026571__Web.png)![17847776](/tf50x0_tc3_nc_ptp/1033/Images/png/3457029771__Web.png)![26412257](/tf50x0_tc3_nc_ptp/1033/Images/png/3457474571__Web.png)

## Position control: Integral Action Time Tn

Integral Action Time `Tn` of the I component of the PID-controller. Integration time.

## Position control: Derivative Action Time Tv

Rate time `Tv` of the real D component (D-T1 component) of the PID-controller.

## Position control: Damping Time Td

Damping time `Td` of the real D component (D-T1 component) of the PID-controller.

![36383728](/tf50x0_tc3_nc_ptp/1033/Images/png/3457026571__Web.png)![59018101](/tf50x0_tc3_nc_ptp/1033/Images/png/3457029771__Web.png)![61400865](/tf50x0_tc3_nc_ptp/1033/Images/png/3457477771__Web.png)

## Position control: Min./max. limitation I-Part [0.0 … 1.0]

I-part limitation of the PID-controller.

## Position control: Min./max. limitation D-Part [0.0 … 1.0]

D-part limitation of the PID-Controller.

![15736877](/tf50x0_tc3_nc_ptp/1033/Images/png/3457026571__Web.png)![7414170](/tf50x0_tc3_nc_ptp/1033/Images/png/3457029771__Web.png)![66727538](/tf50x0_tc3_nc_ptp/1033/Images/png/3456994571__Web.png)

## Disable I-Part during active positioning

The I-part of the PID-controller can be disabled during active positioning.

![63676932](/tf50x0_tc3_nc_ptp/1033/Images/png/3457026571__Web.png)![36221483](/tf50x0_tc3_nc_ptp/1033/Images/png/3457029771__Web.png)![57557895](/tf50x0_tc3_nc_ptp/1033/Images/png/3456997771__Web.png)

## Feedforward Acceleration: Proportional Factor Ka

The acceleration feedforward proportional factor `Ka` is the gain factor when NC acceleration feedforward control is used. `Output velocity component = Ka * setpoint acceleration`.

## Additional Information: Acceleration Feedforward

Consult section [Acceleration Feedforward](ms-xhelp:///?Id=beckhoff-ab53-49d4-aa94-e8195f14f93e) for more information on Acceleration Feedforward.

## Feedforward Velocity: Pre-Control Weighting [0.0 … 1.0]

This parameter is a relative weighting of the feedforward. Thereby, the default parameter value `1.0` corresponds to 100% feedforward weighting. Velocity feedforward precontrol weighting can be reduced to avoid an overshot in position.
