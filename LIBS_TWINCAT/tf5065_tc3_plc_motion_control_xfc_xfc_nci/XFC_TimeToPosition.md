# XFC_TimeToPosition

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TimeToPosition

XFC\_TimeToPosition Position  LREALOptions  ST\_NcTimeConversionOptions↔Axis  Reference To AXIS\_REFDINT  DurationT\_DCTIME32  TimeOfPositionBOOL  ErrorUDINT  ErrorID

XFC\_TimeToPosition calculates the time period within which an axis will reach a position, or the time that has elapsed since the axis passed this position.

The function block extrapolates the time in relation to the current position and dynamics. Precise extrapolation is only possible over a short interval, since the axis dynamics may change.

It needs exactly one call to provide the result. It can therefore be used similar to a function, although as well as the time it may also return an error. This error must be analyzed in order to ensure that the calculated time duration is valid.

## 52078514 Inputs

```
VAR_INPUT  
    Position    : LREAL;  
    Options     : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Position | LREAL | Absolute axis position |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for position extrapolation. |

## 66053444 Outputs

```
VAR_OUTPUT  
    Duration       : DINT;   
    TimeOfPosition : T_DCTIME32;   
    Error          : BOOL;  
    ErrorID        : UDINT;   
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Duration | DINT | Time duration in nanoseconds after which the position will be reached (> 0) or since the position was passed (< 0).  Duration is a differential value from two variables of the type T\_DCTIME32 Distributed Clock System Time. |
| TimeOfPosition | T\_DCTIME32 | Distributed clock system time at which the position will be reached or was reached.  DcTime contains the lower 32 bits of the complete DcTime and covers a time range of +/- 2 seconds around the current time. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 57610085/48728718 Inputs/outputs

```
VAR_IN_OUT  
    Axis     : AXIS_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
