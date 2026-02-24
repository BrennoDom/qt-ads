# MC_Reset

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Axis functions](ms-xhelp:///?Id=beckhoff-1c7e-485e-b51b-6dcbce9af3d9)
4. MC\_Reset

# MC\_Reset

![43144677](/tcplclib_tc2_mc2/1033/Images/png/9007199324929803__Web.png)

MC\_Reset resets the NC axis. In many cases this also leads to a reset of a connected drive device. Depending on the bus system or drive types, in some cases a separate reset may be required for the drive device.

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE if the reset was successfully executed.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new command. At the same time, one of the outputs "Done" or "Error" is set.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

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
