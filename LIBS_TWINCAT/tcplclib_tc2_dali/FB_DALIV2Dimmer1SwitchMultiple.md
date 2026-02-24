# FB_DALIV2Dimmer1SwitchMultiple

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
7. FB\_DALIV2Dimmer1SwitchMultiple

# FB\_DALIV2Dimmer1SwitchMultiple

![8557861](/tcplclib_tc2_dali/1033/Images/gif/9007199398102283__en-US__Web.gif)

Function block for switching and dimming DALI devices with one switch. For applications in which up to five DALI lines (0..4) can be installed. The basic function of this function block can be found in the description of [FB\_DALIV2Dimmer1Switch()](ms-xhelp:///?Id=beckhoff-9d5c-44a9-af7d-8d2c52724170).

## VAR\_INPUT

```
bSwitchDimm                  : BOOL;  
bOn                          : BOOL;  
bOff                         : BOOL;  
bSetDimmValue                : BOOL;  
nDimmValue                   : BYTE;  
tSwitchOverTime              : TIME := t#400ms;  
tCycleDelay                  : TIME := t#500ms;  
bMemoryModeOn                : BOOL := FALSE;  
nOnValueWithoutMemoryMode    : BYTE := 254;  
nAddr                        : BYTE := 0;  
eAddrType                    : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr               : BYTE := 0;  
nMasterDevLine               : BYTE := 0;  
nMinLevelMasterDev           : BYTE := 126;  
nMaxLevelMasterDev           : BYTE := 254;  
tCycleActualLevelMasterDev   : TIME := t#0s;  
nDALILineEnable              : BYTE := 2#0000_0001;
```

**bSwitchDimm:** Switches or dims the addressed devices on all the activated DALI lines.

**bOn:** Switches the addressed devices on all the activated DALI lines to the last output value, or to the value specified by *nOnValueWithoutMemoryMode*.

**bOff:** Switches the addressed devices on all the activated DALI lines off (value 0).

**bSetDimmValue:** A positive edge at this input sets the addressed devices on all the activated DALI lines immediately to the brightness value that is asserted at the *nDimmValue* input. If the value of *nDimmValue* changes, the brightness value is set immediately to the changed value if the *bSetDimmValue* input is FALSE.

**nDimmValue:** see *bSetDimmValue*.

**tSwitchOverTime:** Time for switching between the light on/off and dimming functions for the *bSwitchDimm* input.

**tCycleDelay:** Delay time, if either the minimum or maximum value is reached.

**bMemoryModeOn:** Switches over to use the memory function, so that the previous value is written to the output as soon as it is switched on.

**nOnValueWithoutMemoryMode:** Switch-on value if the memory function is not active.

**nAddr:** The address of a participating device or of a group.

**eAddrType :** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**nMasterDevAddr:** The address of the master device for group and common switching operations (0 - 63).

**nMasterDevLine:** The line on which the master device for group and common configurations is located. Depending on the function block, there is only one master device that is to be selected from one of the activated DALI lines. The lines are numbered from 0 to 4.

**nMinLevelMasterDev:** The minimum value of the master device.

**nMaxLevelMasterDev:** The maximum value of the master device.

**tCycleActualLevelMasterDev:** Cycle time required to read the current actual value (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) in the background. So that the dimming of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

**nDALILineEnable:** Input variable in the form of a bit pattern. A 1 in the bit pattern indicates that the DALI line is active. **Example:** 2#01001 means that DALI lines 0 and 3 are enabled.

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
stCommandBuffer00 : ST_DALIV2CommandBuffer;  
stCommandBuffer01 : ST_DALIV2CommandBuffer;  
stCommandBuffer02 : ST_DALIV2CommandBuffer;  
stCommandBuffer03 : ST_DALIV2CommandBuffer;  
stCommandBuffer04 : ST_DALIV2CommandBuffer;
```

**stCommandBuffer00 - stCommandBuffer04 :** Reference to the internal structures for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
