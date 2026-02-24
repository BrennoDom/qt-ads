# FB_EcSetMasterState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT State Machine](ms-xhelp:///?Id=beckhoff-56be-4a7d-aed8-3fbe734e9580)
3. FB\_EcSetMasterState

# FB\_EcSetMasterState

![38064613](/tcplclib_tc2_ethercat/1033/Images/png/57217419__Web.png)

With this function block the EtherCAT state of a master device can be requested and set. The requested EtherCAT state is transferred with the reqState variable. The function block requests the EtherCAT state and, unlike the function block FB\_EcReqMasterState, remains active until the new state is set or the maximum time tTimeout is exceeded. The current state is output in the currState variable.

See also: [FB\_EcReqMasterState](ms-xhelp:///?Id=beckhoff-a795-424d-a249-5b7e0134734d)

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;  
    bExecute : BOOL;   
    tTimeout : TIME := T#10s;   
    reqState : WORD;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the EtherCAT master device. (type: T\_AmsNetId)

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

**reqState:** EtherCAT state requested from the master. The possible values for reqState are:

| Constant | Value | Description |
| --- | --- | --- |
| EC\_DEVICE\_STATE\_INIT | 0x01 | Request Init state from master |
| EC\_DEVICE\_STATE\_PREOP | 0x02 | Request Pre-operational state from master |
| EC\_DEVICE\_STATE\_SAFEOP | 0x04 | Request Safe-operational state from master |
| EC\_DEVICE\_STATE\_OP | 0x08 | Request Operational state from master |

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrId    : UDINT;  
    currState : WORD;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**currState**: Current EtherCAT state of the master.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
