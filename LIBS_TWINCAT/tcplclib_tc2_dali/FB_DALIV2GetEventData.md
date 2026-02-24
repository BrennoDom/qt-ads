# FB_DALIV2GetEventData

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_DALIV2GetEventData

# FB\_DALIV2GetEventData

![13780214](/tcplclib_tc2_dali/1033/Images/gif/4345397643__Web.gif)

Filters out an event specified by the event scheme.

Each event sent by a DALI device contains two fields that provide information about the event source. These two fields are a combination of the short address, instance number, instance type, instance group or device group. The recipient of the event must know which address scheme is used to send the data.

For each event that is to be received and processed further, an instance of FB\_DALIV2GetEventData() must be created and configured with the correct event scheme.

## VAR\_INPUT

```
bEnable          : BOOL;  
eEventScheme     : E_DALIV2EventScheme := eDALIV2EventSchemeDeviceInstance;  
nAddressInfo01   : BYTE;  
nAddressInfo02   : BYTE;
```

**bEnable**: Enables the function block. If this input is set to FALSE, no further events are output.

**eEventScheme**: The event scheme defines the address information required for filtering the desired result.

**nAddressInfo01**: (see table below)

**nAddressInfo02**: (see table below)

| eEventScheme | nAddressInfo01 | nAddressInfo02 |
| --- | --- | --- |
| eDALIV2EventSchemeInstance | Instance type (0-31) | Instance number (0-31) |
| eDALIV2EventSchemeDevice | Short address (0-63) | Instance type (0-31) |
| eDALIV2EventSchemeDeviceInstance | Short address (0-63) | Instance number (0-31) |
| eDALIV2EventSchemeDeviceGroup | Device group (0-31) | Instance type (0-31) |
| eDALIV2EventSchemeInstanceGroup | Instance group  (0-31) | Instance type (0-31) |

## VAR\_OUTPUT

```
bNewData          : BOOL;  
nEventInfo        : WORD;
```

**bNewData:** If an event was received that corresponds to the event scheme and address information, this output is set to TRUE for one PLC cycle.

**nEventInfo**: If the output *bNewData* is TRUE, further information about the event can be found at this output. The exact meaning depends on the device type and is described in the respective Part 3xx of IEC 62386.

## VAR\_IN\_OUT

```
stCommandBuffer   : ST_DALIV2CommandBuffer;
```

**stCommandBuffer**: Reference to the internal structure for communication with the function block [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
