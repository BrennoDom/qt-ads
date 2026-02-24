# FB_EcSoeRead

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [SoE interface](ms-xhelp:///?Id=beckhoff-a221-4618-8618-6d101e603a71)
3. FB\_EcSoeRead

# FB\_EcSoeRead

![11842506](/tcplclib_tc2_ethercat/1033/Images/png/57233419__Web.png)

The function block `FB_EcSoeRead` can be used to read drive parameters by means of the “Servo drive profile over EtherCAT (SoE)” protocol. To this end the slave must have a mailbox and support the SoE protocol. The drive parameter to be read is specified with the parameters nIdn (identification number), nElement and nDriveNo.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;   
    nSlaveAddr : UINT;   
    nSubIndex  : BYTE;   
    nIdn       : WORD;  
    nElement   : BYTE;  
    nDriveNo   : BYTE;  
    bCommand   : BOOL  
    pDstBuf    : PVOID;   
    cbBufLen   : UDINT;   
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave to which the SoE read command is to be sent.

**nIdn:** Identification number of the parameter to be read.

**nElement:** Element number of the parameter to be read. The following values are permitted:

| Value | Description |
| --- | --- |
| 0x01 | Data status |
| 0x02 | Name (read only) |
| 0x04 | Attribute |
| 0x08 | Unit |
| 0x10 | Minimum |
| 0x20 | Maximum |
| 0x40 | Value |
| 0x80 | Default |

**nDriveNo:** Drive number.

**bCommand:** This parameter should be set if internal command execution is to be used.

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
PROGRAM TEST_SoERead  
VAR  
    fbSoERead   : FB_EcSoERead;  
    sNetId      : T_AmsNetId:= '172.16.2.131.2.1';  
    bExecute    : BOOL;  
    nSlaveAddr  : UINT := 1006;  
    nIdn        : WORD := 15;  
    nElement    : BYTE := 0;  
    nDriveNo    : BYTE := 0;  
    bCommand    : BOOL := FALSE;  
    val         : UINT;  
    bError      : BOOL;  
    nErrId      : UDINT;  
END_VAR  
  
fbSoERead(sNetId:= sNetId,nSlaveAddr :=nSlaveAddr, nIdn := nIdn, nElement:=nElement, nDriveNo := nDriveNo, bCommand:=bCommand, pDstBuf:= ADR(val), cbBufLen:=SIZEOF(val),bExecute:=bExecute);  
bError := fbSoERead.bError;  
nErrId := fbSoERead.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
