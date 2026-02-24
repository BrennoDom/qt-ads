# Movement directions

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Movement directions

# Movement directions

The jog button should be used to move the axis slowly. If this is not the case, the pressure supply must be checked. Furthermore, switching valves may also have to be operated or the compensation of the valve overlap is set too small.

It is recommended to specify a positive direction of movement for the axis that corresponds to the way the machine works. If the axis moves in this direction, the actual position should count upwards. If this is not the case, the counting direction can be inverted on the **Encoder** tab. If the direction of change of the indicated position corresponds to the mechanical movement, but the direction of action of the given commands is not as desired, the output can be inverted on the **Valve** tab.

|  |  |
| --- | --- |
| 61772230 | When the valve output is inverted, the offset compensation must be adjusted, as it is not inverted and its effect is reversed. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
