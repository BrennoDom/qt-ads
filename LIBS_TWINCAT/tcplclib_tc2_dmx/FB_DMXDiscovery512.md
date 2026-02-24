# FB_DMXDiscovery512

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXDiscovery512

![21736599](/tcplclib_tc2_dmx/1033/Images/gif/9007199753485579__en-US__Web.gif)

This function block searches for up to 512 DMX devices and automatically sets the start address (optional). The most important information for the devices found is displayed in a structure.

## VAR\_INPUT

```
bStart    : BOOL;  
dwOptions : DWORD;
```

**bStart:** The block is activated by a positive edge at this input.

**dwOptions:** Options (see table). The individual constants must be linked with OR operators.

| Constant | Description |
| --- | --- |
| DMX\_OPTION\_COMPLETE\_NEW\_DISCOVERY | All DMX devices are taken into account. |
| DMX\_OPTION\_SET\_START\_ADDRESS | The start address is set for all DMX devices that are found. Consecutive, starting with 1. |
| DMX\_OPTION\_OPTICAL\_FEEDBACK | When a DMX device is found, the function IDENTIFY\_DEVICE is called for two seconds. |

## VAR\_OUTPUT

```
bBusy                    : BOOL;  
bError                   : BOOL;  
udiErrorId               : UDINT;  
uliLowerBoundSearchUID   : T_ULARGE_INTEGER;  
uliUpperBoundSearchUID   : T_ULARGE_INTEGER;  
arrDMXDeviceInfoList     : ARRAY [1..512] OF ST_DMXDeviceInfo;  
uiNextDMX512StartAddress : UINT;  
iFoundedDevices          : INT;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**uliLowerBoundSearchUID:** During the search, the lower search address is sent to this output.

**uliUpperBoundSearchUID:** During the search, the upper search address is sent to this output.

**arrDMXDeviceInfoList:** Array with the main information of the found DMX devices (see [ST\_DMXDeviceInfo](ms-xhelp:///?Id=beckhoff-e7d8-4212-bec4-dbb924043926)).

**uiNextDMX512StartAddress:** If the DMX\_OPTION\_SET\_START\_ADDRESS option is activated, then the start address that will be assigned to the next DMX device will be displayed at this output.

**iFoundedDevices:** During the search, the current number of devices found will be sent to this output.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
