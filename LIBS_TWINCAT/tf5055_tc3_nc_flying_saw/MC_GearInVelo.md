# MC_GearInVelo

## Library
tf5055_tc3_nc_flying_saw

## Category
Motion Control

1. [TF5055 TC3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
2. [Flying saw](ms-xhelp:///?Id=beckhoff-0f55-447a-861e-cd3f87251e76)
3. MC\_GearInVelo

# MC\_GearInVelo

MC\_GearInVelo Execute  BOOLRatioNumerator  LREALRatioDenominator  UINTSyncMode  ST\_SyncModeVelocity  LREALAcceleration  LREALDeceleration  LREALJerk  LREALBufferMode  MC\_BufferModeOptions  ST\_GearInVeloOptions↔Master  Reference To AXIS\_REF↔Slave  Reference To AXIS\_REFBOOL  StartSyncBOOL  InSyncBOOL  BusyBOOL  ActiveBOOL  CommandAbortedBOOL  ErrorUDINT  ErrorID

The function block *MC\_GearInVelo* activates a linear master-slave coupling (gear coupling). If the master axis is already moving, the slave axis synchronizes to the master velocity. The function block accepts a fixed gear ratio in numerator/denominator format.

The slave axis can be uncoupled with the function block [MC\_GearOut](ms-xhelp:///?Id=beckhoff-ade0-428d-928f-7b95a879c82f). If the slave is decoupled while it is moving, then it retains its velocity and can be halted using [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) or [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7).

## Inputs

```
VAR_INPUT  
    Execute          : BOOL;  
    RatioNumerator   : LREAL;  
    RatioDenominator : UINT;  
    SyncMode         : ST_SyncMode;  
    Velocity         : LREAL;  
    Acceleration     : LREAL;  
    Deceleration     : LREAL;  
    Jerk             : LREAL;  
    BufferMode       : MC_BufferMode;  
    Options          : ST_GearInVeloOptions;   
END_VAR
```

**Execute**: The command is executed with a rising edge at *Execute* input.

**RatioNumerator**: Gear ratio numerator. Alternatively, the gear ratio can be specified in the enumerator as a floating point value, if the denominator is 1.

**RatioDenominator**: Gear ratio denominator

**SyncMode:** In the data structure [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee) boundary conditions for the synchronization process are specified via individual flags.

**Velocity:** Maximum slave velocity in the synchronization phase. If a velocity is not specified, the maximum velocity of the axis from the system manager data is used. **Note**: The velocity given here is only checked if this checking is activated through the [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee) variable.

**Acceleration**: Maximum slave acceleration in the synchronization phase. If an acceleration is not specified, the maximum acceleration of the axis from the system manager data is used. **Note**: The acceleration given here is only checked if this checking is activated through the [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee) variable.

**Deceleration:** Maximum slave deceleration in the synchronization phase. If a deceleration is not specified, the maximum deceleration of the axis from the system manager data is used. **Note**: The deceleration given here is only checked if this checking is activated through the [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee) variable.

**Jerk**: Maximum slave jerk in the synchronization phase. If a jerk is not specified, the maximum jerk of the axis from the system manager data is used. **Note**: The jerk given here is only checked if this checking is activated through the [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee) variable.

**BufferMode:** Currently not implemented

**Options:** The data structure contains two position values as limits. The check for these position limits can be activated. To do this, two flags have to be set in the structure [SyncMode](ms-xhelp:///?Id=beckhoff-6eff-44dd-903d-4bdd4bb65fee).

For a 1:4 ratio the *RatioNumerator* must be 1, the *RatioDenominator* must be 4. Alternatively, the *RatioDenominator* may be 1, and the gear ratio can be specified as floating point number 0.25 under *RatioNumerator*. The *RatioNumerator* may be negative.

## Outputs

```
VAR_OUTPUT  
    StartSync      : BOOL;  
    InSync         : BOOL;  
    Busy           : BOOL;   
    Active         : BOOL;   
    CommandAborted : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
END_VAR
```

**StartSync**: Becomes TRUE when the synchronization with the master axis was started.

**InSync:** Becomes TRUE, if the coupling was successfully completed and the slave axis is synchronized with the master axis.

**Busy:** The *Busy* output becomes TRUE when the command is started with *Execute* and remains TRUE as long as the command is processed. If *Busy* becomes FALSE again, the function block is ready for a new job. At the same time one of the outputs *InSync*, *CommandAborted* or *Error* is set.

**Active:** Active indicates that the command is executed (currently Active=Busy, see BufferMode)

**CommandAborted**: Becomes TRUE, if the command could not be fully executed. The axis may have become decoupled during the coupling process (simultaneous command execution).

**Error**: Becomes TRUE, as soon as an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number

## Inputs/outputs

```
VAR_IN_OUT  
    Master : AXIS_REF;  
    Slave  : AXIS_REF;  
END_VAR
```

**Master**: Axis data structure of the master.

**Slave**: Axis data structure of the Slave.

The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state.

[TF5055 | TwinCAT 3 NC Flying Saw](ms-xhelp:///?Id=beckhoff-70fc-458e-9475-9aee1787ddfa)
