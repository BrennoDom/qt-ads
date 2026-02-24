# FB_IPCDiag_Register

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-3319-4dd0-851e-d5ecb0f774ff)
3. FB\_IPCDiag\_Register

# FB\_IPCDiag\_Register

The function block checks which IPC diagnostic parameters are available and creates a register for this purpose. Specifically, a list of all available parameter modules is created. The function block only needs to determine this once, typically at the start of the program.   
If diagnostic parameters of a remote system are to be queried by means of a non-local AMS Net Id, the function block must be executed after its start.

The instance of FB\_IPCDiag\_Register must be transferred to other function blocks from the library such as [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6) in order to obtain information about the determined register.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute    : BOOL;  
    tTimeout    : TIME := DEFAULT_ADS_TIMEOUT;   (* States the time before the function is cancelled. *)  
    sNetId      : T_AmsNetId := '';              (* keep empty '' for the local device *)  
END_VAR
```

**bExecute:** The function block is called by a positive edge on the input *bExecute*, if the function block is not already active.

**tTimeout:** Specifies a maximum length of time for the execution of the function block.

**sNetId:** To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid         : BOOL;        (* read data available =(NOT bBusy AND NOT bError) *)  
    bBusy          : BOOL;  
    bError         : BOOL;  
    hrErrorCode    : HRESULT;  
    ipErrorMessage : I_TcMessage;  
    stModuleList   : ST_IPCDiag_ModuleList;  
END_VAR
```

**bValid:** This output is TRUE if both bBusy and bError are FALSE.

**bBusy:** This output is TRUE as long as the function block is active.

**bError:** Becomes TRUE as soon as an error situation occurs.

**hrErrorCode:** Returns an [error code](ms-xhelp:///?Id=beckhoff-3344-4b4f-bca8-387e3119823f) if the bError output is set.

**ipErrorMessage**: Returns detailed information if a bError output is set. The interface pointer used here is always valid (not equal to zero) and is of the type I\_TcMessage. In particular, the corresponding error is immediately visible as plain text in the PLC OnlineView.

**stModuleList:** This output specifies the list of available modules. This information is not usually necessary in an application itself.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_IPCDiag |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
