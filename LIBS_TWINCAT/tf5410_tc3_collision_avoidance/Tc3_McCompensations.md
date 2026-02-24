# Tc3_McCompensations

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Tc3\_McCompensations

## What do setpoints refer to?

Setpoints always refer to the XTS motor path, because it is the motor that physically has to be moved. Consequently, a motor movement leads to a target position on the XTS motor path and thus on the path of the tool center point.

Even if the setpoints for the path dynamics are applied to the XTS motor path, they can be calculated for the dynamic control of the path of the tool center point. Accordingly, the `y` offset depends on the desired application and may be different for different applications. For example, the control of the center of gravity dynamics or the improvement of the performance of a tool mounted on a mover could be intended. In particular, a different tool size may require a different mover template. When the path for the tool center point is selected, setpoints are calculated to control it dynamically.

## Coordinate system of the XTS motor path

The origin of the coordinate system of the mover's motor path is located on the mover's motor path at the offset `x` value defined in the XTS standard object.

## Coordinate system of the Tool Center Point

The origin of the Tool Center Point coordinate system is at the Tool Center Point.

## XTS motor path to Tool Center Point: Understanding the coordinate transformation

The coordinate transformation from the motor path of the mover to the Tool Center Point is always perpendicular to the motor path of the mover. Ideally and theoretically, the scalar product of the vector describing the translation of the motor path of the mover to the Tool Center Point and the corresponding vector of the tangent of the motor path of the mover has the value zero.

Further Information

* [Function Blocks](ms-xhelp:///?Id=beckhoff-a87e-4c26-8aef-16a895027567)
