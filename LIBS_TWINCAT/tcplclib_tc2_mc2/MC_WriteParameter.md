# MC_WriteParameter

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_WriteParameter

# MC\_WriteParameter

![30902896](/tcplclib_tc2_mc2/1033/Images/png/9007199324965003__Web.png)

Axis parameters can be written with the function block MC\_WriteParameter.

|  |  |
| --- | --- |
| 9690616 | In this case "axis" refers to the TwinCAT NC axis and its parameters, and not the drive. |

## Inputs

```
VAR_INPUT  
    Execute         : BOOL;  
    ParameterNumber : INT;  
    Value           : LREAL;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**ParameterNumber:** Number of the parameter to be written. (See [MC\_AxisParameter](ms-xhelp:///?Id=beckhoff-de96-43e9-9f5f-2643db2c8c21))

**Value:** LREAL value that is written.

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

## Sample

```
VAR   
    Axis1           : Axis_REF;  
    fbWriteParameter: MC_WriteParameter;  
END_VAR
```

```
fbWriteParameter(  
    Execute := TRUE;  
    Axis:= Axis1 ,  
    ParameterNumber:= SWLimitPos ,  
    Value:= 2000   
);
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
