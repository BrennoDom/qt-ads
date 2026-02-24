# MC_GearInMultiMaster

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Axis coupling](ms-xhelp:///?Id=beckhoff-7801-4505-8925-dac3e0bfa5d7)
4. MC\_GearInMultiMaster

# MC\_GearInMultiMaster

![61170512](/tcplclib_tc2_mc2/1033/Images/png/9007199325096203__Web.png)

The function block MC\_GearInMultiMaster is used to activate linear master/slave coupling (gear coupling) for up to four different master axes. The gear ratio can be adjusted dynamically during each PLC cycle. The slave movement is determined by the superimposed master movements. The "Acceleration" parameter has a limiting effect in situations with large gear ratio variations.

The slave axis can be decoupled with the function block [MC\_GearOut](ms-xhelp:///?Id=beckhoff-ade0-428d-928f-7b95a879c82f). If the slave is decoupled while it is moving, then it retains its velocity and can be halted using [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6).

If less than four masters are used, an empty data structure can be transferred for each of the parameters "Master2" to "Master4" (the axis ID must be 0).

## Inputs

```
VAR_INPUT  
    Enable       : BOOL;  
    GearRatio1   : LREAL;  
    GearRatio2   : LREAL;  
    GearRatio3   : LREAL;  
    GearRatio4   : LREAL;  
    Acceleration : LREAL;  
    Deceleration : LREAL;  
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_GearInMultiMasterOptions;  
END_VAR
```

**Enable:** The coupling is executed with a positive edge. The gear ratio can be changed cyclically as long as "Enable" is TRUE. The command is terminated if "Enable" becomes FALSE after coupling. The gear ratio is frozen at its last value, but the slave is not decoupled.

**GearRatio1:** Gear ratio as floating point value for the first master axis. The gear ratio can be changed cyclically as long as "Enable" is TRUE. If "Enable" isFALSE, the gear ratio remains unchanged.

**GearRatio2:** Gear ratio as floating point value for the second master axis. The gear ratio can be changed cyclically as long as "Enable" is TRUE. If "Enable" isFALSE, the gear ratio remains unchanged.

**GearRatio3:** Gear ratio as floating point value for the third master axis. The gear ratio can be changed cyclically as long as "Enable" is TRUE. If "Enable" isFALSE, the gear ratio remains unchanged.

**GearRatio4:** Gear ratio as floating point value for the fourth master axis. The gear ratio can be changed cyclically as long as "Enable" is TRUE. If "Enable" isFALSE, the gear ratio remains unchanged.

**Acceleration:** Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used. The parameter limits the acceleration of the slave in situations with large gear ratio variations.

**Deceleration:** Deceleration (≥0). If the value is 0, the standard deceleration from the axis configuration in the System Manager is used. The parameter limits the deceleration of the slave in situations with large gear ratio variations. **Used only for the option "Advanced Slave Dynamics".**

**Jerk:** Jerk (≥0). If the value is 0, the standard jerk from the axis configuration in the System Manager is used. The parameter limits the jerk of the slave in situations with large gear ratio variations. **Used only for the option "Advanced Slave Dynamics".**

**BufferMode:** Currently not implemented

**Options:**

* **AdvancedSlaveDynamics:** Swaps the internal algorithm of the function block. This makes it possible to synchronize to masters already in motion. In this case, "Acceleration" and "Deceleration" should only be parameterized symmetrically. If jerk presets are too large, this is reduced to the extent that a change from zero to the parameterized acceleration / deceleration can take place in one NC cycle. The resolution of the acceleration / deceleration thus depends directly on the suitable parameterization of the jerk value.
* **SyncMode (since TC3.1.4024.11):** The SyncMode specifies how the axis coupling behaves if the movement of the slave axis is limited in the AdvancedSlaveDynamics mode (limitation of velocity, acceleration and jerk). The following parameters can be set:

+ VELOSYNC:   
  The slave axis and the master axes move with a synchronized velocity. In the case of a dynamic limitation, the slave establishes a position difference that is not caught up again.
+ POSSYNC1:  
  The slave axis and the master axes move with synchronized velocity and position. In the case of a dynamic limitation, the slave establishes a position difference that is then caught up at a later time. Changes in the gear ratios during the journey are executed taking into account the dynamics. The position difference between master and slave resulting from this is not caught up.
+ POSSYNC2:  
  The slave axis and the master axes move with synchronized velocity and position. In the case of a dynamic limitation, the slave establishes a position difference that is then caught up at a later time. Changes in the gear ratios during the journey are immediately calculated internally and the slave continuously synchronizes itself to the new position.   
    
  **Overview:** Which user command results in a permanent position difference or catches it up depending on the SyncMode?User commandsCoupling during the journeyDynamic limitation(Velo, Acc, Jerk)Change Gearing factorPermanent position differencePermanent position differencePermanent position differencePermanent position differencePermanent position differenceCatch up position differenceCatch up position differenceCatch up position differenceCatch up position differenceSyncModePOSSYNC1VELOSYNC(default)POSSYNC2

|  |  |
| --- | --- |
| 13663696 | If coupling takes place with a constant gear ratio with the axes at a standstill (and the gear ratio no longer changes during the course of coupling), then the two SyncModes POSSYNC1 and POSSYNC2 behave identically. |

## Outputs

```
VAR_OUTPUT  
    InGear         : BOOL;  
    Busy           : BOOL;   
    Active         : BOOL;   
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**InGear:** TRUE if the coupling was successful.

**Busy:** TRUE as soon as the command is started with "Enable" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "InGear", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. (Currently Active = Busy)

**CommandAborted:** TRUE if the command could not be executed completely. The axis may have become decoupled during the coupling process (simultaneous command execution).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Master1 : AXIS_REF;  
    Master2 : AXIS_REF;  
    Master3 : AXIS_REF;  
    Master4 : AXIS_REF;  
    Slave   : AXIS_REF;  
END_VAR
```

**Master1:** Axis data structure of the first master. (Type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**Master2:** Axis data structure of the second master. (Type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**Master3:** Axis data structure of the third master. (Type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**Master4:** Axis data structure of the fourth master. (Type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

**Slave:** Axis data structure of the Slave. (Type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

The axis data structure of type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
