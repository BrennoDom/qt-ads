# MC_ImediateStop_BkPlcMc (from V3.0.5)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_ImediateStop\_BkPlcMc (from V3.0.5)

# MC\_ImediateStop\_BkPlcMc (from V3.0.5)

![58343698](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854720139__Web.gif)

The function block cancels a current axis motion.

```
VAR_INPUT  
    Execute:        BOOL;  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    Active:         BOOL;  
    CommandAborted: BOOL;  
END_VAR
```

```
VAR_INOUT  
    Axis:           Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A rising edge at this input ends a movement being carried out by the axis.

**Busy**: Indicates that a command is being processed.

**Done**: This indicates successful processing of the operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Active**: Indicates that a command is being processed.

**CommandAborted**: Indicates that processing of this command was cancelled by another command.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block:

The function block is activated by a rising edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* The stop can only be executed if the axis is actively carrying out a movement. If it is stationary, the function block immediately asserts the **Done** signal.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If the axis is in a state, in which it is controlled by a coupling with another axis or a comparable mechanism, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.

The Stop operation begins if these checks can be carried out without problems. The control value of the axis is immediately set to 0, without any ramp. All outputs of control or regulation voltages are then suppressed, as long as **Execute** is set to TRUE.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
