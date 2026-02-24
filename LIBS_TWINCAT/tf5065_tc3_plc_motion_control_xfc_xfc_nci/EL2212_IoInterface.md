# EL2212_IoInterface

## Library
tf5065_tc3_plc_motion_control_xfc_xfc_nci

## Category
Motion Control

# EL2212\_IoInterface

| Name | Type | Description |
| --- | --- | --- |
| Status1 | WORD | Status channel 1 |
| Status1 | WORD | Status channel 2 |
| Feedback | BYTE | Not used |
| WcState | BOOL | Not used |
| State | UINT | Not used |
| Output1 | BOOL | Signal output channel 1 |
| TriState1 | BOOL | Channel 1 |
| Reset1 | BOOL | Channel 1 |
| Output2 | BOOL | Signal output channel 2 |
| TriState2 | BOOL | Channel 2 |
| Reset2 | BOOL | Channel 2 |
| Activate | BYTE | PDO 0x1602, activates the output |
| StartTime | T\_ULARGE\_INTEGER | PDO 0x1602, activates the output |
