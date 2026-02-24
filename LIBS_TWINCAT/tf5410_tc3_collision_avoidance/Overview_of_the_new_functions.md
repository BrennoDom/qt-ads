# Overview of the new functions

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Overview of the new functions

**From** V3.1.10.30:

* Behavior change in modulo positioning. Additional turns can now be commanded via the new parameter `ST_MoveAbsoluteCAOptions.AdditionalTurns`. Please read the notes on [Modulo positioning](ms-xhelp:///?Id=beckhoff-b707-4905-b887-f0cfc84eafbd).

**From** V3.1.10.1:

* Track management
* Revised state diagram
* Requires TwinCAT V3.1.4024.7 or higher

**From** V3.1.6.3:

* Geo compensation

**From** V3.1.4.4:

* New: `MC_MAXIMUM` is supported as input value from software version 3.1.4.4. For more detailed information please refer to the documentation for the respective function block.

**From** V3.1.2.47:

* New input [MC\_GAP\_CONTROL\_MODE](ms-xhelp:///?Id=beckhoff-0e9a-45b7-a3fc-2f744339d69e) at each motion function block.
* New flag [MC\_GearInPosCAOptions](ms-xhelp:///?Id=beckhoff-dfb7-4eea-8762-2deabb22447e). OverrideSlaveDynamicRestrictions to improve the behavior when coupled to a master with non-constant velocity (e.g. encoder axis).
* New CA group parameter `GapControlModeDirection` defines the direction of distance monitoring.
