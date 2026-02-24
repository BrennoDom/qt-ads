# Dynamics/target approach

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Dynamics/target approach

# Dynamics/target approach

At this point in time, the axis is able to position with different velocities and moderate dynamics.

On the **Monitor** tab you can set when the axis should report ready. An axis is in the target if the remaining distance is smaller than PosRange and BrakeDistance; for the TargetFilterTime the remaining distance must be smaller than Targetrange. These three parameters must be set appropriately according to the application requirements.

The user subsequently has to decide whether the axis should be positioned time-based or displacement-based.

Most hydraulic applications can be operated path-controlled. If, however, time-based profile generation is necessary, the **TimeBased** check mark should be set.

Further Information

* [Displacement-based axis](ms-xhelp:///?Id=beckhoff-1801-45e3-8703-efa4ae9f4d78)
* [Time-based axis control](ms-xhelp:///?Id=beckhoff-a13d-4bb7-8607-6a2f5d34bbc3)

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
