# FB_EcReqSlaveState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcReqSlaveState

# FB\_EcReqSlaveState

![34055563](/tcplclib_tc2_ethercat/1033/Images/png/57207819__Web.png)

With this function block a slave can be set to a specified EtherCAT state. The requested EtherCAT state is transferred in the state variable. The function block becomes inactive as soon as it has sent the command to change state. Unlike the function block FB\_EcSetSlaveState it does not wait until the EtherCAT slave has attained the new state.

See also: [FB\_EcSetSlaveState](ms-xhelp:///?Id=beckhoff-b140-482e-aa91-7517afad9b29)

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    nSlaveAddr : UINT;       
    bExecute   : BOOL;   
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;   
    state      : WORD;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave whose EtherCAT state is to be set.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**state:** EtherCAT state to which the slave is to be set. The possible State values are:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Set slave to Init state |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Set slave to Pre-operational state |
| EC\_DEVICE\_STATE\_BOOTSTRAP | 0x03 | Set slave to Bootstrap state. This state is used for firmware downloads. |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Set slave to Safe-operational state |
| EC\_DEVICE\_STATE\_OP | 0x08 | Set slave to Operational state |
| EC\_DEVICE\_STATE\_ERROR | 0x10 | If the error bit in the status byte is set in the EtherCAT slave (state.deviceState & EC\_DEVICE\_STATE\_ERROR = TRUE), the error bit can be reset by setting EC\_DEVICE\_STATE\_ERROR. |

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
PROGRAM TEST_ReqSlaveState  
VAR  
    fbGetSlaveState : FB_EcReqSlaveState;  
    sNetId          : T_AmsNetId:= '172.16.2.131.2.1';  
    bExecute        : BOOL;  
    state           : WORD := EC_DEVICE_STATE_INIT;  
    nSlaveAddr      : UINT := 1001;  
    bError          : BOOL;  
    nErrId          : UDINT;  
END_VAR  
  
fbGetSlaveState(sNetId:= sNetId, nSlaveAddr:= nSlaveAddr, bExecute:=bExecute, state:=state);  
bError := fbGetSlaveState.bError;  
nErrId := fbGetSlaveState.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
