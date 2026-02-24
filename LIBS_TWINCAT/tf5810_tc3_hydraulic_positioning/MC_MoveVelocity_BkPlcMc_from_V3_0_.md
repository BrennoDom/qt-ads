# MC_MoveVelocity_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_MoveVelocity\_BkPlcMc (from V3.0)

# MC\_MoveVelocity\_BkPlcMc (from V3.0)

![36391162](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854729867__Web.gif)

This function block starts and monitors the movement of an axis.

```
VAR_INPUT  
    Execute:        BOOL;  
    Velocity:       LREAL;  
    Acceleration:   LREAL;  
    Deceleration:   LREAL;  
    Direction:      MC_Direction_BkPlcMc;  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    InVelocity:     BOOL;  
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

**Velocity**: [mm/s] The required motion velocity in actual value units of the axis per second.

**Acceleration**: [mm/s2] The required acceleration in actual value units of the axis per square second.

**Deceleration**: [mm/s2] The required deceleration in actual value units of the axis per square second.

**Direction**: A direction specification, coded according to [MC\_Direction\_BkPlcMc](ms-xhelp:///?Id=beckhoff-655d-48f0-bea8-21f606b985a9).

**BufferMode:** Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**InVelocity**: This output becomes TRUE when the axis reaches the required velocity for the first time.

**CommandAborted**: Abortion of the movement is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* Depending on the movement algorithm specified in **Axis.pStAxParams^.nProfile** the axis may either only be able to begin the movement initiated here when stationary, or may be able to begin from another movement that has not yet been completed. If it is unable at the present time to accept this new order, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdNotStartable.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If **Velocity** is too small (less than 1% of the reference velocity) the function block reacts with **Error** and **ErrorID**:=dwTcHydErrCdSetVelo.
* If the movement algorithm is already indicating an error code, the function block responds with **Error** and **ErrorID**:= the movement algorithm's error code.

The movement begins if these checks can be carried out without problems. This is done by selecting a value for the target position depending on **Direction** and the parameters for the software limit switches. The parameters **Velocity, Acceleration** and **Deceleration** are then limited to the maximum permissible values and are passed to the movement algorithm. The axis is now in the [McState\_Continuousmotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b) state, and the function block begins to monitor the movement.

If the movement algorithm reports an error code while the movement is being executed, the function block responds with **Error** and **ErrorID**:=the movement algorithm's error code. If completion of the movement is prevented by the activity of another function block, the function block responds with **CommandAborted**. **InVelocity** is set when the motion algorithm reaches the required velocity.

A negative edge at **Execute** clears all the pending output signals. If, while the movement is still active, **Execute** is set to FALSE, execution of the movement that had started continues unaffected. The signals provided at the end of the movement (**Error**, **ErrorID, CommandAborted, InVelocity**) are made available for one cycle.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
