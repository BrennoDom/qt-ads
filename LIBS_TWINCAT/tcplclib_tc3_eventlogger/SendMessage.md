# SendMessage

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# SendMessage

![13669843](/tcplclib_tc3_eventlogger/1033/Images/png/5027225227__Web.png)

This method sends a message.

## Syntax

```
METHOD SendMessage : HRESULT  
VAR_INPUT  
    eventClass    : GUID;  
    nEventId      : UDINT;  
    eSeverity     : TcEventSeverity;   
    ipSourceInfo  : I_TcSourceInfo := 0;   
    nTimeStamp    : ULINT := 0;  
    ipArguments   : I_TcArguments := 0;  
END_VAR
```

## 55919726 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID | GUID of the event class. |
| nEventId | UDINT | ID of the event. |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Severity of the event. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |
| nTimeStamp | ULINT | 0: Current time stamp is used.  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |
| ipArguments | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Pointer to the ITcArguments interface. |

## 33515489 Return value

| Name | Type | Description |
| --- | --- | --- |
| SendMessage | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
