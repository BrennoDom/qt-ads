# FB_DALIV2Ramp

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
7. FB\_DALIV2Ramp

# FB\_DALIV2Ramp

![30752875](/tcplclib_tc2_dali/1033/Images/gif/9007199398121483__en-US__Web.gif)

Function block for realizing a light-ramp.

A rising edge at the input *bOn* switches the light to the maximum value of the master lamp. A rising edge at input *bOff* switches the light off. Rising edges at the *bToggle* input invert the respective light state. A positive edge at the *bStart* input allows the function block to dim the light from the current level to *nEndLevel*. The time required for this is defined by *tRampTime*. All inputs are only active as long as *bEnable* is *TRUE*; otherwise the function block is internally reset and no further DALI commands are output.  
At each start of the dimming ramp a check takes place to determine whether the *nEndLevel* value lies within the permissible limits ([MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) of the master device. The value "0" is also allowed.

## Ramp implementation

Basically, the function block is designed such that it issues the required number of *OnAndStepUp* or *StepDownAndOff* commands at uniform intervals within the specified ramp time.  
 However, processing of these step and query commands also takes time. The further the ramp time is reduced, the more likely is it that the internally calculated time for a StepUp or StepDown command is no longer sufficient. The actual ramp time will keep increasing, relative to the set time.  
In order to be able to realize small ramps, the operating principle of the function block is switched from step mode to DirectArcPower mode when the ramp time falls below an internally preset limit value of 11 s. The DALI command *DirectArcPowerControl* brings the corresponding lamps from their current value to the set end value within the [FADE TIME](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). In total there are 16 different fade time values, which are stored in the control unit for each lamp:

|  |  |
| --- | --- |
| **nFadeTime** | **tFadeTime (s)** |
| 0 | <0.0707 |
| 1 | 0.707 |
| 2 | 1.000 |
| 3 | 1.414 |
| 4 | 2.000 |
| 5 | 2.828 |
| 6 | 4.000 |
| 7 | 5.657 |
| 8 | 8.000 |
| 9 | 11.314 |
| 10 | 16.000 |
| 11 | 22.627 |
| 12 | 32.000 |
| 13 | 45.255 |
| 14 | 64.000 |
| 15 | 90.510 |

The next value for the ramp that is set at the function block is taken from the table and programmed for all control gears to be controlled. At 6 s, step 7 = 5.657 s would apply, for example. The same value would also be used for a ramp time of 5 s. Precise timing would then no longer be possible. After successful completion of the ramp control, the value of the master device **before** the time setting is transferred back to all control gears.  
During the ramp motion the value *nActualLevelMasterDev* is output as internally calculated value, in order to avoid burdening the DALI bus with recurring query commands. This calculation is based on the difference between start and end value and the selected ramp time. Since it is a calculated value, it can be subject to errors caused by rounding and command delays and should be used for guidance only. After completion of the ramp the brightness is queried directly and the output value is exact again.

## Comment on the nMasterDevAddr parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Since the individual devices may belong to different groups, the individual lamps may have different brightness states before a group or common control command. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. *In this case, the nMasterDevAddr* parameter has no significance.

## VAR\_INPUT

```
bEnable                    : BOOL := TRUE;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
bStart                     : BOOL;  
nEndLevel                  : BYTE;  
tRampTime                  : TIME := t#8s;  
nOptions                   : DWORD := 0;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bEnable:** The *bOn*, *bOff*, *bToggle* and *bStart* inputs are active as long as this input is TRUE. A negative state deactivates the inputs and resets the function block after processing the last necessary DALI commands. No further DALI commands are then output, apart from the cyclic querying of the brightness of the master device.

**bOn:** A rising edge directly switches the controlled lamps to the maximum value of the master lamp.

**bOff:** A positive edge immediately switches off the controlled lamps.

**bToggle:** A rising edge immediately switches the controlled lamps off if the master lamp is **not** switched off and switches them on if the master lamp is off.

**bStart:** If a positive edge is applied to this input, the light is dimmed up or down respectively from the current value (the master device is decisive here) to *nEndLevel*. The time required for this is defined by *tRampTime*. The dimming procedure can be interrupted at any time by *bOn, bOff* or *bToggle*.

**nEndLevel:** Target value of the dimming procedure. (Valid range of values: 0 or [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)).

**tRampTime:** Ramp time, see *bStart*. (Preset value: 8 seconds).

**nOptions:** Reserved for future developments.

**nAddr:** Address of the single device in case of individual control or of the group in the case of group control.

**nMasterDevAddr:** The address of the master device for group and common switching operations.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**tCycleActualLevelMasterDev:** Cycle time with which the actual value is read in the background (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)). So that the dimming of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited.

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
