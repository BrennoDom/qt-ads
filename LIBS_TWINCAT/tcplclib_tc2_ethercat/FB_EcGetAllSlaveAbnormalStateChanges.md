# FB_EcGetAllSlaveAbnormalStateChanges

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetAllSlaveAbnormalStateChanges

# FB\_EcGetAllSlaveAbnormalStateChanges

![66748299](/tcplclib_tc2_ethercat/1033/Images/png/2239744267__Web.png)

The function block `FB_EcGetAllSlaveAbnormalStateChanges` can be used to read the unexpected EtherCAT state changes of all the slaves connected to the master. If the call is successful, the buffer transferred in the parameter pBufAddr contains the number of unexpected state changes of all slaves as an array of UDINTs. EtherCAT state changes are unexpected if they were not requested by the EtherCAT master, e.g. if an EtherCAT slave spontaneously switches from OP state to SAFEOP state.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId          :    T_AmsNetId; (*AmsNetId of the EtherCAT master device*)  
    pAddrBuf        :    POINTER TO ARRAY [0..EC_MAX_SLAVES] OF UDINT; (*Contains the address of the buffer the counters for the state changes f.i. Op to SafeOp-Err are copied to.*)  
    cbBufLen        :    UDINT; (*Size of the buffer pAddrBuf. The size of the buffer must be at least nSlave *4 Bytes *)  
    bExecute        :    BOOL; (*Function Block execution is triggered by a rising edge at this input*)  
    tTimeout        :    TIME; (*States the time before the function is cancelled.*)  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**pAddrBuf**: Address of an array of UDINTs, into which the number of unexpected state changes of the individual slaves is to be written.

**cbBufLen**: Maximum available buffer size (in bytes) for the data to be read.

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

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
