# ST_TcPlcMcLogEntry (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcMcLogEntry (from V3.0)

# ST\_TcPlcMcLogEntry (from V3.0)

A variable with this structure contains a message of the LogBuffer of the library. Used as a component in [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1). Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

|  |  |
| --- | --- |
| 39434429 | The data in this structure must not be modified by the application. |

```
TYPE ST_TcPlcMcLogEntry:  
STRUCT  
    TimeLow:    UDINT:=0;  
    TimeHigh:   UDINT:=0;  
    LogLevel:   DWORD:=0;  
    Source:     DWORD:=0;  
    Msg:        STRING(255);  
    ArgType:    INT:=0;  
    diArg:      DINT:=0;  
    lrArg:      LREAL:=0;  
    sArg:       STRING(255);  
END_STRUCT  
END_TYPE
```

**TimeLow**, **TimeHigh**: The timestamp of the message. Records the time at which the message was generated.

**LogLevel**: Indicates the urgency of the message. Only values from a specified [pool of numbers](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) should appear here.

**Source**: Indicates the source of the message. Only values from a specified [pool of numbers](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) should appear here.

**Msg**: The message text with an optional placeholder for a variable component.

**ArgType**: The type of the optional component.

**diArg**: If an optional component of type DINT is used, its value can be found here.

**lrArg**: If an optional component of type LREAL is used, its value can be found here.

**sArg**: If an optional component of type STRING is used, its value can be found here.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
