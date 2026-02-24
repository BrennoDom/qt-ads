# MC_PhasingAbsolute

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Phasing](ms-xhelp:///?Id=beckhoff-d090-45d7-8263-c9f51979259f)
4. MC\_PhasingAbsolute

# MC\_PhasingAbsolute

![33017564](/tcplclib_tc2_mc2/1033/Images/png/9007201496529547__Web.png)

The function block MC\_PhasingAbsolute can be used to set a phase shift between a master axis and a slave axis. The function block executes a superimposed movement of the slave axis and thus sets a position difference "PhaseShift" between master and slave.

The dynamic values "velocity", "acceleration" and "deceleration" refer to the superimposed movement with that the phase shift is carried out. The movement is always jerk-limited, based on the constant jerk value set in the "Jerk" parameter. This value applies to both: "Acceleration" and "Deceleration".

## Inputs

```
VAR_INPUT  
    Execute:          BOOL;  
    ContinuousUpdate: BOOL;  
    PhaseShift:       LREAL;  
    Velocity:         LREAL;  
    Acceleration:     LREAL;  
    Deceleration:     LREAL;  
    Jerk:             LREAL;  
    BufferMode:       MC_BufferMode;  
    Options:          ST_PhasingOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**ContinuousUpdate:** If this input is TRUE when there is a rising edge at the Execute input, then during performing the command the inputs "PhaseShift", "Velocity", "Acceleration", "Deceleration" and "Jerk" can be changed and come into effect as quickly as possible.

**PhaseShift:** Phase shift to be set between master and slave axis.

**Velocity:** Maximum velocity that may be reached during the phase shift (>=0.01).

**Acceleration:** Maximum acceleration value.

**Deceleration:** Maximum deceleration value.

**Jerk:** Maximum jerk value.

**BufferMode:** Not implemented.

**Options:** Data structure containing additional, rarely used parameters. Normally, the input can remain open.

## Outputs

```
VAR_OUTPUT  
    Done               : BOOL;  
    Busy               : BOOL;  
    Active             : BOOL;  
    CommandAborted     : BOOL;  
    Error              : BOOL;  
    ErrorId            : UDINT;  
    AbsolutePhaseShift : LREAL;  
END_VAR
```

**Done:** TRUE when the absolute phase shift is established.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the phase shift occurs. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** TRUE if the command could not be executed completely. The axis was stopped or the current command was replaced by another Move command.

**Error:** TRUE if an error occurs.

**ErrorId:** If the error output is set, this parameter supplies the error number.

**AbsolutePhaseShift:** Absolute phase shift.

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
