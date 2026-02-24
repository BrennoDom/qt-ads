# MC_ReadBoolParameter

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_ReadBoolParameter

# MC\_ReadBoolParameter

![33470841](/tcplclib_tc2_mc2/1033/Images/png/9007199324949003__Web.png)

The function block MC\_ReadBoolParameter is used to read a boolean axis parameter.

|  |  |
| --- | --- |
| 32802119 | In this case "axis" refers to the TwinCAT NC axis and its parameters, and not the drive. |

## Inputs

```
VAR_INPUT  
 Enable          : BOOL;         (* B *)  
 ParameterNumber : MC_AxisParameter; (* B *)  
 ReadMode        : E_ReadMode (* V *)  
EEND_VAR
```

**Enable:** TRUE as long as the command is executed.

**ParameterNumber**: Number of the parameter to be read. (Type [MC\_AxisParameter](ms-xhelp:///?Id=beckhoff-de96-43e9-9f5f-2643db2c8c21))

**ReadMode:** Read mode of the parameter to be read (once or cyclic). (Type: [E\_ReadMode](ms-xhelp:///?Id=beckhoff-6ca2-4964-a2e5-45fae549f006))

## Outputs

```
VAR_OUTPUT  
    Valid   : BOOL;  (* B *)  
    Busy    : BOOL;  (* E *)  
    Error   : BOOL;  (* B *)  
    ErrorID : DWORD; (* E *)  
    Value   : BOOL;  (* B *)  
END_VAR
```

**Valid:** TRUE if the value signaled at output "Value" is valid.

**Busy:** TRUE as soon as the command is started with Enable and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order.

**Error**: TRUE, if an error occurs.

**ErrorID**: If the error output is set, this parameter supplies the error number.

**Value**: Shows the read Boolean value.

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
