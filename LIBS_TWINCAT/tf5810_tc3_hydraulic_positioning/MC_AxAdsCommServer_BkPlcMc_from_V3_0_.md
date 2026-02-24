# MC_AxAdsCommServer_BkPlcMc (from V3.0)

## Library
tf5810_tc3_hydraulic_positioning

## Category
Motion Control

1. [TwinCAT PLC Hydraulics](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
2. [PLCopen Motion Control](ms-xhelp:///?Id=beckhoff-1ded-451e-88ec-a82873484e92)
3. [Parameter](ms-xhelp:///?Id=beckhoff-b417-4e0c-b473-d1906e164f8c)
4. MC\_AxAdsCommServer\_BkPlcMc (from V3.0)

# MC\_AxAdsCommServer\_BkPlcMc (from V3.0)

![14981763](/tf5810_tc3_hydraulic_positioning/1033/Images/gif/9007200854858763__Web.gif)

The function block gives the application the capacity to function as an ADS server. Calls function blocks of type [MC\_AxAdsReadDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-481a-4a03-8125-5c248c8f87e9) and [MC\_AxAdsWriteDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2966-42df-8743-cf2a33ec4367) as required. The [ADS codes](ms-xhelp:///?Id=beckhoff-d319-45ac-96c4-54e861345d4c) are listed in the Knowledge Base.

```
VAR_INPUT  
    nFirstAxisIndex:    INT;  
    nLastAxisIndex:     INT;  
END_VAR
```

```
VAR_INOUT  
    pAxItf:             POINTER TO Axis_Ref_BkPlcMc;  
END_VAR
```

```
VAR_OUTPUT  
    PlcMcManOffline:    BOOL;  
END_VAR
```

**nFirstAxisIndex**, **nLastAxisIndex**: This parameter is used to specify the dimensioning of the [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) array.

Note

**Crash of the PLC application**

An incorrect specification at this point excludes some of the axes from the communication or results in a **crash of the PLC application** by triggering serious runtime errors (**Page Fault Exception**)

**pAxItf**: Here, the address of a variable or an array of variables of type [Axis\_Ref\_BkPlcMc](ms-xhelp:///?Id=beckhoff-002b-4aba-81ea-1693fb03013c) should be transferred.

## Behavior of the function block

Through cyclic calling of this function block in the PLC application, the application assumes the character of an ADS server and responds to ADS read and ADS write-access like any other ADS server. This includes the decoding of IdxGroup/IdxOffset addressing. Function blocks of type [MC\_AxAdsReadDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-481a-4a03-8125-5c248c8f87e9) and [MC\_AxAdsWriteDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2966-42df-8743-cf2a33ec4367) are called as required.

|  |  |
| --- | --- |
| 618145 | This function block must not be used if the PLC application already is an ADS server. |

In this case the function blocks of type [MC\_AxAdsReadDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-481a-4a03-8125-5c248c8f87e9) and [MC\_AxAdsWriteDecoder\_BkPlcMc](ms-xhelp:///?Id=beckhoff-2966-42df-8743-cf2a33ec4367) should be called from the existing ADS server function block of the application.

[TF5810 | TwinCAT 3 Hydraulic Positioning](ms-xhelp:///?Id=beckhoff-18ff-48cf-8a46-004002f87446)
