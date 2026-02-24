# GetAlarm

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# GetAlarm

![35744420](/tcplclib_tc3_eventlogger/1033/Images/png/5027158027__Web.png)

Returns an interface pointer to an existing instance.

## Syntax

```
METHOD GetAlarm : HRESULT  
VAR_INPUT  
    eventClass   : GUID;  
    nEventId     : UDINT;  
    ipSourceInfo : I_TcSourceInfo := 0;  
    fbAlarm      : REFERENCE TO FB_TcAlarm;  
END_VAR
```

## 53264332 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID | GUID of the event class. |
| nEventId | UDINT | ID of the event |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |
| fbAlarm | REFERENCE TO [FB\_TcAlarm](ms-xhelp:///?Id=beckhoff-6b09-4b64-be2e-d6258f05d173) | Pointer to an alarm. |

## 9616944 Return value

| Name | Type | Description |
| --- | --- | --- |
| GetAlarm | HRESULT | Returns ADS\_E\_NOTFOUND if no instance was found.  Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
