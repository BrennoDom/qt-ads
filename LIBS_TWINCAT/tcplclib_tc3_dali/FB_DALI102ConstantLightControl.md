# FB_DALI102ConstantLightControl

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
7. FB\_DALI102ConstantLightControl

# FB\_DALI102ConstantLightControl

![41816140](/tcplclib_tc3_dali/1033/Images/png/10944513291__Web.png)

The FB\_DALI102ConstantLightControl function block provides the basic functions for implementing constant light regulation.

The system attempts to regulate to a specified setpoint (*nSetpointValue*) by dimming up and down cyclically. The control dynamics are determined by a dead time (*tDeadTime*). The dead time defines the waiting time between the individual DALI commands for changing the output value (*nActualLevel*). The smaller the dead time, the faster the adjustment. A freely definable hysteresis (*nHysteresis*) prevents continuous oscillation around the setpoint. If the actual value is within the hysteresis range around the setpoint, the output value of the DALI control gears is not changed.

**Operation**

The function block offers the option to address a single DALI control gear via a short address, several DALI control gears via a group address, or all DALI control gears of a DALI line via a broadcast.

The variables [minLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7), [maxLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7), [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7), [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) are parameters that are stored separately in each DALI control gear. These variables can be changed in the DALI control gears by writing the properties and with a positive edge at the input *bInitialize*.

**Control**

The output value of the DALI control gears can be switched by positive edges at the inputs *bOn*, *bOff* and *bToggle*. If the DALI control gears are switched on and control is active (*bEnable* = TRUE), control is performed to the specified setpoint. If the control is not active (*bEnable* = FALSE), the output value of the DALI control gears remains unchanged.

The step-by-step adaption of the output value of the DALI control gears is carried out with the DALI commands STEP UP and STEP DOWN. The dead time (*tDeadtime*) specifies the time after which the output value is adapted. The DALI command STEP UP / STEP DOWN is called only once per control cycle. If the control deviation (*nDeviation*) is smaller than (*nHysteresis* / 2), the output value of the DALI control gears remains unchanged. The control deviation is calculated from *nSetpointValue* - *nActualBrightness*.

**Operation via the inputs bOn, bOff, and bToggle inputs**

The output value of the DALI control gears can be changed immediately by positive edges at the inputs *bOn*, *bOff*, and *bToggle*. This is independent of whether the control has been activated or deactivated (*bEnable*).

The variables *fadeTime*, *extendedFadeTimeBase*, and *extendedFadeTimeMultiplier* specify the speed at which the output value is changed when the DALI control gears are switched on via *bOn* or *bToggle*. Switching off the DALI control gears by *bOff* or *bToggle* takes place immediately. In this case, *nSwitchOnLevel* is used as the switch-on value. This value must lie in the range of the properties *nMinLevel* and *nMaxLevel*.

**DALI short address reference device (nReferenceDeviceAddress)**

If several DALI control gears are addressed, the current output value of the reference DALI control gear is read out via *nReferenceDeviceAddress*. The DALI control gears are set to the desired output value, depending on the state of the reference DALI control gear.

The parameter *nReferenceDeviceAddress* is also used if the output value of the reference DALI control gear is read out cyclically in the background (*tCycleActualLevel* > 0 sec).

No reference DALI control gear is required if a single DALI control gear is to be controlled with the function block (*eAddressType* *= E\_DALIAddressType.Short*). The output value of the individual DALI control gear is determined via *nAddress*. The parameter *nReferenceDeviceAddress* has no meaning in this case.

If *nReferenceDeviceAddress* is used, it must always contain the short address of a DALI control gear, which is also contained in the addressed DALI group. For a broadcast, a DALI control gear with the corresponding short address must be present on the DALI line.

## Example

The following example shows how a DALI light sensor can be combined with the FB\_DALIConstantLightControl function block. In this example, the PD11-BMS-FLAT DALI sensor from B.E.G. is used.

Since only the measured brightness is required, the instance for the motion sensor is deactivated (property *bEnableOccupancy*).

The brightness is read out from the DALI sensor via the input *bQueryBrightness*. Thus, the instance for the light sensor can also be deactivated (property *bEnableBrightness*).

At the end of the dead time, the output *bControlCyclerEnding* of the constant light regulation is set to TRUE. This positive edge is connected to the input *bQueryBrightness* of the DALI sensor. This means that the current brightness value is read out immediately before the control deviation (nDeviation) is calculated.

|  |  |
| --- | --- |
| 40800942 | By deactivating both instances, the DALI sensor does not send any events and the DALI bus is not unnecessarily loaded. |

The properties are initialized directly when the instance is declared. This means that explicit assignment at runtime is no longer necessary.

```
PROGRAM P_ConstantLightControl  
VAR  
  fbBrightness           : FB_DALI_BEG_PD11_BMS_V8_Flat(Communication.fbKL6821Communication) :=  
                                 (bEnableOccupancy  := FALSE,  
                                  bEnableBrightness := FALSE);  
  fbConstantLightControl : FB_DALI102ConstantLightControl(Communication.fbKL6821Communication) :=  
                                 (nMinLevel := 85,  
                                  nMaxLevel := 254);  
  bInitialize            : BOOL;  
  bToggle                : BOOL;  
  nBrightnessLevel       : UINT;  
  nActualLevel           : BYTE;  
  nDeviation             : DINT;  
END_VAR
```

![31664161](/tcplclib_tc3_dali/1033/Images/png/10944516235__Web.png)

## VAR\_INPUT

```
bInitialize                : BOOL := FALSE;  
bEnable                    : BOOL := TRUE;  
nAddress                   : BYTE;  
eAddressType               : E_DALIAddressType := E_DALIAddressType.Short;  
nSetpointValue             : UINT := 500;  
nActualBrightness          : UINT := 500;  
nHysteresis                : UINT := 30;  
tDeadtime                  : TIME := T#10S;  
bOn                        : BOOL;  
bOff                       : BOOL;  
bToggle                    : BOOL;  
nSwitchOnLevel             : BYTE := 254;  
nReferenceDeviceAddress    : BYTE;  
tCycleActualLevel          : TIME := T#30S;  
nOptions                   : DWORD := 0;
```

**bInitialize:** A positive edge at this input writes the values of all properties to the DALI control gears.

**bEnable:** Activates the constant light regulation as soon as this input is TRUE. If the input is FALSE, the constant light regulation is deactivated.

**nAddress:** Address of a DALI control gear or a DALI group.

**eAddressType:** Defines whether the input *nAddress* contains a short address (0…63) or a group address (0…15). The input *nAddress* has no meaning if a broadcast or a broadcast to unaddressed devices (BroadcastUnaddr) has been selected (see [E\_DALIAddressType](ms-xhelp:///?Id=beckhoff-8a4e-4869-9ea1-1920c00d61f5)).

**nSetpointValue:** The setpoint is applied to this input (0...65535).

**nActualBrightness:** The actual value is applied to this input.

**nHysteresis:** Control hysteresis (1...65535) around the setpoint. If the actual value is within this range, the output values of the DALI control gears are not changed.

**tDeadtime:** After the dead time (T#3S...T#3600S) has elapsed, the control deviation is recalculated and, if necessary, the output values of the DALI control gears are reduced or increased by one stage.

**bOn:** A positive edge at this input sets the DALI control gears to *nSwitchOnLevel*.

**bOff:** The DALI control gears are switched off via a positive edge at this input.

**bToggle:** A positive edge at this input toggles the DALI control gears between Off and *nSwitchOnLevel*.

**nSwitchOnLevel:** Output value (*minLevel*...*maxLevel*) for switching on the DALI control gears via the inputs *bOn* and *bToggle*.

**nReferenceDeviceAddress:** Short address (0...63) of the reference DALI control gear for group call and broadcast. This parameter is not evaluated if *eAddressType = E\_DALIAddressType.Short*. In this case, the reference DALI control gear is read out via *nAddress*.

**tCycleActualLevel:** Cycle time with which the current output value of the reference DALI control gear is read out in the background. Set the cycle time such that as few DALI commands as possible are sent. If the time is set to 0 sec, no readout takes place.

**nOptions:** Reserved for future extensions.

## VAR\_OUTPUT

```
bError               : BOOL;  
ipResultMessage      : I_TcMessage;  
bBusy                : BOOL;  
bInitializing        : BOOL;  
nActualLevel         : BYTE;  
nDeviation           : DINT;  
bControlCycleEnding  : BOOL;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**bInitializing:** The output is set as soon as the initialization of the DALI control gears has been started, and remains active until all DALI commands have been executed.

**nActualLevel:** Current output value (0, *minLevel*...*maxLevel*, 255) of the reference DALI control gear that is addressed via nReferenceDeviceAddress. If *eAddressType = E\_DALIAddressType.Short*, the reference DALI control gear is read out via *nAddress*. A value of 255 (MASK) indicates that an error occurred when reading the output value from the reference DALI control gear. The cause may be, for example, a technical defect or the DALI control gear is in the start-up phase. In this case *bError* is not set to TRUE.

**nDeviation:** Actual control deviation (*nSetpointValue* - *nActualBrightness*).

**bControlCycleEnding:** Before the dead time (*tDeadtime*) expires, this output is set to TRUE for 2 seconds. This output can be used, for example, to read the current brightness from a DALI light sensor.

## Properties

All parameters that are written to the DALI control device via *bInitialize* are available as properties.

| Name | Type | Access | Initial value | Description |
| --- | --- | --- | --- | --- |
| nMaxLevel | BYTE | Get, Set | 254 | See variable [maxLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| nMinLevel | BYTE | Get, Set | 126 | See variable [minLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eFadeTime | [E\_DALIFadeTime](ms-xhelp:///?Id=beckhoff-dc14-4a77-afee-af76d66da9e6) | Get, Set | Disabled | See variable [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eExtendedFadeTimeBase | [E\_DALIExtendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-148d-4d6f-b8c8-a2df66a7851b) | Get, Set | Base01 | See variable [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| eExtendedFadeTimeMultiplier | [E\_DALIExtendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-876c-47dc-b80f-957ea84b912b) | Get, Set | Disabled | See variable [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) |
| ipDALICommunication | I\_DALICommunication | Get, Set | 0 | Interface pointer to the communication block (e.g. [FB\_KL6821Communication](ms-xhelp:///?Id=beckhoff-37ef-403f-bac1-40d77b04945d)) |

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.25 | Tc3\_DALI from v3.10.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
