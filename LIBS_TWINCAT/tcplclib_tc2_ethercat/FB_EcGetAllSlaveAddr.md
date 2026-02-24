# FB_EcGetAllSlaveAddr

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetAllSlaveAddr

# FB\_EcGetAllSlaveAddr

![63863782](/tcplclib_tc2_ethercat/1033/Images/png/57169419__Web.png)

The `FB_EcGetAllSlaveAddr` function block allows the addresses of all the slaves connected to the master to be read. When the call is successful, the buffer passed in the parameter pAddrBuf contains the addresses of all the slaves as an array of UINTs.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;  
    pAddrBuf : POINTER TO ARRAY[0..EC_MAX_SLAVES] OF UINT;   
    cbBufLen : UDINT   
    bExecute : BOOL;   
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**pAddrBuf:** Address of an array of UINTs into which the addresses of the individual slaves are to be written.

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
PROGRAM TEST_GetAllSlaveAddresses  
VAR  
    fbGetAllSlaveAddr : FB_EcGetAllSlaveAddr;  
    sNetId            : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute          : BOOL;  
    slaveAddresses    : ARRAY[0..255] OF UINT;  
    nSlaves           : UINT := 0;  
    bError            : BOOL;  
    nErrId            : UDINT;  
END_VAR  
  
fbGetAllSlaveAddr(sNetId:= sNetId,pAddrBuf := ADR(slaveAddresses), cbBufLen:= SIZEOF(slaveAddresses), bExecute:=bExecute);  
nSlaves := fbGetAllSlaveAddr.nSlaves;  
bError := fbGetAllSlaveAddr.bError;  
nErrId := fbGetAllSlaveAddr.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
