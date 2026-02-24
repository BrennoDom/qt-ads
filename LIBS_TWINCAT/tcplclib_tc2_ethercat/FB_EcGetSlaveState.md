# FB_EcGetSlaveState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcGetSlaveState

# FB\_EcGetSlaveState

![61729771](/tcplclib_tc2_ethercat/1033/Images/png/57201419__Web.png)

The function block `FB_EcGetSlaveState` allows the EtherCAT status and the Link status of an individual EtherCAT slave to be read. If the call is successful, the output variable state, whose type is ST\_EcSlaveState, contains the requested status information.

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

**nSlaveAddr**: Fixed address of the EtherCAT slave whose status is to be read

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    state  : ST_EcSlaveState;       
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**state**: Structure that contains the EtherCAT status and the Link status of the slave. (type: [ST\_EcSlaveState](ms-xhelp:///?Id=beckhoff-cf4e-4cba-b99d-e782280f62ee))

## Example of an implementation in ST:

```
PROGRAM TEST_GetSlaveState  
VAR  
    fbGetSlaveState : FB_EcGetSlaveState;  
    sNetId          : T_AmsNetId := '172.16.2.131.2.1';  
    bExecute        : BOOL;  
    state           : ST_EcSlaveState;  
    nSlaveAddr      : UINT := 1001;  
    bError          : BOOL;  
    nErrId          : UDINT;  
END_VAR  
  
fbGetSlaveState(sNetId:= sNetId, nSlaveAddr:= nSlaveAddr, bExecute:=bExecute);  
state := fbGetSlaveState.state;  
bError := fbGetSlaveState.bError;  
nErrId := fbGetSlaveState.nErrId;
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
