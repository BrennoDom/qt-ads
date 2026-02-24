# FB_EcReqMasterState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcReqMasterState

# FB\_EcReqMasterState

![18697032](/tcplclib_tc2_ethercat/1033/Images/png/57211019__Web.png)

With this function block the EtherCAT state of a master device can be requested and set. The requested EtherCAT state is transferred in the state variable. The function block becomes inactive as soon as it has requested the EtherCAT state. Unlike the function block FB\_EcSetMasterState it does not wait until the new state is set.

See also: [FB\_EcSetMasterState](ms-xhelp:///?Id=beckhoff-77bf-4e47-8e83-bc646252bb97)

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;  
    bExecute : BOOL;   
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;   
    state    : WORD;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**state:** EtherCAT state requested from the master. The possible State values are:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Request Init state from master |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Request Pre-operational state from master |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Request Safe-operational state from master |
| EC\_DEVICE\_STATE\_OP | 0x08 | Request Operational state from master |

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
PROGRAM TEST_ReqMasterState  
VAR  
    fbReqMasterState : FB_EcReqMasterState;  
    sNetId           : T_AmsNetId:= '172.16.2.131.2.1';  
    bExecute         : BOOL;  
    state            : WORD :=EC_DEVICE_STATE_INIT;  
    bError           : BOOL;  
    nErrId           : UDINT;  
END_VAR  
  
fbReqMasterState(sNetId:= sNetId, bExecute:=bExecute, state:=state);  
bError := fbGetMasterState.bError;  
nErrId := fbGetMasterState.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
