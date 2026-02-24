# FB_DALIV2LightControl

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
7. FB\_DALIV2LightControl

# FB\_DALIV2LightControl

![45118907](/tcplclib_tc2_dali/1033/Images/gif/9007199398115083__en-US__Web.gif)

Function block for daylight-dependent lighting control with up to 30 interpolation points.

At the core of this function block is an input/control value table of 30 elements with threshold switching. If the actual value of the brightness reaches the range of an interpolation point (*arrControlTable[n].nActualValue-arrControlTable[n].nSwitchRange/2* to *arrControlTable[n].nActualValue+arrControlTable[n].nSwitchRange/2*), the control value jumps to the corresponding value arrControlTable[n].nControlValue (see diagram). Coupled to this is a ramp block that runs up the control value over the time *tRampTime*. When switching on with a positive edge at *bOn*, however, the light is initially switched directly to the nearest control value. Only then is the controller activated. While the control is active, ‘post-starting’ can take place at any time with a positive edge at *bOn*, thus directly controlling the light to the nearest control variable. A positive edge at *bOff* directly switches off all the controlled lamps.

![3416986](/tcplclib_tc2_dali/1033/Images/gif/143377291__en-US__Web.gif)

The whole range of the table does not have to be used. The first table element that has a 0 as the table end *nSwitchRange* is regarded as the beginning of the unused range.

## Comment on the nMasterDevAddr parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Since the individual devices may belong to different groups, the individual lamps may have different brightness states before a group or common control command. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. *In this case, the nMasterDevAddr* parameter has no significance.

## VAR\_INPUT

```
bEnable                    : BOOL := TRUE;  
bOn                        : BOOL;  
bOff                       : BOOL;  
nActualValue               : UINT;  
tRampTime                  : TIME := t#30s;  
arrControlTable            : ARRAY[1..30] OF ST_DALIV2ControlTable;  
nOptions                   : DWORD := 0;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bEnable:** The *bOn* and *bOff* inputs are active as long as this input is TRUE. A negative state deactivates the inputs and resets the function block after processing the last necessary DALI commands. No further DALI commands are then output, apart from the cyclic querying of the brightness of the master device.

**bOn:** A positive edge switches the controlled lamp directly to the nearest control value.

**bOff:** A positive edge immediately switches off the controlled lamps.

**nActualValue:** Actual value of the brightness.

**tRampTime:** Period during which the control value is controlled to the next value (preset value: 30 s).

**arrControlTable:** Input/control value table. *arrControlTable [1]* to *arrControlTable [30]* of the type *ST\_DALIV2ControlTable* (see [ST\_DALIV2ControlTable](ms-xhelp:///?Id=beckhoff-7798-408a-8d0b-70ac1fdfc4d8)).

**nOptions:** Reserved for future developments.

**nAddr:** Address of the single device in case of individual control or of the group in the case of group control.

**nMasterDevAddr:** The address of the master device for group and common switching operations.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**tCycleActualLevelMasterDev:** Cycle time required to read the current control value (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) in the background. So that the dimming of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

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
