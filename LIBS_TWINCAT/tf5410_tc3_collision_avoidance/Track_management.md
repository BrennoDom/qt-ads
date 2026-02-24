# Track management

## Library
tf5410_tc3_collision_avoidance

## Category
Motion Control

# Track management

With the aid of track management an XTS configuration can be divided into individual, spatially separated XTS parts. These can comprise just one or any number of consecutive motor modules. Individual, adjacent XTS parts can be combined to XTS tracks. The XTS parts and XTS tracks can be configured via the [XTS Configurator](https://infosys.beckhoff.com/index.php?content=../content/1031/xts_software/8398119691.html&id=8116219233490731735). In the system manager, the XTS parts and XTS tracks are inserted as TcCOM modules, with a unique ObjectID, as child nodes below the XTS Processing Unit (see [XTS documentation](https://infosys.beckhoff.com/index.php?content=../content/1031/xts_software/8398119691.html&id=8116219233490731735)).

![53130157](/tf5410_tc3_collision_avoidance/1033/Images/png/8969311627__Web.png)

For each individual axis a track can be activated via the function block MC\_ActivateTrack using the ObjectID of the XTS track. When activating an XTS track, the mover must be on an XTS part that is assigned to the track. ObjectID 0 can be used to reactivate the absolute reference system for the individual axis. The current target positions on the tracks and parts can be read out using the function block MC\_ReadTrackPositions.
