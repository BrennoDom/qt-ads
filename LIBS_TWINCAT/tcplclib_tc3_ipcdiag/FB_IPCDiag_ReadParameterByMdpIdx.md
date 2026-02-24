# FB_IPCDiag_ReadParameterByMdpIdx

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-3319-4dd0-851e-d5ecb0f774ff)
3. [Access by index specification](ms-xhelp:///?Id=beckhoff-ecbf-4c31-85ef-3a2175d6c259)
4. FB\_IPCDiag\_ReadParameterByMdpIdx

# FB\_IPCDiag\_ReadParameterByMdpIdx

In individual cases, this function block can be used as an alternative to the simpler [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6) in order to query any desired parameters of the IPC diagnostics.

The MDP (Modular Device Profile) information model lists all parameters with the help of areas, modules and tables. As the generic access to each parameter, an addressing is defined whose main component is the MDP index (2 bytes).

Details can be found in the documentation on the [Beckhoff Device Manager](https://infosys.beckhoff.com/content/1033/devicemanager/90071992810335755.html).

## VAR\_INPUT

```
VAR_INPUT  
    bExecute      : BOOL;  
    nIndex        : WORD;     (* F_IPCDiag_GetMdpIndex should be used if parameter is out of configuration area *)  
    nFlags        : BYTE;  
    nSubIndex     : BYTE;  
    pBuffer       : PVOID;    (* Contains the address of the buffer for the received data. *)  
    nBufferSize   : UDINT;    (* Contains the max. number of bytes to be received. *)  
    tTimeout      : TIME := DEFAULT_ADS_TIMEOUT;   (* States the time before the function is cancelled. *)  
    sNetId        : T_AmsNetId := '';              (* keep empty '' for the local device *)  
END_VAR
```

**bExecute:** The function block is called by a positive edge on the input *bExecute*, if the function block is not already active.

**nIndex:** At this input the first part of the addressing for the required IPC diagnostic data is specified.  
If the desired parameter originates from the MDP Configuration Area, the MDP index contains the dynamically generated module ID. In this case it is recommended to use the [F\_IPCDiag\_GetMdpIdx()](ms-xhelp:///?Id=beckhoff-341f-48c6-aef3-c98aeaa8e85b) function.

**nFlags:** At this input the second part of the addressing for the required IPC diagnostic data is specified.

**nSubIndex:** At this input the third part of the addressing for the required IPC diagnostic data is specified.  
The subindex also corresponds to the table row in the MDP information model.

**pBuffer:** The memory address of the data buffer is specified at this input. The received data are stored there if the query is successful.

**nBufferSize:** The length of the data buffer in bytes is specified at this input.

**tTimeout:** Specifies a maximum length of time for the execution of the function block.

**sNetId:** To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid         : BOOL;  
    bBusy          : BOOL;  
    bError         : BOOL;  
    hrErrorCode    : HRESULT;  
    ipErrorMessage : I_TcMessage;  
    nCount         : UDINT;      (* returns the number of bytes received *)  
END_VAR
```

**bValid:** This output is TRUE if both bBusy and bError are FALSE.

**bBusy:** This output is TRUE as long as the function block is active.

**bError:** Becomes TRUE as soon as an error situation occurs.

**hrErrorCode:** Returns an error code if the bError output is set.

**ipErrorMessage**: Returns detailed information if a bError output is set. The interface pointer used here is always valid (not equal to zero) and is of the type I\_TcMessage. In particular, the corresponding error is immediately visible as plain text in the PLC OnlineView.

**nCount:** This output indicates the number of bytes read.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_IPCDiag |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
