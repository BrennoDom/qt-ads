# MC_SetOverride

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_SetOverride

# MC\_SetOverride

![9803039](/tcplclib_tc2_mc2/1033/Images/png/9007199325013003__Web.png)

The override for an axis can be specified with the function block MC\_SetOverride.

## Inputs

```
VAR_INPUT  
    Enable     : BOOL; (* B *)  
    VelFactor  : LREAL (* B *) := 1.0; (* 1.0 = 100% *)  
    AccFactor  : LREAL (* E *) := 1.0; (* 1.0 = 100% *) (* not supported *)  
    JerkFactor : LREAL (* E *) := 1.0; (* 1.0 = 100% *) (* not supported *)  
END_VAR
```

**Enable:** TRUE as long as the command is executed.

**VelFactor:** Velocity override factor

**AccFactor:** Not supported

**JerkFactor:** Not supported

## Outputs

```
VAR_OUTPUT  
    Enabled : BOOL;  
    Busy    : BOOL;  
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

**Enabled:** The parameterized override is set.

**Busy:** TRUE as soon as the command is started with Enable and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order.

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
