# MC_SetEncoderScalingFactor

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_SetEncoderScalingFactor

# MC\_SetEncoderScalingFactor

![21118492](/tcplclib_tc2_mc2/1033/Images/png/9007199325016203__Web.png)

MC\_SetEncoderScalingFactor changes the scaling factor for the active encoder of an axis, either at standstill or in motion.

The change can be absolute or relative. This mode is only suitable at standstill, since in absolute mode the change in scaling factor leads to a position discontinuity. In relative mode an internal position offset is adapted at the same time such that no discontinuity occurs. Note that an intervention during the motion results in a change in the actual axis velocity, while the real velocity remains constant. Therefore only small changes can be implemented during the motion.

## Inputs

```
VAR_INPUT  
    Execute       : BOOL;  
    ScalingFactor : LREAL;   
    Mode          : E_SetScalingFactorMode;   
    Options       : ST_SetEncoderScalingOptions;   
END_VAR
```

**Execute:** The command is executed with a positive edge.

**ScalingFactor:** Scaling factor of the active encoder of an axis. The scaling factor is specified in physical positioning units [u] divided by the number of encoder increments.

**Mode:** The scaling factor can be set in absolute or relative mode (ENCODERSCALINGMODE\_ABSOLUTE, ENCODERSCALINGMODE\_RELATIVE).  
In absolute mode counting starts at the origin of the axis coordinate system, resulting in a position discontinuity if the scaling factor is changed. In relative mode the actual position of the axis does not change. This mode is therefore also suitable for changes during motion.

**Options:** Data structure containing additional, rarely used parameters. The input can normally remain open.

* **SelectEncoderIndex:** Can be set if an axis with several encoders is used and the position of a particular encoder is to be set (Options.EncoderIndex).
* **EncoderIndex:** Indicates the encoder (0..n) if "SelectEncoderIndex" is TRUE.

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

**Busy:** TRUE as soon as the command is started with Execute and as long as the command is processed. If "Busy" is FALSE, the function block is ready for a new order. At the same time, one of the outputs "Done" or "Error" is set.

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
