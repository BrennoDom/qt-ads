# FB_EcGetMasterState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcGetMasterState

# FB\_EcGetMasterState

![14315403](/tcplclib_tc2_ethercat/1033/Images/png/57198219__Web.png)

The function block `FB_EcGetMasterState` can be used to read the EtherCAT state of the master. If the call is successful, the State output variable of type WORD contains the requested status information.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;   
    bExecute : BOOL;   
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    state  : WORD;   
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**state**: Current EtherCAT state of the master. The possible values are:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Master is in Init state |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Master is in Pre-operational state |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Master is Safe-operational state |
| EC\_DEVICE\_STATE\_OP | 0x08 | Master is Operational state |

## Example of an implementation in ST:

```
PROGRAM TEST_GetMasterState  
VAR  
    fbGetMasterState : FB_EcGetMasterState;  
    sNetId           : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute         : BOOL;  
    state            : WORD;  
    bError           : BOOL;  
    nErrId           : UDINT;  
END_VAR  
  
fbGetMasterState(sNetId:= sNetId, bExecute:=bExecute);  
state := fbGetMasterState.state;  
bError := fbGetMasterState.bError;  
nErrId := fbGetMasterState.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
