# FB_DALI102SetSettings

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Programming](ms-xhelp:///?Id=beckhoff-b5e2-4347-b4c8-164a6e6f2543)
3. [POUs](ms-xhelp:///?Id=beckhoff-57a2-4b7a-aa99-0fc670e505a2)
4. [Applications](ms-xhelp:///?Id=beckhoff-bd9c-45d9-9ddb-74b3ed68e5b8)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-4b6c-4c81-97bd-55dd3a8527c6)
6. [Settings](ms-xhelp:///?Id=beckhoff-aabc-4b67-a14b-978f02b856f6)
7. FB\_DALI102SetSettings

# FB\_DALI102SetSettings

![17022773](/tcplclib_tc3_dali/1033/Images/gif/7296316555__Web.gif)

This function block writes the values stored in the structure [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00) to several variables (see table [below](ms-xhelp:///?Id=beckhoff-6b75-4650-87a1-2efcd855223c)) of selected DALI control gears in a DALI line.

The DALI control gears that are to be written to can be specified by the input variable *nDevices*. Each bit of this variable corresponds to a short address.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. A check is first made as to whether a DALI control gear is present at all. If this is the case, then the *bPresent* bit is set in the respective structure (see [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00)), after which the settings are written one by one to the control gear. If a device is detected as being missing, the writing is skipped and work continues with the next device. The structure index here reflects the address of the device. In other words, data for the device with short address 0 is located at *arrDALIDeviceSettings[0]*, and so on through to the device with short address 63 having its data at *arrDALIDeviceSettings[63]*. If a device error occurs during writing, the corresponding bit in *nErrors* is set for the respective structure without the function block itself switching to error mode. The following table shows which bit is set in the *nErrors* variable when an error occurs during the reading of a variable from a control gear.

| Bit | Error |
| --- | --- |
| 0 | An error occurred while attempting to seek the DALI control gear. |
| 2 | Error while writing the variable [powerOnLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 3 | Error while writing the variable [systemFailureLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 4 | Error while writing the variable [minLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 5 | Error while writing the variable [maxLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 6 | Error while writing the variable [fadeRate](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 7 | Error while writing the variable [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 8 | Error while writing the variables [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 10 | Error while writing the variable [gearGroups](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 11 | Error while writing the variable [scene0-scene15](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |

## VAR\_INPUT

```
bStart            : BOOL;  
nDevices          : LWORD;  
nOptions          : DWORD;  
bCancel           : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.Middle;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nDevices:** Variable for selecting the DALI control gears that are to be initialized. Each bit of the variable represents a DALI control gear (0...63). All short addresses are written to with a setting of 16#FFFF\_FFFF\_FFFF\_FFFF.

**nOptions:** Options for writing the variables (see table below). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| Tc3\_DALI.GVL.cOptionPowerOnLevel | Initializes the current [switch-on value](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionSystemFailureLevel | Initializes the current [setting value](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) in case of a DALI bus error. |
| Tc3\_DALI.GVL.cOptionMinLevel | Initializes the [maximum](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) output value. |
| Tc3\_DALI.GVL.cOptionMaxLevel | Initializes the [minimum](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) output value. |
| Tc3\_DALI.GVL.cOptionFadeRate | Initializes the [FadeRate](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionFadeTime | Initializes the [FadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) |
| Tc3\_DALI.GVL.cOptionExtendedFadeTime | Initializes the extended [FadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and the [FadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionGroups | Initializes the [group allocations](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionSceneLevels | Initializes the [scene settings](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionAll | Initializes all variables. |

**bCancel:** A positive edge at this input will disable the function block and hence abort the initialization of the variable.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are sent (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 18987236 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

## VAR\_OUTPUT

```
bError                : BOOL;  
ipResultMessage       : I_TcMessage;  
bBusy                 : BOOL;  
nCurrentShortAddress  : BYTE;
```

**bError:** This output is switched to TRUE if an error occurs during the execution. Further information about the error can be queried via the variable *ipResultMessage*. The output is set to FALSE again as soon as *bBusy* switches to TRUE.

**ipResultMessage:** Interface pointer (see [error evaluation](ms-xhelp:///?Id=beckhoff-e964-4db2-800a-4efdb6dc0429)) that can be used to obtain detailed information about the processing of the function block (see [runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The interface pointer is valid after *bBusy* has changed from TRUE to FALSE.

**bBusy:** The output is set as soon as execution of the DALI commands has commenced. It remains active until all DALI commands have been processed.

**nCurrentShortAddress:** Indicates which short address is currently being written to.

## VAR\_IN\_OUT

```
arrDALIDeviceSettings  : ARRAY [0..63] of ST_DALIControlGearSettings;
```

arrDALIDeviceSettings: Array containing the read parameters (see [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00)) of the individual control gears.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.4 | Tc3\_DALI from v3.2.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
