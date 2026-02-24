# Planar track operation modes

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar track operation modes

The Planar track has four different operation modes that indicate whether and how the track performs or can perform its function as a "Street for Movers": Moving, Standing, Configuring and Uninitialized.

![34934986](/tf5430_tc3_xplanar/1033/Images/png/9007208306690187__Web.png)

## Moving

In Moving mode, one or more movers are about to move on the track (MoveOnTrack). The first mover to start a movement on the track in Standing mode automatically changes the mode from Standing to Moving. Accordingly, the last mover that completes its movement changes the mode back to Standing. No mover is allowed to execute a JoinTrack or LeaveTrack command while the track is in Moving mode. If the track is in a Planar group, it blocks its surface.

## Standing

In Standing mode the track is usable by movers. All movers on the track are standing and waiting for travel commands. JoinTrack, LeaveTrack and MoveOnTrack commands are allowed for the movers in this mode. Each of these commands ends the Standing mode of the track. If the track is in a Planar group, it does not block its surface.

## Configuring

In Configuring mode, one or more movers are about to leave the track (LeaveTrack) or join the track (JoinTrack). The first mover to leave (or join) the track in Standing mode automatically changes the mode from Standing to Configuring. Accordingly, the last mover to complete leaving or joining changes the mode back to Standing. No mover is allowed to execute a MoveOnTrack command while the track is in Configuring mode. If the track is in a Planar group, it does not block its surface.

## Uninitialized

The track is not usable by movers in the Uninitialized mode. It does not have a finished geometric description yet. When the user creates and enables this geometric description, the track switches to Standing mode.
