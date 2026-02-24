# Valve

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. Valve

# Valve

The valve is generally the actuator, which controls the axis. For continuous valves, a distinction is made between:

* Servo valve
* Proportional valve
* Control valve

## Servo valve

These valves control large oil flows via small electrical signals

* A small torque motor controls the connected control oil, thereby adjusting the slider of the main stage.
* Often multi-stage design
* High responsiveness and controllability

## Proportional valve

A coil current generates a proportional force, which moves the valve slider against the force of a spring.

Compared to servo valve:

* Longer step response time
* Higher current consumption
* Larger hysteresis
* More robust against contamination
* Attractive price

## Control valve:

A proportional valve, for which the slider position is measured and automatically adjusted:

* Shorter step response time
* Smaller hysteresis
* Smaller load reaction
* More complex and more expensive than proportional valves
* Electronics on the valve or in the control cabinet

## Basic principles of reading valve data sheets

A continuous valve is usually used as actuator for a controller. The designs of valves from different manufacturers or different types may differ quite significantly. In order to adapt the output scaling to the particular situation, the valve data sheet for the continuous valve must be available during commissioning. A valve has a number of hydraulic ports. A and B are the valve outputs; A is connected to the cylinder side with the larger piston area, B is connected to the cylinder side with the smaller piston area. P and T represent the supply connections. P is the pressure line, and T is the return line to the tank.

|  |  |
| --- | --- |
| 54645451 | In the hydraulics library, the A-side is always the side under positive pressure, the B-side is the side under negative pressure. |

In many cases the valve slide has to move slightly before an oil flow can be detected. This stroke is listed in the valve data sheet under overlap.

|  |  |
| --- | --- |
| 22047016 | The data sheet may indicate an overlapped valve, although this overlap is compensated in the valve electronics. |

![64205424](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/1600156683__Web.gif)

The characteristic volume flow curve shows the key information for the valve. The diagram above shows that the piston itself has an overlap of 20%, which was reduced to 5% in the valve electronics. As a result, no overlap compensation via the hydraulics library is required.

|  |  |
| --- | --- |
| 40977906 | The fact that overlap compensation was carried out in the valve does not make it a zero overlap valve, and the axis is therefore only capable of position control to a limited degree. |

The diagram shows that the oil flow in the A-chamber of the piston is greater than the oil flow in the B-chamber. This asymmetry indicates an area compensation in valve, in this case with a ratio of 11:6.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
