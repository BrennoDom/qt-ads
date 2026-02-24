# Maximum Dynamics, Default Dynamics

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Maximum Dynamics, Default Dynamics

![28099101](/tf50x0_tc3_nc_ptp/1033/Images/png/3260123019__Web.png)![51565323](/tf50x0_tc3_nc_ptp/1033/Images/png/3260117899__Web.png)![61434729](/tf50x0_tc3_nc_ptp/1033/Images/png/3260126219__Web.png)![16041657](/tf50x0_tc3_nc_ptp/1033/Images/png/3260098699__Web.png)![10157186](/tf50x0_tc3_nc_ptp/1033/Images/png/3260095499__Web.png)![24305815](/tf50x0_tc3_nc_ptp/1033/Images/png/3260092299__Web.png)

## Dynamic-Parameters

* Velocity *Vel*,
* Acceleration *Acc*,
* Deceleration *Dec*,
* Jerk.

The *jerk* is the derivative of acceleration or deceleration with respect to time. Thus, it describes how quickly acceleration or deceleration change.

## “Maximum Dynamic-Values” and “Default Dynamic-Values”

|  |  |
| --- | --- |
| *Range of Values* | * Absolute values. * Unsigned. * Positive. * Different from *zero*. |

|  |  |
| --- | --- |
| *Limits* | * With respect to their absolute values, “maximum dynamic-values” exceed their corresponding “default dynamic-values”. * Formally allowed: With respect to its absolute value, a “maximum dynamic-value” equals its corresponding “default dynamic-value”. |

## Tc2\_NC2 Library, Tc2\_MC2 Library

|  |  |
| --- | --- |
| *Tc2\_NC2,Tc2\_MC2* *Default values* | * If the input value "0.0" is assigned to a motion function block for one of the dynamics parameters "Acc, Dec or Jerk", the value "0.0" is replaced by a default value for this parameter. * If no input value is assigned to a motion function block for one of the dynamic parameters "Acc, Dec or Jerk", this dynamic parameter is set to "0.0", and the value "0.0" is replaced by a default value for this parameter. |

|  |  |
| --- | --- |
| *Tc2\_NC2, Tc2\_MC2* *Maximum dynamics* | * The maximum dynamic range is regarded as an actual physical limit for the corresponding axis. * Values exceeding the values prescribed by the maximum velocity are not accepted and will lead to an error. * Values that exceed the maximum acceleration and deceleration are accepted and not rejected. |

|  |  |
| --- | --- |
| *Tc2\_NC2* *"Online Transformation"* | * During an "Online Transformation" from slave to master, various measures are taken to prevent the maximum velocity being exceeded or the direction of movement being reversed. * Examples of such measures are increasing the jerk or increasing the acceleration or deceleration to the maximum value. * From slave to master: Decoupling a slave axis in an accelerated or decelerated movement. |

## Tc3\_McCoordinatedMotion Library, Tc3\_McCollisionAvoidance Library

|  |  |
| --- | --- |
| *Tc3\_Mc* *CoordinatedMotion* *Tc3\_Mc* *CollisionAvoidance* *Default Values* | * If for one of the dynamic-parameters “Acc, Dec, jerk” the input value “0.0” is assigned to a motion function block, this assignment leads to an error that means that this value is not allowed. * If for one of the dynamic-parameters “Acc, Dec, jerk” you would like to refer to a default value at a motion function block, this parameter has to be set to the constant value “*MC\_Default*”. |

|  |  |
| --- | --- |
| *Tc3\_Mc* *CoordinatedMotion* *Tc3\_Mc* *CollisionAvoidance* *Maximum Dynamics* | Vel, Acc, Dec   * For the dynamic-parameters “Vel, Acc, Dec” the parameterized values are used. * For the dynamic-parameters “Vel, Acc, Dec” maximum values can be parameterized at a motion function block using the constant value “*MC\_Maximum*”.   Jerk   * There is no maximum value for the jerk. * The jerk is set to the value “unlimited”. Simultaneously, a three-phase-profile or a three-phase-acceleration-setter is applied for motion.   Default Values   * It is allowed to parameterize default values that exceed their corresponding maximum values. * If a default value is parameterized that exceeds ist corresponding maximum value, a warning will be given, but no error is thrown. * At a Tc3\_McCoordinatedMotion-function block or a Tc3\_McCollisionAvoidance-function block parameterized default values using the constant value *MC\_Default* will be mutually limited to the corresponding maximum values without giving an error message. |
