# Planar TrackTrail

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar TrackTrail

The MC\_PlanarTrackTrail is an object that defines a path of consecutive Planar tracks in a network. Unlike the individual Planar tracks from which the Planar TrackTrail is built, the Planar TrackTrail has no fixed equivalent in a TCOM object on the MC side, but is declared solely in the PLC, similar to a [Planar Feedback](ms-xhelp:///?Id=beckhoff-cb94-4ca3-8efe-c1c971af05f5).

A PlanarTrackTrail can be used to define a path of Planar tracks over which a synchronization movement of a Slave Planar Mover [Example "Synchronizing a Planar mover on a track with one axis"](ms-xhelp:///?Id=beckhoff-601e-4ac1-ac69-f22aa6a5fa8b) or [Example: "Synchronizing a Planar mover on a track with another Planar mover"](ms-xhelp:///?Id=beckhoff-1246-47be-8dc9-d0045da148ba) should take place (if this path consists of more than the current Planar track of the Slave Planar Mover).

The Planar TrackTrail provides methods for adding a Planar track at its end and emptying its configuration. These methods modify only the Planar TrackTrail and, in particular, leave the underlying Planar tracks and the network untouched.

When adding a Planar track, make sure that it connects to the end of the current last Planar track in the Planar TrackTrail. It is impossible for a Planar track to be added more than once.

Further Information

* [Example "Synchronization movement over two Planar tracks"](ms-xhelp:///?Id=beckhoff-4510-4569-b911-12eec2a707ef)
