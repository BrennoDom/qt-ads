# E_TcEventStreamType

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_TcEventStreamType

# E\_TcEventStreamType

```
TYPE E_TcEventStreamType :  
(  
    TCEVENTSTREAM_INVALID       := 0, (* no source name, no prog id *)  
    TCEVENTSTREAM_SIMPLE,             (* no source name, no prog id *)  
    TCEVENTSTREAM_NORMAL,             (* source name AND prog id *)  
    TCEVENTSTREAM_NOSOURCE,           (* no source name, but prog id *)  
    TCEVENTSTREAM_CLASSID,            (* source name AND class id *)  
    TCEVENTSTREAM_CLSNOSRC,           (* no source name but class id *)  
    TCEVENTSTREAM_READCLASSCOUNT,     (* *)  
    TCEVENTSTREAM_MAXTYPE             (* no source name but class id *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
