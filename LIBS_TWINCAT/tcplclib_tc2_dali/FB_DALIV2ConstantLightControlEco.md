# FB_DALIV2ConstantLightControlEco

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
7. FB\_DALIV2ConstantLightControlEco

# FB\_DALIV2ConstantLightControlEco

![52667802](/tcplclib_tc2_dali/1033/Images/gif/9007199398092683__en-US__Web.gif)

The function block FB\_DALIV2ConstantLightControlEco() is used for constant light control with DALI control gears.

The system tries to match a specified set value through cyclic dimming. The control dynamics are determined by a dead time (*tDeadTime*). The dead time defines the delay between the individual commands for changing the control value. The smaller the dead time, the faster the control. A freely definable hysteresis (*nHysteresis*) prevents continuous oscillation around the set value. If the actual value is within the hysteresis range around the set value, the lamps brightness remains unchanged. An option is available for specifying whether the lamps should be switched on and off automatically (see table below).

## Comment on the nMasterDevAddr parameter

The DALI system provides facilities not just for controlling lamps individually, but also for addressing them as groups or through common commands. Since the individual devices may belong to different groups, the individual lamps may have different brightness states before a group or common control command. So that it is nevertheless possible to be clear whether the lamps now are to be switched on or off, a master device is assigned to each group, whose state is followed by the other devices. It is not necessary to specify a master device if the function block is to be used to control a single lamp, *eAddrType* = *eAddrTypeShort*. *In this case, the nMasterDevAddr* parameter has no significance.

## VAR\_INPUT

```
bEnable                    : BOOL := TRUE;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
nSetpointValue             : UINT := 500;  
nActualValue               : UINT;  
nHysteresis                : UINT := 50;  
tDeadTime                  : TIME := t#10s;  
nAddr                      : BYTE := 0;  
eAddrType                  : E_DALIV2AddrType := eDALIV2AddrTypeShort;  
nMasterDevAddr             : BYTE := 0;  
tCycleActualLevelMasterDev : TIME := t#0s;  
nOptions                   : DWORD := 0;
```

**bEnable:** Enables the function block. If this input is FALSE, the inputs *bOn*, *bOff* and *bToogle* are disabled. No control values are output.

**bOn:** Switches the addressed devices to [MAX\_LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) and activates constant light control.

**bOff:** Switches the addressed devices off and disables constant light control.

**bToggle:** The lighting is switched on or off, depending on the state of the reference device.

**nSetpointValue:** This input is used for specifying the set value.

**nActualValue:** The actual value is applied at this input.

**nHysteresis:** Control hysteresis around the set value. If the actual value is within this range, the control values for the lamps remain unchanged.

**tDeadTime:** Dead time between the individual commands used for changing the control value for the DALI lamps.

**nAddr:** The address of a participating device or of a group.

**eAddrType:** Short address, group address or broadcast (see [E\_DALIV2AddrType](ms-xhelp:///?Id=beckhoff-d59c-42a4-9d77-6cc67c0d1971)).

**nMasterDevAddr:** The address of the master device (reference device) for group and common switching operations.

**tCycleActualLevelMasterDev:** Cycle time required to read the current actual value (see [ACTUAL DIM LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e)) of the reference lamp in the background. So that the controlling of the lamps is not disturbed, reading always has the lowest priority. If the value is set to 0, reading is prohibited. The value read is output at the *nActualLevelMasterDev* output.

**nOptions:** Options (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_SWITCH\_ON\_AND\_OFF | The DALI commands [ON\_AND\_STEP\_UP](ms-xhelp:///?Id=beckhoff-8144-48dd-80f9-921461915276) and [STEP\_DOWN\_AND\_OFF](ms-xhelp:///?Id=beckhoff-944e-45e1-817f-793b352b4c5a) are used for changing the control value. This causes the lamps to be switched off when [MIN\_LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). If the control deviation is above the hysteresis, the lamps are switched on again. If this option is not set, the commands [STEP\_UP](ms-xhelp:///?Id=beckhoff-3460-4665-b990-63a4c61b601b) and [STEP\_DOWN](ms-xhelp:///?Id=beckhoff-921f-433b-9306-614ff4f7a874). In this cases the lamps remain switched on continuously. |
| DALIV2\_OPTION\_SWITCH\_ON\_WITH\_MIN\_LEVEL | If the light is switched on again by the constant light control, this option always uses the command [MIN\_LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). If the option is not set, [MAX\_LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is used. This option is available from v3.3.2.0 of the Tc2\_DALI PLC library. |

## VAR\_OUTPUT

```
nActualLevelMasterDev : BYTE;  
nDeviation            : INT;  
bControllerIsActive   : BOOL;  
bBusy                 : BOOL;  
bError                : BOOL;  
nErrorId              : UDINT;
```

**nActualLevelMasterDev:** Current output value of the master device (always the respectively addressed device if *eAddrType = eAddrTypeShort*).

**nDeviation:** Current control deviation (set value/actual value).

**bControllerIsActive:** This output is set once the control is activated.

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
