# XFC_TimeToModuloPosition

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TimeToModuloPosition

XFC\_TimeToModuloPosition Position  LREALModuloFactor  LREALOptions  ST\_NcTimeConversionOptions↔Axis  Reference To AXIS\_REFDINT  DurationLREAL  AbsolutePositionT\_DCTIME32  TimeOfPositionBOOL  ErrorUDINT  ErrorID

XFC\_TimeToModuloPosition calculates the time period within which an axis will reach a position, or the time that has elapsed since the axis passed this position. In this case the position is the nearest modulo position in the direction of travel.

The function extrapolates the time in relation to the current position and dynamics. Precise extrapolation is only possible over a short interval, since the axis dynamics may change.

The function block requires precisely one call in order to provide the result. It can therefore be used similar to a function, although as well as the time it may also return an error. This error must be analyzed in order to ensure that the calculated time duration is valid.

## 35905280 Inputs

```
VAR_INPUT  
    Position     : LREAL;  
    ModuloFactor : LREAL;  
    Options      : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Position | LREAL | Absolute axis position |
| ModuloFactor | LREAL | Modulo divider to be used for the calculation. ModuloFactor can be identical to the modulo factor of the axis, e.g. 360. However, a factor deviating from that can also be used. |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for position extrapolation. |

## 54712068 Outputs

```
VAR_OUTPUT  
    Duration         : DINT;   
    AbsolutePosition : LREAL;   
    TimeOfPosition   : T_DCTIME32;   
    Error            : BOOL;  
    ErrorID          : UDINT;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Duration | DINT | Time duration in nanoseconds after which the position will be reached.  Duration is a differential value from two variables of the type T\_DCTIME32 Distributed Clock System Time. |
| AbsolutePosition | LREAL | Absolute position (not modulo) corresponding to the modulo position and the determined time. |
| TimeOfPosition | T\_DCTIME32 | Distributed clock system time at which the Position will be reached or was reached.  DcTime contains the lower 32 bits of the complete DcTime and covers a time range of +/- 2 seconds around the current time. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 22646572 /2492560 Inputs/outputs

```
VAR_IN_OUT  
    Axis     : AXIS_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
