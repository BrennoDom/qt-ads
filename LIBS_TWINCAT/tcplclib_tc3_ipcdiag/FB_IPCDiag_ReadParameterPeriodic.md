# FB_IPCDiag_ReadParameterPeriodic

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-3319-4dd0-851e-d5ecb0f774ff)
3. FB\_IPCDiag\_ReadParameterPeriodic

# FB\_IPCDiag\_ReadParameterPeriodic

This function block allows an IPC diagnostic parameter to be queried periodically. The desired parameter is selected from the enumeration [E\_IPCDiag\_ParameterKey](ms-xhelp:///?Id=beckhoff-a43e-4ae7-94cf-ccf5dddf0869).

The functionality is analogous to the function block [FB\_IPCDiag\_ReadParameter](ms-xhelp:///?Id=beckhoff-41de-431c-804d-3aa55cec49b6), where the parameter is queried once. For `FB_IPCDiag_ReadParameterPeriodic`, the parameter is permanently queried with a regularity defined by `tPeriod`.

Some parameters may exist several times. In this case, the function block reads all existing values at once and these values can be copied individually or all at once using the GetParameter() methods.

The parameters are subdivided into groups. Some of these groups correspond to the modules of the 'Configuration Area' in the MDP. Modules may be instanced several times. Accordingly, a parameter of a multi-instanced module exists several times or has a correspondingly large number of values.

On the other hand, there are list parameters whose identifier already makes this clear. According to the number of list entries, the parameter also exists here several times or has several values.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute       : BOOL;  
    eParameterKey  : E_IPCDiag_ParameterKey;  
    nModuleIdx     : USINT := 0;   (* optional module selection for parameters of configuration area; 0:all corresponding modules are read (or rather the first module is read in case of list parameters) *)   
    tPeriod        : TIME := T#60S;               (* set tPeriod >= tTimeout for periodical reading (set 0 for direct execution) *)  
    tTimeout       : TIME := DEFAULT_ADS_TIMEOUT; (* ADS communication timeout *)  
    sNetId         : T_AmsNetId := '';            (* keep empty '' for the local device *)  
END_VAR  
VAR_IN_OUT CONSTANT  
    fbRegister     : FB_IPCDiag_Register;  
END_VAR
```

**bExecute:** The function block is called by a positive edge on the input *bExecute*, if the function block is not already active.

**eParameterKey:** The parameter to be queried is selected at this input as an enumeration value of the type [E\_IPCDiag\_ParameterKey](ms-xhelp:///?Id=beckhoff-a43e-4ae7-94cf-ccf5dddf0869).  
If the parameter is a list parameter, the complete list is read at once and made available.

**nModuleIdx:** The module index can optionally be specified at this input if the parameter belongs to a module that exists several times.  
If the parameter belongs to a multi-existent module and the input nModuleIdx is left at 0, then the parameter values of all module instances are read.   
If the parameter is a list parameter, however, then only one module instance can be read.

**tPeriod:** Specifies the regularity with which the parameter is to be queried. `tPeriod` must be greater than or equal to `tTimeout`.

**tTimeout:** Specifies a maximum time to execute the internal ADS communication.

**sNetId:** To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

**fbRegister:** The instance of [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab) must be transferred so that the function block can use the available information for the IPC diagnostic configuration on the target system.   
This instance must have been called beforehand. Otherwise an error is output.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bValid          : BOOL;     (* read data available (equal IF NOT bBusy AND NOT bError) *)  
    bError          : BOOL;  
    hrErrorCode     : HRESULT;  
    ipErrorMessage  : I_TcMessage;  
    nReadParameterValues : USINT;    (* number of read parameter values *)  
    nModuleCount         : USINT;    (* number of module instances (configuration area) with the demanded parameter *)  
END_VAR
```

**bValid:** This output is TRUE if a parameter query takes place and bError is FALSE.

**bError:** Becomes TRUE as soon as an error situation occurs.

**hrErrorCode:** Returns an [error code](ms-xhelp:///?Id=beckhoff-3344-4b4f-bca8-387e3119823f) if the bError output is set.

**ipErrorMessage**: Returns detailed information if a bError output is set. The interface pointer used here is always valid (not equal to zero) and is of the type I\_TcMessage. In particular, the corresponding error is immediately visible as plain text in the PLC OnlineView.

**nReadParameterValues:** This output indicates the number of parameter values read. In the case of list parameters, therefore, all list entries are always read automatically and made available.

**nModuleCount:** This output indicates the number of module instances that contain the selected parameter.  
The parameter must originate from the MDP Configuration Area for this. Otherwise, nModuleCount=0.

## Methods

After the reading procedure has been successfully completed, the parameter can be copied using one of the following methods.

**GetParameter() :**

```
METHOD GetParameter : HRESULT  
VAR_INPUT  
    pBuffer        : PVOID;    // buffer for parameter with a given size of nParameterSize  
    nBufferSize    : UDINT;    // buffer size in bytes (for one or more values)  
END_VAR
```

The `GetParameter()` method provides easy access to the read parameter. All values are available if the parameter existed several times. In that case, all values are copied at once or, as the case may be, as many values are copied as the specified buffer size can contain. Hence, an ARRAY of the corresponding data type can be used to obtain a complete list.  
This is not possible with parameters of the type STRING on account of the different length. If a parameter of the type STRING exists several times, or if a list parameter of the type STRING exists, then a different method must be used to read the other values.

**GetParameterByIdx() :**

```
METHOD GetParameterByIdx : HRESULT  
VAR_INPUT  
    pBuffer          : PVOID;            // buffer for parameter with a given size of nParameterSize  
    nBufferSize      : UDINT;            // buffer size in bytes (for one or more values)  
    nParameterIdx    : USINT(1..255);    // selection of parameter value (1..nReadParameterValues)  
END_VAR
```

This function is required if the parameter was present several times and individual values are to be copied. The input `nParameterIdx` specifies which parameter value is to be copied. If it is a list parameter, specify the desired list index there. Specify the module index if it is not a list parameter, but a parameter that had several module instances. Both indices begin with 1.

**GetParameterStrings() :**

```
METHOD GetParameterStrings : HRESULT  
VAR_INPUT  
    pBuffer     : PVOID;    // buffer for parameter with a given size of nParameterSize  
    nBufferSize : UDINT;    // buffer size in bytes (for one or more values)  
    nStrings    : USINT;    // number of strings to be copied (each string with size=nBufferSize/nStrings)  
END_VAR
```

If the parameter existed several times and represents a character string (STRING) in terms of the data type, this method can be used to copy several character strings at the same time. The input `nStrings` specifies how many character strings are to be copied. An 'ARRAY[1..nStrings] OF STRING' can serve as a buffer.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_IPCDiag |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
