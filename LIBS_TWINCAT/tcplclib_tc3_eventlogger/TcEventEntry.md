# TcEventEntry

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# TcEventEntry

Defines an event by means of event class, event ID and severity.

## Syntax

Definition:

```
TYPE TcEventEntry :   
STRUCT  
    uuidEventClass : GUID;  
    nEventId       : UDINT;  
    eSeverity      : TcEventSeverity;  
END_STRUCT  
END_TYPE
```

## Parameter

| Name | Type | Description |
| --- | --- | --- |
| uuidEventClass | GUID | GUID of the event class. |
| nEventId | UDINT | ID of the event. |
| eSeverity | TcEventSeverity | Event severity defines the severity of the event, |
