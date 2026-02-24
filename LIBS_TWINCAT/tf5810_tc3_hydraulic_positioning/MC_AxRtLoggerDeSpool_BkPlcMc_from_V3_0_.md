# MC_AxRtLoggerDeSpool_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Message logging](ms-xhelp:///?Id=beckhoff-549e-46f1-aed9-6f287acf0910)
5. MC\_AxRtLoggerDeSpool\_BkPlcMc (from V3.0)

# MC\_AxRtLoggerDeSpool\_BkPlcMc (from V3.0)

![55167604](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854832011__Web.gif)

The function block prevents overflowing of the LogBuffer of the library. Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

```
VAR_INPUT  
    Spare:      INT;  
END_VAR
```

```
VAR_INOUT  
    pBuffer:    POINTER TO ST_TcPlcMcLogBuffer;  
END_VAR
```

**Spare**: The required number of free messages in the LogBuffer.

**pBuffer**: This parameter is used to transfer the address of a variable of type [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1).

## Behaviour of the function block

With each call the function block removes a message from the LogBuffer, if the number of free messages is smaller than the minimum number transferred in **Spare**. An [MC\_AxRtLoggerSpool\_BkPlcMc](ms-xhelp:///?Id=beckhoff-54e4-42b0-8b15-e29767b6b2eb) function block should be used to include the whole history in the Windows Event Viewer.

|  |  |
| --- | --- |
| 26746391 | Using this function block makes sense whenever a write-restricted mass storage medium is used (typically a FLASH DISK). As a minimum, a limited history of 10 to 15 messages is enabled. |

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
