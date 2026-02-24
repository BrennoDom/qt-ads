# Example "Moving the Planar mover in CRotationFreeMovement mode"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Moving the Planar mover in CRotationFreeMovement mode"

Using this short guide you will create a TwinCAT project that contains a Planar mover and moves it in a simple way.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create a Planar mover.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Use **MAIN** to create the mover or movers ("MC\_PlanarMover") as follows.
![46766508](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   They represent the movers in the MC Configuration.

:   2. Create a Planar mover, a state variable for a state machine and a target position for a travel command of the mover, as shown below.

```
PROGRAM MAIN  
VAR  
    mover : MC_PlanarMover;  
    state : UDINT;  
    target_position_c : LREAL;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code activates the mover and rotates it to position c=20.

```
CASE state OF  
  0:  
    mover.Enable(0);  
    state := 1;  
  1:  
    IF mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 2;  
    END_IF  
  2:  
    target_position_c := 20.0;  
    mover.MoveC(0, target_position_c, 0, 0);  
    state := 3;  
END_CASE
```

## **Sending the command**

:   4. To send the command, you must call the mover cyclically with its update method after END\_CASE:

```
mover.Update();
```

When creating the PLC, a symbol of the "PLC Mover" is created, which can then be linked to the mover instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
:   Subsequently, the Planar mover in the "MC Project" (double-click) can be linked with the **Link To PLC...** button on the **Settings** tab.

## Activating and starting the project

:   1. Activate the configuration via the button in the menu bar ![18245395](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![29990828](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![1482002](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

The mover is at the end of the state machine (state=3) at the desired (rotated) position and is in command mode CRotationFreeMovement, since the angle is greater than 15°. A further movement of the C-axis up to e.g. 90° would change the command mode back to Free Movement after completion of the command.

![13338021](/tf5430_tc3_xplanar/1033/Images/png/11303803787__Web.png)
