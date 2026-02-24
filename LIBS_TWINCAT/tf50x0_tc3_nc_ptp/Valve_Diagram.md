# Valve Diagram

## Library
tf50x0_tc3_nc_ptp

## Category
Motion Control

# Valve Diagram

![4491214](/tf50x0_tc3_nc_ptp/1033/Images/png/3458696971__Web.png)![40420929](/tf50x0_tc3_nc_ptp/1033/Images/png/3458700171__Web.png)![28244045](/tf50x0_tc3_nc_ptp/1033/Images/png/3460175371__Web.png)

Within this section cam tables are employed to construct linear position coupling. Thus, for numerical control e.g. a hydraulic axis may be treated similarly to a servo axis.

A cam plate is a relation `R` that describes non-linear position coupling between a master axis and a slave axis:

* `y = R(x)`,
* `x`-axis: master axis position,
* `y`-axis: slave axis position.

This relation is stored within a valve diagram table. Within this table the number pairs `(x, y)` are discrete.

## Valve Diagram: Table Id

Each valve diagram table has its own identification number Id. It is assigned serially to each table. The table Id uniquely identifies the cam plate in the TwinCAT system.

## Valve Diagram: Interpolation type

Two interpolation types

* ‘LINEAR’ or
* ‘SPLINE’

can be selected to join the discrete number pairs `(x, y)` within the valve diagram table.

## Valve Diagram: Output offset [-1.0 … 1.0]

This parameter allows to adjust a zero transition of a position coupling curvature through the origin. Thus, e.g. a hysteresis branch can be adjusted to run through the origin.

## TwinCAT PLC Hydraulics Library

Employing a cam plate relation some simple types of hydraulic axes can be controlled like servo axes. For more intricate types of hydraulic axes follow

* [TwinCAT PLC Hydraulics](https://infosys.beckhoff.com/content/1033/tcplclibhydraulics30/index.html) or  
  https://infosys.beckhoff.com/content/1033/tcplclibhydraulics30/index.html

to find information on controlling them with the TwinCAT PLC Hydraulics Library.
