# MC_CamIn_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_CamIn\_BkPlcMc (from V3.0)

# MC\_CamIn\_BkPlcMc (from V3.0)

![29194114](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854690955__Web.gif)

The function block starts and monitors a cam plate coupling between two axes. To release the coupling, an [MC\_CamOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f9e2-45c8-b5d2-c0ebfc965ddd) function block should be used.

```
VAR_INPUT  
    Execute:        BOOL;  
    MasterOffset:   LREAL:=0.0;  
    SlaveOffset:    LREAL:=0.0;  
    MasterScaling:  LREAL:=0.0;  
    SlaveScaling:   LREAL:=0.0;  
    StartMode:      MC_StartMode_BkPlcMc:=MC_StartMode_Absolute;  
    CamTableId:     MC_CAM_ID_BkPlcMc;  
    BufferMode:     MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    InSync:         BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    EndOfProfile:   BOOL;  
END_VAR
```

```
VAR_INOUT  
    Master:         Axis_Ref_BkPlcMc;  
    Slave:          Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge at this input starts the coupling.

**MasterOffset, MasterScaling**: [mm, 1] These values are offset against with the actual position of the master, before the resulting value is looked up in the master column of the table.

**SlaveOffset**, **SlaveScaling**: [mm, 1] These values are offset against the slave position from the table.

**StartMode**: A value from [MC\_StartMode\_BkPlcMc](ms-xhelp:///?Id=beckhoff-09ff-451e-afa7-6320737ad1dd), which specifies the behavior of the slave axis when the coupling is activated.

**CamTableId**: Here, a variable of type [MC\_CAM\_ID\_BkPlcMc](ms-xhelp:///?Id=beckhoff-c699-42ea-8202-bcc2f3dbf8c5) should be transferred, which was initialized by a function block of type [MC\_CamTableSelect\_BkPlcMc](ms-xhelp:///?Id=beckhoff-af26-44f2-901d-1b7a99b37e87).

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**InSync**: This indicates the first successful synchronization of the axes. The signal the remains active, even if the synchronization subsequently fails temporarily or permanently.

**CommandAborted**: This indicates abortion of the coupling.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**EndOfProfile**: This is indicates whether the master has reached the end of the defined range.

**Master, Slave**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* If **CamTableId**.bValidated was not set by a function block of type MC\_CamTableSelect\_BkPlcMc, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdTblNoInit.
* If either the master or the slave are not in idle state, the system responds with **Error** and **ErrorID:=dwTcHydErrCdNotStartable.**
* If the value MC\_StartMode\_RampIn is specified as **StartMode**, the function block responds with **Error** and **ErrorID**:=dwTcHydErrCdNotSupport.

If these checks could be performed without problem, the coupling is initiated. Depending on **StartMode**, the reference position for **Slave** is either set to 0.0 or to the current actual position of **Slave**. The axis is now in state [McState\_Synchronizedmotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b), and the function block starts calculating and monitoring the coupling.

The set position and set velocity of **Slave** are calculated depending on the actual position and the set velocity of the master and the table.

When the velocity required by the coupling is reached for the first time while the slave axis coupling is active, this is indicated at output InGear. Since the coupling can currently only be activated at standstill, this is the case immediately. If the slave axis is unable to follow the specifications for some reason while the coupling is active, InGear remains unchanged.

If an error code occurs in the motion generator while the coupling is active, the system responds with **Error** and **ErrorID**:=motion algorithm error code.

A negative edge at **Execute** neither aborts the calculation nor the monitoring of the coupling. This is only brought about if the coupling is activated through an MC\_CamOut\_BkPlcMc function block or if an error occurs. Only then are all pending output signals cleared.

|  |  |
| --- | --- |
| 61420436 | This function block temporarily deals with setpoint generation. To indicate this, Busy is not only TRUE up to the transition to synchronicity, but remains TRUE until the coupling is released. |

|  |  |
| --- | --- |
| 15913018 | Function block call  It is therefore imperative that this function block is called cyclically, if **Busy** is TRUE. Subsequently, the function block should be called at least once with **Execute**:=FALSE. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
