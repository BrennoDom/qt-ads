# FB_DMXGetStatusMessages

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXGetStatusMessages

![60507121](/tcplclib_tc2_dmx/1033/Images/gif/2746035979__en-US__Web.gif)

This function block collects the status or error information of an DMX device.

## VAR\_INPUT

```
bStart                     : BOOL;  
wDestinationManufacturerId : WORD;  
dwDestinationDeviceId      : DWORD;  
byPortId                   : BYTE;  
eStatusType                : E_DMXStatusType := eDMXStatusTypeNone;  
dwOptions                  : DWORD := 0;
```

**bStart:** The block is activated by a positive edge at this input.

**wDestinationManufacturerId:** Unique manufacturer Id of the DMX device.

**dwDestinationDeviceId:** Unique device Id of the DMX device.

**byPortId:** Channel within the addressed DMX device. Sub-devices are addressed through the Port Id. The root device always has the Port Id 0.

**eStatusType:** Status type (see [E\_DMXStatusType](ms-xhelp:///?Id=beckhoff-ba0b-429d-b6b2-842aadc2fa4b)).

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bBusy             : BOOL;  
bError            : BOOL;  
udiErrorId        : UDINT;  
arrStatusMessages : ARRAY [0..24] OF ST_DMXStatusMessage;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE (see [error codes](ms-xhelp:///?Id=beckhoff-7467-42b5-96f4-eb6c6efdbb2f)).

**arrStatusMessages:** Once command execution is complete (*bBusy* is FALSE), all status/error information is available at this output (see [ST\_DMXStatusMessage](ms-xhelp:///?Id=beckhoff-12ba-425a-b3b0-894a7e6e012d)).

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
