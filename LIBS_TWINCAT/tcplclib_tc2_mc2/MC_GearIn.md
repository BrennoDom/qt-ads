# MC_GearIn

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Axis coupling](ms-xhelp:///?Id=beckhoff-7801-4505-8925-dac3e0bfa5d7)
4. MC\_GearIn

# MC\_GearIn

![29623765](/tcplclib_tc2_mc2/1033/Images/png/9007199325086603__Web.png)

The function block MC\_GearIn activates a linear master-slave coupling (gear coupling). The function block accepts a fixed gear ratio in numerator/denominator format.

The slave axis can be coupled to the master axis at standstill. With this function block it is not possible to synchronize to a moving master axis. The flying saw function blocks MC\_GearInVelo or MC\_GearInPos can be used for this purpose.

The slave axis can be decoupled with the function block [MC\_GearOut](ms-xhelp:///?Id=beckhoff-ade0-428d-928f-7b95a879c82f). If the slave is decoupled while it is moving, then it retains its velocity and can be halted using [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) or [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7).

Alternatively, the function block [MC\_GearInDyn](ms-xhelp:///?Id=beckhoff-e073-4a8b-9567-8ee7b037efba) with dynamically changeable gear ratio is available.

## Inputs

```
VAR_INPUT  
    Execute          : BOOL;  
    RatioNumerator   : LREAL;  
    RatioDenominator : UINT;  
    Acceleration     : LREAL;  
    Deceleration     : LREAL;  
    Jerk             : LREAL;  
    BufferMode       : MC_BufferMode;   
    Options          : ST_GearInOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**RatioNumerator:** Gear ratio numerator. Alternatively, the gear ratio can be specified in the numerator as a floating point value, if the denominator is 1.

**RatioDenominator:** Gear ratio denominator

**Acceleration:** Acceleration (≥0). (Currently not implemented)

**Deceleration:** Deceleration (≥0). (Currently not implemented)

**Jerk:** Jerk (≥0). (Currently not implemented)

**BufferMode:** Currently not implemented

**Options:** Currently not implemented

For a 1:4 ratio the RatioNumerator must be 1, the RatioDenominator must be 4. Alternatively, the RatioDenominator may be 1, and the gear ratio can be specified as floating point number 0.25 under RatioNumerator. The RatioNumerator may be negative.

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

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "InGear", "CommandAborted" or "Error" is set.

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
