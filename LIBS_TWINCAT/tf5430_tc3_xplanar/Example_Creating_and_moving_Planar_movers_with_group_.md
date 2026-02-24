# Example: "Creating and moving Planar movers with group"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example: "Creating and moving Planar movers with group"

Using this guide, you will to create a TwinCAT project that contains two Planar movers and one Planar group. Both movers are added to the group and moved.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create two Planar movers.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.
:   3. Change the start position of the second mover to x = 240.

## Creating a Planar group

:   4. Add the Planar group via **Groups > Add New Item…**, see [Configuration](ms-xhelp:///?Id=beckhoff-c7e4-4674-924a-b28386438ed1).

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create two movers ("MC\_PlanarMover") and a Planar group "MC\_PlanarGroup" via **MAIN**.
![9967070](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent the movers and the group in the MC Configuration.

:   2. Create a state variable for a state machine as shown below, plus two auxiliary positions for the "MoveToPosition" commands of the movers.

```
PROGRAM MAIN  
VAR  
    mover_one, mover_two : MC_PlanarMover;  
    group : MC_PlanarGroup;  
    state : UDINT;  
    pos1, pos2 : PositionXYC;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code activates the group and both movers. Both movers are then added to the group.

```
CASE state OF  
  0:  
    mover_one.Enable(0);  
    mover_two.Enable(0);  
    state := 1;  
  1:  
    IF mover_one.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled  
    AND mover_two.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 2;  
    END_IF  
  2:  
     group.Enable(0);  
     state := 3;  
  3:  
    IF group.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 4;  
    END_IF  
  4:  
    mover_one.AddToGroup(0, group);  
    mover_two.AddToGroup(0, group);  
    state := 5;  
  5:  
    IF mover_one.MCTOPLC.STD.GroupOID = group.MCTOPLC_STD.GroupOID  
    AND mover_two.MCTOPLC.STD.GroupOID = group.MCTOPLC_STD.GroupOID THEN  
      state := 6;  
    END_IF  
  6:  
    pos1.SetValuesXY(0, 240);  
    pos2.SetValuesXY(0, 0);  
    mover_one.MoveToPosition(0, pos1, 0, 0);  
    mover_two.MoveToPosition(0, pos2, 0, 0);  
    state := 7;  
END_CASE
```

## **Sending the command**

:   4. To send the command you must trigger the movers and the group cyclically using the update methods:

```
mover_one.Update();  
mover_two.Update();  
group.Update();
```

Building the PLC creates symbols of the "PLC mover" and the "PLC group", which can then be linked to the mover or group instance in the MC project.

:   5. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![22594769](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   Subsequently, the Planar movers in the "MC Project" can be linked with the **Link To PLC...** button on the **Settings** tab.
:   6. Double-click Mover 1 first, then Mover 2.
![2026335](/tf5430_tc3_xplanar/1033/Images/png/9249870859__Web.png):   The group must be linked separately via the following dialog boxes.

![18237015](/tf5430_tc3_xplanar/1033/Images/png/9682009483__Web.png)![29915412](/tf5430_tc3_xplanar/1033/Images/png/9292850315__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![803253](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![7229285](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![65063572](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

After logging into the PLC and starting, you will see that the movers are not both in the target positions at the end of the state machine (state=7). Mover 1 has moved to x = 0 and y = 240. Mover 2 has not moved to the origin because Mover 1 still stood there and the command was therefore rejected because both are in a common group.

Since the dynamic limits of the movers are quite high by default, the change of positions after logging in may be difficult to follow with the naked eye. For the dynamic limits, see [Planar mover](ms-xhelp:///?Id=beckhoff-8335-4007-8339-21fa46bc6063).

![48701244](/tf5430_tc3_xplanar/1033/Images/png/9253612043__Web.png)
