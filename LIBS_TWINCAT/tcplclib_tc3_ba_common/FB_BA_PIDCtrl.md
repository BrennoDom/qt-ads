# FB_BA_PIDCtrl

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# FB\_BA\_PIDCtrl

![45525183](/tcplclib_tc3_ba_common/1033/Images/gif/9007203824470795__Web.gif)

Universal PID controller, alternatively in parallel structure or with upstream proportional component.

## Functional description

This controller is divided internally into two consecutive parts:

* the controller itself, illustrated in the functional diagrams below as P, I and D component with an output limitation.
* a deadband element that applies a hysteresis to the output changes of the controller.

## Functional diagram

*udiMode* = 0 (upstream proportional component):

![7073466](/tcplclib_tc3_ba_common/1033/Images/gif/4936089483__en-US__Web.gif)

*udiMode* = 1 (parallel structure):

![63661202](/tcplclib_tc3_ba_common/1033/Images/gif/4936094219__en-US__Web.gif)

## Passive behavior (bEn = FALSE)

The outputs are set as follows:

|  |  |
| --- | --- |
| rY | 0.0 |
| rE | 0.0 |
| bARW | FALSE |

The internal values for the P, I, and D components are set to 0, also the values for the I and D components of the preceding cycle. In case of a restart the control value is thus calculated in the first cycle without past values.

## Active behavior (bEn = TRUE)

In the first cycle, the I and D components are calculated "clean", i.e. without historical values, as already mentioned.

## Synchronization

A positive signal at *bSync* sets the I component such that the control value assumes the value *rSync*. If *bEn* and *bSync* are set at the same time, this method can be used to set an initial value as a starting point for the control. If the I component is not active, the D component is set accordingly. Note that internally only the rising edge of *bSync* is evaluated, in view of the fact that it is a set action. For a further synchronization, e.g. with a transfer value, a TRUE signal must be set again at input *bSync*.

## Anti-Reset-Windup

If the I component is active, the controller ensures that it this maintained if the controller output *rY* should try to go beyond the limits *rYMin* or *rYMax.* A preliminary calculation of the controller output takes place inside the controller in every cycle. If this is smaller than the lower output limit *rYMin* or greater than the upper limit *rYMax*, then the I component is adjusted in such a way that the sum of the P, I and D components results in *rYMin* or *rYMax* respectively. This ensures that the I component is always just large enough so that the control value can immediately assume values within the limits in the case of a corresponding control deviation without an integral component that has become too large having to be reduced first.

## Direction of action

*bActn* = FALSE can be used to reverse the direction of action such that a control deviation of less than 0 results in a change in control value to positive. This is achieved by a negative calculation of the control deviation:

| **bActn** | **rXW (control deviation)** | **Direction of action** |
| --- | --- | --- |
| TRUE | *rX*-*rW* (actual value-set value) | direct (*cooling)* |
| FALSE | *rW*-*rX* (set value-actual value) | indirect (heating) |

## Neutral zone

A value of *rNZ* > 0.0 enables the function of the neutral zone (deadband). A value equal to zero deactivates the deadband element and the values at the input are passed directly through.

If, in the active case, the change at the input of the element *rYin* in a PLC cycle is smaller than *rNZ*/2 in comparison with the previous PLC cycle, then the output is held at the value of the previous cycle until the change is larger than or equal to *rNZ*/2.

**Example**: *rNZ* = 1, *rYin* = 55.0, *rY* = 55.0

|  |  |  |
| --- | --- | --- |
| PLC cycle+1 | *rYin* = 55.2 | *rY* = 55.0 |
| PLC cycle+2 | *rYin* = 55.3 | *rY* = 55.0 |
| PLC cycle+3 | *rYin* = 55.1 | *rY* = 55.0 |
| PLC cycle+4 | *rYin* = 55.6 | *rY* = 55.6 |
| PLC cycle+5 | *rYin* = 55.4 | *rY* = 55.6 |
| PLC cycle+6 | *rYin* = 55.3 | *rY* = 55.6 |
| PLC cycle+7 | *rYin* = 55.1 | *rY* = 55.1 |

This function is intended to avoid an unnecessarily large number of actuating pulses.

## VAR\_INPUT

```
bEn         : BOOL;  
rW          : REAL;  
rX          : REAL;  
udiOpMode   : UDINT;  
bActn       : BOOL;  
rKp         : REAL;  
udiTn_ms    : UDINT;  
udiTv_ms    : UDINT;  
udiTd_ms    : UDINT;  
rYMax       : REAL;  
rYMin       : REAL;  
rNZ         : REAL;  
udiCycCl    : UDINT;  
bSync       : BOOL;  
rSync       : REAL;
```

**bEn:** Controller activation.

**rW:** Set value.

**rX:** Actual value.

**udiOpMode:** *udiMode* = 0: Controller with upstream proportional component, *udiMode* = 1: Controller in parallel structure. Internally limited to the values 0 and 1.

**bActn:** [Direction of action](ms-xhelp:///?Id=beckhoff-480e-47a5-877e-eb3ff0f703a7) of the controller.

**rKp:** Controller gain. Only affects the proportional component. Internally limited to a minimum value of 0.

**udiTn\_ms:** Integral action time of the I component [ms]. A zero value at this parameter disables the I component. Internally limited to a minimum value of 0.

**udiTv\_ms:** Rate time of the D component [ms]. A zero value at this parameter disables the D component. Internally limited to a minimum value of 0.

**udiTd\_ms:** Damping time of the D component [s]. Internally limited to a minimum value of 0.

**rYMax:** Upper controller output limit. Selectable range: 0..100%.

**rYMin:** Lower controller output limit [%]. Selectable range: 0..100%. The value *rYMin* is upwardly limited by *rYMax*.

**rNZ:** Neutral zone.

**udiCycCl:** Call cycle of the function block as a multiple of the cycle time. Internally limited to a minimum value of 1.

Example: *tTaskCycleTime* = 20ms, *udiCtrlCycleCall* =10 -> The control algorithm is called every 200 ms. Thus the outputs are also updated only every 200 ms.

**bSync / rSync:** Synchronization command: Set output value *rY* to *rSync.* The value *rSync* is limited internally to values ranging from *rYMin* to *rYMax*.

## VAR\_OUTPUT

```
rY        : REAL;  
rE        : REAL;  
bARW      : BOOL;
```

**rY:** Control value. Range limited by *rYMin* and *rYMax.*

**rE:** Control deviation (The calculation depends on the [direction of action](ms-xhelp:///?Id=beckhoff-480e-47a5-877e-eb3ff0f703a7)).

**bARW:** Anti-Reset-Windup function is active.

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
