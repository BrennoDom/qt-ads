# Example: "Following a Planar mover through a Track Network"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example: "Following a Planar mover through a Track Network"

Guided by these instructions, you will create a TwinCAT project in which a Planar mover located on a Planar track follows a preceding Planar mover on the same Planar track on its path through a track network.

Following through a track network is realized by the command `GearInPosOnTrackWithMasterMover`, which is described in more detail in [Example: "Synchronizing a Planar mover on a track with another Planar mover"](ms-xhelp:///?Id=beckhoff-1246-47be-8dc9-d0045da148ba). Creating and building a network of Planar tracks is explained in more detail in the [Example "Connecting Planar tracks to a network"](ms-xhelp:///?Id=beckhoff-e50b-46ba-b0f2-35c661f52b01). This example is short and builds on the above examples.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create two Planar movers.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a Planar track

:   3. Add three Planar tracks via **Groups > Add New Item…**, see [Configuration](ms-xhelp:///?Id=beckhoff-c351-4189-816e-179812e8671e).
:   The Solution Explorer has the following entries:   
    ![3261819](/tf5430_tc3_xplanar/1033/Images/png/10789651851__Web.png)

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create the desired number of movers ("MC\_PlanarMover") and tracks ("MC\_PlanarTrack") via **MAIN.**
![29356372](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent movers and tracks in the MC Configuration.

:   2. Create the following variables.

```
PROGRAM MAIN  
VAR  
    master_mover  : MC_PlanarMover;  
    slave_mover   : MC_PlanarMover;  
    track_in      : MC_PlanarTrack;  
    track_out1    : MC_PlanarTrack;  
    track_out2    : MC_PlanarTrack;  
    move_feedback : MC_PlanarFeedback;  
    options       : ST_GearInPosOnTrackWithMasterMoverOptions;  
    state         : UDINT;  
    pos1, pos2    : PositionXYC;  
END_VAR
```

:   3. Build the PLC to create symbols of the "PLC movers" and "tracks".  
    ![62880759](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png)
:   4. Link the Planar movers and the Planar tracks (see [Example "Joining and moving a Planar mover on the track"](ms-xhelp:///?Id=beckhoff-e2e4-424c-8cf3-f68e7f61defe)).

## Programming state machines

With the following state machine, which is programmed in MAIN, first the Planar tracks are geometrically defined and activated (states 0 to 7), so that they represent the following switch configuration:

![29055926](/tf5430_tc3_xplanar/1033/Images/png/10790063883__Web.png)

In states 8 to 19 the two Planar movers are activated, coupled to the Planar track in front of the switch (`track_in`) and moved to position 200 (`master_mover`) or 0 (`slave_mover`). The Master Planar Mover is then commanded to position 500 on the upper of the two branching Planar tracks (`track_out1`) (State 20). Finally, in State 21, the `GearInPosOnTrackWithMasterMover` command is sent to the Slave Planar Mover. As usual, the Planar objects are updated cyclically after the `END_CASE` statement.

```
CASE state OF  
  0:  
    pos1.SetValuesXYC(100, 360, 0);  
    pos2.SetValuesXYC(400, 360, 0);  
    track_in.AppendLine(0, pos1, pos2);  
    track_in.Enable(0);  
    state := state + 1;  
  1:  
    IF track_in.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  2:  
    track_out1.StartFromTrack(0, track_in);  
    state := state + 1;  
  3:  
    pos1.SetValuesXYC(450, 410, 0);  
    pos2.SetValuesXYC(860, 620, 0);  
    track_out1.AppendLine(0, pos1, pos2);  
    track_out1.Enable(0);  
    state := state + 1;  
  4:  
    IF track_out1.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  5:  
    track_out2.StartFromTrack(0, track_in);  
    state := state + 1;  
  6:  
    pos1.SetValuesXYC(450, 310, 0);  
    pos2.SetValuesXYC(860, 100, 0);  
    track_out2.AppendLine(0, pos1, pos2);  
    track_out2.Enable(0);  
    state := state + 1;  
  7:  
    IF track_out2.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  8:  
    master_mover.Enable(0);  
    state := state + 1;  
  9:  
    IF master_mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  10:  
    master_mover.JoinTrack(0, track_in, 0, 0);  
    state := state + 1;  
  11:  
    IF master_mover.MCTOPLC.STD.CommandMode = MC_PLANAR_MOVER_COMMAND_MODE.OnTrack THEN  
      state := state + 1;  
    END_IF  
  12:  
    master_mover.MoveOnTrack(move_feedback, track_in, 200, 0, 0);  
    state := state + 1;  
  13:  
    IF move_feedback.Done THEN  
      state := state + 1;  
    END_IF  
  14:  
    slave_mover.Enable(0);  
    state := state + 1;  
  15:  
    IF slave_mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  16:  
    slave_mover.JoinTrack(0, track_in, 0, 0);  
    state := state + 1;  
  17:  
    IF slave_mover.MCTOPLC.STD.CommandMode = MC_PLANAR_MOVER_COMMAND_MODE.OnTrack THEN  
      state := state + 1;  
    END_IF  
  18:  
    slave_mover.MoveOnTrack(move_feedback, track_in, 0, 0, 0);  
    state := state + 1;  
  19:  
    IF move_feedback.Done THEN  
      state := state + 1;  
    END_IF  
  20:  
    master_mover.MoveOnTrack(0, track_out1, 500, 0, 0);  
    state := state + 1;  
  21:  
    options.followMover := TRUE;  
    slave_mover.GearInPosOnTrackWithMasterMover(0, master_mover, 0, 210, track_in, 10, track_in, 0, options);  
    state := state + 1;  
END_CASE  
  
master_mover.Update();  
slave_mover.Update();  
track_in.Update();  
track_out1.Update();  
track_out2.Update();  
move_feedback.Update();
```

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![60176744](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![4719792](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![42478134](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

The Master Planar Mover will move to the given target position (in this case 500) on the specified Planar track, and the Slave Planar Mover will follow its movement. The positions of the Planar movers can be tracked in the online view (by clicking the button ![46758891](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png)).

Since the positions 210 for the master and 10 for the slave were specified as the sync positions of the two Planar movers in the function call in State 21, the Slave Planar Mover will follow its master through the network at a distance of 200. It stops at position 300 on the upper of the two branching Planar tracks (on which the Master Planar Mover is also located), which can be checked in the online view:

![18176840](/tf5430_tc3_xplanar/1033/Images/png/10790067211__Web.png)

Note that setting the "FollowMover" option in the Options object and passing it in the function call in State 21 avoids the need to specify a [PlanarTrackTrail](ms-xhelp:///?Id=beckhoff-6aff-4b37-aeaf-0ee7bb1946de) object. The path through the network that the Slave Planar Mover should take does not have to be explicitly determined, since it automatically follows the Master Planar Mover and turns to the correct Planar track at the switch. With the set option this behavior is also reproduced in a larger network, where the Master Planar Mover moves across multiple track boundaries.
