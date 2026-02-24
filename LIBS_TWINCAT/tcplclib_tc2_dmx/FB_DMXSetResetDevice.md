# FB_DMXSetResetDevice

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXSetResetDevice

![26298136](/tcplclib_tc2_dmx/1033/Images/gif/9007199309970443__en-US__Web.gif)

This function block activates a reset in a DMX device.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The *wDestinationManufacturerId* and *dwDestinationDeviceId* inputs address the DMX device. The *byPortId* input defines the channel within the addressed DMX device. If the execution of the command has been completed, the *bBusy* output goes back to FALSE. The *bError* and *udiErrorId* outputs can now be processed. Further positive edges at the *bStart* input will be ignored as long as the block is active (*bBusy* is TRUE).

## VAR\_INPUT

```
bStart                     : BOOL;  
wDestinationManufacturerId : WORD;  
dwDestinationDeviceId      : DWORD;  
byPortId                   : BYTE;  
eResetDeviceType           : E_DMXResetDeviceType := eDMXResetDeviceTypeWarm;  
dwOptions                  : DWORD := 0;
```

**bStart:** The command is started by a positive edge at this input.

**wDestinationManufacturerId:** Unique manufacturer Id of the DMX device (for details, see DMX device address).

**dwDestinationDeviceId:** Unique device Id of the DMX device (for details, see DMX device address).

**byPortId:** Channel within the addressed DMX device. Sub-devices are addressed through the Port Id. The root device always has the Port Id 0.

**eResetDeviceType:** This specifies whether a warm start (eDMXResetDeviceTypeWarm) or a cold start (eDMXResetDeviceTypeCold) is to be performed. No other values are possible for this input (see [E\_DMXResetDeviceType](ms-xhelp:///?Id=beckhoff-23ac-4aae-9417-156b6a812a3b)).

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bBusy      : BOOL;  
bError     : BOOL;  
udiErrorId : UDINT;
```

**bBusy:** When the block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
