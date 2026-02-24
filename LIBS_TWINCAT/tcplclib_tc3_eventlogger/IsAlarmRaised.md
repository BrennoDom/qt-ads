# IsAlarmRaised

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# IsAlarmRaised

![14438051](/tcplclib_tc3_eventlogger/1033/Images/png/5027184907__Web.png)

This method queries whether an alarm is in the Raised state.

## Syntax

```
METHOD IsAlarmRaised : BOOL  
VAR_INPUT  
    eventClass   : GUID;  
    nEventId     : UDINT;  
    ipSourceInfo : I_TcSourceInfo := 0;  
END_VAR
```

## 62833603 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID | GUID of the event class. |
| nEventId | UDINT | ID of the event. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |

## 28631516 Return value

| Name | Type | Description |
| --- | --- | --- |
| IsAlarmRaised | BOOL | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
