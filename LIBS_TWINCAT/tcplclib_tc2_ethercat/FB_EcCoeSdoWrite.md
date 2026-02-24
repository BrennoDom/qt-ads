# FB_EcCoeSdoWrite

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [CoE interface](ms-xhelp:///?Id=beckhoff-97aa-4270-a785-40e41b9c6021)
3. FB\_EcCoeSdoWrite

# FB\_EcCoeSdoWrite

![29844704](/tcplclib_tc2_ethercat/1033/Images/png/57150219__Web.png)

The `FB_EcCoeSdoWrite` function block permits an object from the object directory of an EtherCAT slave to be written by means of an SDO download. This requires the slave to have a mailbox and to support the “CANopen over EtherCAT” (CoE) protocol. The nSubIndex and nIndex parameters allow the object that is to be written to be selected. The function block [FB\_EcCoeSdoWriteEx](ms-xhelp:///?Id=beckhoff-5dfd-4974-858e-6b9d41d1270c) must be used for access to the complete parameter, including subelements.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;   
    nSlaveAddr : UINT;   
    nSubIndex  : BYTE;   
    nIndex     : WORD;  
    pSrcBuf    : PVOID;   
    cbBufLen   : UDINT;   
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave to which the SDO download command should be sent.

**nSubIndex:** Subindex of the object that is supposed to be written.

**nIndex:** Index of the object that is supposed to be written.

**pSrcBuf:** Address (pointer) to the send buffer.

**cbBufLen:** Number of date to be sent in bytes.

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
PROGRAM TEST_SdoWrite  
  
VAR  
    fbSdoWrite : FB_EcCoESdoWrite;  
    sNetId     : T_AmsNetId := '172.16.2.131.2.1'; (* NetId of EtherCAT Master *)  
    nSlaveAddr : UINT := 1005; (* Port Number of EtherCAT Slave *)  
    nIndex     : WORD := 16#4062; (* CoE Object Index *)  
    nSubIndex  : BYTE := 1; (* Subindex of CoE Object *)  
    nValue     : UINT := 2; (* variable to be written to the CoE Object *)  
    bExecute   : BOOL; (* rising edge starts writing to the CoE Object *)  
    bError     : BOOL;  
    nErrId     : UDINT;  
END_VAR  
  
  
fbSdoWrite(  
    sNetId     := sNetId,  
    nSlaveAddr := nSlaveAddr,  
    nIndex     := nIndex,  
    nSubIndex  := nSubIndex,  
    pSrcBuf    := ADR(nValue),  
    cbBufLen   := SIZEOF(nValue),  
    bExecute   := bExecute  
);  
  
  
IF NOT fbSdoWrite.bBusy THEN  
    bExecute := FALSE;  
    IF NOT fbSdoWrite.bError THEN   
        (* write successful *)  
        bError := FALSE;  
        nErrId := 0;  
    ELSE   
        (* write failed *)  
        bError := fbSdoWrite.bError;  
        nErrId := fbSdoWrite.nErrId;  
    END_IF  
  
    fbSdoWrite(bExecute := FALSE);  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
