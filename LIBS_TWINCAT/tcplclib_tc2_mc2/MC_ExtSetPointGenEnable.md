# MC_ExtSetPointGenEnable

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [External set value generator](ms-xhelp:///?Id=beckhoff-5236-4f1a-806c-02440c61d98c)
4. MC\_ExtSetPointGenEnable

# MC\_ExtSetPointGenEnable

![19701298](/tcplclib_tc2_mc2/1033/Images/png/9007199324981003__Web.png)

The external setpoint generator of an axis can be switched on with the function block MC\_ExtSetPointGenEnable. The axis then adopts the set value specifications from its cyclic axis interface (Axis.PlcToNc.ExtSetPos, ExtSetVelo, ExtSetAcc and ExtSetDirection).

An external setpoint generator is usually a PLC function block that calculates cyclic set values for an axis and can therefore substitute the internal setpoint generator in an NC axis.

See also: [MC\_ExtSetPointGenDisable](ms-xhelp:///?Id=beckhoff-845c-4f7d-83db-63af7bf93769) and [MC\_ExtSetPointGenFeed](ms-xhelp:///?Id=beckhoff-3891-4667-8003-dc8c6d114c7a)

## Inputs

```
VAR_INPUT  
    Execute      : BOOL;  
    Position     : LREAL;  
    PositionType : E_PositionType;  
END_VAR
```

**Execute:** The command is executed with a positive edge.

**Position:** Position for target position monitoring. Setting of this position does not mean that the axis moves to this position, for which only the external setpoint generator is responsible. Instead, setting this position activates the target position monitoring. The flag InTargetPosition becomes TRUE when this position is reached.

**PositionType:** POSITIONTYPE\_ABSOLUTE or POSITIONTYPE\_RELATIVE (type: [E\_PositionType](ms-xhelp:///?Id=beckhoff-32de-4b58-8e40-c77eb0411e7d))

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
