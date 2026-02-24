# Example "Creating and moving a Planar mover with External Setpoint Generation"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Creating and moving a Planar mover with External Setpoint Generation"

Using this short guide you will create a TwinCAT project that contains a Planar mover and moves it in a simple way by means of external setpoint generation.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create a Planar mover.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Use **MAIN** to create the mover or movers ("MC\_PlanarMover") as follows.
![55999443](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   They represent the movers in the MC Configuration.

:   2. Create a Planar mover, a state variable for a state machine and variables for the external setpoint, as shown below.

```
PROGRAM MAIN  
VAR  
    mover : MC_PlanarMover;  
    state : UDINT;  
    p,v,a : MoverVector;  
    deltat : LREAL := 0.001;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code activates the mover and starts the external setpoint generation. A profile is then followed that ends with a positive velocity. The subsequent stopping of the external setpoint generation ensures that the mover reduces its velocity to zero and is in the FreeMovement state after stopping (this is done with the maximum dynamics of the mover).

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
    p.x := 0.0; v.x := 0.0; a.x := 0.0;  
    mover.StartExternalSetpointGeneration(0,0);  
    mover.SetExternalSetpoint(p,v,a);         
    state := 3;  
  3:  
    p.x := p.x + deltat * v.x;  
    v.x := v.x + deltat * a.x;  
    a.x := a.x + deltat * 1.0;  
    mover.SetExternalSetpoint(p,v,a);         
    IF a.x >= 1.0 THEN  
      state := 4;  
    END_IF;   
  4:  
    p.x := p.x + deltat * v.x;  
    v.x := v.x + deltat * a.x;  
    a.x := a.x + deltat * 1.0;  
    mover.SetExternalSetpoint(p,v,a);         
    IF a.x >= 1.0 THEN  
      state := 5;  
    END_IF;  
  5:  
    mover.StopExternalSetpointGeneration(0);  
    state := 6;      
END_CASE
```

## **Sending the command**

:   4. To send the commands you need to trigger the update method of the mover after the END\_CASE:

```
mover.Update();
```

When creating the PLC, a symbol of the "PLC Mover" is created, which can then be linked to the mover instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![34232944](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   Subsequently, the Planar mover in the "MC Project" (double-click) can be linked with the **Link To PLC...** button on the **Settings** tab.

![39661040](/tf5430_tc3_xplanar/1033/Images/png/9249870859__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![21405046](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![58427690](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![56087165](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

At the end of the state machine (state = 6), the mover is in the desired positive x-position.

![35022440](/tf5430_tc3_xplanar/1033/Images/png/9335263371__Web.png)
