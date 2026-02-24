# MC_SetPosition

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Axis functions](ms-xhelp:///?Id=beckhoff-1c7e-485e-b51b-6dcbce9af3d9)
4. MC\_SetPosition

# MC\_SetPosition

![52757779](/tcplclib_tc2_mc2/1033/Images/png/9007199324933003__Web.png)

MC\_SetPosition sets the current axis position to a parameterizable value.

In absolute mode, the actual position is set to the parameterized absolute Position value. In relative mode, the actual position is offset by the parameterized Position value. In both cases, the set position of the axis is set such that any lag error that may exist is retained. The switch Options.ClearPositionLag can be used to clear the lag error.

Relative mode can be used to change the axis position during the motion.

## Inputs

```
VAR_INPUT  
    Execute  : BOOL;  
    Position : LREAL;   
    Mode     : BOOL; (* RELATIVE=True, ABSOLUTE=False (Default) *)  
    Options  : ST_SetPositionOptions;   
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Position:** Position value to which the axis position is to be set. In absolute mode the actual position is set to this value, in relative mode it is shifted by this value.

**Mode:** The axis position is set to an absolute value set if Mode = FALSE. Otherwise the axis position is changed relative to the specified Position value. Relative mode can be used for changing the position of an axis during motion.

**Options:** Data structure containing additional, rarely used parameters. The input can normally remain open.

* **ClearPositionLag:** Can optionally be used to set the set and actual positions to the same value. In this case the lag error is cleared.
* **SelectEncoderIndex:** Can optionally be set if an axis with several encoders is used and the position of a particular encoder is to be set (Options.EncoderIndex).
* **EncoderIndex:** Indicates the encoder (0..n) if SelectEncoderIndex = TRUE.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Done    : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Done:** TRUE if the position was set successfully.

**Busy:** TRUE as soon as the command is started with "Execute" and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

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
