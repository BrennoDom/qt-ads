# MC_GearInDyn

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Axis coupling](ms-xhelp:///?Id=beckhoff-7801-4505-8925-dac3e0bfa5d7)
4. MC\_GearInDyn

# MC\_GearInDyn

![65287294](/tcplclib_tc2_mc2/1033/Images/png/9007199325089803__Web.png)

The function block MC\_GearInDyn activates a linear master-slave coupling (gear coupling). The gear ratio can be adjusted dynamically during each PLC cycle. Hence a controlled master/slave coupling can be build up. The "Acceleration" parameter has a limiting effect in situations with large gear ratio variations.

The slave axis can be decoupled with the function block [MC\_GearOut](ms-xhelp:///?Id=beckhoff-ade0-428d-928f-7b95a879c82f). If the slave is decoupled while it is moving, then it retains its velocity and can be halted using [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) or [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7).

Alternatively, the function block [MC\_GearIn](ms-xhelp:///?Id=beckhoff-21e6-4762-8262-c4167658b337) with dynamically variable gear ratio is available.

## Inputs

```
VAR_INPUT  
    Enable       : BOOL;  
    GearRatio    : LREAL;  
    Acceleration : LREAL;  
    Deceleration : LREAL;  
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;   
    Options      : ST_GearInDynOptions;  
END_VAR
```

**Enable:** The coupling is executed with a positive edge. The gear ratio can be changed cyclically as long as "Enable" is TRUE. The command is terminated if "Enable" becomes FALSE after coupling. The gear ratio is frozen at its last value, but the slave is not decoupled.

**GearRatio:** Gear ratio as floating point value. The gear ratio can be changed cyclically as long as "Enable" is TRUE. If "Enable" isFALSE, the gear ratio remains unchanged.

**Acceleration:** Acceleration (≥0). If the value is 0, the standard acceleration from the axis configuration in the System Manager is used. The parameter limits the acceleration of the slave in situations with large gear ratio variations. The maximum acceleration is only reached at the maximum master velocity. Otherwise the slave acceleration is below this value when the gear ratio changes significantly.

**Deceleration:** Deceleration (≥0). (Not implemented)

**Jerk:** Jerk (≥0). (Not implemented)

**BufferMode:** Currently not implemented

**Options:** Currently not implemented

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

**Busy:** TRUE as soon as the command is started and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "InGear", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. (Currently Active = Busy)

**CommandAborted:** TRUE if the command could not be executed completely. The axis may have become decoupled during the coupling process (simultaneous command execution).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

## Inputs/outputs

```
VAR_IN_OUT  
    Master : AXIS_REF;  
    Slave  : AXIS_REF;  
END_VAR
```

**Master:** Axis data structure of the master.

**Slave:** Axis data structure of the Slave.

The axis data structure of type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
