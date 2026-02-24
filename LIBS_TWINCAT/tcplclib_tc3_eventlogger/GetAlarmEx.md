# GetAlarmEx

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# GetAlarmEx

![19443632](/tcplclib_tc3_eventlogger/1033/Images/png/5027159947__Web.png)

Returns an interface pointer to an existing instance.

## Syntax

```
METHOD GetAlarmEx : HRESULT  
VAR_INPUT  
    stEventEntry : TcEventEntry;   
    ipSourceInfo : I_TcSourceInfo := 0; // optional  
    fbAlarm      : REFERENCE TO FB_TcAlarm;  
END_VAR
```

## 40774967 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event definition. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |
| fbAlarm | REFERENCE TO [FB\_TcAlarm](ms-xhelp:///?Id=beckhoff-6b09-4b64-be2e-d6258f05d173) | Pointer to an alarm. |

## 31430389 Return value

| Name | Type | Description |
| --- | --- | --- |
| GetAlarmEx | HRESULT | Returns ADS\_E\_NOTFOUND if no instance was found.  Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
