# TcEventSeverity

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# TcEventSeverity

Defines the severity of the event.

## Syntax

Definition:

```
{attribute 'qualified_only'}  
TYPE TcEventSeverity : (  
    Verbose  := 0,   
    Info     := 1,   
    Warning  := 2,   
    Error    := 3,   
    Critical := 4);  
END_TYPE
```

## Parameter

|  | Name | Description |
| --- | --- | --- |
| 4 | Critical | Critical |
| 3 | Error | Error |
| 2 | Warning | Warning |
| 1 | Info | Information |
| 0 | Verbose | Extended output |
