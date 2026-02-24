# MC_HaltPhasing

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Phasing](ms-xhelp:///?Id=beckhoff-d090-45d7-8263-c9f51979259f)
4. MC\_HaltPhasing

# MC\_HaltPhasing

![55864401](/tcplclib_tc2_mc2/1033/Images/png/2241785995__Web.png)

The function block MC\_HaltPhasing leads to a controlled stop of the phase shift of a slave axis relative to the master axis. The "Halt" is always jerk-limited, based on the constant jerk value for the braking delay set in the "Jerk" parameter. MC\_HaltPhasing terminates a superimposed movement through MC\_PhasingAbsolute or MC\_PhasingRelative.

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Deceleration : LREAL;  
    Jerk         : LREAL;  
    BufferMode   : MC_BufferMode;  
    Options      : ST_PhasingOptions;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Deceleration:** Maximum deceleration value

**Jerk:** Maximum jerk value

**BufferMode:** Not implemented

**Options:** Data structure containing additional, rarely used parameters. The input can normally remain open.

## Outputs

```
VAR_OUTPUT  
    Done           :    BOOL;  
    Busy           :    BOOL;  
    Active         :    BOOL;  
    CommandAborted :    BOOL;  
    Error          :    BOOL;  
    ErrorId        :    UDINT;  
END_VAR
```

**Done:** TRUE if velocity = 0 is reached.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done", "CommandAborted" or "Error" is set.

**Active:** Indicates that the command is executed. If the command was buffered, it becomes active once a running command is completed.

**CommandAborted:** TRUE if the command could not be executed completely. The axis was stopped or the current command was replaced by another Move command.

**Error:** TRUE, if an error occurs.

**ErrorId:** If the error output is set, this parameter supplies the error number.

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
