# FB_DALIV2SendDALICommand

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [[obsolete]](ms-xhelp:///?Id=beckhoff-eb1c-4b28-ba1b-364cf88c04c2)
5. FB\_DALIV2SendDALICommand

# FB\_DALIV2SendDALICommand

![30787047](/tcplclib_tc2_dali/1033/Images/gif/9007199397820683__en-US__Web.gif)

This function block is for the general sending of a DALI command, defined by command number and, if necessary, transfer parameter. Moreover, it is possible to set whether the command is sent twice in succession and whether to wait for a response. The latter can be used, for example, to realize a fast sequence of step-up commands.

## VAR\_INPUT

```
bStart                       : BOOL;  
nAddr                        : BYTE;  
eAddrType                    : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
eCommandPriority             : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nCommand                     : INT := 0;  
nParameter                   : BYTE := 0;  
bWaitingForDALISlaveResponse : BOOL := FALSE;  
bRepeatCommand               : BOOL := FALSE;  
bSuppressResponseBuffer      : BOOL := FALSE;  
nDeviceType                  : BYTE := 0;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nCommand:** Number of the DALI command to be sent.

**nParameter:** Parameter for the value transfer.

**bWaitingForDALISlaveResponse:** If FALSE there is **no** waiting for the response of the DALI control gear. Its application makes no sense in connection with any kind of query command.

**bRepeatCommand:** Decides whether the command is to be sent twice in succession.

**bSuppressResponseBuffer:** If TRUE, the internal software buffer is **not** filled with the response from function block [FB\_DALIV2Communication()](ms-xhelp:///?Id=beckhoff-d5b3-457e-91f9-d1f3e8f70687).

**nDeviceType:** Identifier for the device type.

| Value | Description |
| --- | --- |
| 0 | Standard device |
| 1 | Device for emergency lighting. |
| 2 | Device for discharge lamps. |
| 3 | Device for low-voltage halogen lamps. |
| 4 | Device for dimming incandescent lamps. |
| 5 | Device for converting digital signals into DC signals. |
| 6 | Device for light emitting diodes (LEDs). |

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
nErrorId      : UDINT;  
nResponseData : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nResponseData:** The value received from the DALI control gear, if a query command has been called.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DALIV2CommandBuffer;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
