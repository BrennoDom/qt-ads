# IsAlarmRaisedEx

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# IsAlarmRaisedEx

![56357057](/tcplclib_tc3_eventlogger/1033/Images/png/5027186827__Web.png)

This method queries whether an alarm is in the Raised state.

## Syntax

```
METHOD IsAlarmRaisedEx : BOOL  
VAR_INPUT  
    stEventEntry : TcEventEntry;   
    ipSourceInfo : I_TcSourceInfo := 0;  
END_VAR
```

## 37451465 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | UDINT | Event definition. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |

## 1518871 Return value

| Name | Type | Description |
| --- | --- | --- |
| IsAlarmRaisedEx | BOOL | Returns TRUE if the alarm is in the raised state. |
