# FB_EcLogicalReadCmd

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Commands](ms-xhelp:///?Id=beckhoff-d66b-4ed1-85c6-c6f6b1a5e763)
3. FB\_EcLogicalReadCmd

# FB\_EcLogicalReadCmd

![13251620](/tcplclib_tc2_ethercat/1033/Images/png/57163019__Web.png)

The master sends a logical EtherCAT read command (LRD) with the function block `FB_EcLogicalReadCmd`. In each slave, local address ranges (DPRAM) can be mapped to global logical address ranges. This command therefore addresses all EtherCAT slaves, which have mapping configured for the selected logical address range.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;   
    logAddr  : UDINT;   
    len      : UDINT;  
    pDstBuf  : PVOID;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**logAddr:** Logical address.

**len:** Number of bytes to be read.

**pDstBuf:** Address (pointer) to the receive buffer.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    wkc    : UINT;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**wkc:** The working counter is incremented by each EtherCAT slave that has processed this command successfully. If only one EtherCAT slave was addressed by this command, this value should therefore be 1.

## Example of an implementation in ST:

```
PROGRAM Test_LogicalReadCmd  
VAR  
    fbReadCmd : FB_EcLogicalReadCmd;  
    bExecute  : BOOL;  
    value     : USINT;  
    logAddr   : UDINT :=16#10000;  
    sNetId    : T_AmsNetId:='192.168.1.5.3.1';  
    wkc       : UINT;  
    bError    : BOOL;  
    nErrId    : UDINT;  
END_VAR  
  
fbReadCmd (sNetId:=sNetID, logAddr:=logAddr, LEN := SIZEOF(value), pDstBuf:=ADR(value), bExecute:=bExecute);  
wkc := fbReadCmd.wkc;  
bError:= fbReadCmd.bError;  
nErrId:= fbReadCmd.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
