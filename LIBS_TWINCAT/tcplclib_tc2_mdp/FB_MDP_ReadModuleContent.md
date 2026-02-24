# FB_MDP_ReadModuleContent

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_ReadModuleContent

# FB\_MDP\_ReadModuleContent

![14499957](/tcplclib_tc2_mdp/1033/Images/gif/178790283__en-US__Web.gif)

The function block enables querying of the content of an IPC diagnostics module.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute      : BOOL;  
    stMDP_DynAddr : ST_MDP_Addr;    (* includes the dynamic module type for which the module content is requested. All subindexes of the chosen table are requested. *)  
    iSubIdxCount  : USINT;          (* the number of SubIndexes to be requested *)  
    pDstBuf       : DWORD;          (* Contains the address of the buffer for the received data. *)  
    cbDstBufLen   : UDINT;          (* Contains the max. number of bytes to be received. *)  
    tTimeout      : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId     : T_AmsNetId;     (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**stMDP\_DynAddr**: The MDP addressing belonging to the selected module is specified at this input. The structure is of the type [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493). The dynamic Module ID must already be transferred with it.

**iSubIdxCount**: The input *iSubIdxCount* is used to specify how many subindices of the selected Table ID are to be queried.

**pDstBuf**: The memory address of the data buffer is specified at this input. The received data are stored there if the query is successful.

**cbDstBufLen**: The length of the data buffer in bytes is specified at this input.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy       : BOOL;  
    bError      : BOOL;     (* indicates if Read was successfull or not *)  
    nErrID      : UDINT;  
    iErrPos     : USINT;  
    arrStartIdx : ARRAY[0..255] OF UINT;    (* startindexes in bytes of each subindex element *)  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**iErrPos**: If an error occurred and this refers to an individual element, then this output indicates the position (subindex of the element) at which an error first occurred.

**arrStartIdx**: This array describes how the individually queried subindices have been stored in the buffer.  
The array index zero indicates the position in bytes at which the data of subindex zero begins in the buffer. Subsequent subindices are handled analogously.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
