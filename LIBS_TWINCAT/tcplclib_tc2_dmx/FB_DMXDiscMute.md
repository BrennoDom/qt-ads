# FB_DMXDiscMute

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXDiscMute

![35356632](/tcplclib_tc2_dmx/1033/Images/gif/9007199309954443__en-US__Web.gif)

This function block sets the mute flag of a DMX device. The mute flag specifies whether a DMX device reacts to the [FB\_DMXDiscUniqueBranch()](ms-xhelp:///?Id=beckhoff-7c3d-41e7-af6c-f64c5237278d) command (mute flag is not set) or not (mute flag is set).

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The *wDestinationManufacturerId* and *dwDestinationDeviceId* inputs address the DMX device. The *byPortId* input defines the channel within the addressed DMX device. If the execution of the command has been completed, the *bBusy* output goes back to FALSE. The *bError*, *udiErrorId* and *wControlField* outputs can now be processed. Further positive edges at the *bStart* input will be ignored as long as the block is active (*bBusy* is TRUE).

## VAR\_INPUT

```
bStart                     : BOOL;  
wDestinationManufacturerId : WORD;  
dwDestinationDeviceId      : DWORD;  
byPortId                   : BYTE;  
dwOptions                  : DWORD := 0;
```

**bStart:** The command is started by a positive edge at this input.

**wDestinationManufacturerId:** Unique manufacturer Id of the DMX device (for details, see DMX device address).

**dwDestinationDeviceId:** Unique device Id of the DMX device (for details, see DMX device address).

**byPortId:** Channel within the addressed DMX device. Sub-devices are addressed through the Port Id. The root device always has the Port Id 0.

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bBusy         : BOOL;  
bError        : BOOL;  
udiErrorId    : UDINT;  
wControlField : WORD;
```

**bBusy:** When the block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**wControlField:** If the execution of the command has been completed (*bBusy* is FALSE), then further information about the DMX device will be output at this output. The meaning of the individual bits is defined as follows:

| Bit | Description |
| --- | --- |
| 0 - Managed Proxy Flag | This bit is set if the DMX device is a proxy device. |
| 1 - Sub-Device Flag | This bit is set if the DMX device supports sub-devices. |
| 2 - Boot-Loader Flag | This bit is set if the DMX device cannot receive any commands (e.g. whilst the firmware is being loaded). |
| 3 - Proxied Device Flag | This bit is set if the response was transmitted by a proxy device. |
| 4 - 15 | Reserve (always 0). |

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
