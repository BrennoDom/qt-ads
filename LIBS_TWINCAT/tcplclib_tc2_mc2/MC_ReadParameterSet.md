# MC_ReadParameterSet

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_ReadParameterSet

# MC\_ReadParameterSet

![21989419](/tcplclib_tc2_mc2/1033/Images/png/9007199324955403__Web.png)

The function block MC\_ReadParameterSet can be used to read the entire parameter set of an axis.

|  |  |
| --- | --- |
| 63687043 | In this case "axis" refers to the TwinCAT NC axis and its parameters, and not the drive. |

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute**: The command is executed with a positive edge.

## Inputs/outputs

```
VAR_IN_OUT  
    Parameter : ST_AxisParameterSet;  
    Axis      : AXIS_REF;  
END_VAR
```

**Parameter:** Parameter data structure into which the parameters are read. (Type: [ST\_AxisParameterSet](ms-xhelp:///?Id=beckhoff-632f-49fe-8da5-ab1f945b3f07))

**Axis:** Axis data structure that unambiguously addresses an axis in the system. Among other parameters it contains the current axis status, including position, velocity or error state. (Type: [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01))

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done**: TRUE if the parameters were read successfully.

**Busy**: TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

**Error**: TRUE, if an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number.

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
