# FB_EcGetSlaveCrcError

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetSlaveCrcError

# FB\_EcGetSlaveCrcError

![3791404](/tcplclib_tc2_ethercat/1033/Images/png/57175819__Web.png)

The function block `FB_EcGetSlaveCrcError` allows the CRC error counters of the individual ports (A, B and C) of a slave to be read. If the call is successful, the output variable crcError, whose type is `ST_EcCrcError`, contains the requested CRC error counter.

The function block FB\_EcGetSlaveCrcError can only be used with slaves with up to 3 ports (e.g. EK1100). The function block `FB_EcGetSlaveCrcErrorEx` can also be used with slaves with up to 4 ports (e.g. EK1122).

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    nSlaveAddr : UINT;       
    bExecute   : BOOL;   
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave whose CRC error counter is to be read

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    crcError : ST_EcCrcError;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**crcError**: [CRC error](ms-xhelp:///?Id=beckhoff-f195-46ff-b9af-37f1fc01d16e) counters for the individual ports.

## Example of an implementation in ST:

```
PROGRAM TEST_GetSlaveCrcError  
VAR  
    fbGetSlaveCrcError : FB_EcGetSlaveCrcError;  
    sNetId : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute : BOOL;  
    crcError : ST_EcCrcError;  
    nSlaveAddr : UINT := 1001;  
    bError : BOOL;  
    nErrId : UDINT;  
END_VAR  
  
fbGetSlaveCrcError(sNetId:= sNetId, nSlaveAddr:= nSlaveAddr, bExecute:=bExecute);  
crcError := fbGetSlaveCrcError.crcError;  
bError := fbGetSlaveCrcError.bError;  
nErrId := fbGetSlaveCrcError.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
