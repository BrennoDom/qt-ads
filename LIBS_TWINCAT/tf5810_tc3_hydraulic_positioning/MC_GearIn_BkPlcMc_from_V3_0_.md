# MC_GearIn_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_GearIn\_BkPlcMc (from V3.0)

# MC\_GearIn\_BkPlcMc (from V3.0)

![59133445](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854707979__Web.gif)

The function block starts and monitors a coupling between two axes. To release the coupling, an [MC\_GearOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f42f-49a2-831a-c7c89ada8df9) function block should be used.

```
VAR_INPUT  
    Execute:                BOOL;  
    RatioNumerator:         INT;  
    RatioDenominator:       INT;  
    Acceleration:           LREAL;  
    Deceleration:           LREAL;  
    Jerk:                   LREAL;  (ab/from V3.0.5)  
    BufferMode:             MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;    (ab/from V3.0.8)  
END_VAR
```

```
VAR_OUTPUT  
    Busy:           BOOL;  
    InGear:         BOOL;  
    CommandAborted: BOOL;  
    Error:          BOOL;  
    ErrorID:        UDINT;  
    Active:         BOOL;  
END_VAR
```

```
VAR_INOUT  
    Master:         Axis_Ref_BkPlcMc;  
    Slave:          Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge at this input starts the coupling.

**RatioNumerator, RatioDenominator**: [1, 1] These parameters describe the coupling factor in the form of a gear unit.

**Acceleration**: [mm/s2] The acceleration permitted for the synchronization in actual value units of the axis per square second.

**Deceleration**: [mm/s2] The deceleration permitted for the synchronization in actual value units of the axis per square second.

**Jerk**: [mm/s3] The jerk to be applied.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**Busy**: Indicates that a command is being processed.

**InGear**: This indicates the first successful synchronization of the axes. The signal the remains active, even if the synchronization subsequently fails temporarily or permanently.

**CommandAborted**: This indicates abortion of the coupling.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Active:** Indicates that a command is being processed.

**Master, Slave**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* Next, the system checks whether **RatioDenominator** is 0. In this case the function block will react by asserting **Error** with **ErrorID**:=dwTcHydErrCdIllegalGearFactor.
* Currently, the coupling can only be activated if both the master and the slave are at standstill. Otherwise the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotStartable.
* If the axis is already in a fault state, or if it is in the process of carrying out a stop operation, it responds with **Error** and **ErrorID**:=dwTcHydErrCdNotReady.
* If the movement algorithm is already indicating an error code, the function block responds with **Error** and **ErrorID**:= the movement algorithm's error code.

If these checks could be performed without problem, the coupling is initiated. The axis is now in state [McState\_Synchronizedmotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b), and the function block starts monitoring the coupling.

When the velocity required by the coupling is reached for the first time while the slave axis coupling is active, this is indicated at output InGear. Since the coupling can currently only be activated at standstill, this is the case immediately. If the slave axis is unable to follow the specifications for some reason while the coupling is active, InGear remains unchanged.

If an error code occurs in the motion generator while the coupling is active, the system responds with **Error** and **ErrorID**:=motion algorithm error code.

A negative edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the coupling is still active, the existing coupling remains unaffected and active.

|  |  |
| --- | --- |
| 62438959 | The output Active is currently identical to the output Busy. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
