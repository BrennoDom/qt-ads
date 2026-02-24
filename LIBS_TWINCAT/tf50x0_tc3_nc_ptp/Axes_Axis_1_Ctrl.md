# Axes | Axis 1 | Ctrl

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Axes | Axis 1 | Ctrl

## Controller

The purpose of the controller is to operate on the basis of setpoint velocities or other setpoint magnitudes (e.g. acceleration) and on the basis of setpoint magnitude differences as following errors. Controller operation is performed in a way to keep following errors as small as possible and to prevent any axis to undergo any overshots in position or velocity.

Supported is a wide variety of controller versions: Servo position controllers and special controllers for particular axis types.

## Controller Types

* *Position Controllers*: Control the actual position to follow the setpoint position as precisely as possible. Position controller `P`, following error proportional controller, position controller with two `P` constants, following error proportional controller with different constants for the stationary state and for movement, position PID-T1 controller with proportional acceleration feed forward.
* *Controllers for Axes*: Servo axes, stepper motors, low-speed axes, high-speed axes.

![7663035](/tf50x0_tc3_nc_ptp/1033/Images/png/3414196747__Web.png)

At “MOTION | NC-Task 1 SAF | Axes | Axis 1 | Ctrl” the file card Parameter displays the parameter groups

* Monitoring,
* Position Control Loop,
* Other Settings.

Furthermore, the parameter groups

* Velocity Control Loop,
* Observer

may appear.

## Controller Types and their Parameters

The following table lists the available controller types and shows what parameters configure (“x”) or do not configure (“-”) each one of them.

Position controller P
Position controller
with two P constants (with Ka)
Position controller PID
(with Ka)
Position P and
velocity PID controller
(Torque)
Position P and
velocity PI controller
with Observer (Torque)
Two speed controller
Stepper controller
SERCOS controller
(Position by SERCOS)
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
-
x
x
-
x
-
-
-
x
-
x
x
x
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
x
x
x
-
-
-
x
x
x
x
x
x
x
x
-
-
-
x
x
-
-
-
-
-
-
x
x
-
-
-
-
-
-
x
x
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
-
-
-
-
x
-
-
-
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
x
-
-
-
-
-
-
x
x
-
-
-
-
-
-
x
x
-
-
-
-
-
-
x
x
x
-
-
-
-
-
x
x
x
x
x
-
-
-
Monitoring:
Position Lag Monitoring
Maximum Position Lag Value
Maximum Position Lag Filter Time
Position Control Loop:
Position control: Dead Band Position Deviation
Position control: Proportional Factor Kv
Position control: Proportional Factor Kv (standstill)
Position control: Proportional Factor Kv (moving)
Position control: Integral Action Time Tn
Position control: Derivative Action Time Tv
Position control: Damping Time Td
Position control: Min./max. limitation I-Part [0.0 â€¦ 1.0]
Position control: Min./max. limitation D-Part [0.0 â€¦ 1.0]
Disable I-Part during active positioning
Position control: Velocity threshold V dyn [0.0 â€¦ 1.0]
Feedforward Acceleration: Proportional Factor Ka
Feedforward Velocity: Pre-Control Weighting [0.0 â€¦ 1.0]
Velocity Control Loop:
Velocity control: Proportional Factor Kv
Velocity control: Integral Action Time Tn
Velocity control: Derivative Action Time Tv
Velocity control: Damping Time Td
Velocity control: Min./max. limitation D-Part [0.0 â€¦ 1.0]
Velocity control: Min./max. limitation I-Part [0.0 â€¦ 1.0]
Observer:
Velocity Filter: Time Constant T
Observer Mode
Motor: Torque Constant Kt
Motor: Moment of Inertia Jm
Bandwidth f0
Correction Factor Kc
Other Settings:
Controller Mode
Auto Offset
Offset Timer
Offset Limit (of Calibration Velocity)
Slave coupling control: Proportional Factor Kcp
Controller Outputlimit [0.0 â€¦ 1.0]

Further Information

* [Monitoring](ms-xhelp:///?Id=beckhoff-dff8-40da-ba32-863b106cea0b)
* [Position Control Loop](ms-xhelp:///?Id=beckhoff-2259-4ae8-8c12-488e37577224)
* [Velocity Control Loop](ms-xhelp:///?Id=beckhoff-8bf2-40d9-9971-faeac9583084)
* [Observer](ms-xhelp:///?Id=beckhoff-f007-41a5-a0c9-9ca1d6e889ab)
* [Other Settings](ms-xhelp:///?Id=beckhoff-75a6-45bc-8aca-2c0961761fe4)
