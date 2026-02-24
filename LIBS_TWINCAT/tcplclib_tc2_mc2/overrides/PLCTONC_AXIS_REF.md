# PLCTONC_AXIS_REF

```
TYPE PLCTONC_AXIS_REF :
STRUCT
    ControlDWord         : PLCTONC_AXIS_REF_CTRL;
    Override             : UDINT;
    AxisModeRequest      : UDINT;
    AxisModeDWord        : UDINT;
    AxisModeLReal        : LREAL;
    PositionCorrection   : LREAL;
    ExtSetPos            : LREAL;
    ExtSetVelo           : LREAL;
    ExtSetAcc            : LREAL;
    ExtSetDirection      : DINT;
    {attribute 'hide'}
    _reserved1           : UDINT;
    ExtControllerOutput  : LREAL;
    GearRatio1           : LREAL;
    GearRatio2           : LREAL;
    GearRatio3           : LREAL;
    GearRatio4           : LREAL;
    MapState             : BOOL;
    PlcCycleControl      : BYTE;
    PlcCycleCount        : BYTE;
    {attribute 'hide'}
    _reserved2           : ARRAY [1..5] OF USINT;
    ExtTorque            : LREAL;
    {attribute 'hide'}
    _reserved3           : ARRAY [1..8] OF USINT;
END_STRUCT
END_TYPE
```