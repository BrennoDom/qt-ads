# ClearAlarms

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ClearAlarms

![29574043](/tcplclib_tc3_eventlogger/1033/Images/png/10408818187__Web.png)

Method for clearing active alarms. Returns `S_OK` if successful.

## 64839795 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | Set to 0 to obtain the current time automatically. Initial: 0 |
| bResetConfirmation | BOOL | If TRUE and the confirmation status is  WaitForConfirmation, the confirmation status is set to Reset. Otherwise, the confirmation status is not changed. Initial: FALSE |
| ipFilter | I\_TcEventFilter | Specify which alarms are to be cleared, otherwise all triggered alarms are cleared. |

## 46687245 Return values

| Name | Type | Description |
| --- | --- | --- |
| ClearAlarms | HRESULT |  |
