# MC_ReadStatus

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_ReadStatus

# MC\_ReadStatus

![36312476](/tcplclib_tc2_mc2/1033/Images/png/9007199324958603__Web.png)

MC\_ReadStatus determines the current operating state of an axis and signals it at the function block outputs.

The updated operating state is additionally stored in the Status output data structure and in the Axis.Status axis data structure. This means the operating state only has to be read once at the start of each PLC cycle and can then be accessed via Axis.Status.

The Axis variable (type [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01)) already includes an instance of the function block MC\_ReadStatus. This means that the operating state of an axis can be updated at the start of a PLC cycle by calling up Axis.ReadStatus.

**Sample**:

```
PROGRAM MAIN  
VAR  
    Axis1 : AXIS_REF  
END_VAR  
  
(* call the read status function *)  
Axis1.ReadStatus;
```

## Inputs

```
VAR_INPUT  
    Enable : BOOL;   
END_VAR
```

**Enable:** if Enable = TRUE, the axis operating state is updated with each call of the function block.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Valid              : BOOL;   
    Busy               : BOOL;   
    Error              : BOOL;  
    ErrorId            : UDINT;  
    (* motion control statemachine states: *)  
    ErrorStop          : BOOL;   
    Disabled           : BOOL;   
    Stopping           : BOOL;   
    StandStill         : BOOL;   
    DiscreteMotion     : BOOL;   
    ContinuousMotion   : BOOL;   
    SynchronizedMotion : BOOL;   
    Homing             : BOOL;  
    (* additional status *)  
    ConstantVelocity   : BOOL;  
    Accelerating       : BOOL;  
    Decelerating       : BOOL;   
    (* status data structure *)  
    Status             : ST_AxisStatus;   
END_VAR
```

**Valid:** Indicates that the axis operating state indicated at the other outputs is valid.

**Busy:** Indicates that the function block is active.

**Error**: TRUE, if an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number.

**ErrorStop:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**Disabled:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**Stopping:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**StandStill:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**DiscreteMotion:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**ContinousMotion:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**SynchronizedMotion:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**Homing:** Axis status according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe)

**ConstantVelocity:** The axis is moving with constant velocity.

**Acceleration:** The axis accelerates.

**Decelerating:** The axis decelerates.

**Status:** Extended [status data structure](ms-xhelp:///?Id=beckhoff-1153-4ed0-8c31-5628d5b609a0) with additional status information. (Type: [ST\_AxisStatus](ms-xhelp:///?Id=beckhoff-1153-4ed0-8c31-5628d5b609a0))

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Inputs/outputs

```
VAR_IN_OUT  
    Axis : AXIS_REF;  
END_VAR
```

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
