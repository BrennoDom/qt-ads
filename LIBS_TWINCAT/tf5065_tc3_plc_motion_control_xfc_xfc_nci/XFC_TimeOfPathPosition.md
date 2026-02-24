# XFC_TimeOfPathPosition

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TimeOfPathPosition

XFC\_TimeOfPathPosition GrpId  UINTPathPosition  LREALOptions  ST\_NcTimeConversionOptionsT\_DCTIME32  DcTimeBOOL  ErrorUDINT  ErrorID

XFC\_TimeOfPathPosition calculates the time at which an Nci group has travelled or will have travelled a preset relative path.

The function extrapolates the time in relation to the current path position and dynamics. Precise extrapolation is only possible over a short interval, since the Nci group dynamics may change.

The function block requires precisely one call in order to provide the result. It can therefore be used similar to a function, although as well as the time it may also return an error. This error must be analyzed in order to ensure that the calculated time DcTime is valid.

## 60173144 Inputs

```
VAR_INPUT  
    GrpId        : UDINT;  
    PathPosition : LREAL;  
    Options      : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| GrpId | UDINT | Group ID of the Nci group. This clearly identifies the requested Nci group in the system. |
| PathPosition | LREAL | Relative path |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for the extrapolation of the relative path. |

## 4687385 Outputs

```
VAR_OUTPUT  
    DcTime  : T_DCTIME32;   
    Error   : BOOL;  
    ErrorID : UDINT;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| DcTime | T\_DCTIME32 | Distributed clock system time at which the relative path PathPosition will have been travelled or at which this was passed.  DcTime contains the lower 32 bits of the complete DcTime and covers a time range of +/- 2 seconds around the current time. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |
