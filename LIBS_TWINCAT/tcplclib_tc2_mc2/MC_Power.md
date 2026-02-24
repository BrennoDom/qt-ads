# MC_Power

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Axis functions](ms-xhelp:///?Id=beckhoff-1c7e-485e-b51b-6dcbce9af3d9)
4. MC\_Power

# MC\_Power

![37815352](/tcplclib_tc2_mc2/1033/Images/png/9007199324926603__Web.png)

MC\_Power activates software enable for an axis. Enable can be activated for both directions of travel or only one direction. At "Status" output operational readiness of the axis is indicated.

A velocity override influences the velocity of all travel commands by a specified percentage.

Depending on the drive type, “Status” also signals operational readiness of the drive. Digital drives provide feedback on operational readiness, while analog drives are unable to indicate their operational readiness. In the latter case Status only indicated operational readiness of the control side.

|  |  |
| --- | --- |
| 4793853 | In addition to software enable it may be necessary to activate a hardware enable signal in order to enable a drive. This signal is not influenced by MC\_Power and must be activated separately by the PLC. |

## Inputs

```
VAR_INPUT  
    Enable          : BOOL; (* B *)  
    Enable_Positive : BOOL; (* E *)  
    Enable_Negative : BOOL; (* E *)  
    Override        : LREAL (* V *) := 100.0; (* in percent - Beckhoff proprietary input *)  
    BufferMode      : MC_BufferMode; (* V *)  
END_VAR
```

**Enable:** General software enable for the axis.

**Enable\_Positive:** Advance movement enable in positive direction. Only takes effect if Enable = TRUE.

**Enable\_Negative:** Advance movement enable in negative direction. Only takes effect if Enable = TRUE.

**Override:** Velocity override in % for all motion commands. (0 ≤ Override≤ 100.0)

**BufferMode:** This is evaluated when "Enable" is reset (see also [MC\_BufferMode](ms-xhelp:///?Id=beckhoff-53fe-47a4-8963-2af9ad8ff58b)). MC\_Aborting mode leads to immediate deactivation of the axis enable. Otherwise, e.g. in "MC\_Buffered" mode, the function block waits until the axis no longer executes a command.

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd)

## Outputs

```
VAR_OUTPUT  
    Status  : BOOL; (* B *)  
    Busy    : BOOL; (* V *)  
    Active  : BOOL; (* V *)  
    Error   : BOOL; (* B *)  
    ErrorID : UDINT; (* E *)  
END_VAR
```

**Status:** TRUE when the axis is ready for operation.

**Busy:** TRUE, as long as the function block is called with Enable = TRUE.

**Active:** Indicates that the command is executed.

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
