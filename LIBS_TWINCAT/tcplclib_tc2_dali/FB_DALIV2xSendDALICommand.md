# FB_DALIV2xSendDALICommand

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Base](ms-xhelp:///?Id=beckhoff-48f6-479b-b1fc-0ba402ee9f92)
6. FB\_DALIV2xSendDALICommand

# FB\_DALIV2xSendDALICommand

![56913064](/tcplclib_tc2_dali/1033/Images/gif/4415377931__Web.gif)

This function block is for the general sending of a DALI command, defined by command number and, if necessary, transfer parameter. Moreover, it is possible to set whether the command is sent twice in succession and whether to wait for a response. The latter can be used, for example, to realize a fast sequence of step-up commands.

Unlike the function block [FB\_DALIV2SendDALICommand()](ms-xhelp:///?Id=beckhoff-8c67-439e-a8bb-1a1e14531539), this function block is also able to control DALI control units (sensors).

## VAR\_INPUT

```
bStart                       : BOOL;  
nAddr                        : BYTE;  
eAddrType                    : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nInstAddr                    : BYTE := 0;  
eInstAddrType                : E_DALIV2InstAddrType := eDALIV2InstAddrTypeNumber;  
eCommandPriority             : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nCommand                     : INT := 0;  
nParameter01                 : BYTE := 0;  
nParameter02                 : DINT := 0;  
bWaitingForDALISlaveResponse : BOOL := FALSE;  
bRepeatCommand               : BOOL := FALSE;  
bSuppressResponseBuffer      : BOOL := FALSE;  
nDeviceType                  : BYTE := 0;  
nOptions                     : DWORD := 0;  
eDataFrameType               : E_DALIV2DataFrameType := eDALIV2DataFrameType16Bit;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr**: The address of a participating device or of a group.

**eAddrType**: Short address, group address or broadcast.

**nInstAddr**: Address of the instance within the device.

**eInstAddrType**: Defines the meaning of the variable *nInstAddr* for addressing the instance (e.g. by instance number, instance type,...)

**eCommandPriority**: Priority (high, medium or low) with which the command is processed by the library.

**nCommand**: Number of the DALI command to be sent.

**nParameter01**: Parameter for the value transfer.

**nParameter02**: Parameter for the value transfer.

**bWaitingForDALISlaveResponse:** If FALSE, the system does not wait for the answer from the DALI device. Its application makes no sense in connection with any kind of query command.

**bRepeatCommand:** Decides whether the command is to be sent twice in succession.

**bSuppressResponseBuffer:** If TRUE, the internal buffer is not filled with the response from the function block [FB\_KL6811Communication](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

**nDeviceType**: Identifier for the device type.

| Value | Description |
| --- | --- |
| 0 | Standard device |
| 1 | Device for [emergency lighting](ms-xhelp:///?Id=beckhoff-d13a-4887-aecd-3e1c1e84a57b) |
| 2 | Device for [discharge lamps](ms-xhelp:///?Id=beckhoff-66ac-4597-b9c5-1741053775fa) |
| 3 | Device for low-voltage halogen lamps |
| 4 | Device for dimming incandescent lamps |
| 5 | Device for converting digital signals into DC signals |
| 6 | Device for [light emitting diodes (LEDs)](ms-xhelp:///?Id=beckhoff-5f60-42ba-bae7-3c7ad0e76f35) |
| 7 | Device for switching functions |
| 8 | Device for [controlling the color/color temperature](ms-xhelp:///?Id=beckhoff-a837-4797-bf19-33a8438d83d2) |
| 9 | Sequencer |

**nOptions**: reserved for future expansions.

**eDataFrameType**: Output format of the DALI command (*eDALIV2DataFrameType24Bit*, *eDALIV2DataFrameType16Bit* or *eDALIV2DataFrameTypeOsram*).

## VAR\_OUTPUT

```
bBusy                        : BOOL;  
bError                       : BOOL;  
nErrorId                     : UDINT;  
arrResponseData              : ARRAY [0..3] OF BYTE;
```

**bBusy**: When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId**: Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**arrResponseData:** The value received from the DALI device if a query command was invoked.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DALIV2CommandBuffer;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4022.4 | Tc2\_DALI from v3.6.2.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
