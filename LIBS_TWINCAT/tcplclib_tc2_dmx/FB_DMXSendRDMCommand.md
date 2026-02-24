# FB_DMXSendRDMCommand

## Library
tcplclib_tc2_dmx

## Category
Motion Control

# FB\_DMXSendRDMCommand

![61411666](/tcplclib_tc2_dmx/1033/Images/gif/2742470283__en-US__Web.gif)

This function block is for the general sending of a RDM command, defined by command number and, if necessary, transfer parameter.

## VAR\_INPUT

```
bStart                     : BOOL;  
wDestinationManufacturerId : WORD;  
dwDestinationDeviceId      : DWORD;  
byPortId                   : BYTE;  
wSubDevice                 : WORD;  
eCommandClass              : E_DMXCommandClass;  
eParameterId               : E_DMXParameterId;  
byParameterDataLength      : BYTE;  
arrParameterData           : ARRAY [0..255] OF BYTE;  
dwOptions                  : DWORD := 0;
```

**bStart:** The block is activated by a positive edge at this input.

**wDestinationManufacturerId:** Unique manufacturer Id of the DMX device.

**dwDestinationDeviceId:** Unique device Id of the DMX device.

**byPortId:** Channel within the addressed DMX device. Sub-devices are addressed through the Port Id. The root device always has the Port Id 0.

**wSubDevice:** Sub-devices should be used in devices with a recurring number of modules, such as a dimmer rack. The sub-devices input enables parameter messages to be sent to a particular module within the device, in order to read or set module properties.

**eCommandClass:** Command Class (CC) indicates the message action (see [E\_DMXCommandClass](ms-xhelp:///?Id=beckhoff-a2f8-4b3f-a0fb-df7e418aa576)).

**eParameterId:** Parameter Id is a 16-bit number, which identifies a particular type of parameter data (see [E\_DMXParameterId](ms-xhelp:///?Id=beckhoff-1b50-40f9-ab12-11814105381d)).

**byParameterDataLength:** The parameter data length (PDL) is the preceding number of slots, included in the parameter data area. If this input is 0x00, there is no parameter data to follow.

**arrParameterData:** Parameter data of variable length. The format of the content depends on the PID.

**dwOptions:** Options (currently not used).

## VAR\_OUTPUT

```
bBusy                  : BOOL;  
bError                 : BOOL;  
udiErrorId             : UDINT;  
byResponseMessageCount : BYTE;  
byResponseDataLength   : BYTE;  
arrResponseData        : ARRAY [0..255] OF BYTE;
```

**bBusy:** When the function block is activated the output is set, and it remains active until execution of the command has been completed.

**bError:** This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in *udiErrorId*. Only valid if *bBusy* is FALSE.

**udiErrorId:** Contains the command-specific error code of the most recently executed command. Only valid if *bBusy* is FALSE. See Error codes.

**byResponseMessageCount:** This output indicates that the DMX slave contains further messages. The RDM command Get: QUEUES\_MESSAG is used to read these messages.

**byResponseDataLength:** Contains the number of bytes returned by the RDM command.

**arrResponseData:** This output contains the data of the response from the RDM command. The length is variable, and the data format depends on the RDM command.

## VAR\_IN\_OUT

```
stCommandBuffer : ST_DMXCommandBuffer;
```

**stCommandBuffer:** Reference to the structure for communication (buffer) with the block [FB\_EL6851Communication()](ms-xhelp:///?Id=beckhoff-e0f5-4e32-bcef-0f966cb91ec9) (see [ST\_DMXCommandBuffer](ms-xhelp:///?Id=beckhoff-b046-4e82-a9e9-879db0644a35)).

## **Requirements**

| Development environment | required TC3 PLC library |
| --- | --- |
| TwinCAT from v3.1.4020.14 | Tc2\_DMX from 3.5.3.0 |
