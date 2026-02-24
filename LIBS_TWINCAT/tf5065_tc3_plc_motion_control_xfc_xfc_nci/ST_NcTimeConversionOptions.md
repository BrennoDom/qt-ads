# ST_NcTimeConversionOptions

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# ST\_NcTimeConversionOptions

```
TYPE ST_NcTimeConversionOptions :  
STRUCT  
    SubIndex :             UINT;  
    InterpolationOptions : UINT;  
    CompensationTime :     DINT;  
END_STRUCT  
END_TYPE
```

| Name | Type | Description |
| --- | --- | --- |
| SubIndex | UINT | For axes with more than one encoder the index (0..9) of the encoder to which the position refers can be specified in SubIndex.  No subindex can be specified for Path function blocks that refer to multiple interpolated axes. |
| InterpolationOptions | UINT | Bit mask for special options:  InterpolationOptions.0 = FALSE: The position extrapolation is carried out with the current velocity, without taking into account the current acceleration.  InterpolationOptions.0 = TRUE: The axis acceleration is included in the position extrapolation.  InterpolationOptions.12 = TRUE: The position buffer is ignored.  InterpolationOptions.15 = TRUE: a logger message is forced. |
| CompensationTime | DINT | Additional compensation time |
