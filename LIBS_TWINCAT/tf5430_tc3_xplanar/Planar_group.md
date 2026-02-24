# Planar group

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar group

The Planar group is a software object that prevents collisions between Planar movers as well as collisions of Planar movers with the boundary of the stator area on the two-dimensional XPlanar stator area. To do this, the 2D areas of all objects in the group are blocked. When a motion command is transferred to a mover, the required area is requested from the Planar group and the motion command is rejected if this area would collide with already reserved areas. If the motion command can be executed, the area is added to the set of reserved area and blocked accordingly.

Further Information

* [Configuration](ms-xhelp:///?Id=beckhoff-c7e4-4674-924a-b28386438ed1)
* [Example: "Creating and moving Planar movers with group"](ms-xhelp:///?Id=beckhoff-566f-4196-af48-a93ad961d1ce)
