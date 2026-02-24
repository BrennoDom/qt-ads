# FB_DSIDirectArcPowerControl

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [Low-Level commands](ms-xhelp:///?Id=beckhoff-408c-4669-b5d5-6c547023c614)
5. [DSI](ms-xhelp:///?Id=beckhoff-784f-491e-bb89-7aaf1f451a8d)
6. FB\_DSIDirectArcPowerControl

# FB\_DSIDirectArcPowerControl

![55365254](/tcplclib_tc2_dali/1033/Images/gif/9007199398057483__en-US__Web.gif)

The *nArcPowerLevel* parameter specifies the brightness to which the lamp is switched.

| nArcPowerLevel | Comment |
| --- | --- |
| 0 | Lamp is switched off |
| 1 | Lamp is switched to the minimum brightness |
| 255 | Lamp is switched to the maximum brightness |

Control gears with a DSI interface do not have a short address. All the control gears on a DSI line are given the same value.

Note that the KL6811 must be switched over to the DSI mode. Details for this can be found in the operating instructions for the KL6811.

DSI control gears and DALI control gears cannot be mixed on a line. However, it is possible to operate several KL6811s on one controller, each in different operating modes (DSI/DALI).

## VAR\_INPUT

```
bStart           : BOOL;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nArcPowerLevel   : BYTE;
```

**bStart:** The function block is activated by a positive edge at this input.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nArcPowerLevel:** Lamp power value (0 to 255).

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

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
