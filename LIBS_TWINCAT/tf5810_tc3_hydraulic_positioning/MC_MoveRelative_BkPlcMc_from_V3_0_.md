# MC_MoveRelative_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_MoveRelative\_BkPlcMc (from V3.0)

# MC\_MoveRelative\_BkPlcMc (from V3.0)

![4043462](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854727435__Web.gif)

This function block starts and monitors the movement of an axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    Distance:       LREAL;  
    Velocity:       LREAL;  
    Acceleration:   LREAL;  
    Deceleration:   LREAL;  
    Jerk:           LREAL;  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    Done:           BOOL;  
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

**Distance**: [mm] The distance to the target position of the movement in actual value units of the axis.

**Velocity**: [mm/s] The required motion velocity in actual value units of the axis per second.

**Acceleration**: [mm/s2] The required acceleration in actual value units of the axis per square second.

**Deceleration**: [mm/s2] The required deceleration in actual value units of the axis per square second.

**Jerk**: [mm/s3] reserved.

**BufferMode:** Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Done**: Successful processing of the movement is indicated here.

**CommandAborted**: Abortion of the movement is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* The possibility that moving through **Distance** will lead to a conflict with an active software limit switch is checked next. In this case the function block will react by asserting **Error** with **ErrorID**:=dwTcHydErrCdSoftEnd.
* Depending on the movement algorithm specified in **Axis.pStAxParams^.nProfile** the axis may either only be able to begin the movement initiated here when stationary, or may be able to begin from another movement that has not yet been completed. If it is unable at the present time to accept this new order, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdNotStartable.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If **Velocity** is too small (less than 1% of the reference velocity) the function block reacts with **Error** and **ErrorID**:=dwTcHydErrCdSetVelo.
* If **Acceleration** is too small (the **Velocity** cannot be reached within 100 seconds) the function block reacts with **Error** and **ErrorID**:=dwTcHydErrCdAcc.
* If **Deceleration** is too small (the **Velocity** cannot be reached within 100 seconds) the function block reacts with **Error** and **ErrorID**:=dwTcHydErrCdDec.
* If the movement algorithm is already indicating an error code, the function block responds with **Error** and **ErrorID**:= the movement algorithm's error code.

The movement begins if these checks can be carried out without problems. This is done by limiting the parameters **Distance, Velocity, Acceleration** and **Deceleration** to the maximum permissible values and passing them to the movement algorithm. The axis is now in the [McState\_DiscreteMotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b) state, and the function block begins to monitor the movement.

If the movement algorithm reports an error code while the movement is being executed, the function block responds with **Error** and **ErrorID**:=the movement algorithm's error code. If completion of the movement is prevented by the activity of another function block, the function block responds with **CommandAborted**. If the movement algorithm achieves the target conditions for the axis, the function block reacts with **Done**.

A negative edge at **Execute** clears all the pending output signals. If, while the movement is still active, **Execute** is set to FALSE, execution of the movement that had started continues unaffected. The signals provided at the end of the movement (**Error**, **ErrorID, CommandAborted**, **Done**) are made available for one cycle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
