# SendMessage2

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# SendMessage2

![33203949](/tcplclib_tc3_eventlogger/1033/Images/png/10408825867__Web.png)

## 30400092 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID |  |
| nEventId | UDINT |  |
| eSeverity | TcEventSeverity |  |
| ipSourceInfo | I\_TcSourceInfo | Optional  Initial: 0 |
| nTimeStamp | ULINT | Set 0 to obtain the time automatically.  Initial: 0 |
| ipArguments | I\_TcArguments | Optional  Initial: 0 |
| sJsonAttribute | STRING |  |

## 5165373 Return values

| Name | Type | Description |
| --- | --- | --- |
| SendMessage2 | HRESULT |  |
