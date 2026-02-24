# MC_MoveJoySticked_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_MoveJoySticked\_BkPlcMc (from V3.0)

# MC\_MoveJoySticked\_BkPlcMc (from V3.0)

![28219072](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854725003__Web.gif)

This function block starts and monitors the movement of an axis.

|  |  |
| --- | --- |
| 52645056 | This function is currently only supported by axes, which are controlled by a function block of type MC\_AxRuntimeCtrlBased\_BkPlcMc (in preparation: MC\_AxRunTimeTimeRamp\_BkPlcMc). Such a function block is selected by specifying the corresponding constant from E\_TcMcProfileType under nProfileType in ST\_TcHydAxParam. |

```
VAR_INPUT  
    Execute:        BOOL;  
    JoyStick:       LREAL;  
    Acceleration:   LREAL;  
    Deceleration:   LREAL;  
    Jerk:           LREAL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: The movement is initiated by a positive edge at this input.

**JoyStick**: [1] The velocity specified via the control unit, normalized to the range ±1.0.

**Acceleration**: [mm/s2] The required acceleration in actual value units of the axis per square second.

**Deceleration**: [mm/s2] The required deceleration in actual value units of the axis per square second.

**Jerk**: [mm/s3] reserved.

**Busy**: Indicates that a command is being processed.

**CommandAborted**: Abortion of the movement is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If the movement algorithm is already indicating an error code, the function block responds with **Error** and **ErrorID**:= the movement algorithm's error code.
* Next, the system checks whether the generator of the axis supports the required function. If this is not the case, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotCompatible.

The movement begins if these checks can be carried out without problems. To this end the motion algorithm is set to state iTcHydStateExtGenerated and the axis to state McState\_Synchronizedmotion. The axis velocity is specified through **JoyStick** and [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fRefVelo. Changes in velocity are accompanied by ramp limitation to [ST\_TcHydAxParam](ms-xhelp:///?Id=beckhoff-12fe-4458-a931-b3c9fca583f2).fMaxAcc. If the axis moves towards an active software limit switch, the velocity is limited, depending on the remaining distance, such that the limit switch is approached correctly.

A falling edge at **Execute** offset puts motion algorithm in state iTcHydStateTcDecP or iTcHydStateTcDecM and the axis in state McState\_Standstill. If the axis is in motion at this point in time, it is decelerated with a stop ramp and assumes state iTcHydStateIdle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
