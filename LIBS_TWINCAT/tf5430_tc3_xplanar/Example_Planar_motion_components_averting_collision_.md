# Example "Planar motion components: averting collision"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Planar motion components: averting collision"

Using this brief guide you will create a TwinCAT project that contains a Planar mover whose travel command is rejected due to a collision with the Planar environment.

## Creating a Planar mover

:   See [Configuration](ms-xhelp:///?Id=beckhoff-ea49-493d-92b5-c99b2c221493).

:   1. Create a Planar mover.
:   2. Put "Parameter (Init)" into simulation mode (`TRUE`). The parameter is hidden and only becomes visible if the "Show Hidden Parameters" checkbox is activated.

## Creating a Planar environment

:   3. Create a Planar environment, see [Configuration](ms-xhelp:///?Id=beckhoff-df1b-4b70-9bc2-34f29a675df1).

## Creating a Planar group

:   4. Create a Planar group, see [Configuration](ms-xhelp:///?Id=beckhoff-c7e4-4674-924a-b28386438ed1).

## Creating a PLC

:   In order to create the geometry of the environment and control the mover, a PLC must be created from which the user can send commands to both.

![42410114](/tf5430_tc3_xplanar/1033/Images/png/9241971595__Web.png)![46146710](/tf5430_tc3_xplanar/1033/Images/png/9241974923__Web.png):   5. Add the libraries [Tc3\_Physics](ms-xhelp:///?Id=beckhoff-5d84-47ec-beb4-21f6e21ea48c) and Tc3\_Mc3PlanarMotion to the PLC project; see [Inserting libraries](ms-xhelp:///?Id=beckhoff-623a-435f-bb36-b392b0ea9fc5).
:   6. Create an "MC\_PlanarMover" and an "MC\_PlanarEnvironment" via **MAIN**.
![12667213](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   These represent the mover and the environment in the MC Configuration.

```
PROGRAM MAIN  
VAR  
    mover           : MC_PlanarMover;  
    environment     : MC_PlanarEnvironment;  
    group           : MC_PlanarGroup;  
    feedback        : MC_PlanarFeedback;  
    state           : UDINT;  
    target_position : PositionXYC;  
END_VAR
```

In this example you have created a state variable for a simple state machine and a target position for a travel command of the mover, with which a sequence can subsequently be programmed in the MAIN:

```
CASE state OF  
  0:  
    environment.AddStator(0,-120.0,-120.0);  
    environment.CreateBoundary(0);  
    state := 1;  
  1:  
    mover.Enable(0);  
    group.Enable(0);  
    state := 2;  
  2:  
    IF mover.MCTOPLC.STD.State = MC_PLANAR_STATE.Enabled AND  
    group.MCTOPLC_STD.State = MC_PLANAR_STATE.Enabled THEN  
      state := 3;  
    ENDIF  
  3:  
    mover.AddToGroup(0,group);  
    environment.AddToGroup(0,group);  
    state := 4;  
  4:  
    IF mover.MCTOPLC.STD.GroupOID > 0 AND  
    environment.MCTOPLC_STD. GroupOID > 0 THEN  
      state := 5;  
    ENDIF  
  5:  
    target_position.SetValuesXY(100, 100);  
    mover.MoveToPosition(feedback, target_position, 0, 0);  
    state := 6;  
END_CASE
```

This program code activates the mover and creates an environment from a tile on which the mover is located. An attempt is then made to move the mover to the position x = 100 and y = 100.

## **Sending the command**

:   7. In order to issue the command and monitor the feedback, you must call the objects cyclically with their update methods after the END\_CASE:

```
mover.Update();  
environment.Update();  
group.Update();  
feedback.Update();
```

When creating the PLC, a symbol of the "PLC Mover" is created, which can then be linked to the mover instance in the MC project.

:   1. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![46896054](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   Subsequently, the Planar mover in the "MC Project" (double-click) can be linked with the **Link To PLC...** button on the **Settings** tab.
![19411308](/tf5430_tc3_xplanar/1033/Images/png/9682818187__Web.png):   Subsequently, the Planar environment can be linked via the following dialog boxes in the "MC Project".
![40484047](/tf5430_tc3_xplanar/1033/Images/png/9682814347__Web.png)![28812104](/tf5430_tc3_xplanar/1033/Images/png/9682812427__Web.png):   The group is linked in the same way.

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![57982344](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![52079048](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![66058249](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

At the end of the state machine (state=6), the mover is in the desired position. The mover did not move because the command was rejected. The feedback shows a collision error and the environment is specified as the collision partner in the ObjectInfo.

![57653332](/tf5430_tc3_xplanar/1033/Images/png/9682821771__Web.png)
