# Position measuring system

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e)
3. [Commissioning](ms-xhelp:///?Id=beckhoff-89eb-40cd-9eeb-3b237fbc590a)
4. Position measuring system

# Position measuring system

The axis should show a plausible actual position for both an absolute and an incremental position measuring system. The zero point of the encoder and the defined zero point of the axis usually do not coincide. On the **Encoder** tab, you can enter the desired current position and transfer it to the axis via the **Set-Pos** button. At this point in time, this set position does not have to match the actual position exactly. Especially with incremental measuring systems, homing is carried out later on.

![19079158](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/4761619211__Web.gif)

The PlcMcManager adapts the display of the parameters as far as possible to the set encoder type. As a result, different parameters can be visible for different axes.

For incremental encoder types, the diagram shown above appears. The visibility of the parameters for homing depends on the set homing method.

To avoid collisions during commissioning, the software limit switches should be activated and set appropriately in the **Monitor** tab. Since the actual position can differ slightly from the actual position, it is recommended to set the software limit switches a little closer.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
