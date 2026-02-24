# MC_Stop_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_Stop\_BkPlcMc (from V3.0)

# MC\_Stop\_BkPlcMc (from V3.0)

![62003000](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854732299__Web.gif)

The function block cancels a current axis motion and monitors the stop operation.

|  |  |
| --- | --- |
| 21156092 | The stop operation initiated by this function block cannot be interrupted by other function blocks. A function block MC\_Halt\_BkPlcMc should be used to enable an axis restart during a stop operation. |

```
VAR_INPUT  
    Execute:        BOOL;  
    Deceleration:   LREAL;  (ab/from V3.0.5)  
    Jerk:           LREAL;  (ab/from V3.0.5)  
    RampTime:       LREAL;  (ab/from V3.0.5)  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
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

**Execute**: A positive edge at this input ends a movement being carried out by the axis.

**Deceleration**: [mm/s2] The deceleration to be applied.

**Jerk**: [mm/s3] The jerk to be applied.

**RampTime**: [s] The required stopping time.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Done**: This indicates successful processing of the operation.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Active:** Indicates that a command is being processed.

**CommandAborted**: Indicates that processing of this command was canceled by another command.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* The stop can only be executed if the axis is actively carrying out a movement. If it is stationary, the function block immediately asserts the **Done** signal.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If the axis is in a state, in which it is controlled by a coupling with another axis or a comparable mechanism, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.

The Stop operation begins if these checks can be carried out without problems. **Deceleration** is used, if this parameter is recognizably greater than 0. Otherwise **RampTime** is used to calculate a deceleration, taking into account the reference speed. If a jerk-limiting control value generator is selected, **Jerk** is used if this parameter is recognizably greater than 0. If none of the mentioned parameters is recognizably greater than 0, the axis parameter MaxDec and MaxJerk are used.

The next reachable position is determined and used as new target position, taken into account the current set velocity and the currently valid parameters. Once this position has been reached, the axis assumes its regular behavior in idle state.

|  |  |
| --- | --- |
| 56187107 | The RampTime specifies the time during which the axis is to be decelerated from its reference speed to standstill. If the axis moves with a different velocity, the braking time reduces accordingly. If control value generators with creep mode are used, the corresponding time is added to the braking time. |

If the movement algorithm reports an error code while the movement is being executed, the function block responds with **Error** and **ErrorID**:=the movement algorithm's error code. If completion of the process is prevented by the activity of another function block, the function block responds with **CommandAborted**. Successful completion of the operation is reported with **Done**.

A negative edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the operation is still active, the initiated stop continues unaffected. The signals provided at the end of the movement (**Error**, **ErrorID, Done**) are made available for one cycle.

|  |  |
| --- | --- |
| 35921916 | The output Active is currently identical to the output Busy. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
