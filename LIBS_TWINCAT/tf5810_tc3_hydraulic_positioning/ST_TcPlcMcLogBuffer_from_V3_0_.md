# ST_TcPlcMcLogBuffer (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Data types](ms-xhelp:///?Id=beckhoff-25bd-4475-8df7-6d29ea7ab5ff)
4. ST\_TcPlcMcLogBuffer (from V3.0)

# ST\_TcPlcMcLogBuffer (from V3.0)

A variable with this structure forms the LogBuffer of the library. Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

|  |  |
| --- | --- |
| 56577386 | The data in this structure must not be modified by the application. |

```
TYPE ST_TcMcLogBuffer:  
STRUCT  
    ReadIdx:        INT:=0;  
    WriteIdx:       INT:=0;  
    MessageArr:     ARRAY [0..19] OF ST_TcPlcMcLogEntry;  
END_STRUCT  
END_TYPE
```

[ST\_TcPlcMcLogEntry](ms-xhelp:///?Id=beckhoff-c2a3-4a8e-b580-6d17a51b8af8)

**ReadIdx**: The read index of the buffer.

**WriteIdx**: The write index of the buffer.

**MessageArr**: The currently stored messages.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
