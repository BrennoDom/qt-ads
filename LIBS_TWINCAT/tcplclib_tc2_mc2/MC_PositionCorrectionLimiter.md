# MC_PositionCorrectionLimiter

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Organization blocks](ms-xhelp:///?Id=beckhoff-7981-40e5-8240-8b7aa05d05b3)
3. [Special extensions](ms-xhelp:///?Id=beckhoff-8c7a-4985-bc2a-8740f4381d5f)
4. MC\_PositionCorrectionLimiter

# MC\_PositionCorrectionLimiter

![32876269](/tcplclib_tc2_mc2/1033/Images/png/2240508299__Web.png)

The function block MC\_PositionCorrectionLimiter writes a correction value (PositionCorrectionValue) at the actual position of an axis. Depending on the correction mode the data are fed either directly or filtered to the axis.

|  |  |
| --- | --- |
| 27450972 | To use this function block successfully, the "PositionCorrection" parameter must be activated in the System Manager. The function block should only be used with enabled axes. |

## Inputs

```
VAR_INPUT  
    Enable                  :    BOOL;  
    PositionCorrectionValue :    LREAL;  
    CorrectionMode          :    E_AxisPositionCorrectionMode;  
    Acceleration            :    LREAL;  
    CorrectionLength        :    LREAL;  
END_VAR
```

**Enable:** Activates continuous writing of the correction value "PositionCorrectionValue". It must be TRUE as long as new correction values are to be accepted.

**PositionCorrectionValue:** Correction value to be added to the actual value of the axis

**CorrectionMode:** Depending on this mode, the correction value "PositionCorrectionValue" is written either directly or filtered. For a detailed description see [E\_AxisPositionCorrectionMode](ms-xhelp:///?Id=beckhoff-dd35-486d-8e62-3cde8221eb86).

**Acceleration:** Depending on the "CorrectionMode" the maximum acceleration to reach the new correction value is specified here. In the case of [PositionCorrectionMode\_Fast](ms-xhelp:///?Id=beckhoff-dd35-486d-8e62-3cde8221eb86) this value has a direct effect on the position delta by PLC-tick.  
Maximum permissible correction value Position delta = acceleration \* (PLC cycle time)2.  
If acceleration is parameterized as 0.0, the position correction is not limited.

**CorrectionLength:** Becomes active when the "CorrectionMode" matches [PositionCorrectionMode\_FullLength](ms-xhelp:///?Id=beckhoff-dd35-486d-8e62-3cde8221eb86). A change in the "PositonCorrectionValue" is distributed over this correction length.

## Outputs

```
VAR_OUTPUT  
    Busy     :    BOOL;  
    Error    :    BOOL;  
    ErrorID  :    UDINT;  
    Limiting :    BOOL;  
END_VAR
```

**Busy:** TRUE as soon as the function block is active. FALSE when it returns to its original state.

**Error:** TRUE, if an error occurs.

**ErrorID:** If the error output is set, this parameter supplies the error number.

**Limiting:** TRUE if the required correction value "PositionCorrectionValue" is not yet fully accepted.

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
