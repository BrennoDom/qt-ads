# EqualsToEventClass

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# EqualsToEventClass

![52155720](/tcplclib_tc3_eventlogger/1033/Images/png/5027129227__Web.png)

This method carries out a comparison with another event class specified at the input.

## Syntax

```
METHOD EqualsToEventClass : BOOL  
VAR_INPUT  
    OtherEventClass : GUID  
END_VAR
```

## 66748299 Inputs

| Name | Type | Description |
| --- | --- | --- |
| OtherEventClass | GUID | Event class to be compared. |

## 63863782 Return value

| Name | Type | Description |
| --- | --- | --- |
| EqualsToEventClass | BOOL | Returns TRUE if the event classes match. |
