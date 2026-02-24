# ST_EL2262_Diagnostics

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# ST\_EL2262\_Diagnostics

The data type ST\_EL2262\_Diagnostics contains diagnostic data that can be used for error analysis.

```
TYPE ST_EL2262_Diagnostics :   
STRUCT   
    ErrorOnOutputMissed     : BOOL;  
    ErrorOffOutputMissed    : BOOL;  
    OnPrecisionReduced      : BOOL;  
    OffPrecisionReduced     : BOOL;  
    LastOutputLevel         : BOOL;  
    ActivatedOnValues       : INT;  
    ActivatedOffValues      : INT;  
END_STRUCT   
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| ErrorOnOutputMissed | BOOL | Indicates that a rising switching edge could not be determined to an exact cycle and therefore could not be output. The ForceWhenLate input can be set in order to output the switching edge as well as possible. |
| ErrorOffOutputMissed | BOOL | Indicates that a falling switching edge could not be determined to an exact cycle and therefore could not be output. The ForceWhenLate input can be set in order to output the switching edge as well as possible. |
| OnPrecisionReduced | BOOL | Indicates that a rising switching edge could not be determined to an exact cycle. However, the switching edge was output as well as possible. |
| OffPrecisionReduced | BOOL | Indicates that a falling switching edge could not be determined to an exact cycle. However, the switching edge was output as well as possible. |
| LastOutputLevel | BOOL | Indicates which signal state the channel of the EL2262 will have after the following update. |
| ActivatedOnValues | INT | Number of rising edges activated in this cycle |
| ActivatedOffValues | INT | Number of falling edges activated in this cycle |
