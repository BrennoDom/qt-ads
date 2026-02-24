# Background Information

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# Background Information

## Coordinate systems – relationships

* **WCS**  
  World Coordinate System.
* **MCS**  
  Machine Coordinate System.
* **UCS**  
  User Coordinate System.
* **PCS**  
  Programmed Coordinate System. Workpiece.

## Pick-and-Place: From warehouse to carrier

![15612815](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5643865227__Web.png)

The workpieces must be taken from the warehouse and placed in the free carrier positions running on the conveyor belt.

Thereby,

* the storage place is defined within the `WCS`,
* the robot is located somewhere within the `WCS`,
* the robot can be controlled within its `MCS`,
* the conveyor belt is located somewhere in the `WCS`,
* on the conveyor belt a carrier can be located within the `UCS`,
* a workpiece can be located within its carrier within the `PCS`.

## Pick-and-Place: From conveyor belt towards conveyor belt

![6297612](/tf5420_tc3_advanced_pick_and_place/1033/Images/png/5643867787__Web.png)

The workpieces have to be taken from the upper conveyor belt and placed on the lower conveyor belt.

Thereby,

* the robot is located somewhere within the `WCS`,
* the robot can be controlled within its `MCS`,
* each conveyor belt is located somewhere in the `WCS`,
* workpieces on the conveyor belt can be located within a `UCS`.
