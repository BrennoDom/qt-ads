# MC_GearInPos_BkPlcMc (from V3.0.33)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Motion](ms-xhelp:///?Id=beckhoff-c1ef-44e8-b7a5-0096a7da1950)
4. MC\_GearInPos\_BkPlcMc (from V3.0.33)

# MC\_GearInPos\_BkPlcMc (from V3.0.33)

![25079723](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854710411__Web.gif)

The function block starts and monitors an on-the-fly coupling between two axes. To release the coupling, an [MC\_GearOut\_BkPlcMc](ms-xhelp:///?Id=beckhoff-f42f-49a2-831a-c7c89ada8df9) function block should be used.

```
VAR_INPUT  
     Execute:               BOOL;  
     RatioNumerator:        INT;  
     RatioDenominator:      INT;  
     MasterSyncPosition:    LREAL;  
     SlaveSyncPosition:     LREAL;  
     SyncMode:              INT;  
     MasterStartDistance:   LREAL;  
     Acceleration:          LREAL;  
     Deceleration:          LREAL;  
     Jerk:                  LREAL;   (ab/from V3.0.5)  
     BufferMode:            MC_BufferMode_BkPlcMc:=Aborting_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
     StartSync:        BOOL;  
     InSync:           BOOL;  
     Busy:             BOOL;  
     Active:           BOOL;  
     CommandAborted:   BOOL;  
     Error:            BOOL;  
     ErrorID:          UDINT;  
END_VAR
```

```
VAR_INOUT  
     Master:       Axis_Ref_BkPlcMc;  
     Slave:        Axis_Ref_BkPlcMc;  
END_VAR
```

**Execute**: A positive edge at this input starts the coupling.

**RatioNumerator, RatioDenominator**: [1, 1] These parameters describe the coupling factor in the form of a gear unit.

**MasterSyncPosition**: [mm] The coupling is fully active from this master position.

**SlaveSyncPosition**: [mm] The coupling is fully active from this slave position.

**SyncMode**: Currently not supported.

**MasterStartDistance**: [mm] This is the master distance over which the coupling is established.

**Acceleration**: [mm/s2] The acceleration permitted for the synchronization in actual value units of the axis per square second.

**Deceleration**: [mm/s2] The deceleration permitted for the synchronization in actual value units of the axis per square second.

**Jerk**: [mm/s3] The jerk to be applied.

**BufferMode**: Reserved. This input is provided in preparation for a future build. It should currently either not be assigned or assigned the constant Aborting\_BkPlcMc. (from V3.0.8)

**StartSync**: Indicates the transition phase between idle state and fully active coupling.

**InSync**: This indicates the first successful synchronization of the axes. The signal the remains active, even if the synchronization subsequently fails temporarily or permanently.

**Busy**: Indicates that a command is being processed.

**Active:** Indicates that a command is being processed.

**CommandAborted**: This indicates abortion of the coupling.

**Error**: The occurrence of an error is indicated here.

**ErrorID**: An encoded indication of the cause of the error is provided here.

**Master, Slave**: Here, the address of a variable of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

The function block is activated by a positive edge at **Execute**, and investigates the axis interface that has been passed to it. A number of problems can be detected and reported during this process:

* Next, the system checks whether **RatioDenominator** is 0. In this case the function block will react by asserting **Error** with **ErrorID**:=dwTcHydErrCdIllegalGearFactor.
* **If RatioDenominator** is less than 0, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotSupport.
* The coupling can only be activated if the slave is at standstill. Otherwise the system responds with **Error** and **ErrorID**:=dwTcHydErrCdNotStartable.
* If the absolute value of the **MasterStartDistance** is too small, the system responds with **Error** and **ErrorID**:=dwTcHydErrCdCannotSynchronize.
* If the actual position of the master is not between **MasterSyncPosition** and the end of the synchronization distance specified by **MasterStartDistance,** the system responds with **Error** and **ErrorID**:=dwTcHydErrCdCannotSynchronize.

If these checks could be performed without problem, the coupling is initiated. The slave axis initially continues to be in state [McState\_Standstill](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b). Only when the master axis reaches the start of the synchronization distance for the first time does the slave axis report [McState\_Synchronizedmotion](ms-xhelp:///?Id=beckhoff-ec30-4c5a-b456-5a14920f0c0b) and indicate **StartSync,** and the function block starts monitoring the coupling. As soon as the axis reaches the end the synchronization distance for the first time, the slave axis indicates **InSync**. Should the master axis later pass the start of the synchronization distance backwards, the coupling is not released.

If an error code occurs in the motion generator while the coupling is active, the system responds with **Error** and **ErrorID**:=motion algorithm error code.

A negative edge at **Execute** clears all the pending output signals. If **Execute** is set to FALSE while the coupling is still active, the existing coupling remains unaffected and active.

An example is available under [#103](ms-xhelp:///?Id=beckhoff-6af5-4f42-8491-7a510b7dd9b7).

|  |  |
| --- | --- |
| 24390923 | The function block does not support the functionality of TwinCAT NC. |

|  |  |
| --- | --- |
| 18191719 | The output Active is currently identical to the output Busy. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
