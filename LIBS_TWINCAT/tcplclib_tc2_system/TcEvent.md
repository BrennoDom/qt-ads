# TcEvent

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. TcEvent

# TcEvent

```
TYPE TcEvent   
STRUCT  
    Class                : UDINT;  
    Prio                 : UDINT;  
    Id                   : UDINT;  
    bQuitRequired        : BOOL;  
    DataFormatStrAddress : PVOID;  
    UserFlags            : DWORD;  
    Flags                : DWORD;  
    StreamType           : UDINT;  
    SourceString         : STRING[15]; (* TCEVENT_SRCNAMESIZE *)  
    SourceId             : UDINT;  
    ProgId               : STRING[31]; (* TCEVENT_FMTPRGSIZE *)  
END_STRUCT  
END_TYPE
```

**Class**: Event class, take value from the enum [E\_TcEventClass](ms-xhelp:///?Id=beckhoff-867d-4a00-a58e-364a76cd468b)

**Prio**: Priority of the event inside a class, free selectable count (1..MaxUDINT)

**Id**: Id of the events, is used for explicit identification in the Eventlogger

**bQuitRequired**: Edges for switch on and off the acknowledgement obligatory (TRUE → acknowledgement obligatory)

**DataFormatStrAddress**: Address of a strings. String contains formatting instructions (e.g. %d%f formates an Integer and a Real (float) value)

**UserFlags**: 32 bit count is free available

**Flags**: 32 bit count for identification of the event. The meaning of the single bits is declared in the [global Variables](ms-xhelp:///?Id=beckhoff-c946-481f-b039-a29293e727aa) of the libraries

**StreamType**: Type of events. Take the value from the enum [E\_TcEventStreamType](ms-xhelp:///?Id=beckhoff-fe08-4002-8967-f450ba20cbb8)

**SourceString**: String with the source name ([max. 15 strings](ms-xhelp:///?Id=beckhoff-c946-481f-b039-a29293e727aa))

**SourceId**: Source-ID

**ProgId**: String (Prog-Id) with the name of the formatter ([max. 31 strings](ms-xhelp:///?Id=beckhoff-c946-481f-b039-a29293e727aa))

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
