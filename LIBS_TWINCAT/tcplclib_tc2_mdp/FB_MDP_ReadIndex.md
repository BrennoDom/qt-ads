# FB_MDP_ReadIndex

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. [Advanced](ms-xhelp:///?Id=beckhoff-584b-427d-b7e4-ffafcb682f50)
5. FB\_MDP\_ReadIndex

# FB\_MDP\_ReadIndex

The function block enables querying of any IPC diagnostics element. In addition to the configuration area, data from the device area are also accessible.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute    : BOOL;             (* Function block execution is triggered by a rising edge at this input.*)  
    nIndex      : WORD;  
    nSubIndex   : BYTE;  
    pDstBuf     : DWORD;            (* Contains the address of the buffer for the received data. *)  
    cbDstBufLen : UDINT;            (* Contains the max. number of bytes to be received. *)  
    tTimeout    : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId   : T_AmsNetId;       (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**nIndex**: At this input the first part of the addressing for the required IPC diagnostic data is specified.

**nSubIndex**: At this input the second part of the addressing for the required IPC diagnostic data is specified.

**pDstBuf**: The memory address of the data buffer is specified at this input. The received data are stored there if the query is successful.

**cbDstBufLen**: The length of the data buffer in bytes is specified at this input.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    nCount : UDINT;  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**nCount**: This output indicates the number of bytes read.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4013 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
