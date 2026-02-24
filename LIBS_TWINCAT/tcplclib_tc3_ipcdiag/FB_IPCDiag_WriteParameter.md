# FB_IPCDiag_WriteParameter

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-3319-4dd0-851e-d5ecb0f774ff)
3. FB\_IPCDiag\_WriteParameter

# FB\_IPCDiag\_WriteParameter

The function block allows an IPC diagnostic parameter to be written. The desired parameter is selected from the enumeration [E\_IPCDiag\_ParameterKey](ms-xhelp:///?Id=beckhoff-a43e-4ae7-94cf-ccf5dddf0869).

Some parameters may generally exist several times. However, the inputs of the function block must be used to explicitly define which individual parameters are to be written.

```
VAR_INPUT  
    bExecute       : BOOL;  
    eParameterKey  : E_IPCDiag_ParameterKey;  
    pBuffer        : PVOID;                        (* parameter buffer with a given size of nBufferSize *)  
    nBufferSize    : UDINT;  
    nModuleIdx     : USINT := 1;                   (* optional module selection *)  
    nListIdx       : USINT := 1;                   (* optional list entry selection *)  
    tTimeout       : TIME := DEFAULT_ADS_TIMEOUT;  (* States the time before the function is cancelled. *)  
    sNetId         : T_AmsNetId := '';             (* keep empty '' for the local device *)  
END_VAR  
VAR_IN_OUT CONSTANT  
    fbRegister     : FB_IPCDiag_Register;  
END_VAR
```

**bExecute:** The function block is called by a positive edge on the input *bExecute*, if the function block is not already active.

**eParameterKey:** The parameter to be written is selected at this input as an enumeration value of the type [E\_IPCDiag\_ParameterKey](ms-xhelp:///?Id=beckhoff-a43e-4ae7-94cf-ccf5dddf0869).

**pBuffer:** The memory address of the data buffer is specified at this input. The data to be transmitted must be stored there.

**nBufferSize:** The length of the data buffer in bytes is specified at this input.

**nModuleIdx:** If there are several module instances that contain the parameter, the desired module instance must be selected here. The module index begins with 1.

**nListIdx:** The list item must be selected here if the parameter is a list parameter. The list index begins with 1.

**tTimeout:** Specifies a maximum length of time for the execution of the function block.

**sNetId:** To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

**fbRegister:** The instance of [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab) must be transferred so that the function block can use the available information for the IPC diagnostic configuration on the target system.   
This instance must have been called beforehand. Otherwise an error is output.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy          : BOOL;  
    bError         : BOOL;  
    hrErrorCode    : HRESULT;  
    ipErrorMessage : I_TcMessage;  
END_VAR
```

**bBusy:** This output is TRUE as long as the function block is active.

**bError:** Becomes TRUE as soon as an error situation occurs.

**hrErrorCode:** Returns an [error code](ms-xhelp:///?Id=beckhoff-3344-4b4f-bca8-387e3119823f) if the bError output is set.

**ipErrorMessage**: Returns detailed information if a bError output is set. The interface pointer used here is always valid (not equal to zero) and is of the type I\_TcMessage. In particular, the corresponding error is immediately visible as plain text in the PLC OnlineView.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_IPCDiag |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
