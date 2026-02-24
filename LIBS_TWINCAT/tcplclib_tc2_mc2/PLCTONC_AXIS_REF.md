# PLCTONC_AXIS_REF

## Library
tcplclib_tc2_mc2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
2. [Data types](ms-xhelp:///?Id=beckhoff-683b-4615-8584-914eb091e041)
3. [Axis interface](ms-xhelp:///?Id=beckhoff-6c92-40ec-8c23-14d31eb6d79e)
4. PLCTONC\_AXIS\_REF

# PLCTONC\_AXIS\_REF

The data structure PLCTONC\_AXIS\_REF is part of the [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) data structure and cyclically transfers information to the NC. PLCTONC\_AXIS\_REF is also referred to as axis interface between PLC and NC.

```
TYPE PLCTONC_AXIS_REF  
STRUCT  
    ControlDWord        : PLCTONC_AXIS_REF_CTRL; (* Control double word *)  
    Override            : UDINT; (* Velocity override *)  
    AxisModeRequest     : UDINT; (* Axis operating mode (PLC request) *)  
    AxisModeDWord       : UDINT; (* optional mode parameter *)  
    AxisModeLReal       : LREAL; (* optional mode parameter *)  
    PositionCorrection  : LREAL; (* Correction value for current position *)  
    ExtSetPos           : LREAL; (* external position setpoint *)  
    ExtSetVelo          : LREAL; (* external velocity setpoint *)  
    ExtSetAcc           : LREAL; (* external acceleration setpoint *)  
    ExtSetDirection     : DINT; (* external direction setpoint *)  
    {attribute 'hide'}  
    _reserved1          : UDINT; (* reserved *)  
    ExtControllerOutput : LREAL; (* external controller output *)  
    GearRatio1          : LREAL; (* Gear ratio for dynamic multi master coupling modes *)  
    GearRatio2          : LREAL; (* Gear ratio for dynamic multi master coupling modes *)  
    GearRatio3          : LREAL; (* Gear ratio for dynamic multi master coupling modes *)  
    GearRatio4          : LREAL; (* Gear ratio for dynamic multi master coupling modes *)  
    MapState            : BOOL; (* reserved - internal use *)  
    PlcCycleControl     : BYTE;  
    PlcCycleCount       : BYTE;  
    {attribute 'hide'}  
    _reserved2          : ARRAY [1..21] OF USINT;  
END_STRUCT  
END_TYPE
```

| Variable name | Data type | Definition range | Description |
| --- | --- | --- | --- |
| ControlDWord | [PLCTONC\_AXSI\_REF\_CTRL](ms-xhelp:///?Id=beckhoff-2cfc-447a-ad25-74a110ad1dec) | 0/1 | Control double word |
| Override | UDINT | 0...1000000 | Velocity override (0% to 100%) |
| AxisModeRequest | UDINT |  | Axis operating mode. Only provided for internal use! |
| AxisModeDWord | UDINT |  | Only provided for internal use! |
| AxisModeLReal | LREAL |  | Only provided for internal use! |
| PositionCorrection | LREAL |  | Actual position correction value |
| ExtSetPos | LREAL |  | External set position |
| ExtSetVelo | LREAL |  | External set velocity |
| ExtSetAcc | LREAL |  | External set acceleration |
| ExtSetDirection | DINT |  | External set travel direction [-1,0,1] |
| ExtControllerOutput | LREAL |  | External controller output. Not yet released! |
| GearRatio1 | LREAL | ±∞ | Gear ratio (coupling factor) 1 |
| GearRatio2 | LREAL | ±∞ | Gear ratio (coupling factor) 2 |
| GearRatio3 | LREAL | ±∞ | Gear ratio (coupling factor) 3 |
| GearRatio4 | LREAL | ±∞ | Gear ratio (coupling factor) 4 |
| MapState | BOOL |  | Internal use only |
| PlcCycleControl | BYTE |  | Internal use only |
| PlcCycleCount | BYTE |  | Internal use only |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.0.0 | PC or CX (x86 or x64) | Tc2\_MC2 |

[TwinCAT 3 | PLC Library: Tc2\_MC2](ms-xhelp:///?Id=beckhoff-63a7-4c0e-8569-314547c8cffc)
