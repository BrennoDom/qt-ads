# SetLimit

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# SetLimit

![14093819](/tcplclib_tc3_eventlogger/1033/Images/png/10362543115__Web.png)

Indicates the number of events to be cleared. The limit is applied after sorting and filtering.

## 59735509 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eType | TcEventLimitType | Determines the reference whether the limit applies to the first or last events. |
| nLimit | DINT | Specifies the number  (-1 = no limit) |
| nOffset | DINT | Optional. Defines how many entries are to be skipped. |

## 748676 Return values

| Name | Type | Description |
| --- | --- | --- |
| SetLimit | HRESULT | Returns `S_OK` if successful. |
