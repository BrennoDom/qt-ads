# EqualsToEventEntry

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# EqualsToEventEntry

![37903130](/tcplclib_tc3_eventlogger/1033/Images/png/5027131147__Web.png)

This method carries out a comparison with another event specified at the input.

## Syntax

```
METHOD EqualsToEventEntry : BOOL  
VAR_INPUT  
    OtherEventClass : GUID;  
    nOtherEventID   : UDINT;  
    eOtherSeverity  : TcEventSeverity;  
END_VAR
```

## 5583857 Inputs

| Name | Type | Description |
| --- | --- | --- |
| OtherEventClass | GUID | Event class of the event to be compared. |
| nOtherEventID | UDINT | Event ID of the event to be compared. |
| eOtherSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Event severity of the event to be compared. |

## 50254714 Return value

| Name | Type | Description |
| --- | --- | --- |
| EqualsToEventEntry | BOOL | Returns TRUE if the events match. |
