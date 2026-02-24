# Displacement-based axis

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. [Dynamics/target approach](ms-xhelp:///?Id=beckhoff-2d7c-4725-a2bb-6a61eee54a70)
5. Displacement-based axis

# Displacement-based axis

The position controller is only active for the target approach.   
The acceleration can be set so steeply that the axis gently accelerates without significant jerks when it starts moving.   
For braking on the target approach, not only the deceleration but also the creep distance, creep velocity and braking distance must be set. All three parameters depend on each other and influence the target approach. If the axis is within the braking distance, it is only controlled by the position controller. The creep velocity and creep distance are used to stabilize the axis after deceleration, in order to take it to its target via the position controller.

The target approach should look like this:

![59414099](/tf5810_tc3_hydraulic_positioning/1033/Images/png/9007203500827403__en-US__Web.png)

It is often observed that an axis that is extremely slowed down requires a longer creep phase in order to position as accurately as an axis with a gentler deceleration.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
