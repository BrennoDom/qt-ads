# FB_CoERead_ByDriveRef

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [CoE interface](ms-xhelp:///?Id=beckhoff-97aa-4270-a785-40e41b9c6021)
3. FB\_CoERead\_ByDriveRef

# FB\_CoERead\_ByDriveRef

![1501966](/tcplclib_tc2_ethercat/1033/Images/png/260286603__Web.png)

The function block `FB_CoERead_ByDriveRef` can be used to read drive parameters by means of the “CANopen over EtherCAT (CoE)” protocol. This requires the slave to have a mailbox and to support the “CANopen over EtherCAT” (CoE) protocol. The nSubIndex and nIndex parameters allow the object that is to be read to be selected. Via `bCompleteAccess := TRUE` the parameter can be read with sub-elements.

```
VAR_INPUT  
    stDriveRef         :    ST_DriveRef; (*Contains sNetID of EcMaster, nSlaveAddr of EcDrive, nDriveNo of EcDrive, either preset or read from NC*)  
    nIndex             :    WORD; (*SoE IDN: e.g. “S_0_IDN+1” for S-0-0001 or “P_0_IDN+23” for P-0-0023*)  
    nSubIndex          :    BYTE;   
    pDstBuf            :    PVOID; (*Contains the address of the buffer for the received data*)  
    cbBufLen           :    UDINT; (*Contains the max. number of bytes to be received*)   
    bExecute           :    BOOL; (*Function block execution is triggered by a rising edge at this input*)  
    tTimeout           :    TIME; (*States the time before the function is cancelled*)  
    bCompleteAccess    :    BOOL;  
END_VAR
```

**stDriveRef**: Structure containing the AMS network ID of the EtherCAT master device and the address of the slave device. The reference to the drive can be linked directly to the PLC in the System Manager. To this end an instance of ST\_PlcDriveRef must be used and the NEtID of the Byte array converted to a string.

**nIndex**: Index of the object that is to be read.

**nSubIndex**: Subindex of the object that is to be read.

**pDstBUF**: Address (pointer) to the receive buffer.

**cbBUFLen**: Maximum available buffer size (in bytes) for the data to be read.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**bCompleteAccess**: If bCompleteAccess is set, the whole parameter can be read in a single access.

```
VAR_OUTPUT  
    bBusy         : BOOL;  
    bError        : BOOL;  
    iAdsErrId     : UINT;  
    iCANopenErrId : UINT;      
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iCANopenErrId:** Returns the CANopen error code if the bError output is set.

## Example of an implementation in ST:

```
PROGRAM MAIN  
VAR  
    fbCoERead       : FB_CoERead_ByDriveRef;  
    stDriveRef      : ST_DriveRef;   
    nIndex          : WORD := 16#1018;  
    nSubIndex       : BYTE := 1;   
    bExecute        : BOOL := TRUE;  
    tTimeout        : TIME := T#5S;  
    bCompleteAccess : BOOL := TRUE;  
    vendorId        : UDINT;  
    bError          : BOOL;  
    nAdsErrId       : UDINT;  
    nCANopenErrId   : UDINT;  
END_VAR  
  
fbCoERead(  
    stDriveRef:= stDriveRef,   
    nIndex:= nIndex,   
    nSubIndex:= nSubIndex,   
    pDstBuf:= ADR(vendorId),   
    cbBufLen:= SIZEOF(vendorId),   
    bExecute:= bExecute,   
    tTimeout:= tTimeout,   
    bCompleteAccess:= bCompleteAccess,   
);  
  
IF NOT fbCoERead.bBusy THEN  
    bError:=fbCoERead.bError;  
    nAdsErrId:=fbCoERead.iAdsErrId;  
    nCANopenErrId:=fbCoERead.iCANopenErrId;  
    bExecute := FALSE;  
    fbCoERead(bExecute := bExecute);  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
