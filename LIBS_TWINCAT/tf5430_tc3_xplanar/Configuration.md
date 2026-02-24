# Configuration

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Configuration

:   In order to create a Planar track, an **MC Configuration** must first be created.

:   1. Select **MOTION** > **Add New Item...**
![52933326](/tf5430_tc3_xplanar/1033/Images/png/9225015435__Web.png):   2. In the following dialog box, select **MC Configuration** and confirm with **OK**.
![6637886](/tf5430_tc3_xplanar/1033/Images/png/9225017355__Web.png):   You have created an MC Project.
:   3. Select **MC Project** > **Groups** > **Add New Item…**.
![59740974](/tf5430_tc3_xplanar/1033/Images/png/9225011595__Web.png):   4. In the following dialog box, create one (or more) Planar tracks and confirm with **OK**.

![797855](/tf5430_tc3_xplanar/1033/Images/png/9250423051__Web.png):   The Planar track is now created and can be parameterized.

## Open detailed description

* Select the Planar track in the tree and double-click it.

**Meaning of the individual tabs**

**Object:** General information (name, type, ID and so on) is shown here.

![7180698](/tf5430_tc3_xplanar/1033/Images/png/9250426379__Web.png)

**Parameter (Init):** Specifies initial parameters that the user can change in order to affect the behavior of the track.

![64626289](/tf5430_tc3_xplanar/1033/Images/png/9007208505182731__Web.png)

The initial parameters are initially set so that the Planar track (ready linked) can be traversed with the hardware. If the movers on the track are larger or smaller, the two "Maximum mover width/height" parameters should be adjusted. The parameter "Check collision against static objects" determines whether a track in a Planar group is checked for collisions with other static objects (tracks/edge of the stator surface). The parameter "Collision range mode" determines whether the "Collision range at start/end" is specified by the user via the corresponding parameters or whether it is automatically calculated internally by the track. The "Collision range" is the distance from the start/end of the track from which a Planar mover is taken into account for collision avoidance for Planar movers on other tracks.

**From version V3.1.10.44:** The parameters "Geometric information", "Closed loop", "Starts from tracks" and "Ends at tracks" can be used to define the geometry of the track and its connection to other tracks. The parameters have exactly the same effect as the corresponding PLC commands.

**Parameters (Online):** Shows the state of the track at runtime, e.g. the number of Planar movers or the length.

![44765691](/tf5430_tc3_xplanar/1033/Images/png/9007209493523723__Web.png)

**From version V3.1.10.30:** The parameters "Previous Tracks" and "Subsequent Tracks" are arrays containing the OIDs of all tracks directly before or directly after this track.

**From version V3.1.10.44:** The parameter "Geometric online information" displays the geometry of the track available at runtime. This results from the corresponding initial parameter and/or the PLC commands used.

**Data Area:** Shows the memory area via which the track communicates with the PLC track.

![238043](/tf5430_tc3_xplanar/1033/Images/png/9718460683__Web.png)
