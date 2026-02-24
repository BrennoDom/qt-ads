# FB_EcCoeSdoRead

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [CoE interface](ms-xhelp:///?Id=beckhoff-97aa-4270-a785-40e41b9c6021)
3. FB\_EcCoeSdoRead

# FB\_EcCoeSdoRead

![63334794](/tcplclib_tc2_ethercat/1033/Images/png/57143819__Web.png)

The `FB_EcCoeSdoRead` function block allows data to be read from an object dictionary of an EtherCAT slave through an SDO (Service Data Object) access. This requires the slave to have a mailbox and to support the “CANopen over EtherCAT” (CoE) protocol. The nSubIndex and nIndex parameters allow the object that is to be read to be selected. The function block [FB\_EcCoeSdoReadEx](ms-xhelp:///?Id=beckhoff-5d7e-4a37-b3a4-42d70075341a) must be used for access to the complete parameter, including subelements.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;   
    nSlaveAddr : UINT;   
    nSubIndex  : BYTE;   
    nIndex     : WORD;  
    pDstBuf    : PVOID;   
    cbBufLen   : UDINT;   
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave to which the SDO upload command should be sent.

**nSubIndex:** Subindex of the object that is to be read.

**nIndex:** Index of the object that is to be read.

**pDstBuf:** Address (pointer) to the receive buffer.

**cbBufLen:** Maximum available buffer size (in bytes) for the data to be read.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

## Example of an implementation in ST:

```
PROGRAM TEST_SdoRead  
VAR  
    fbSdoRead  : FB_EcCoESdoRead;  
    sNetId     : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute   : BOOL;  
    nSlaveAddr : UINT := 1006;  
    nIndex     : WORD := 16#1018;  
    nSubIndex  : BYTE :=1;  
    vendorId   : UDINT;  
    bError     : BOOL;  
    nErrId     : UDINT;  
END_VAR  
  
fbSdoRead(sNetId:= sNetId,nSlaveAddr :=nSlaveAddr, nIndex:=nIndex, nSubIndex :=nSubIndex, pDstBuf:= ADR(vendorId), cbBufLen:=SIZEOF(vendorId),bExecute:=bExecute);  
bError:=fbSdoRead.bError;  
nErrId:=fbSdoRead.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
