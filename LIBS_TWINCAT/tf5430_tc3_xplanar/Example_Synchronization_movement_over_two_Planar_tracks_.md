# Example "Synchronization movement over two Planar tracks"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Synchronization movement over two Planar tracks"

This example is an extension of the example [Example "Synchronizing a Planar mover on a track with one axis"](ms-xhelp:///?Id=beckhoff-601e-4ac1-ac69-f22aa6a5fa8b), in which the synchronization movement of the Planar mover takes place over two Planar tracks. The above example is modified so that *two* Planar tracks are created in the MC Configuration. The Solution Explorer then has the following entries:  
![49117947](/tf5430_tc3_xplanar/1033/Images/png/10223523723__Web.png)

## Customizing the PLC project

:   1. Add the libraries Tc3\_Mc3PlanarMotion, Tc3\_Physics and Tc2\_MC2 to the PLC project; see [Inserting libraries](ms-xhelp:///?Id=beckhoff-623a-435f-bb36-b392b0ea9fc5).
:   2. Declare the following variables in MAIN:

```
PROGRAM MAIN  
VAR  
    mover      : MC_PlanarMover;  
    track1     : MC_PlanarTrack;  
    track2     : MC_PlanarTrack;  
    trail      : MC_PlanarTrackTrail;  
    axis       : AXIS_REF;  
    power_axis : MC_Power;  
    move_axis  : MC_MoveAbsolute;   
    state      : UDINT;  
    pos1, pos2 : PositionXYC;  
END_VAR
```

:   3. Configure the PLC to create symbols of the "PLC mover", the "PLC tracks" and the "PLC axis".  
    ![39408341](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png)
:   4. Link the Planar movers, Planar tracks (see example "[Example: "Creating and moving Planar movers"](ms-xhelp:///?Id=beckhoff-d5b8-4fa4-891b-b4977856d68c)") and the axis (see example "[Example "Synchronizing a Planar mover on a track with one axis"](ms-xhelp:///?Id=beckhoff-601e-4ac1-ac69-f22aa6a5fa8b)").

|  |  |
| --- | --- |
| 19130757 | All the steps so far, except for doubling the number of Planar tracks and the slightly modified code, are identical to those in the example [Example "Synchronizing a Planar mover on a track with one axis"](ms-xhelp:///?Id=beckhoff-601e-4ac1-ac69-f22aa6a5fa8b). |

## Programming state machines

The next step is to modify the program code so that the Planar TrackTrail is passed to the `GearInPosOnTrack` command. Before that the Planar TrackTrail is populated with both Planar tracks, which in this example form a simple [Example "Connecting Planar tracks to a network"](ms-xhelp:///?Id=beckhoff-e50b-46ba-b0f2-35c661f52b01), consisting of an L-configuration with a loop piece:

```
CASE state OF  
  0:  
    pos1.SetValuesXYC(100, 100, 0);  
    pos2.SetValuesXYC(400, 100, 0);  
    track1.AppendLine(0, pos1, pos2);  
    track1.Enable(0);  
    state := state + 1;  
  1:  
    IF track1.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  2:  
    track2.StartFromTrack(0, track1);  
    state := state + 1;  
  3:  
    pos1.SetValuesXYC(500, 100, 0);  
    pos2.SetValuesXYC(860, 100, 0);  
    track2.AppendLine(0, pos1, pos2);  
    track2.Enable(0);  
    state := state + 1;   
  4:  
    IF track2.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  5:  
    mover.Enable(0);  
    state := state + 1;   
  6:  
    IF mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := state + 1;  
    END_IF  
  7:  
    mover.JoinTrack(0, track1, 0, 0);  
    state := state + 1;  
  8:  
    IF mover.MCTOPLC.STD.CommandMode =  
    MC_PLANAR_MOVER_COMMAND_MODE.OnTrack THEN  
      state := state + 1;  
    END_IF  
  9:  
    power_axis(Axis := axis,  
    Enable := TRUE,  
    Enable_Positive := TRUE);  
    IF power_axis.Status THEN  
      move_axis(Axis := axis, Execute := FALSE);  
      state := state + 1;  
    END_IF  
  10:  
    move_axis(Axis := axis,  
              Position := 700,  
              Velocity := 30,  
              Acceleration := 100,  
              Deceleration := 100,  
              Jerk := 100,  
              Execute := TRUE);  
    state := state + 1;  
  11:  
    trail.AddTrack(track1);  
    trail.AddTrack(track2);  
    mover.GearInPosOnTrack(0, axis.DriveAddress.TcAxisObjectId, trail, 100, 100, track1, 0, 0);  
    state := state + 1;  
END_CASE  
  
mover.Update();  
track1.Update();  
track2.Update();  
power_axis(Axis := axis);  
move_axis(Axis := axis);  
axis.ReadStatus();
```

The two Planar tracks are added to the Planar TrackTrail in State 11. The order is crucial here, since `track2` follows `track1` and not vice versa. The Planar TrackTrail is passed as the third argument to the `GearInPosOnTrack` command.

## Activating and starting the project

:   1. Activate the configuration via the button in the menu bar ![37959091](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![6087504](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![54787541](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

## Observe the process in the online view

:   5. Note in the online view how the Planar mover initially moves along the first Planar track towards its end:
![23325828](/tf5430_tc3_xplanar/1033/Images/png/9007209478385803__Web.png):   6. You will then see it switch to the subsequent Planar track (note the TrackOIDs):
![8605860](/tf5430_tc3_xplanar/1033/Images/png/9007209478387723__Web.png):   7. Finally, you can see how it comes to a standstill on the second Planar track:

![10343879](/tf5430_tc3_xplanar/1033/Images/png/9007209478383883__Web.png):   Also in this example, the Planar mover will abort its synchronization movement if the behavior of the master axis should require it to pass over the end of the second Planar track (e.g. by making the target position of the master axis greater than the sum of the lengths of the two Planar tracks). In this case the Planar mover comes to a halt at the end of the second track, loses its potential synchronization status and reports an error.  
      
    If another Planar track is added to the end of the *first* track so that a switch is created at its end, the Planar mover "knows" unambiguously through the Planar TrackTrail to which of the two Planar tracks it should turn and thus continue its synchronization movement (after all, the master axis produces its setpoints independently of Planar tracks). In this way, a Planar TrackTrail can be used to perform a synchronization movement through track networks of any complexity on a unique path of any length.  
      
    Since the Planar TrackTrail is a pure PLC object that does not communicate via TCOM but only acts as a container, no cyclic update, as for example for the Planar mover, the Planar tracks or [Planar Feedback](ms-xhelp:///?Id=beckhoff-cb94-4ca3-8efe-c1c971af05f5) (which are not used in this example), is necessary, and a corresponding method is not available.
