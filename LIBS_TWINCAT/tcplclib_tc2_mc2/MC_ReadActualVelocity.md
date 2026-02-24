# MC_ReadActualVelocity

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Status and parameter](ms-xhelp:///?Id=beckhoff-0ebf-4c69-b478-131974c43a33)
4. MC\_ReadActualVelocity

# MC\_ReadActualVelocity

![45521706](/tcplclib_tc2_mc2/1033/Images/png/9007199324939403__Web.png)

The actual axis velocity value can be read with the function block `MC_ReadActualVelocity`. The actual velocity value is the velocity value that is returned from the drive amplifier to the axis.

## Inputs

```
VAR_INPUT  
    Enable : BOOL;  
END_VAR
```

**Enable:** TRUE as long as the command is executed.

## Outputs

```
VAR_OUTPUT  
    Valid          : BOOL;  
    Busy           : BOOL;  
    Error          : BOOL;  
    ErrorID        : UDINT;  
    ActualVelocity : LREAL;  
END_VAR
```

**Valid:** TRUE if the output "ActualVelocity" has a valid value.

**Busy:** Indicates that the function block is active.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**ActualVelocity:** Current axis velocity

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
