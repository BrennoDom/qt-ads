# Create

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Create

![9347313](/tcplclib_tc3_eventlogger/1033/Images/png/5027117707__Web.png)

This method creates an alarm instance in the EventLogger.

## Syntax

```
METHOD Create : HRESULT  
    eventClass        : GUID;  
    nEventId          : UDINT;  
    eSeverity         : TcEventSeverity;  
    bWithConfirmation : BOOL;  
    ipSourceInfo      : I_TcSourceInfo;  
END_VAR
```

## 17016957 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID | GUID of the event class. |
| nEventId | UDINT | ID of the event. |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Severity of the event. |
| bWithConfirmation | BOOL | Defines whether the alarm requires mandatory confirmation. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Interface pointer to the source information.  Default source information is created if no interface pointer is transferred. |

## 18934887 Return value

| Name | Type | Description |
| --- | --- | --- |
| Create | HRESULT | Returns S\_OK if a new alarm was successfully created.  Returns ERROR\_ALREADY\_EXISTS if the alarm has already existed.  Otherwise returns HRESULT as the error code |
