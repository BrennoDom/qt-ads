# XFC_TimeToPathPosition

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_TimeToPathPosition

XFC\_TimeToPathPosition GrpId  UINTPathId  UDINTPathPosition  LREALOptions  ST\_NcTimeConversionOptionsDINT  DurationT\_DCTIME32  TimeOfPositionBOOL  ErrorUDINT  ErrorID

XFC\_TimeToPathPosition calculates the time period within which an Nci group has travelled a relative path or which has elapsed since then.

The function extrapolates the time in relation to the current path position and dynamics. Precise extrapolation is only possible over a short interval, since the group dynamics may change.

The function block requires precisely one call in order to provide the result. It can therefore be used similar to a function, although as well as the time it may also return an error. This error must be analyzed in order to ensure that the calculated time duration is valid.

## 42186470 Inputs

```
VAR_INPUT  
    GrpId        : UDINT;  
    PathId       : UDINT;  
    PathPosition : LREAL;  
    Options      : ST_NcTimeConversionOptions;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| GrpId | UDINT | Group ID of the Nci group. This clearly identifies the requested Nci group in the system. |
| PathId | UDINT | Unique ID that continually increases over the path course and belongs to the relative path. |
| PathPosition | LREAL | Relative path |
| Options | [ST\_NcTimeConversionOptions](ms-xhelp:///?Id=beckhoff-eb90-4afe-b70a-100cd0747937) | Data structure with options for the extrapolation of the relative path. |

## 44133910 Outputs

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
| Duration | DINT | Time period in nanoseconds after which the relative path will have been travelled (>0) or which has elapsed since then (<0).  Duration is a differential value from two variables of the type T\_DCTIME32 |
| TimeOfPosition | T\_DCTIME32 | Distributed clock system time at which the relative path distance was or will have been be travelled.  DcTime contains the lower 32 bits of the complete DcTime and covers a time range of +/- 2 seconds around the current time. |
| Error | BOOL | Becomes TRUE if an error occurs. |
| ErrorID | UDINT | If the error output is set, this parameter supplies the error number. |
