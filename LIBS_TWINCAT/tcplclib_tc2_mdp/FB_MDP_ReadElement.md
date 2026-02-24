# FB_MDP_ReadElement

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_ReadElement

# FB\_MDP\_ReadElement

![3493029](/tcplclib_tc2_mdp/1033/Images/gif/178783883__en-US__Web.gif)

The function block enables querying of an individual MDP element. In this way, each element from each module of the configuration area can be read!

Internally, the device is scanned for the selected module, and the element information is queried with the dynamic module ID.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute    : BOOL;  
    stMDP_Addr  : ST_MDP_Addr;        (* includes all address parameters without the Dynamic Module Id *)  
    eModuleType : E_MDP_ModuleType;   (* chosen module type out of the module type list *)  
    iModIdx     : USINT;              (* chosen index(0..n) of the demanded module type. E.g. second NIC(idx 1) of three found NICs. *)  
    pDstBuf     : DWORD;              (* Contains the address of the buffer for the received data. *)  
    cbDstBufLen : UDINT;              (* Contains the max. number of bytes to be received. *)  
    tTimeout    : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId   : T_AmsNetId;         (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**stMDP\_Addr**: The MDP addressing belonging to the selected module is specified at this input. The structure is of the type [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493).  
 The area must be specified as configuration area.  
 The dynamic module ID is first added internally and must not be specified.

**iModIdx**: If several instances of an MDP module exist, a selection can be made by means of the input *iModIdx* (0,...,n).

**pDstBuf**: The memory address of the data buffer is specified at this input. The received data are stored there if the query is successful.

**cbDstBufLen**: The length of the data buffer in bytes is specified at this input.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy            : BOOL;  
    bError           : BOOL;         (* indicates if Read was successfull or not *)  
    nErrID           : UDINT;  
    nCount           : UDINT;  
    stMDP_DynAddr    : ST_MDP_Addr;  (* includes the new dynamic module type id. *)  
    iModuleTypeCount : USINT;        (* returns the number of found modules equal the demanded module type. *)  
    iModuleCount     : USINT;        (* returns the number of all detected MDP modules. *)  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**nCount**: This output indicates the number of bytes read.

**stMDP\_DynAddr**: At this output the MDP addressing relating to the selected MDP module is specified. The structure is of the type [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493). The dynamic Module ID was added by the function block.

**iModuleTypeCount**: The output *iModuleTypeCount* indicates the number of modules that correspond to the specified type.

**iModuleCount**: The output *iModuleCount* indicates the entire number of modules on the device.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
