# Planar mover command diagram

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Planar mover command diagram

The Planar mover has six different command modes that indicate what type of command the mover executes: OnTrack, LeavingTrack, JoiningTrack, ExternalSetpointGeneration and CRotationFreeMovement/-OnTrack (from Version V3.1.10.51). In all modes except ExternalSetpointGeneration mode, collision avoidance is active for the mover when it is in a group.

![48620907](/tf5430_tc3_xplanar/1033/Images/png/9007209477574539__Web.png)

## OnTrack

In the OnTrack mode the mover joins a track and can be moved on it (MoveOnTrack). The mover can also leave the track again (LeaveTrack), which changes the mode to LeavingTrack. MoveC commands cause a change to CRotationOnTrack mode if necessary.

## LeavingTrack

In LeavingTrack mode the mover does not accept any further commands. The mode is quit automatically when the mover has ended the LeaveTrack command. The mover is then in FreeMovement mode.

## JoiningTrack

In JoiningTrack mode the mover does not accept any further commands. The mode is quit automatically when the mover has ended the JoinTrack command. The mover is then in the OnTrack mode.

## FreeMovement

After enabling the mover, it is automatically in this command mode, unless the mover is twisted too much. Then it is in CRotationFreeMovement mode. The mover can be moved freely with MoveToPosition commands. If the user starts the external setpoint generation via a command, the mode switches to ExternalSetpointGeneration. JoinTrack commands are also possible that change the mode to JoiningTrack. MoveC commands may cause a change to the CRotationFreeMovement mode.

## CRotationFreeMovement/-OnTrack

This mode is started by the MoveC command if the C-movement that is in progress does not take place entirely within a C-position window. The windows are defined by the position limits of the C-axis of the mover and exist 4 times each rotated by 90° (the 90° rotation results from the mover symmetry: e.g. limits +-15° -> window 1. [-15°,+15°], 2. [75°,105°], 3. [165°,195°], 4. [255°,285°]). Depending on whether you were previously in FreeMovement or OnTrack mode, the mode will be CRotationFreeMovement or CRotationOnTrack accordingly. The mode is finished when the C-movement is completed and the end position is within one of the four windows. The mover then automatically returns to the previous mode. The mover thus changes from CRotationFreeMovement to *FreeMovement* or from CRotationOnTrack to *OnTrack*. Otherwise, it remains in CrotationFreeMovement/-OnTrack mode. In both CRotation modes, the X and Y-axes of the mover cannot be moved. If the mover already has an orientation outside the 4 windows when it starts up, it is immediately in CRotationFreeMovement mode instead of FreeMovement.

## ExternalSetpointGeneration

In ExternalSetpointGeneration mode, the mover executes a corresponding command. This mode begins (or ends) with the beginning (or end) of the corresponding command. In the ExternalSetpointGeneration mode, the mover follows the external setpoints that the user provides cyclically.

External setpoint generation can be used in conjunction with the other modes. In this case, the external setpoints are simply added as relative offsets from the setpoints of the other modes. However, the mover is then not in ExternalSetpointGeneration mode.
