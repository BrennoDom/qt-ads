# FB_DALIV2GetSettingsType01

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 202 (emergency lighting)](ms-xhelp:///?Id=beckhoff-07b5-44cf-a3f3-1a7bf71ce22d)
6. FB\_DALIV2GetSettingsType01

# FB\_DALIV2GetSettingsType01

![32481801](/tcplclib_tc2_dali/1033/Images/gif/9007199398191883__en-US__Web.gif)

This function block reads the variables (BATTERY CHARGE, DURATION TEST RESULT, LAMP EMERGENCY TIME…) from all emergency lighting control gears in a DALI line and stores them in a structure of type [ST\_DALIV2DeviceSettingsType01](ms-xhelp:///?Id=beckhoff-36a3-4a0e-a772-dde3f5dacd3c).

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. A check is first made as to whether a control gear is present at all. If this is the case, then the *bPresent* bit is set in the corresponding structure (see [ST\_DALIV2DeviceSettingsType01](ms-xhelp:///?Id=beckhoff-36a3-4a0e-a772-dde3f5dacd3c)), after which the settings of the control gear are read out one by one and written in the associated variables in the structure. If it is found that a device is not available, the reading is skipped and work continues with the next device. The structure index here reflects the address of the device. In other words, data for the device with short address 0 is located at *arrDALIDeviceSettingsType01[0]*, and so on through to the device with short address 63 having its data at *arrDALIDeviceSettingsType01[63]*. If a read error occurs when reading from a device, the corresponding bit in *nErrors* is set for the respective structure without the function block itself switching to error mode. The following table shows which bit is set in the *nErrors* variable when an error occurs during the reading of a variable from a control gear.

| Bit | Error |
| --- | --- |
| 0 | An error occurred whilst attempting to seek the control gear. |
| 1 | Error whilst reading the variable [BATTERY CHARGE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 2 | Error whilst reading the variable  [DURATION TEST RESULT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 3 | Error whilst reading the variable  [LAMP EMERGENCY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 4 | Error whilst reading the variable  [LAMP TOTAL OPERATION TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 5 | Error whilst reading the variable [EMERGENCY LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 6 | Error whilst reading the variable  [EMERGENCY MIN LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 7 | Error whilst reading the variable  [EMERGENCY MAX LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 8 | Error whilst reading the variable [RATED DURATION](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 9 | Error whilst reading the variable  [FUNCTION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 10 | Error whilst reading the variable  [DURATION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 11 | Error whilst reading the variable  [FUNCTION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 12 | Error whilst reading the variable  [DURATION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 13 | Error whilst reading the variable  [TEST EXECUTION TIMEOUT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 14 | Error whilst reading the variable [PROLONG TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 15 | Error whilst reading the variable [EMERGENCY MODE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 16 | Error whilst reading the variable [FEATURES](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 17 | Error whilst reading the variable [FAILURE STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |
| 18 | Error whilst reading the variable [EMERGENCY STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) |

When the function block has been processed, the *bBusy* output changes from TRUE to FALSE. Processing this function block can take several seconds, depending on how many control gears are attached.

## VAR\_INPUT

```
bStart           : BOOL;  
bCancel          : BOOL;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityHigh;  
nOptions         : DWORD;
```

**bStart:** The function block is activated by a positive edge at this input.

**bCancel:** A positive edge at this input will deactivate the function block and hence abort the reading of the variable.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nOptions:** Options for reading the variables (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_BATTERY\_CHARGE | The variable [BATTERY CHARGE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_DURATION\_TEST\_RESULT | The variable  [DURATION TEST RESULT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_LAMP\_EMERGENCY\_TIME | The variable  [LAMP EMERGENCY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_LAMP\_TOTAL\_OPERATION\_TIME | The variable  [LAMP TOTAL OPERATION TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_EMERGENCY\_LEVEL | The variable [EMERGENCY LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_EMERGENCY\_MIN\_LEVEL | The variable  [EMERGENCY MIN LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_EMERGENCY\_MAX\_LEVEL | The variable  [EMERGENCY MAX LEVEL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_RATED\_DURATION | The variable [RATED DURATION](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_NEXT\_FUNCTION\_TEST | The variable  [FUNCTION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_NEXT\_DURATION\_TEST | The variable  [DURATION TEST DELAY TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_FUNCTION\_TEST\_INTERVAL | The variable  [FUNCTION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_DURATION\_TEST\_INTERVAL | The variable  [DURATION TEST INTERVAL](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_TEST\_EXECUTION\_TIMEOUT | The variable  [TEST EXECUTION TIMEOUT](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_PROLONG\_TIME | The variable [PROLONG TIME](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_EMERGENCY\_MODE | The variable [EMERGENCY MODE](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_FEATURES | The variable [FEATURES](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_FAILURE\_STATUS | The variable [FAILURE STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_EMERGENCY\_STATUS | The variable [EMERGENCY STATUS](ms-xhelp:///?Id=beckhoff-5a16-4048-a4a1-4ec68f5b801b) is read. |
| DALIV2\_OPTION\_ALL | All variables are read. |

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
nCurrentShortAddr : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nCurrentShortAddr:** Short address of the current control gear from which variables are being read.

## VAR\_IN\_OUT

```
stCommandBuffer             : ST_DALIV2CommandBuffer;  
arrDALIDeviceSettingsType01 : ARRAY [0..63] OF ST_DALIV2DeviceSettingsType01;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

**arrDALIDeviceSettingsType01:** Reference to an array of 64 elements (see [ST\_DALIV2DeviceSettingsType01](ms-xhelp:///?Id=beckhoff-36a3-4a0e-a772-dde3f5dacd3c)). The settings of each individual DALI control gear are stored in this variable.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
