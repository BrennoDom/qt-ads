# MC_TouchProbeRecordedData

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Touch probe](ms-xhelp:///?Id=beckhoff-cbed-493e-ab05-255e22e5dafd)
4. MC\_TouchProbeRecordedData

# MC\_TouchProbeRecordedData

```
TYPE MC_TouchProbeRecordedData :  
STRUCT  
    Counter             : LREAL;  
    RecordedPosition    : LREAL;  
    AbsolutePosition    : LREAL;  
    ModuloPosition      : LREAL;  
END_STRUCT  
END_TYPE
```

**Counter**: Counter indicating how many valid edges were detected in the last cycle. Detection of multiple edges is only implemented in mode TOUCHPROBEMODE\_CONTINUOUS under SERCOS / SOE and must be supported explicitly by the hardware (e.g. AX5000).

**RecordedPosition:** Axis position recorded at the point in time of the trigger signal. This corresponds to the absolute axis position or the modulo axis position, depending on the parameterization.

**AbsolutePosition**: Absolute axis position detected at the time of the trigger signal.

**ModuloPosition**: Modulo axis position recorded at the time of the trigger signal.

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
