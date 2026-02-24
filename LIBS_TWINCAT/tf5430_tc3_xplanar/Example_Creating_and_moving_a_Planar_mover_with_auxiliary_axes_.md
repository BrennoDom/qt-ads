# Example: "Creating and moving a Planar mover with auxiliary axes"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example: "Creating and moving a Planar mover with auxiliary axes"

Using this short guide you will create a TwinCAT project that contains a Planar mover and moves it in a simple way.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create a Planar mover.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Use **MAIN** to create the mover or movers ("MC\_PlanarMover") as follows.
![1651899](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   They represent the movers in the MC Configuration.

:   2. Create a Planar mover, a state variable for a state machine and a target position for a travel command of the mover, as shown below.

```
PROGRAM MAIN  
VAR  
    mover : MC_PlanarMover;  
    state : UDINT;  
    target_a : LREAL := 1.0;  
    target_b : LREAL := -1.0;  
    target_c : LREAL := 3.0;  
    target_z : LREAL := 5.0;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code activates the mover and moves the four auxiliary axes.

```
CASE state OF  
  0:  
    mover.Enable(0);  
    state := 1;  
  1:  
    IF mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 2;  
    END_IF  
  2:  
    mover.MoveA(0, target_a, 0);  
    mover.MoveB(0, target_b, 0);  
    // Since Version V3.1.10.11 MoveC has an options parameter,   
    // details can be found in the CRotation example  
    // and the options descriptions  
    //mover.MoveC(0, target_c, 0);  // until version V3.1.10.11  
    mover.MoveC(0, target_c, 0, 0); // since version V3.1.10.30  
    mover.MoveZ(0, target_z, 0);   
    state := 3;  
END_CASE
```

**Further information:**

* [Example "Moving the Planar mover in CRotation mode"](ms-xhelp:///?Id=beckhoff-26cf-4be7-8d64-bdb508541bc2)
* [Limits and options of the motion commands](ms-xhelp:///?Id=beckhoff-43d0-4de3-9efb-d3cee42de85e)

## **Sending the command**

:   4. To send the command, you must call the mover cyclically with its update method after END\_CASE:

```
mover.Update();
```

When creating the PLC, a symbol of the "PLC Mover" is created, which can then be linked to the mover instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![14867095](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   Subsequently, the Planar mover in the "MC Project" (double-click) can be linked with the **Link To PLC...** button on the **Settings** tab.

![66694991](/tf5430_tc3_xplanar/1033/Images/png/9682818187__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![63384014](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![33585220](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![33831530](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

At the end of the state machine (state=3), the mover is in the desired position.

![36048322](/tf5430_tc3_xplanar/1033/Images/png/9334643211__Web.png)
