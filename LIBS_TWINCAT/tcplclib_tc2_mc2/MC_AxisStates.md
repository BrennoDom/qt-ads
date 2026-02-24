# MC_AxisStates

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Motion](ms-xhelp:///?Id=beckhoff-2107-47ed-8b8e-b9259019655e)
4. MC\_AxisStates

# MC\_AxisStates

This data type describes the operating states according to the [PlcOpen state diagram](ms-xhelp:///?Id=beckhoff-b7d4-4248-ac4c-cc4128783cfe).

```
TYPE MC_AxisStates :  
(  
    MC_AXISSTATE_UNDEFINED,  
    MC_AXISSTATE_DISABLED,  
    MC_AXISSTATE_STANDSTILL,  
    MC_AXISSTATE_ERRORSTOP,  
    MC_AXISSTATE_STOPPING,  
    MC_AXISSTATE_HOMING,  
    MC_AXISSTATE_DISCRETEMOTION,  
    MC_AXISSTATE_CONTINOUSMOTION,  
    MC_AXISSTATE_SYNCHRONIZEDMOTION  
);  
END_TYPE
```

See also: [General rules for MC function blocks](ms-xhelp:///?Id=beckhoff-8c0b-4b22-91c9-62cc025540bd).

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
