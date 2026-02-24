# FB_DMXGetProductDetailIdList

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXGetProductDetailIdList

![55167604](/tcplclib_tc2_dmx/1033/Images/gif/2744869899__en-US__Web.gif)

This function block queries the categories to which the DMX device belongs.

RDM defines different device categories. Each DMX device can be assigned to up to 6 categories. The assignment is done by the device manufacturer and cannot be changed via RDM.

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
bBusy             : BOOL;  
bError            : BOOL;  
udiErrorId        : UDINT;  
arrProductDetails : ARRAY [1..6] OF E_DMXProductDetail;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**arrProductDetails:** Contains the list with up to 6 device categories (see [E\_DMXProductDetail](ms-xhelp:///?Id=beckhoff-cfc1-432d-ae14-d5f297656c80)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
