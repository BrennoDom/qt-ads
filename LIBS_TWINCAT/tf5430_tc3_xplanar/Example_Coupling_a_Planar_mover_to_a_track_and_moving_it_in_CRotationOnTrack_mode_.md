# Example "Coupling a Planar mover to a track and moving it in CRotationOnTrack mode"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Coupling a Planar mover to a track and moving it in CRotationOnTrack mode"

Using this guide, you will to create a TwinCAT project that contains two Planar movers and one Planar track. Both movers are joined and moved on the track.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create two Planar movers.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.
:   3. Change the start position of the second mover to x = 240.

## Creating a Planar track

:   4. Add the Planar track via **Groups > Add New Item…**, see [Configuration](ms-xhelp:///?Id=beckhoff-c351-4189-816e-179812e8671e).

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create the desired number of movers ("MC\_PlanarMover") and tracks ("MC\_PlanarTrack") via **MAIN.**
![27898002](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent movers and tracks in the MC Configuration.

:   2. Create two Planar movers, a Planar track, a state variable for a state machine and two auxiliary positions for the track, as shown below.

```
PROGRAM MAIN  
VAR  
    mover_one, mover_two : MC_PlanarMover;  
    track : MC_PlanarTrack;  
    state : UDINT;  
    pos1, pos2 : PositionXYC;  
    join_track_options : ST_JoinTrackOptions;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code creates and activates a track and both movers. Then both movers are coupled on the track and rotated.

```
CASE state OF  
  0:  
    pos1.SetValuesXY(0, 0);  
    pos2.SetValuesXY(400, 0);  
    track.AppendLine(0, pos1, pos2);  
    track.Enable(0);  
    state := 1;  
  1:  
    IF track.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 2;  
    END_IF  
  2:  
    mover_one.Enable(0);  
    mover_two.Enable(0);  
    state := 3;  
  3:  
    IF mover_one.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled  
    AND mover_two.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 4;  
    END_IF  
  4:  
    join_track_options.useOrientation := FALSE;  
    mover_one.JoinTrack(0, track, 0, join_track_options);  
    mover_two.JoinTrack(0, track, 0, join_track_options);  
    state := 5;  
  5:  
    IF mover_one.MCTOPLC.STD.CommandMode = MC_PLANAR_MOVER_COMMAND_MODE.OnTrack  
    AND mover_two.MCTOPLC.STD.CommandMode = MC_PLANAR_MOVER_COMMAND_MODE.OnTrack THEN  
      state := 6;  
    END_IF  
  6:  
    mover_one.MoveC(0, 20.0, 0, 0);  
    mover_two.MoveC(0, 90.0, 0, 0);  
    state := 7;  
  7:  
    IF mover_one.MCTOPLC.SET.SetPos.c >= 19.9  
    AND mover_two.MCTOPLC.SET.SetPos.c >= 89.9 THEN  
      state := 8;  
    END_IF  
  
END_CASE
```

## Sending the command

:   4. To send the command, you must call the movers and the track cyclically with their update method after the END\_CASE:

```
mover_one.Update();  
mover_two.Update();  
track.Update();
```

Building the PLC creates symbols of the "PLC mover" and “track”, which can then be linked to the mover and track instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
:   Subsequently, the Planar movers in the "MC Project" can be linked with the **Link To PLC...** button on the **Settings** tab.
:   The track must be linked separately via the following dialog boxes.

![49755431](/tf5430_tc3_xplanar/1033/Images/png/9682002827__Web.png)![45145696](/tf5430_tc3_xplanar/1033/Images/png/9252507019__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![3658088](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![32922799](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![27869743](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

At the end of the state machine (state=8), the movers are in the desired positions. Mover two is (again) in the OnTrack state and mover one is in the CRotationOnTrack state after both were in the CRotationOnTrack state during the movement. Mover one can now only continue to rotate, while mover two can continue to move on the track or even leave the track.

![49501095](/tf5430_tc3_xplanar/1033/Images/png/11304064523__Web.png)
