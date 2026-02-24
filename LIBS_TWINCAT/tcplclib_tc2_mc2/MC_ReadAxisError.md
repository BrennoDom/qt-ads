# MC_ReadAxisError

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_ReadAxisError

# MC\_ReadAxisError

![33545144](/tcplclib_tc2_mc2/1033/Images/png/9007199324945803__Web.png)

MC\_ReadAxisError reads the axis error of an axis.

## Inputs

```
VAR_INPUT  
    Enable : BOOL; (* B *)  
END_VAR
```

**Enable:** If Enable = TRUE, the axis error is output at the "AxisErrorID" output.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Valid       : BOOL; (* B *)  
    Busy        : BOOL; (* E *)  
    Error       : BOOL; (* B *)  
    ErrorID     : DWORD; (* B *)  
    AxisErrorID : DWORD; (* B *)  
END_VAR
```

**Valid:** TRUE if the error signaled at the "AxisErrorID" output is valid.

**Busy:** TRUE as soon as the command is started with Enable and as long as the command is processed. If Busy is FALSE, the function block is ready for a new order.

**Error:** TRUE, if an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number.

**AxisErrorID**: Error number for the axis

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
