# Example "Creating a Planar mover and Planar Feedback"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Creating a Planar mover and Planar Feedback"

Using this short guide you will create a TwinCAT project that contains a Planar mover and a Planar Feedback.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create a Planar mover.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a PLC

:   See preliminary steps under [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create a mover ("MC\_PlanarMover") and a Planar Feedback ("MC\_PlanarFeedback") via MAIN as follows.
![40040492](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent the mover and the Planar Feedback in the MC Configuration.

```
PROGRAM MAIN  
VAR  
    mover : MC_PlanarMover;  
    feedback : MC_PlanarFeedback;  
    state : UDINT;  
    target_position : PositionXYC;  
END_VAR
```

In this simple example you have created a state variable for a state machine and a target position for a travel command of the Mover. A feedback is also declared in order to monitor the command process, with which a sequence can subsequently be programmed in the MAIN:

```
CASE state OF  
  0:  
    mover.Enable(feedback);  
    state := 1;  
  1:  
    IF feedback.Done THEN  
      state := 2;  
    END_IF  
  2:  
    target_position.SetValuesXY(1000, 1000);  
    mover.MoveToPosition(feedback, target_position, 0, 0);  
    state := 3;  
END_CASE
```

This program code activates the mover and moves it to position x = 1000 and y = 1000.

Note that the state machine will only be advanced when the feedback signals the successful termination of the command via its "Done" flag.

## **Sending the command**

:   2. To issue the command and monitor the feedback, you must call the mover and feedback cyclically with their update methods after the END\_CASE:

```
mover.Update();  
feedback.Update();
```

When creating the PLC, a symbol of the "PLC Mover" is created, which can then be linked to the mover instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![24820109](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   Subsequently, the Planar mover in the "MC Project" (double-click) can be linked with the **Link To PLC...** button on the **Settings** tab.

![22054394](/tf5430_tc3_xplanar/1033/Images/png/9249870859__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![64271818](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![41575456](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![38634788](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

The mover is in the desired position at the end of the state machine (state = 3) and the feedback signals the termination of the command with the "Done" flag.

![12168775](/tf5430_tc3_xplanar/1033/Images/png/9293099147__Web.png)
