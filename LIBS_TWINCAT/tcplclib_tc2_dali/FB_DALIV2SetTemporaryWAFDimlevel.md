# FB_DALIV2SetTemporaryWAFDimlevel

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [Part 209 (color/color temperature control)](ms-xhelp:///?Id=beckhoff-a837-4797-bf19-33a8438d83d2)
6. FB\_DALIV2SetTemporaryWAFDimlevel

# FB\_DALIV2SetTemporaryWAFDimlevel

![25644791](/tcplclib_tc2_dali/1033/Images/gif/9007200265695371__en-US__Web.gif)

Saves the values in the [TEMPORARY WHITE DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44), [TEMPORARY AMBER DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) and [TEMPORARY FREECOLOR DIMLEVEL](ms-xhelp:///?Id=beckhoff-1ce6-4fd4-be82-75082326bd44) variables of the DALI control gear. The values can be read with function block [FB\_DALIV2QueryColourValue()](ms-xhelp:///?Id=beckhoff-bf54-40b6-b294-0a21b4b8b625).

The function block changes the DTR (data transfer registers), DTR1 and DTR2 for all DALI control gears of the DALI line.

The function block supports the following color representations:

* RGBWAF

|  |  |
| --- | --- |
| 29476530 | This command belongs to the application-related expansion commands for lamps for the color/color temperature control with DALI interface. They function only if they are preceded by the *Enable Device Type 8* command, which can be sent with the [FB\_DALIV2EnableDeviceType()](ms-xhelp:///?Id=beckhoff-e277-46a4-85ba-43a8cbcb1cb1) function block. The *Enable Device Type 8* command is internally placed automatically before all application-related expansion commands for lamps for the color/color temperature control with DALI interface. |

## VAR\_INPUT

```
bStart                       : BOOL;  
nAddr                        : BYTE;  
eAddrType                    : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
eCommandPriority             : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nTemporaryWhiteDimlevel      : BYTE;  
nTemporaryAmberDimlevel      : BYTE;  
nTemporaryFreecolourDimlevel : BYTE;
```

**bStart:** The function block is activated by a positive edge at this input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nTemporaryWhiteDimlevel:** The new value for TEMPORARY WHITE DIMLEVEL.

**nTemporaryAmberDimlevel:** The new value for TEMPORARY AMBER DIMLEVEL.

**nTemporaryFreecolourDimlevel:** The new value for TEMPORARY FREECOLOUR DIMLEVEL.

## VAR\_OUTPUT

```
bBusy    : BOOL;  
bError   : BOOL;  
nErrorId : UDINT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

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
