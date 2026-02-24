# Example "Configuring the stator area and boundary"

## Library
tf5430_tc3_xplanar

## Category
Motion Control

# Example "Configuring the stator area and boundary"

Using this guide you will be able to create a TwinCAT project that contains a Planar environment and you will configure its stator surface and boundary.

## Creating a Planar environment

:   1. Create a Planar environment, see [Configuration](ms-xhelp:///?Id=beckhoff-df1b-4b70-9bc2-34f29a675df1).

## Creating a PLC

:   See preliminary steps [Creating a PLC](ms-xhelp:///?Id=beckhoff-2226-4c5b-895c-34b238199e44).

:   1. Create an "MC\_PlanarEnvironment" via **MAIN**.
![62991470](/tf5430_tc3_xplanar/1033/Images/png/9242033803__Web.png):   This represents the environment in the MC configuration.

:   2. Create a state variable for a state machine as shown below.

```
PROGRAM MAIN  
VAR  
    environment : MC_PlanarEnvironment;  
    state : UDINT;  
END_VAR
```

:   3. Then program a sequence in MAIN.
:   This program code adds four stators to the environment. The lower left corner of the square stators (side length 240 mm) is specified in each case. CreateBoundary() then calculates the outer boundary of the stator surface.  
    The stators (red) and boundary elements (blue) are shown schematically in the following illustration.

![30052326](/tf5430_tc3_xplanar/1033/Images/png/9253758603__Web.png)

```
CASE state OF  
  0:  
    environment.AddStator(0,0.0,0.0);  
    environment.AddStator(0,240.0,0.0);  
    environment.AddStator(0,0.0,240.0);  
    environment.AddStator(0,240.0,240.0);  
    environment.CreateBoundary(0);  
    state := 1;  
END_CASE
```

## **Sending the command**

:   4. To send the command, you must call the environment cyclically with its update method after the END\_CASE:

```
environment.Update();
```

When creating the PLC, a symbol of the "PLC environment" is created, which can then be linked to the Planar environment in the MC project.

:   5. To build, use the path **PLC > Untitled1 > Untitled1 Project > Build.**
![2035480](/tf5430_tc3_xplanar/1033/Images/png/9242036363__Web.png):   The Planar environment can then be linked in the "MC Project".

![18319327](/tf5430_tc3_xplanar/1033/Images/png/9253763851__Web.png)![30656219](/tf5430_tc3_xplanar/1033/Images/png/9699026059__Web.png)

## **Activating and starting the project**

:   1. Activate the configuration via the button in the menu bar ![7470517](/tf5430_tc3_xplanar/1033/Images/png/9007208996422667__Web.png).
:   2. Set the TwinCAT system to the "Run" state via the ![125790](/tf5430_tc3_xplanar/1033/Images/png/10374712587__Web.png) button.
:   3. Log in the PLC via the button in the menu bar ![1132111](/tf5430_tc3_xplanar/1033/Images/png/9007199391301387__Web.png).
:   4. Start the PLC via the Play button in the menu bar.

The environment is in the desired state at the end of the state machine (state = 1).

![10189001](/tf5430_tc3_xplanar/1033/Images/png/9253843339__Web.png)
