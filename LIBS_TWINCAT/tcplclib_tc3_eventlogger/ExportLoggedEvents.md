# ExportLoggedEvents

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ExportLoggedEvents

![35306501](/tcplclib_tc3_eventlogger/1033/Images/png/10408823947__Web.png)

Async exports logged events. Returns TRUE if the Async request is no longer active.

## 49323054 Inputs

| Name | Type | Description |
| --- | --- | --- |
| sFileName | STRING | Name of the target file |
| ipExportSettings | I\_TcEventExportSettings | Specify which events are to be exported, otherwise all events are exported. |

## 41254304 Return values

| Name | Type | Description |
| --- | --- | --- |
| ExportLoggedEvents | BOOL |  |
| bError | BOOL |  |
| hrErrorCode | HRESULT |  |
