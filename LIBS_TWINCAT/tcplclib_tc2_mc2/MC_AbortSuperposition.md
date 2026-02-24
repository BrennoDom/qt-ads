# MC_AbortSuperposition

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Motion function blocks](ms-xhelp:///?Id=beckhoff-9fda-4d69-a293-05505fb4838c)
3. [Superposition](ms-xhelp:///?Id=beckhoff-1c4d-4ef6-81de-ab45bc73a928)
4. MC\_AbortSuperposition

# MC\_AbortSuperposition

![62218962](/tcplclib_tc2_mc2/1033/Images/png/9007199325073803__Web.png)

The MC\_AbortSuperposition function block terminates a superimposed movement started by [MC\_MoveSuperImposed](ms-xhelp:///?Id=beckhoff-5d13-4934-bf02-f97d70604dd7), without stopping the subordinate axis movement.

A full axis stop can be achieved with [MC\_Stop](ms-xhelp:///?Id=beckhoff-8fd4-4e57-a689-0508c190c4a6) or [MC\_Halt](ms-xhelp:///?Id=beckhoff-5810-4bd8-af0f-d6ee63da26d7), if necessary. In this case MC\_AbortSuperposition does not have to be called.

## Inputs

```
VAR_INPUT  
    Execute : BOOL;  
END_VAR
```

**Execute:** The command is executed with a positive edge and the superimposed movement is completed.

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;   
END_VAR
```

**Done:** TRUE when the superimposed movement was successfully aborted.

**Busy:** TRUE as soon as the function block is active. FALSE when it returns to its initial state.

**Error:** TRUE as soon as an error occurs.

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
