# Path Override (Interpreter Override Types)

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Path Override (Interpreter Override Types)

The path override is a velocity override. Consequently, changing the override creates a new velocity, but does not affect the ramps (acceleration or jerk). The applicable override types merely differ in terms of their underlying reference velocity.

The parameterization takes place in the interpolation channel under the group parameters.

## Option “Reduced (iterated)”

![54151655](/tf50x0_tc3_nc_ptp/1033/Images/gif/3509609227__en-US__Web.gif)![17602849](/tf50x0_tc3_nc_ptp/1033/Images/gif/3510039691__en-US__Web.gif)

*Based on the reduced velocity (default).*

Because of the relevant dynamic parameters (braking distance, acceleration etc.) it is not possible for the programmed velocity, depicted by the blue line, to be achieved in every segment. For this reason, for each geometric segment a velocity, depicted by the red line, is calculated that may possibly be reduced compared to the programmed velocity. In the standard case, the override is made with reference to this possibly reduced segment velocity.

The advantage of this override type is that the machine operates with an approximately linear reduction in velocity when override values are small. Therefore, “Reduced (iterated)” is the correct setting for most applications:

vres = vmax \* Override.

## Option “Original (iterated)”

![24207921](/tf50x0_tc3_nc_ptp/1033/Images/gif/3509601163__en-US__Web.gif)![16544703](/tf50x0_tc3_nc_ptp/1033/Images/gif/3510039691__en-US__Web.gif)

*Based on the programmed path velocity.*

The override value is based on the velocity programmed by the user. The maximum segment velocity has merely a limiting effect.

## Option “Reduced [0 … >100%]”

*Based on internally reduced velocity with the option to specify a value greater than 100%.*

From TwinCAT V2.10, Build 1329.

Generally, the override type behaves like “Reduced (iterated)”. More specifically, with this override type it is possible to travel along the path more quickly than programmed in the G-Code. There is no limitation to 120%, for example. The maximum possible path velocity is limited by the maximum velocities of the axis components (`G0` velocity) and their dynamics.

If limitation to a particular value, e.g. 120%, is required, this limitation can be set within the PLC project.
