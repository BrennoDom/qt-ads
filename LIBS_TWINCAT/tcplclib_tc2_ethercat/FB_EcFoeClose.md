# FB_EcFoeClose

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [FoE interface](ms-xhelp:///?Id=beckhoff-0647-4e46-a9c1-a6ca90dbe01e)
3. FB\_EcFoeClose

# FB\_EcFoeClose

![21192109](/tcplclib_tc2_ethercat/1033/Images/png/57223819__Web.png)

This function block closes the communication port for the “File access over EtherCAT” mailbox protocol.

## VAR\_INPUT

```
VAR_INPUT  
    hFoe     : T_HFoe;  
    bExecute : BOOL;   
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;   
END_VAR
```

**hFoe**: “File access over EtherCAT” [handle](ms-xhelp:///?Id=beckhoff-f3c9-4116-85fd-186fc8905b19).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Maximum time allowed for the execution of the function block.

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

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
