# FB_DALI102Dimmer2Switch

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Applications](ms-xhelp:///?Id=beckhoff-bd9c-45d9-9ddb-74b3ed68e5b8)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-4b6c-4c81-97bd-55dd3a8527c6)
6. [Power control](ms-xhelp:///?Id=beckhoff-861d-492e-a1e1-1a65dcafb2e2)
7. FB\_DALI102Dimmer2Switch

# FB\_DALI102Dimmer2Switch

![14660263](/tcplclib_tc3_dali/1033/Images/png/10944519179__Web.png)

The function block FB\_DALI102Dimmer2Switch provides the main functions for implementing a touch dimmer.

**Operation**

The inputs *bSwitchUp* and *bSwitchDown* are intended for linking with two push buttons. Pressing the button briefly switches the DALI control gears on or off. Pressing the button longer causes the output value of the DALI control gears to dim down to the minimum or up to the maximum values, respectively (see below).

The output value of the DALI control gears can be changed by positive edges at the inputs *bRecallMinLevel*, *bRecallMaxLevel*, *bOn*, *bOff*, *bToogle*, *bGoToScene*, and *bSetLevel* (see below).

The function block offers the option to address a single DALI control gear via a short address, several DALI control gears via a group address or all DALI control gears of a DALI line via a broadcast.

The variables *minLevel*, *maxLevel*, *fadeRate*, *fadeTime*, *extendedFadeTimeBase* and *extendedFadeTimeMultiplier* are parameters that are stored separately in each DALI control gear. These variables can be changed in the DALI control gears by writing the properties and with a positive edge at the input *bInitialize*.

If DALI commands are sent for setting the output values (*bBusy* = TRUE), further positive edges at the inputs are ignored. New commands can be executed as soon as *bBusy* has been reset again.

**Operation via the bSwitchUp and bSwitchDown inputs**

A short signal at the inputs *bSwitchUp* or *bSwitchDown* switches the DALI control gears on or off, depending on the state of the reference DALI control gear. If the signal is present for a longer time, the system switches to dimmer mode and the output values of the DALI control gears move up to *minLevel* or *maxLevel* or until *bSwitchUp* or *bSwitchDown* are FALSE again.

If *bSwitchUp* or *bSwitchDown* is set to FALSE again, the current output values of the DALI control gears remain unchanged. A new pulse at the input *bSwitchUp* or *bSwitchDown* sets the output values to 0.

The rate at which the output values of the DALI control gears change in dimmer mode is determined by the variable *fadeRate* in the individual DALI control gears. The speed at which the DALI control gears are switched on again is specified by the variables *fadeTime*, *extendedFadeTimeBase*, and *extendedFadeTimeMultiplier*.

**Operation via the inputs bOn, bOff, bGoToScene, and bSetLevel**

The output value of the DALI control gears can be changed immediately by positive edges at the inputs *bOn*, *bOff*, *bGoToScene*, and *bSetLevel*.

For *bOn*, *bGoToScene*, and *bSetLevel*, the speed at which the specified value is to be reached is specified by the variables *fadeTime*, *extendedFadeTimeBase*, and *extendedFadeTimeMultiplier*. *bOff* switches the DALI control gears off immediately.

**Memory mode**

When switching on, a distinction must be made as to whether memory mode (see *nOptions*) is active or not. If memory mode is active, the last set value is adopted as the output value for the DALI control gears when the device is switched on. If memory mode is not active, the output value from the parameter *nLevelMemoryMode* is used for the DALI control gears. It is irrelevant whether the DALI control gears are switched via the input *bOn*, *bToggle*, *bSwitchUp*, or *bSwitchDown*.

**DALI short address reference device (nReferenceDeviceAddress)**

If several DALI control gears are addressed, the current output value of the reference DALI control gear is read out via *nReferenceDeviceAddress*. The DALI control gears are set to the desired value, depending on the state of the reference DALI control gear.

The parameter *nReferenceDeviceAddress* is also used if the output value of the reference DALI control gear is read out cyclically in the background (*tCycleActualLevel* > 0 sec).

No reference DALI control gear is required if a single DALI control gear is to be controlled with the function block (*eAddressType = E\_DALIAddressType.Short*). The output value of the individual DALI control gear is determined via *nAddress*. The parameter *nReferenceDeviceAddress* has no meaning in this case.

If *nReferenceDeviceAddress* is used, it must always contain the short address of a DALI control gear, which is also contained in the addressed DALI group. For a broadcast, a DALI control gear with the corresponding short address must be present on the DALI line.

## VAR\_INPUT

```
bInitialize                : BOOL := FALSE;  
nAddress                   : BYTE;  
eAddressType               : E_DALIAddressType := E_DALIAddressType.Short;  
bSwitchUp                  : BOOL;  
bSwitchDown                : BOOL;  
bRecallMaxLevel            : BOOL;  
bRecallMinLevel            : BOOL;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
bGoToScene                 : BOOL;  
nScene                     : BYTE;  
bSetLevel                  : BOOL;  
nLevel                     : BYTE := 254;  
nLevelMemoryMode           : BYTE := 254;  
nReferenceDeviceAddress    : BYTE;  
tCycleActualLevel          : TIME := T#30S;  
nOptions                   : DWORD := 0;
```

**bInitialize:** A positive edge at this input writes the values of all properties to the DALI control gears.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). The input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**bSwitchUp/bSwitchDown**: A short signal at these inputs switches the DALI control gears on or off. If the signal is present for a longer period, the system switches to dimmer mode and the output values of the DALI control gears move to *minLevel* or *maxLevel*.

**bRecallMaxLevel:** A positive edge at this input sets the DALI control gears to *maxLevel*.

**bRecallMinLevel:** A positive edge at this input sets the DALI control gears to *minLevel*.

**bOn:** If memory mode is active (see *nOptions*), a positive edge at this input sets the DALI control gears to their output value before the last switching off. If memory mode is not active, the DALI control gears are set to *nLevelMemoryMode*.

**bOff:** The DALI control gears are switched off via a positive edge at this input. The previous output value is stored internally to be used for switching on if memory mode is active (see *nOptions*).

**bToggle:** Each positive edge at this input causes the DALI control gears to switch between off and their output value before the last switching off (memory mode active) or *nLevelMemoryMode* (memory mode not active).

**bGoToScene:** A positive edge at this input sets the output value of the DALI control gears to the value stored in the *nScene* scene.

**nScene:** Scene (0...15) to be called up in the DALI control gears by *bGoToScene*. Each DALI control gear has its own output value for each scene.

**bSetLevel:** A positive edge at this input sets the output value of the DALI control gears to the value specified by *nLevel*.

**nLevel:** Output value (0, *minLevel*...*maxLevel*, 255) to be called up in the DALI control gears by *bSetLevel*. The output value remains unchanged if the value is 255 (MASK).

**nLevelMemoryMode:** Output value (*minLevel*...*maxLevel*) for switching on the DALI control gears when memory mode is not active.

**nReferenceDeviceAddress:** Short address (0...63) of the reference DALI control gear for group call and broadcast. This parameter is not evaluated if *eAddressType = E\_DALIAddressType.Short*. In this case, the reference DALI control gear is read out via *nAddress*.

**tCycleActualLevel:** Cycle time with which the current output value of the reference DALI control gear is read out in the background. Set the cycle time such that as few DALI commands as possible are sent. If the time is set to 0 sec, no readout takes place.

**nOptions:** Options that affect the behavior of the function block. The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| Tc3\_DALI.GVL.cMemoryMode | Activates memory mode. |

## VAR\_OUTPUT

```
bError             : BOOL;  
ipResultMessage    : I_TcMessage;  
bBusy              : BOOL;  
bInitializing      : BOOL;  
nActualLevel       : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see error evaluation) that can be used to obtain detailed information about the processing of the function block (see runtime messages). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**bInitializing:** The output is set as soon as the initialization of the DALI control gears has been started, and remains active until all DALI commands have been executed.

**nActualLevel:** Current output value (0, *minLevel*...*maxLevel*, 255) of the reference DALI control gear that is addressed via *nReferenceDeviceAddress*. If *eAddressType = E\_DALIAddressType.Short*, the reference DALI control gear is read out via *nAddress*. A value of 255 (MASK) indicates that an error occurred when reading the output value from the reference DALI control gear. The cause may be, for example, a technical defect or the DALI control gear is in the start-up phase. In this case *bError* is not set to TRUE.

## Properties

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| nMaxLevel | BYTE | Get, Set | 254 | See variable [maxLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| nMinLevel | BYTE | Get, Set | 126 | See variable [minLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eFadeRate | [E\_DALIFadeRate](ms-xhelp:///?Id=beckhoff-105a-4ff0-8b03-643eb3dc2c5a) | Get, Set | N045StepsPerSec | See variable [fadeRate](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eFadeTime | [E\_DALIFadeTime](ms-xhelp:///?Id=beckhoff-dc14-4a77-afee-af76d66da9e6) | Get, Set | Disabled | See variable [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eExtendedFadeTimeBase | [E\_DALIExtendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-148d-4d6f-b8c8-a2df66a7851b) | Get, Set | Base01 | See variable [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eExtendedFadeTimeMultiplier | [E\_DALIExtendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-876c-47dc-b80f-957ea84b912b) | Get, Set | Disabled | See variable [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) |
| ipDALICommunication | I\_DALICommunication | Get, Set | 0 | Interface pointer to the communication block (e.g. [FB\_KL6821Communication](ms-xhelp:///?Id=beckhoff-37ef-403f-bac1-40d77b04945d)) |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.25 | Tc3\_DALI from v3.10.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
