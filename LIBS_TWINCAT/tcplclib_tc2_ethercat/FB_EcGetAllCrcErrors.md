# FB_EcGetAllCrcErrors

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetAllCrcErrors

# FB\_EcGetAllCrcErrors

![37903130](/tcplclib_tc2_ethercat/1033/Images/png/57172619__Web.png)

The `FB_EcGetAllSlaveCrcErrors` function block allows the CRC error counters of all the slaves connected to the master to be read. The CRC errors at the individual ports of a slave are added.

In order to read the CRC errors of the individual ports (A, B and C) of a slave, it is necessary to call the [FB\_EcGetSlaveCrcError](ms-xhelp:///?Id=beckhoff-2448-4a39-9d22-5890910b2c3d) function block.

In order to read the CRC errors of the individual ports (A, B, C and D) of a slave, it is necessary to call the [FB\_EcGetSlaveCrcErrorEx](ms-xhelp:///?Id=beckhoff-1eaf-4a61-ae0f-f073ec354615) function block.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId       : T_AmsNetId;  
    pCrcErrorBuf : POINTER TO ARRAY[0..EC_MAX_SLAVES] OF DWORD;  
    cbBufLen     : UDINT;      
    bExecute     : BOOL;   
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**pCrcErrorBuf:** The address of an array of DWORDs into which the CRC error counter is to be written.

**cbBufLen:** Maximum available buffer size (in bytes) for the data to be read.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy   : BOOL;  
    bError  : BOOL;  
    nErrId  : UDINT;  
    nSlaves : UINT;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set. Error 1798 (0x706) indicates a null pointer at the buffer address. Error 1797 (0x705) indicates inadequate buffer size.

**nSlaves**: The number of slaves connected to the master.

## Example of an implementation in ST:

```
PROGRAM TEST_GetAllSlaveCrcErrors  
VAR  
    fbGetAllSlaveCrcErrors : FB_EcGetAllSlaveCrcErrors;  
    sNetId                 : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute               : BOOL;  
    crcErrors              : ARRAY[0..255] OF DWORD;  
    nSlaves                : UINT := 0;  
    bError                 : BOOL;  
    nErrId                 : UDINT;  
END_VAR  
  
fbGetAllSlaveCrcErrors(sNetId:= sNetId, pCrcErrorBuf := ADR(crcErrors), cbBufLen:= SIZEOF(crcErrors), bExecute:=bExecute);  
nSlaves := fbGetAllSlaveCrcErrors.nSlaves;  
bError := fbGetAllSlaveCrcErrors.bError;  
nErrId := fbGetAllSlaveCrcErrors.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
