# FB_EcCoeSdoReadEx

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [CoE interface](ms-xhelp:///?Id=beckhoff-97aa-4270-a785-40e41b9c6021)
3. FB\_EcCoeSdoReadEx

# FB\_EcCoeSdoReadEx

![33142240](/tcplclib_tc2_ethercat/1033/Images/png/57147019__Web.png)

The `FB_EcCoeSdoReadEx` function block allows data to be read from an object dictionary of an EtherCAT slave through an SDO (Service Data Object) access. This requires the slave to have a mailbox and to support the “CANopen over EtherCAT” (CoE) protocol. The nSubIndex and nIndex parameters allow the object that is to be read to be selected. The parameter with subelements can be read via `bCompleteAccess := TRUE`.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId; (* AmsNetId of the EtherCAT master device.*)  
    nSlaveAddr : UINT; (* Address of the slave device.*)  
    nSubIndex  : BYTE; (* CANopen Sdo subindex.*)  
    nIndex     : WORD; (* CANopen Sdo index.*)  
    pDstBuf    : PVOID; (* Contains the address of the buffer for the received data. *)  
    cbBufLen   : UDINT; (* Contains the max. number of bytes to be received. *)  
    bExecute   : BOOL; (* Function block execution is triggered by a rising edge at this input.*)  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;(* States the time before the function is cancelled. *)  
    bCompleteAccess : BOOL; (* access complete object*)  
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

**bCompleteAccess**: If bCompleteAccess is set, the whole parameter can be read in a single access.

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

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
