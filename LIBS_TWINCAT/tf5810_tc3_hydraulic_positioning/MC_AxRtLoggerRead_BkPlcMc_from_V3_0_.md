# MC_AxRtLoggerRead_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [System](ms-xhelp:///?Id=beckhoff-cf25-4865-b897-b1877bc8684d)
4. [Message logging](ms-xhelp:///?Id=beckhoff-549e-46f1-aed9-6f287acf0910)
5. MC\_AxRtLoggerRead\_BkPlcMc (from V3.0)

# MC\_AxRtLoggerRead\_BkPlcMc (from V3.0)

![39390935](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854834443__Web.gif)

The function block reads a message from the LogBuffer of the library. Further information about creating a log buffer can be found under FAQ #10 in the [Knowledge Base](ms-xhelp:///?Id=beckhoff-873e-46cd-925a-b9a96eea638e).

|  |  |
| --- | --- |
| 18974100 | This function block is used by diagnostics tools via ADS. A direct call from the PLC application generally makes no sense. |

```
VAR_INOUT  
    Entry:      INT:=0;  
    pBuffer:    POINTER TO ST_TcPlcMcLogBuffer;  
    pEntry:     POINTER TO ST_TcPlcMcLogEntry;  
END_VAR
```

```
VAR_OUTPUT  
    Result:     DWORD:=0;  
END_VAR
```

**Entry**: The number of the message to be read.

**pBuffer**: This parameter is used to transfer the address of a variable of type [ST\_TcPlcMcLogBuffer](ms-xhelp:///?Id=beckhoff-2e65-4b91-955d-12cfc3c231b1).

**pEntry**: Here, the address of a variable of type [ST\_TcPlcMcLogEntry](ms-xhelp:///?Id=beckhoff-c2a3-4a8e-b580-6d17a51b8af8) should be transferred as target.

**Result**: Here, a coded cause of error is provided.

## Behaviour of the function block

The function block checks the transferred input values with each call. Two problems can be detected during this process:

* If **Entry** is not in the valid range (1..20), the function block returns dwTcHydAdsErrInvalidIdxOffset as **Result**.
* If **pBuffer** or **pEntry** are not defined, the function block returns dwTcHydAdsErrNotReady as **Result**.

If no problem was detected during the check, the function block copies the message selected by **Entry** from the LogBuffer **pBuffer** into the message structure addressed with **pEntry**. Entry is regarded as relative age indication: Use Entry:=1 to select the message that was entered last, with Entry:=2 the next older message, etc. If the requested message is not available, an empty message is provided.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
