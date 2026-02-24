# FB_DALI102GetSettings

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
7. FB\_DALI102GetSettings

# FB\_DALI102GetSettings

![64833508](/tcplclib_tc3_dali/1033/Images/gif/7296300811__Web.gif)

This function block reads several variables (see table [below](ms-xhelp:///?Id=beckhoff-6b75-4650-87a1-2efcd855223c)) from selected DALI control gears and saves them in the structure [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00).

The DALI control gears that are to be read can be specified by the input variable *nDevices*. Each bit of this variable corresponds to a short address.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. A check is first made as to whether a DALI control gear is present at all. If this is the case, then the *bPresent* bit is set in the respective structure (see [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00)), after which the settings of the control gear are read one by one and written in the associated variables in the structure. If it is found that a device is not available, the reading is skipped and work continues with the next device. The structure index here reflects the address of the device. In other words, data for the device with short address 0 is located at *arrDALIDeviceSettings[0]*, and so on through to the device with short address 63 having its data at *arrDALIDeviceSettings[63]*. If a read error occurs when reading from a device, the corresponding bit in *nErrors* is set for the respective structure without the function block itself switching to error mode. The following table shows which bit is set in the *nErrors* variable when an error occurs during the reading of a variable from a control gear.

| Bit | Error |
| --- | --- |
| 0 | An error occurred while attempting to seek the DALI control gear. |
| 1 | Error while reading the variable [actualLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 2 | Error while reading the variable [powerOnLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 3 | Error while reading the variable [systemFailureLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 4 | Error while reading the variable [minLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 5 | Error while reading the variable [maxLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 6 | Error while reading the variable [fadeRate](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 7 | Error while reading the variable [fadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 8 | Error while reading the variables [extendedFadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and [extendedFadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 9 | Error while reading the variable [randomAddress](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 10 | Error while reading the variable [gearGroups](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 11 | Error while reading the variable [scene0-scene15](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| 12 | Error while reading the variable [statusInformation](ms-xhelp:///?Id=beckhoff-827d-4a6e-a233-9334ccee818f). |
| 13 | Error while reading the version number from the [MemoryBank](ms-xhelp:///?Id=beckhoff-f157-4446-a05b-f675f276156a). |
| 14 | Error while reading the supported device types. |
| 15 | Error while reading the variable [physicalMinLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |

## VAR\_INPUT

```
bStart            : BOOL;  
nDevices          : LWORD;  
nOptions          : DWORD;  
bCancel           : BOOL;  
eCommandPriority  : E_DALICommandPriority := E_DALICommandPriority.MiddleLow;
```

**bStart:** Execution of the DALI commands is triggered via a positive edge at this input.

**nDevices:** Variable for selecting the DALI control gears to be read. Each bit of the variable represents a DALI control gear (0...63). All short addresses are queried with a setting of 16#FFFF\_FFFF\_FFFF\_FFFF.

**nOptions:** Options for reading the variables (see table below). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| Tc3\_DALI.GVL.cOptionActualDimLevel | Reads the current [output value](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionPowerOnLevel | Reads the current [switch-on value](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionSystemFailureLevel | Reads the current [setting value](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) in case of a DALI bus error. |
| Tc3\_DALI.GVL.cOptionMinLevel | Reads the [maximum](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) output value. |
| Tc3\_DALI.GVL.cOptionMaxLevel | Reads the [minimum](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) output value. |
| Tc3\_DALI.GVL.cOptionFadeRateFadeTime | Reads the [FadeRate](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and the [FadeTime](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionExtendedFadeTime | Reads the extended [FadeTimeBase](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7) and the [FadeTimeMultiplier](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionRandomAddress | Reads the [random address](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionGroups | Reads the [group allocations](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionSceneLevels | Reads the [scene settings](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionStatusInformation | Reads the [status information](ms-xhelp:///?Id=beckhoff-827d-4a6e-a233-9334ccee818f). |
| Tc3\_DALI.GVL.cOptionVersionNumber | Reads the [version number](ms-xhelp:///?Id=beckhoff-f157-4446-a05b-f675f276156a) of the DALI control gear. |
| Tc3\_DALI.GVL.cOptionDeviceType | Reading the [device type](ms-xhelp:///?Id=beckhoff-0d4a-425d-a093-a2ad7c648ae6). |
| Tc3\_DALI.GVL.cOptionPhysicalMinLevel | Reads the [PhysicalMinLevel](ms-xhelp:///?Id=beckhoff-e013-4a7e-9d50-4deaaa138af7). |
| Tc3\_DALI.GVL.cOptionAll | Reads all variables. |

**bCancel:** A positive edge at this input will disable the function block and hence abort the reading of the variables.

**eCommandPriority:** Priority (low, middle low, middle, middle high, high) with which the DALI commands are processed (see [E\_DALICommandPriority](ms-xhelp:///?Id=beckhoff-0df2-4cc5-8ea6-5c4eb6040cf5)).

|  |  |
| --- | --- |
| 46630661 | *eCommandPriority* has no function with the KL6811. The command priorities are supported by the KL6821 from the firmware version BD. |

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

**nCurrentShortAddress:** Indicates which short address is currently being queried.

## VAR\_IN\_OUT

```
arrDALIDeviceSettings  : ARRAY [0..63] of ST_DALIControlGearSettings;
```

**arrDALIDeviceSettings:** Array containing the read parameters (see [ST\_DALIControlGearSettings](ms-xhelp:///?Id=beckhoff-57b0-43e1-b6e7-0f00a0dcbb00)) of the individual control gears.

## Requirements

| Development environment | Required PLC library |
| --- | --- |
| TwinCAT from v3.1.4024.4 | Tc3\_DALI from v3.2.0.0 |

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
