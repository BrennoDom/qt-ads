# MC_ResetAndStop_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Administrative](ms-xhelp:///?Id=beckhoff-93fc-49db-8ba4-346590161207)
4. MC\_ResetAndStop\_BkPlcMc (from V3.0)

# MC\_ResetAndStop\_BkPlcMc (from V3.0)

![50411912](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854671499__Web.gif)

The function block puts a faulty axis in an operational state. If the axis is processing a travel command, this is aborted, and the associated required stop operation is monitored.

```
VAR_INPUT  
    Execute:        BOOL;  
    Deceleration:   LREAL;  (ab/from V3.0.5)  
    Jerk:           LREAL;  (ab/from V3.0.5)  
    RampTime:       LREAL;  (ab/from V3.0.5)  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;  (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:       BOOL;  
    Done:       BOOL;  
    Error:      BOOL;  
    ErrorID:    UDINT;  
END_VAR
```

```
VAR_INOUT  
    Axis:       Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge at this input triggers an axis reset and a stop operation.

**Deceleration**: [mm/s2] The deceleration to be applied.

**Jerk**: [mm/s3] The jerk to be applied.

**RampTime**: [s] The required stopping time.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**Done**: Successful execution of the axis reset is indicated here.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Axis**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If it is not possible to successfully clear an existing fault state for an axis through a reset operation, the function block reacts with **Error** and **ErrorID**:= the ErrorCode for the axis.
* If the axis is placed into an error state in the course of a stop operation that may have been necessary, the function block reacts with **Error** and **ErrorID**:= the ErrorCode for the axis.

Successful completion of both operations is reported with **Done**. The axis is then without error and stationary.

A negative edge at **Execute** clears all the pending output signals.

|  |  |
| --- | --- |
| 51054032 | If the axis is executing a motion, it is decelerated until it stops. In some drive types, signal exchange with an external device is required, in order to rectify certain errors. During the time required for this, the function block is unable to report a final result (Done or Error). Instead, Busy is used to indicate that the function is in progress. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
