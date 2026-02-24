# XFC_ExtendDcTime

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_ExtendDcTime

![2537905](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/png/9832074635__Web.png)

The function XFC\_ExtendDcTime extends a 32-bit time stamp to 64 bit.

A prerequisite for the extension to a complete time stamp is that the 32-bit time stamp is valid for the current time range. It is not possible to guarantee error-free extension of a time stamp that applies more than approx. +/- 2 seconds before or after the current time.

## 22841149 Inputs

```
VAR_INPUT  
    TimeStamp32 : T_DCTIME32;  
END_VAR
```

| Name | Type | Description |
| --- | --- | --- |
| TimeStamp32 | T\_DCTIME32 | Distributed Clock System Time.  Contains the lower 32 bits of the complete DcTime, thus covering a time range of +/- 2 seconds around the current time. |

## Return value

```
FUNCTION XFCF_ExtendDcTime : T_DCTIME
```

| Name | Type | Description |
| --- | --- | --- |
| XFCF\_ExtendDcTime | T\_DCTIME | Return value of the function. Complete 64-bit distributed clock system time. |
