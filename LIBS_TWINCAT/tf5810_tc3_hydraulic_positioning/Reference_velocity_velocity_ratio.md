# Reference velocity/velocity ratio

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Reference velocity/velocity ratio

# Reference velocity/velocity ratio

|  |  |
| --- | --- |
| 37494699 | This chapter describes manual commissioning. A characteristic curve measurement also determines the parameters discussed here. If it is used, this chapter should be skipped. |

Once the axis can be moved at low velocity, the reference velocity must be set.

In order to determine the reference velocity, the set velocity is increased step-by-step, and a check is carried out to determine whether the axis follows with approximately the set velocity.

|  |  |
| --- | --- |
| 1907972 | In this step, only movements in the faster direction are to be evaluated. The oil is transported into the small piston surface! The next step deals with directional dependency. |

To trigger the required movements, the position and velocity can be specified in the **Status** tab. The movement is executed with the Start button. The previously created Scope View should be used to analyze the velocities.

|  |  |
| --- | --- |
| 17171756 | The software limit switches should be activated and set so that the axis does not hit the mechanical limit stops. |

![20328083](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600183435__Web.gif)

If the actual velocity is much lower than the set velocity, the reference velocity should be reduced.

If the actual velocity is much higher than the set velocity, the reference velocity should be increased.

The appropriate reference velocity has been found when the medium to high set and actual velocities almost match.

|  |  |
| --- | --- |
| 48735027 | The reference velocity does not have to correspond to the actual or calculated maximum velocity of the axis. |

The following diagram shows the linearization section-by-section through overlapping and reference velocity with a non-linear characteristic curve. It is left to the user to decide where the maximum deviation between the linearization and the actual characteristic curve can occur.

![35962059](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600202891__Web.gif)

The usual asymmetry of the cylinders causes the axis to move too slowly in the slower direction at any commanded velocity when the reference velocity is set. This behavior can be compensated for on the Valve tab by using the velocity ratio parameter.

When the behavior is symmetrical, this parameter should be set to 1,000. If the positive direction of travel is the slower direction, use a value greater than 1,000. If the negative direction of travel is the slower direction, a value less than 1,000 should be used. This increases the output in the slower direction and compensates for the asymmetry.

|  |  |
| --- | --- |
| 55223077 | With this compensation, the output can only be increased up to its maximum value. The parameterization must be carried out at velocities that the axis can reach in both directions. |

|  |  |
| --- | --- |
| 27245651 | If the parameter is changed in the wrong direction, the velocity decreases in the faster direction. In this case the reference velocity must not be corrected. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
