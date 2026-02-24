# FB_SoEWrite_ByDriveRef

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [SoE interface](ms-xhelp:///?Id=beckhoff-a221-4618-8618-6d101e603a71)
3. FB\_SoEWrite\_ByDriveRef

# FB\_SoEWrite\_ByDriveRef

![43252647](/tcplclib_tc2_ethercat/1033/Images/png/57239819__Web.png)

The function block `FB_SoeWrite_ByRef` can be used to write drive parameters by means of the “Servo drive profile over EtherCAT (SoE)” protocol. To this end the slave must have a mailbox and support the SoE protocol. The drive parameter to be written is specified with the parameters nIdn (identification number), nElement and stDriveRef.

The global variable `bSeqReadDrvAttrAndValue := TRUE` from the Tc2\_EtherCAT library can be used to enforce sequential access to attribute and value. The default value of this variable is FALSE. Devices of the AX5xxx series enable parallel and sequential access to attribute and value. For third-party devices it may be necessary to separate access to attribute and value, which overall slows down access by several cycles.

## VAR\_INPUT

```
VAR_INPUT  
    stDriveRef : ST_DriveRef; (* contains sNetID of EcMaster, nSlaveAddr of EcDrive, nDriveNo of EcDrive, either preset or read from NC *)  
    nIdn       : WORD; (* SoE IDN: e.g. "S_0_IDN + 1" for S-0-0001 or "P_0_IDN + 23" for P-0-0023*)  
    nElement   : BYTE; (* SoE element.*)  
    pSrcBuf    : PVOID; (* Contains the address of the buffer containing the data to be send. *)  
    cbBufLen   : UDINT; (* Contains the max. number of bytes to be received. *)  
    bExecute   : BOOL; (* Function block execution is triggered by a rising edge at this input.*)  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;(* States the time before the function is cancelled. *)  
END_VAR
```

**stDriveRef**: The reference to the drive can be linked directly to the PLC in the System Manager. To this end an instance of ST\_PlcDriveRef must be used and the NetID of the Byte array converted to a string. (type: ST\_DriveRef)

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

**pSrcBuf**: Address (pointer) to the send buffer.

**cbBufLen:** Maximum available buffer size (in bytes) for the data to be read.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    iAdsErrId    : UINT;  
    iSercosErrId : UINT;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**iAdsErrId**: In the case of a set bError output returns the ADS error code of the last executed command.

**iSercosErrId**: In the case of a set bError output returns the Sercos error of the last executed command:

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
