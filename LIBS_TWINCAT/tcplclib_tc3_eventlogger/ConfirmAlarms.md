# ConfirmAlarms

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ConfirmAlarms

![44718725](/tcplclib_tc3_eventlogger/1033/Images/png/10408822027__Web.png)

## 66924213 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | Set to 0 to obtain the current time automatically.  Initial: 0 |
| ipFilter | I\_TcEventFilter | Specify which alarms are to be confirmed, otherwise all alarms with the confirmation status WaitForConfirmation are confirmed. |

## 65447007 Return values

| Name | Type | Description |
| --- | --- | --- |
| ConfirmAlarms | HRESULT |  |
