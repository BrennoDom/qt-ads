# MC_AxRtLogEntry_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Message logging](ms-xhelp:///?Id=beckhoff-549e-46f1-aed9-6f287acf0910)
5. MC\_AxRtLogEntry\_BkPlcMc (from V3.0)

# MC\_AxRtLogEntry\_BkPlcMc (from V3.0)

![43412436](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854829579__Web.gif)

The function block enters a message in the LogBuffer of the library. Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

```
VAR_INPUT  
    pBuffer:        POINTER TO ST_TcPlcMcLogBuffer;  
    LogLevel:       DWORD:=0;  
    Source:         DWORD:=0;  
    Message:        STRING(255);  
    ArgType:        INT:=0;  
    diArg:          DINT:=0;  
    lrArg:          LREAL:=0;  
    sArg:           STRING(255);  
END_VAR
```

**pBuffer**: This parameter is used to transfer the address of a variable of type [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1).

**LogLevel**: A coded specification of the message type. A [Logger Levels](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) value from the [Global Constants](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) should be used.

**Source**: A coded specification of the message source. A [logger sources](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) value from the [Global Constants](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) should be used.

**Message**: The message text.

**ArgType**: The type of the optional argument.

**diArg**: The value of the optional argument, if it is of type DINT.

**lrArg**: The value of the optional argument, if it is of type LREAL.

**sArg**: The value of the optional argument, if it is of type STRING.

## Behavior of the function block

If **pBuffer** was supplied correctly and points to an [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1), which has capacity for at least one further message, the transferred message data are complemented with local time information and entered in the message buffer.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
