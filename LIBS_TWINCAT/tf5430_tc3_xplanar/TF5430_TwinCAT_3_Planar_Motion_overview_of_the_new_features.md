# TF5430 TwinCAT 3 Planar Motion – overview of the new features

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# TF5430 TwinCAT 3 Planar Motion – overview of the new features

**From** version V3.1.10.51:

* New: AdoptTrackOrientation rotates the mover on the track to the track orientation. This changes the C coordinate mode from independent to dependent.
* Advanced: MoveC now always works for standing movers on the track. This may change the C coordinate mode from dependent to independent.

**From** version V3.1.10.44:

* New: GearInPosOnTrack and GearInPosOnTrackWithMasterMover commands for coupling a Planar mover to a master axis or a master mover, respectively
* Advanced: Parameters of the Planar track TcCOM module
* Requires TwinCAT V3.1.4024.17 or higher

**From** version V3.1.10.30:

* New: CRotation command mode (360° rotation) with modulo positioning
* New: Constraints as a new variant to limit the dynamics of the motion commands
* Advanced: Parameters for modulo positioning on "Closed Loop" tracks

**From** version V3.1.10.11:

* First version of Planar Motion released
* Requires TwinCAT V3.1.4024.12 or higher
