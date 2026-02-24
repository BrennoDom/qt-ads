# XFC_PathPositionAtTime

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_PathPositionAtTime

XFC\_PathPositionAtTime GrpId  UINTDcTime  T\_DCTIME32Options  ST\_NcTimeConversionOptionsLREAL  PathPositionBOOL  ErrorUDINT  ErrorID

XFC\_PathPositionAtTime calculates a relative path distance at a given time in relation to the current path position.

The function extrapolates the path distance in relation to the current dynamics. Precise extrapolation is only possible over a short interval, since the group dynamics may change.

The function block requires precisely one call in order to provide the result. Therefore it can be used in a similar way to a function, but may return an error in addition to the relative path distance. This error must be evaluated to ensure that the calculated path distance is valid.

## 8199418 Inputs

```
VAR_INPUT  
    GrpId   : UDINT;  
    DcTime  : T_DCTIME32;   
    Options : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| GrpId | UDINT | Group ID of the Nci group. This clearly identifies the requested Nci group in the system. |
| DcTime | T\_DCTIME32 | Distributed Clock System Time.  DcTime contains the lower 32 bits of the complete DcTime and covers a time range of +/- 2 seconds around the current time. In order to optimize the calculation of the path value, the time should be close to the current time, i.e. only a few PLC or NC cycles in the future or the past. |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for the extrapolation of the relative path. |

## 6685904 Outputs

```
VAR_OUTPUT  
    PathPosition : LREAL;  
    Error        : BOOL;  
    ErrorID      : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| PathPosition | LREAL | Extrapolated relative path up to the preset time DcTime. |
| Error | BOOL | Becomes TRUE if an error occurs |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |
