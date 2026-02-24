# FB_DALIV2StairwellDimmer

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
7. FB\_DALIV2StairwellDimmer

# FB\_DALIV2StairwellDimmer

![27806533](/tcplclib_tc2_dali/1033/Images/gif/9007199398134283__en-US__Web.gif)

Function block for controlling stairwell lighting.

The light is switched to the value *nPresenceValue* by a positive edge at the *bSwitch* input. A negative edge on *bSwitch* starts or restarts a timer with the running time of *tPresenceDuration*. On expiry of this timer the controlled lamps are dimmed within the time *tFadeTime* to the value *nProlongValue*. This value is maintained for the time period *tProlongDuration.* Following which the light is switched off. A positive edge at the *bOff* input immediately switches the light off, a new positive edge at the *bSwitch* input switches the light on again at any time - even during the dimming and waiting times.  
 Each time the light is switched on a check is performed to determine whether the values *nPresenceValue* and *nProlongValue* lie within the permissible limits ([MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) of the master device. The value "0" is also permitted. Beyond that it is possible for *nPresenceValue* to be smaller than *nProlongValue* or for the two values to be identical.

## Comment on the *nMasterDevAddr* parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Because the individual devices can be members of a variety of groups, it can happen that, prior to the issue of a group or common control command, the individual lamps have different brightness levels. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. In this case, the *nMasterDevAddr* parameter has no significance.

![48932206](/tcplclib_tc2_dali/1033/Images/jpg/143396491__en-US__Web.jpg)

## VAR\_INPUT

```
bEnable                    : BOOL := TRUE;  
bSwitch                    : BOOL;  
bOff                       : BOOL;  
nPresenceValue             : BYTE;  
nProlongValue              : BYTE;  
tPresenceDuration          : TIME := t#30s;  
tFadeOffDuration           : TIME := t#10s;  
tProlongDuration           : TIME := t#20s;  
nOptions                   : DWORD := 0;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE;  
tCycleActualLevelMasterDev : TIME := t#0s;
```

**bEnable:** As long as this input is TRUE, the

inputs bOn and bOff are active. A negative state disables the

inputs and resets the function block after the last

required DALI commands have been processed. No further DALI commands are then issued,

except the cyclic query of the brightness of the

master device.

**bSwitch:** Upon a positive edge: the controlled lamps are switched directly to *nPresenceValue*. Upon a negative edge: start of the presence time (see diagram).

**bOff:** Immediately switches off the controlled lamps.

**nPresenceValue:** Value to which the controlled lamps are to be switched during the presence time. (Valid range of values: 0 or [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) - preset value: 254).

**nProlongValue:** Value to which the controlled lamps are to be switched during the dwell time. (Valid range of values: 0 or [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) - preset value: 200).

**tPesenceDuration:** Duration of the presence time for which the controlled lamps are switched to *nPresenceValue* after a negative edge at *bSwitch*. (Preset value: 30 seconds).

**tFadeOffDuration:** Time duration in which the brightness value is controlled from *nPresenceValue* to *nProlongValue*. (Preset value: 10 seconds).

**tProlongDuration:** Duration of the dwell time. (Preset value: 20 seconds).

**nOptions:** Reserved for future developments.

**nAddr:** Address of the single device in case of individual control or of the group in the case of group control.

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

**bBusy:** This output is always set when a change of light is active, i.e. on, off and ramp. Start and target value are irrelevant. This output would also be set in the case of a ramp, for example, from 100 to 100 in 10 s.

**bCycleActive:** Upon activation of the function block the output is set and remains active until the cycle has been processed or the lamps have been switched off.

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
