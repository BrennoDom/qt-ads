# MC_OverrideFilter

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_OverrideFilter

# MC\_OverrideFilter

![949529](/tcplclib_tc2_mc2/1033/Images/png/9007199325009803__Web.png)

The function block MC\_OverrideFilter can be used to convert an unfiltered override value consisting of digits (e.g. a voltage value of an analog input terminal) into a filtered override value that matches the cyclic axis interface (PlcToNc) (DWORD in the range 0...1000000). This filtered override is also available in percent (LREAL in the range 0...100%).

The raw input value is limited to a validity range by "LowerOverrideThreshold" and "UpperOverrideThreshold", and implemented as parameterizable steps (resolution) ("OverrideSteps"). After each override change at the output of the FB, the system internally waits for a minimum recovery time ("OverrideRecoveryTime") before a new override value can be applied. The only exceptions are the override values 0% and 100%, which are always implemented without delay for safety reasons.

|  |  |
| --- | --- |
| 8545767 | Due to the gradation of the output override value ("OverrideValueFiltered"), the filtered override can become zero with very small override input values ("OverrideValueRaw"). A zero override leads to standstill of the axis. If total standstill is undesired, "OverrideValueRaw" should not fall below the smallest level. |

## Inputs

```
VAR_INPUT  
    OverrideValueRaw       : DINT;  
    LowerOverrideThreshold : DINT := 0; (* 0...32767 digits *)  
    UpperOverrideThreshold : DINT := 32767; (* 0...32767 digits *)  
    OverrideSteps          : UDINT := 200; (* 200 steps => 0.5 percent *)  
    OverrideRecoveryTime   : TIME := T#150ms; (* 150 ms *)  
END_VAR
```

**OverrideValueRaw:** Raw, unfiltered override value (e.g. a voltage value of an analog input terminal).

**LowerOverrideThreshold:** Lower bound that limits the raw override value.

**UpperOverrideThreshold:** Upper bound that limits the raw override value.

**OverrideSteps:** The predefined steps (override resolution)

**OverrideRecoveryTime:** Minimum recovery time, after which a new filtered override value is applied to the output. However, the override values 0% and 100% are implemented without delay.

## Outputs

```
VAR_OUTPUT  
    OverrideValueFiltered   : DWORD; (* 0...1000000 counts *)  
    OverridePercentFiltered : LREAL; (* 0...100 % *)  
    Error                   : BOOL;  
    ErrorId                 : UDINT;  
END_VAR
```

**OverrideValueFiltered:** Filtered override value in digits (the data type matches the override in the cyclic axis interface 0..1000000).

**OverridePercentFiltered:** Filtered override value in percent (0..100%).

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

| Possible error number | Possible causes |
| --- | --- |
| MC\_ERROR\_PARAMETER\_NOT\_CORRECT | * OverrideSteps <= 1 * LowerOverrideThreshold >= UpperOverrideThreshold |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
