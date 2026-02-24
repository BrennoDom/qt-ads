# MC_ExtSetPointGenDisable

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [External set value generator](ms-xhelp:///?Id=beckhoff-5236-4f1a-806c-02440c61d98c)
4. MC\_ExtSetPointGenDisable

# MC\_ExtSetPointGenDisable

![43093956](/tcplclib_tc2_mc2/1033/Images/png/9007199324984203__Web.png)

The external setpoint generator of an axis can be switched off with the function block MC\_ExtSetPointGenDisable. The axis then no longer adopts the set value specifications from its cyclic axis interface (Axis.PlcToNc.ExtSetPos, ExtSetVelo, ExtSetAcc and ExtSetDirection)

An external setpoint generator is usually a PLC function block that calculates cyclic set values for an axis and can therefore substitute the internal setpoint generator in an NC axis.

See also: [MC\_ExtSetPointGenEnable](ms-xhelp:///?Id=beckhoff-6eda-4db2-8650-05311e21328c) and [MC\_ExtSetPointGenFeed](ms-xhelp:///?Id=beckhoff-3891-4667-8003-dc8c6d114c7a)

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
    Enabled : BOOL;  
END_VAR
```

**Done:** TRUE if the command was executed successfully.

**Busy:** TRUE as soon as the function block is active. FALSE if it is in the default state.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**Enabled:** Shows the current state of the external setpoint generator, regardless of the function execution.

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
