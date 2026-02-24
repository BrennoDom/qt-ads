# Time-based axis control

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. [Dynamics/target approach](ms-xhelp:///?Id=beckhoff-2d7c-4725-a2bb-6a61eee54a70)
5. Time-based axis control

# Time-based axis control

If the axis control is to be time-based, the position controller is active during the entire motion. This option should only be used for axes with a high natural frequency and ideally with a zero overlap valve.

The acceleration must be limited to values that the axis can follow without strong vibration. Special attention should be paid to starting up.

When braking, the deceleration must be adjusted so that the axis can follow the set value ramp.

The creep velocity, creep distance and braking distance can be set to zero. The actual position must follow the set position to avoid overshooting. If this is not the case, the pre-control must be reduced.

At this point, the axis is fully commissioned for positioning. If a pressure regulator, cam plate or gear coupling is used in the application, these elements must also be put into operation.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
