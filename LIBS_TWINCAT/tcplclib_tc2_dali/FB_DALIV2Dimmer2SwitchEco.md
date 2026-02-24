# FB_DALIV2Dimmer2SwitchEco

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-9f59-405b-9b5e-1a946f4c914f)
6. [Power control](ms-xhelp:///?Id=beckhoff-4c5d-4a51-898b-3f3ce005dcad)
7. FB\_DALIV2Dimmer2SwitchEco

# FB\_DALIV2Dimmer2SwitchEco

![22098140](/tcplclib_tc2_dali/1033/Images/gif/9007199398108683__en-US__Web.gif)

The FB\_DALIDimmer2SwitchEco() function block is a variant of [FB\_DALIV2Dimmer2Switch()](ms-xhelp:///?Id=beckhoff-864e-4800-8bd4-d2f8ba7b7ee7) that saves memory space. It is not equipped with the special function “Switch off memory function”.

## Operation by means of the bSwitchDimmUp and bSwitchDimmDown inputs

The light is switched on or off by a short signal at the *bSwitchDimmUp* or *bSwitchDimmDown* inputs. Dimmer mode will be activated if the signal remains for longer than *tSwitchOverTime* (typical recommended value: 200ms). The addressed devices are now dimmed. When the signal is once more removed, the output signal being generated at that time is retained. Another pulse at one of the inputs will set the output to 0.

## Operation by means of the bOn and bOff inputs

The light is immediately switched on or off if a rising edge is applied to the *bOn* or *bOff* inputs. The output value is set to 0 when switching off.

## The memory function

In contrast to [FB\_DALIV2Dimmer2Switch()](ms-xhelp:///?Id=beckhoff-864e-4800-8bd4-d2f8ba7b7ee7), where the memory function can be switched on or off through the *bMemoryModeOn* input, the memory function is always active on this memory-saving version. This means that the most recently set value is adopted for the brightness when switching on. It is irrelevant, in this case, whether the light it has been switched on by means of the *bOn* input or the *bSwitchDimm* input.

## Comment on the tSwitchOverTime parameter

If a duration of 0 is specified for the parameter *tSwitchOverTime*, the *bSwitchDimm* input can only be used to dim the light. Switching on and off is only possible with the *bOn* and *bOff* inputs.

## Comment on the nMasterDevAddr parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Since the individual devices may belong to different groups, the individual lamps may have different brightness states before a group or common control command. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. *In this case, the nMasterDevAddr* parameter has no significance.

## VAR\_INPUT

```
bSwitchDimmUp              : BOOL;  
bSwitchDimmDown            : BOOL;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bSetDimmValue              : BOOL;  
nDimmValue                 : BYTE;  
tSwitchOverTime            : TIME := t#400ms;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bSwitchDimmUp:** Switches or dims the addressed devices up.

**bSwitchDimmDown:** Switches or dims the addressed devices down.

**bOn:** Switches the addressed devices to the most recent output value.

**bOff:** Switches the addressed devices off (value 0).

**bSetDimmValue:** A positive edge at this input sets the addressed devices immediately to the brightness value that is asserted at the *nDimmValue* input. If the value of *nDimmValue* changes, the brightness value is set immediately to the changed value if the *bSetDimmValue* input is FALSE.

**nDimmValue:** see *bSetDimmValue*.

**tSwitchOverTime:** Time for switching between the light on/off and dimming functions for the *bSwitchDimm* input.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**nMasterDevAddr:** The address of the master device for group and common switching operations.

**tCycleActualLevelMasterDev:** Cycle time required to read the current actual value (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) in the background. So that the dimming of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

## VAR\_OUTPUT

```
nActualLevelMasterDev : BYTE;  
bBusy                 : BOOL;  
bError                : BOOL;  
nErrorId              : UDINT;
```

**nActualLevelMasterDev:** Current output value of the master device (always the respectively addressed device if *eAddrType = eAddrTypeShort*).

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
