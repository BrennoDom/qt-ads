# MC_AxRtLoggerSpool_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Message logging](ms-xhelp:///?Id=beckhoff-549e-46f1-aed9-6f287acf0910)
5. MC\_AxRtLoggerSpool\_BkPlcMc (from V3.0)

# MC\_AxRtLoggerSpool\_BkPlcMc (from V3.0)

![36549175](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854836875__Web.gif)

The function block deals with transferring messages from the LogBuffer of the library into the Windows Event Viewer. Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

```
VAR_INOUT  
    pBuffer:        POINTER TO ST_TcPlcMcLogBuffer;  
END_VAR
```

**pBuffer**: This parameter is used to transfer the address of a variable of type [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1).

## Behaviour of the function block

With each call the function block removes a message from the LogBuffer and transfers it to the Windows Event Viewer.

If the computer uses a write-restricted mass storage medium (typically FLASH DISK), it makes no sense to use the Windows Event Viewer. An [MC\_AxRtLoggerDespool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-4c01-4158-8f0c-ab6270fd0cfd) function block can be used to generate a history in any case.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
