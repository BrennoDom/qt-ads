# FB_DALIV2SetSettings

## Library
tcplclib_tc2_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
2. [Programming](ms-xhelp:///?Id=beckhoff-1e7b-43d6-a8da-8e0049d24778)
3. [POUs](ms-xhelp:///?Id=beckhoff-3c92-4da6-86d7-db508adfb4f0)
4. [High-Level commands](ms-xhelp:///?Id=beckhoff-19b2-4bc9-a63f-87f11156498e)
5. [Part 102 (control gears)](ms-xhelp:///?Id=beckhoff-9f59-405b-9b5e-1a946f4c914f)
6. [Settings](ms-xhelp:///?Id=beckhoff-6eae-4be8-a988-54f89659a337)
7. FB\_DALIV2SetSettings

# FB\_DALIV2SetSettings

![36771698](/tcplclib_tc2_dali/1033/Images/gif/9007199398067083__en-US__Web.gif)

This function block initializes the variables (MIN LEVEL, MAX LEVEL, FADE TIME ...) of all control gears within a DALI line with the values stored in a structure of type [ST\_DALIV2DeviceSettings](ms-xhelp:///?Id=beckhoff-29fc-4d00-a0de-6236f40865c3).

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The system first checks whether the *bPresent* bit is set in the respective structure (see [ST\_DALIV2DeviceSettings](ms-xhelp:///?Id=beckhoff-29fc-4d00-a0de-6236f40865c3)). If this is the case, all control gear variables that are not read-only are initialized with the respective values of the structure. The structure index here reflects the address of the control gear. In other words, data for the device with short address 0 is located at *arrDALIDeviceSettings[0]*, and so on through to the control gear with short address 63 having its data at *arrDALIDeviceSettings[63]*. If a write error occurs for a device, the *nErrors* element is set for the respective structure without the function block itself switching to error mode. The following table shows which bit is set in the *nErrors* variable when an error occurs during the writing of a variable to a control gear.

| Bit | Error |
| --- | --- |
| 2 | Error whilst writing the variable [POWER ON LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 3 | Error whilst writing the variable [SYSTEM FAILURE LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 4 | Error whilst writing the variable [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 5 | Error whilst writing the variable [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 6 | Error whilst writing the variable [FADE RATE](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 7 | Error whilst writing the variable [FADE TIME](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 9 | Error whilst writing the variables [GROUP 0-7](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) and [GROUP 8-15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |
| 10 | Error whilst writing the variables [SCENE 0](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [SCENE 15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e). |

When the function block has been processed, the *bBusy* output changes from TRUE to FALSE. Processing this function block can take several seconds, depending on how many control gears are attached.

## VAR\_INPUT

```
bStart           : BOOL;  
bCancel          : BOOL;  
eCommandPriority : E_DALIV2CommandPriority := eDALIV2CommandPriorityMiddle;  
nOptions         : DWORD;
```

**bStart:** The function block is activated by a positive edge at this input.

**bCancel:** A rising edge at this input will deactivate the function block and hence abort the initialization of the variable.

**eCommandPriority:** Priority (high, medium or low) with which the command is processed by the library (see [E\_DALIV2CommandPriority](ms-xhelp:///?Id=beckhoff-9fcc-400f-b6a8-66e61c15362f)).

**nOptions:** Options for writing the variables (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DALIV2\_OPTION\_POWER\_ON\_LEVEL | The variable [POWER ON LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_SYSTEM\_FAILURE\_LEVEL | The variable [SYSTEM FAILURE LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_MIN\_LEVEL | The variable [MIN LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_MAX\_LEVEL | The variable [MAX LEVEL](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_FADE\_RATE | The variable [FADE RATE](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_FADE\_TIME | The variable [FADE TIME](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) is initialized. |
| DALIV2\_OPTION\_GROUPS | The variables [GROUP 0-7](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) and [GROUP 8-15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) are initialized. |
| DALIV2\_OPTION\_SCENE\_LEVELS | The variables [SCENE 0](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) to [SCENE 15](ms-xhelp:///?Id=beckhoff-1d79-413e-9ba3-da1d3f8e708e) are initialized. |
| DALIV2\_OPTION\_ALL | All variables are initialized. |
| DALIV2\_OPTION\_PUSH\_DALI\_COMMANDS | The buffer containing the feedback messages from the ballasts is **not** read. Hence, writing becomes faster, but errors are not recognized. |

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
nErrorId          : UDINT;  
nCurrentShortAddr : BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *nErrorId*. Is reset to FALSE by the execution of a command at the inputs.

**nErrorId:** Contains the command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs. (See [error codes](ms-xhelp:///?Id=beckhoff-f739-41c2-8ff6-b502954dc54f))

**nCurrentShortAddr:** Short address of the current control gear from which variables are being read.

## VAR\_IN\_OUT

```
stCommandBuffer       : ST_DALIV2CommandBuffer;  
arrDALIDeviceSettings : ARRAY [0..63] OF ST_DALIV2DeviceSettings;
```

**stCommandBuffer:** Reference to the internal structure for communication with the function block [FB\_KL6811Communication()](ms-xhelp:///?Id=beckhoff-a20b-403b-a517-3ca6697b63e6) (KL6811) or [FB\_KL6821Communication()](ms-xhelp:///?Id=beckhoff-24f5-4307-8c46-040081763250) (KL6821).

**arrDALIDeviceSettings:** Reference to an array of 64 elements (see [ST\_DALIV2DeviceSettings](ms-xhelp:///?Id=beckhoff-29fc-4d00-a0de-6236f40865c3)). The settings of each individual DALI control gear are stored in this variable.

## Requirements

| Development environment | required PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DALI from v3.4.3.0 |

[TwinCAT 3 | PLC Library: Tc2\_DALI](ms-xhelp:///?Id=beckhoff-bad6-4627-b8ac-544f0eee130c)
