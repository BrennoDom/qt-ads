# FB_DMXDiscUniqueBranch

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXDiscUniqueBranch

![49774232](/tcplclib_tc2_dmx/1033/Images/gif/9007199309957643__en-US__Web.gif)

This function block queries whether DMX devices are located within a certain address range. This command is used for the discovery of the connected DMX devices.

Applying a positive edge to the *bStart* input starts the function block, and the *bBusy* output goes TRUE. The inputs *wLowerBoundManufacturerId*, *dwLowerBoundDeviceId*, *wUpperBoundManufacturerId* and *dwUpperBoundDeviceId* define the address range in which DMX devices are searched. The *byPortId* input defines the channel within the addressed DMX device. If the execution of the command has been completed, the *bBusy* output goes back to FALSE. The *bError*, *udiErrorId*, *wReceivedManufacturerId* and *dwReceivedDeviceId* outputs can now be evaluated. Further positive edges at the *bStart* input will be ignored as long as the function block is active (*bBusy* is TRUE).

If there is only one DMX device in the defined address range, then the 48-bit UID of the DMX device will be returned via the *wReceivedManufacturerId* and *dwReceivedDeviceId* outputs. If no DMX devices are found in this range, the output *bError* is TRUE and *udiErrorId* is 0x8002 (no response from DMX device). If two or more DMX devices are found in the address range, *bError* is TRUE and *udiError* contains an 0x8006 entry (checksum error).

## VAR\_INPUT

```
bStart                    : BOOL;  
byPortId                  : BYTE;  
wLowerBoundManufacturerId : WORD;  
dwLowerBoundDeviceId      : DWORD;  
wUpperBoundManufacturerId : WORD;  
dwUpperBoundDeviceId      : DWORD;  
dwOptions                 : DWORD := 0;
```

**bStart:** The command is started by a positive edge at this input.

**byPortId:** Channel within the addressed DMX device. Sub-devices are addressed through the Port Id. The root device always has the Port Id 0.

**wLowerBoundManufacturerId:** Unique manufacturer Id from the lower address range.

**dwLowerBoundDeviceId:** Unique device Id from the lower address range.

**wUpperBoundManufacturerId:** Unique manufacturer Id from the upper address range.

**dwUpperBoundDeviceId:** Unique device Id from the upper address range.

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bBusy                   : BOOL;  
bError                  : BOOL;  
udiErrorId              : UDINT;  
wReceivedManufacturerId : WORD;  
dwReceivedDeviceId      : DWORD;
```

**bBusy:** When the block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**wReceivedManufacturerId:** If the execution of the command has been completed (*bBusy* is FALSE), then the state of identification of the DMX device is displayed at this output.

**dwReceivedDeviceId:** If the execution of the command has been completed (*bBusy* is FALSE), then the state of identification of the DMX device is displayed at this output.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
