# FB_DALIV2IAPIR

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Third-party function blocks](ms-xhelp:///?Id=beckhoff-3be5-46f6-9609-796403dd277e)
5. [Interior Automation](ms-xhelp:///?Id=beckhoff-c267-4363-a486-fa9626bdb3d9)
6. FB\_DALIV2IAPIR

# FB\_DALIV2IAPIR

![29622330](/tcplclib_tc2_dali/1033/Images/gif/9007199398143883__en-US__Web.gif)

This function block cyclically reads the status of an IA PIR sensor and scales the measured brightness and detected presence based on the received value.

Two different cycle times can be specified. One cycle time that is used if no presence is detected and one that is used in case of active presence. In this way access to the DALI bus can be minimized. If presence is detected a slower cycle time (e.g. 20 s) can usually be selected, because lighting control and switching off the lighting is not time-critical. If there is no presence, then a shorter cycle time (e.g. 2 s) should be selected. As a result, the lighting is switched on with the shortest possible reaction time when the room is entered.

Further information and a description of the electrical and physical properties can be found in the product description for the IA PIR sensor.

## VAR\_INPUT

```
bReadDirectly           : BOOL := FALSE;  
tCycleTimeIfOccupancy   : TIME := t#20s;  
tCycleTimeIfNoOccupancy : TIME := t#2s;  
nAddr                   : BYTE := 0;  
eAddrType               : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
eCommandPriority        : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;
```

**bReadDirectly:** The function block is activated by a positive edge at this input.

**tCycleTimeIfOccupancy:** Cycle time with active presence.

**tCycleTimeIfNoOccupancy:** Cycle time without active presence.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

## VAR\_OUTPUT

```
bOccupancy  : BOOL;  
nBrightness : INT;  
nRawValue   : BYTE;  
bBusy       : BOOL;  
bError      : BOOL;  
nErrorId    : UDINT;
```

**bOccupancy:** The output is set if the sensor detects presence.

**nBrightness:** Measured brightness in lux.

**nRawValue:** The value of the sensor read before the conversion.

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command.

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
