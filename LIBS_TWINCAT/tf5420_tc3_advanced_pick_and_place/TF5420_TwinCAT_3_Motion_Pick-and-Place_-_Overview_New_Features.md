# TF5420 TwinCAT 3 Motion Pick-and-Place - Overview New Features

## Library
tf5420_tc3_advanced_pick_and_place

## Category
Motion Control

# TF5420 TwinCAT 3 Motion Pick-and-Place - Overview New Features

**From** V3.1.10.1:

* New group type MC Group Coordinated Motion is available.
* Cyclic interface is extended for MC Group Coordinated Motion.
* New function blocks for MC Group Coordinated Motion:

+ MC\_BlockerPreparation
+ MC\_ReleaseBlocker
+ MC\_GroupReadBlockerStatus
+ MC\_DwellTimePreparation

* MC\_GroupHalt is implemented for MC Group Coordinated Motion.
* mcTransModeCornerDistance, mcCircPathchoiceShortSegment and mcCircPathchoiceLongSegment are implemented for MC Group Coordinated Motion.
* Requires TwinCAT V3.1.4024.7 or higher

**From** V3.1.6.27:

* The remaining time and distance of the current segment can be read via ADSREAD.
* Requires TwinCAT V3.1.4022.0 or higher

**From** V3.1.6.3:

* New function blocks for spatial transformations, i.e. for changing the reference system (`MC_SetCoordinateTransform`) and for conveyor tracking (`MC_TrackConveyorBelt`).

**From** V3.1.4.4:

* New: `MC_MAXIMUM` is supported as input value from software version 3.1.4.4. For more detailed information please refer to the documentation for the respective function block.

**From** V3.1.2.47:

* New function block MC\_MoveCircularAbsolutePreparation.
