# FB_EcGetMasterDevState

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcGetMasterDevState

# FB\_EcGetMasterDevState

![44100051](/tcplclib_tc2_ethercat/1033/Images/png/2896109835__Web.png)

The function block `FB_EcGetMasterDevState` can be used to read the current state of the EtherCAT master.

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
VAR_INPUT  
    bBusy     : BOOL;   
    bError    : BOOL;  
    nErrId    : UDINT;  
    nDevState : WORD;  
END_VAR
```

**bBusy:** This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError:** This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId:** Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**nDevState:** Current state of the master device.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
