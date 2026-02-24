# MC_WriteBoolParameterPersistent

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_WriteBoolParameterPersistent

# MC\_WriteBoolParameterPersistent

![20106686](/tcplclib_tc2_mc2/1033/Images/png/2240513675__Web.png)

Boolean axis parameters can be written persistently with the function block MC\_WriteBoolParameterPersistent.

The persistent parameter to be written is stored in an initialization list. At system startup, the system initially starts with the originally configured values and overwrites these with the persistent data from the initialization list before the start of the task. The initialization list is cleared when a new system configuration is registered. The system then starts with the unchanged data from the new configuration.

|  |  |
| --- | --- |
| 46742451 | In this case "axis" refers to the TwinCAT NC axis and its parameters, and not the drive. |

## Inputs

```
VAR_INPUT  
    Execute         : BOOL;  
    ParameterNumber : INT;  
    Value           : BOOL;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**ParameterNumber:** Number of the parameter to be written. (Type [MC\_AxisParameter](ms-xhelp:///?Id=beckhoff-de96-43e9-9f5f-2643db2c8c21))

**Value:** Boolean value that is written.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE if the parameters were written successfully.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

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
