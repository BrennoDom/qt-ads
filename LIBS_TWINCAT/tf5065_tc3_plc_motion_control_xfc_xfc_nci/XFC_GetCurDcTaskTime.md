# XFC_GetCurDcTaskTime

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# XFC\_GetCurDcTaskTime

![7738529](/tf5065_tc3_plc_motion_control_xfc_xfc_nci/1033/Images/png/9832076555__Web.png)

The function XFC\_GetCurDcTaskTime determines the start time of the current PLC cycle.

The function optimizes the calls of the system function F\_GetCurDcTaskTime by answering several queries within a PLC task cycle with the same time, without calling the system function repeatedly.

## Return value

```
FUNCTION XFCF_GetCurDcTaskTime : T_DCTIME 
```

| Name | Type | Description |
| --- | --- | --- |
| XFCF\_GetCurDcTaskTime | T\_DCTIME | Return value of the function.  Complete 64-bit distributed clock system time. Start time of the current PLC cycle (cycle of the task that calls this function.) |
