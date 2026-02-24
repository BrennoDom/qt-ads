# Overlap

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Overlap

# Overlap

In order to determine the overlap, the set velocity must be increased slowly until a response by the actual velocity can be recognized. It is possible that the set velocity must be increased to a value of up to 30 mm/s before a response of the actual velocity can be seen. When measuring the overlap, the overlap itself should always be set to zero.

If different velocity set values are required in order to move the axis in positive or negative direction from standstill, this indicates an asymmetric valve. In this case the check mark **Asym** in the **Global** tab must be set and activated. The valve can now be parameterized separately in positive and negative direction.

The set velocity at which the axis moves must be entered under Overlap in the "Valve" tab. If the overlap has already been assigned a value, this value must be taken into account. For asymmetric valves ensure that the entry is made in the correct field; the overlap for the positive direction is expected in the upper field, the overlap for the negative direction in the lower field.

After this optimization the axis should also respond at different small velocities. Whether the axis responds with the right velocity is not important.

If an overlap has been entered from the data sheet and the axis always moves too fast, the overlap should be reduced.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
