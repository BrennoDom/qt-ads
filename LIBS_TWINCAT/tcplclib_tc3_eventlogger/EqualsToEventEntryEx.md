# EqualsToEventEntryEx

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# EqualsToEventEntryEx

![65588106](/tcplclib_tc3_eventlogger/1033/Images/png/5027133067__Web.png)

This method carries out a comparison with another event specified at the input.

## Syntax

```
METHOD EqualsToEventEntryEx : BOOL  
VAR_INPUT  
    stOther : TcEventEntry;  
END_VAR
```

## 53422044 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stOther | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event to be compared. |

## 11036355 Return value

| Name | Type | Description |
| --- | --- | --- |
| EqualsToEventEntryEx | BOOL | Returns TRUE if the events match. |
