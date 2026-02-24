# Homing procedures

## Library
tcplclib_tc3_mc2_advancedhoming

## Category
Motion Control

# Homing procedures

Until now referencing procedures have been treated as separate sequences during the start phase of a machine or axis. The actual sequence was not visible to the user. In order to gain more control on the referencing sequence itself, user-specific referencing procedures can now be programmed:

* **HomeAbsoluteSwitch –** homing to a sensor with movement range limit position sensors
* **HomeLimitSwitch –** homing to a movement range limit position sensor
* **HomeBlock –** homing to a mechanical fixed stop
* **HomeReferencePulse –** homing to the zero track of an encoder
* **HomeDirect –** static homing, position is set to the user position
* **HomeAbsolute -** static homing, position is set to the position of a reference encoder
