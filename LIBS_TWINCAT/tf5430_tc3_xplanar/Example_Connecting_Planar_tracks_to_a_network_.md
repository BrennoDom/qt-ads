# Example "Connecting Planar tracks to a network"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Connecting Planar tracks to a network"

Using this guide, you will be able to create a TwinCAT project that connects four Planar tracks to a network.

![66273227](/tf5430_tc3_xplanar/1033/Images/png/9007208936769675__Web.png)

## Creating a Planar track

:   1. Add four Planar tracks via **Groups > Add New Item…**, see [Configuration](ms-xhelp:///?Id=beckhoff-c351-4189-816e-179812e8671e).

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create the desired number of movers ("MC\_PlanarMover") and tracks ("MC\_PlanarTrack") via **MAIN.**
![59588135](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent movers and tracks in the MC Configuration.

:   2. Create four tracks as shown below, plus a state variable for a state machine and two auxiliary positions for the tracks.

```
PROGRAM MAIN  
VAR  
    track_one, track_two, track_three, track_four : MC_PlanarTrack;  
    state : UDINT;  
    pos1, pos2 : PositionXYC;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code creates and activates four tracks that are connected to a network, as shown in the illustration above. The so-called "blendings", i.e. the non-linear parts of the track in this example, are generated automatically here. You only specify the straight sections.

```
CASE state OF  
  0:  
    pos1.SetValuesXY(250, 120);  
    pos2.SetValuesXY(650, 120);  
    track_one.AppendLine(0, pos1, pos2);  
    pos1.SetValuesXY(700, 170);  
    pos2.SetValuesXY(800, 450);  
    track_one.AppendLine(0, pos1, pos2);  
    pos1.SetValuesXY(650, 500);  
    pos2.SetValuesXY(250, 500);  
    track_one.AppendLine(0, pos1, pos2);  
    state := 1;  
  1:  
    pos1.SetValuesXY(200, 450);  
    pos2.SetValuesXY(200, 170);  
    track_two.StartFromTrack(0,track_one);  
    track_two.AppendLine(0, pos1, pos2);  
    track_two.EndAtTrack(0,track_one);  
    state := 2;  
  2:  
    pos1.SetValuesXY(200, 500);  
    pos2.SetValuesXY(120, 500);  
    track_three.StartFromTrack(0,track_one);  
    track_three.AppendLine(0, pos1, pos2);  
    state := 3;  
  3:  
    pos1.SetValuesXY(200, 550);  
    pos2.SetValuesXY(200, 750);  
    track_four.StartFromTrack(0,track_one);  
    track_four.AppendLine(0, pos1, pos2);  
    state := 4;  
  4:  
    track_one.Enable(0);  
    track_two.Enable(0);  
    track_three.Enable(0);  
    track_four.Enable(0);  
    state := 5;  
  5:  
    IF track_one.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled AND  
    track_two.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled AND  
    track_three.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled AND  
    track_four.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 6;  
    END_IF  
END_CASE
```

|  |  |
| --- | --- |
| 66531170 | Tracks must be *C²*-continuous at all points. This means that their positions, directions, and curvatures must merge seamlessly. The automatically generated blendings take this requirement into account. Even if the corner pieces look like quarter circles, they are not, because circles have a positive (constant) curvature at each point and straight lines have a zero curvature. |

## **Sending the command**

:   4. To send the command, you must trigger the tracks cyclically with their update method after the END\_CASE:

```
track_one.Update();  
track_two.Update();  
track_three.Update();  
track_four.Update();
```

Building the PLC creates symbols of the "PLC mover" and “track”, which can then be linked to the mover and track instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![61909621](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   The tracks must each be linked separately via the following dialog boxes.

![20315681](/tf5430_tc3_xplanar/1033/Images/png/9682002827__Web.png)![48623408](/tf5430_tc3_xplanar/1033/Images/png/9250423051__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![34957489](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![46181951](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![12984378](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

The creation of the track network is finished at the end of the state machine (state = 6).

![49750539](/tf5430_tc3_xplanar/1033/Images/png/9682752139__Web.png)

The length of each track is in the online parameters of the TCom objects in the MC Project.

![45101667](/tf5430_tc3_xplanar/1033/Images/png/9682750219__Web.png)
