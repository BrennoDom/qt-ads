# FB_EcMasterFrameStatistic

## Library
tcplclib_tc2_ethercat

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
2. [EtherCAT Diagnostic](ms-xhelp:///?Id=beckhoff-b52f-4e72-8bb2-a127b94ebdc5)
3. FB\_EcMasterFrameStatistic

# FB\_EcMasterFrameStatistic

![3453833](/tcplclib_tc2_ethercat/1033/Images/png/57246219__Web.png)

The function block `FB_EcMasterFrameStatistic` can be used to read the frame statistics of the EtherCAT master. A distinction is made between cyclic and acyclic (queued) frames. Acyclic frames are used for the initialization or for parameter access to EtherCAT slaves. Frames are regarded as lost if they fail to return to the master or are invalid.  
The number of lost frames (i.e. lost or invalid cyclic frames), the number of cyclic frames per second, the number of lost queued frames (i.e. lost or invalid acyclic frames) and the number of queued frames per second is provided at the function block output.

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
    bBusy : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    nLostFrames : UDINT;  
    fFramesPerSecond : LREAL;  
    nLostQueuedFrames : UDINT;  
    fQueuedFramesPerSecond : LREAL;  
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: This output is set after the bBusy output has been reset when an error occurs in the transmission of the command.

**nErrId**: Supplies the ADS error code associated with the most recently executed command if the bError output is set.

**nLostFrames**: Returns the current number of lost or invalid cyclic frames.

**fFramesPerSecond**: Returns the current number of cyclic frames per second.

**nLostQueuedFrames**: Returns the current number of lost or invalid queued (acyclic) frames.

**fQueuedFramesPerSecond**: Returns the current number of queued (acyclic) frames per second.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_EtherCAT |

[TwinCAT 3 | PLC Library: Tc2\_EtherCAT](ms-xhelp:///?Id=beckhoff-14bb-4c3e-8a94-7169ba8928ec)
