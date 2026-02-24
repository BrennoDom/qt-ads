# FB_EcSetSlaveState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcSetSlaveState

# FB\_EcSetSlaveState

![7037199](/tcplclib_tc2_ethercat/1033/Images/png/57214219__Web.png)

With this function block a slave can be set to a specified EtherCAT state. The requested EtherCAT state is transferred with the reqState variable. The function block sends the command to change state and, unlike the function block FB\_EcRegSlaveState, remains active until the EtherCAT slave has attained the new state or the maximum time tTimeout is exceeded. The current state is output in the currState variable.

See also: [FB\_EcReqSlaveState](ms-xhelp:///?Id=beckhoff-3f81-4897-8fbe-9273d8a6e3b4)

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    nSlaveAddr : UINT;       
    bExecute   : BOOL;   
    tTimeout   : TIME := T#10s;   
    reqState   : WORD;   
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**nSlaveAddr:** Fixed address of the EtherCAT slave whose EtherCAT state is to be set.

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**reqState:** EtherCAT state to which the slave is to be set. The possible values for reqState are:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Set slave to Init state |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Set slave to Pre-operational state |
| EC\_DEVICE\_STATE\_BOOTSTRAP | 0x03 | Set slave to Bootstrap state. This state is used for firmware downloads. |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Set slave to Safe-operational state |
| EC\_DEVICE\_STATE\_OP | 0x08 | Set slave to Operational state |
| EC\_DEVICE\_STATE\_ERROR | 0x10 | If the error bit in the status byte is set in the EtherCAT slave (currState.deviceState AND EC\_DEVICE\_STATE\_ERROR = TRUE), the error bit can be reset by setting EC\_DEVICE\_STATE\_ERROR. |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    currState : ST_EcSlaveState;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**currState**: Current [EtherCAT state](ms-xhelp:///?Id=beckhoff-cf4e-4cba-b99d-e782280f62ee) of the slave.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
