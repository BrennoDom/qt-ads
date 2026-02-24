# XFC_PositionAtTime

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_PositionAtTime

XFC\_PositionAtTime DcTime  T\_DCTIME32Options  ST\_NcTimeConversionOptions↔Axis  Reference To AXIS\_REFLREAL  PositionBOOL  ErrorUDINT  ErrorID

XFC\_PositionAtTime calculates an axis position, which will be or was valid at a given time.

The function extrapolates the position in relation to the current position and dynamics. Precise extrapolation is only possible over a short interval, since the axis dynamics may change.

The function block requires precisely one call in order to provide the result. It can therefore be used similar to a function, although as well as the position it may also return an error. This error must be analyzed in order to ensure that the calculated position is valid.

## 46045275 Inputs

```
VAR_INPUT  
    DcTime  : T_DCTIME32;   
    Options : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| DcTime | T\_DCTIME32 | Distributed Clock System Time.  Contains the lower 32 bits of the complete DcTime, thus covering a time range of +/- 2 seconds around the current time. In order to optimize the calculation of the position value, the time should be close to the current time, i.e. only a few PLC or NC cycles in the future or the past. |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for position extrapolation. |

## 11754296 Outputs

```
VAR_OUTPUT  
    Position : LREAL;  
    Error    : BOOL;  
    ErrorID  : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Position | LREAL | Extrapolated position that will be or was reached at the specified time DcTime. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |

## 38679804/12573920 Inputs/outputs

```
VAR_IN_OUT  
    Axis     : AXIS_REF;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| Axis | [AXIS\_REF](ms-xhelp:///?Id=beckhoff-7cdc-4b2f-b455-b38811ddad01) | The axis data structure of type AXIS\_REF addresses an axis unambiguously within the system. Among other parameters it contains the current axis status, including position, velocity or error state. |
