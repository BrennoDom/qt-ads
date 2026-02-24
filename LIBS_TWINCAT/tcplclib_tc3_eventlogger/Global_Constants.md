# Global_Constants

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Global\_Constants

```
VAR_GLOBAL CONSTANT  
    EMPTY_EVENT_CLASS : GUID := (Data1:=16#0, Data2:=16#0, Data3:=16#0, Data4:=[16#0,16#0,16#0,16#0,16#0,16#0,16#0,16#0]);  
    EMPTY_EVENT_ID    : UDINT := 16#0;  
    EMPTY_SEVERITY    : TcEventSeverity := TcEventSeverity.Verbose;  
    SUCCESS_EVENT     : TcEventEntry := ( uuidEventClass := EMPTY_EVENT_CLASS, nEventID := EMPTY_EVENT_ID, eSeverity := EMPTY_SEVERITY );                  
END_VAR
```

| Name | Type | Initial value |
| --- | --- | --- |
| EMPTY\_EVENT\_CLASS | GUID | STRUCT(Data1:=16#0, Data2:=16#0, Data3:=16#0, Data4:=[16#0,16#0,16#0,16#0,16#0,16#0,16#0,16#0]) |
| EMPTY\_EVENT\_ID | UDINT | 16#0 |
| EMPTY\_SEVERITY | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | TcEventSeverity.Verbose |
| SUCCESS\_EVENT | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | STRUCT(uuidEventClass := EMPTY\_EVENT\_CLASS, nEventID := EMPTY\_EVENT\_ID, eSeverity := EMPTY\_SEVERITY) |
