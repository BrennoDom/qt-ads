# FB_MDP_ReadModule

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_ReadModule

# FB\_MDP\_ReadModule

![31437268](/tcplclib_tc2_mdp/1033/Images/gif/178787083__en-US__Web.gif)

The function block enables an MDP module to be queried.

The device is scanned internally for the selected module and the module header and the module information are queried with the dynamic Module ID.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute     : BOOL;  
    stMDP_Addr   : ST_MDP_Addr;        (* includes all address parameters without the Dynamic Module Id *)  
    eModuleType  : E_MDP_ModuleType;   (* chosen module type out of the module type list *)  
    iModIdx      : USINT;              (* chosen index(0..n) of the demanded module type. E.g. second NIC(idx 1) of three found NICs. *)  
    iSubIdxCount : USINT;  
    pDstBuf      : DWORD;              (* Contains the address of the buffer for the received data. *)  
    cbDstBufLen  : UDINT;              (* Contains the max. number of bytes to be received. *)  
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId    : T_AmsNetId;         (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**stMDP\_Addr**: The MDP addressing belonging to the selected module is specified at this input. The structure is of the type [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493). The dynamic Module ID is only added internally.

**eModuleType**: The MDP module type is specified at this input. The possible types are listed in the enumeration [E\_MDP\_ModuleType](ms-xhelp:///?Id=beckhoff-e384-4eb4-8d78-0369aa8dc371). (General information: module types list)

**iModIdx**: If several instances of an MDP module exist, a selection can be made by means of the input *iModIdx* (0,...,n).

**iSubIdxCount**: The input *iSubIdxCount* is used to specify how many subindices of the selected Table ID are to be queried.

**pDstBuf**: The memory address of the data buffer is specified at this input. The received data are stored there if the query is successful.

**cbDstBufLen**: The length of the data buffer in bytes is specified at this input.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;                (* indicates if Read was successfull or not *)  
    nErrID       : UDINT;  
    iErrPos      : USINT;  
    stMDP_DynAddr      : ST_MDP_Addr;   (* includes the new dynamic module type id. *)  
    iModuleTypeCount   : USINT;         (* returns the number of found modules equal the demanded module type. *)  
    iModuleCount       : USINT;         (* returns the number of all detected MDP modules. *)  
    stMDP_ModuleHeader : ST_MDP_ModuleHeader;  
    arrStartIdx        : ARRAY[0..255] OF UINT; (* startindexes in bytes of each subindex element *)  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**iErrPos**: If an error occurred and this refers to an individual element, then this output indicates the position (subindex of the element) at which an error first occurred.

**stMDP\_DynAddr**: At this output the MDP addressing relating to the selected MDP module is specified. The structure is of the type [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493). The dynamic Module ID was added by the function block.

**iModuleTypeCount**: The output *iModuleTypeCount* indicates the number of modules that correspond to the specified type.

**iModuleCount**: The output *iModuleCount* indicates the entire number of modules on the device.

**stMDP\_ModuleHeader**: The header information from the read MDP module is displayed at this output in the form of the structure [ST\_MDP\_ModuleHeader.](ms-xhelp:///?Id=beckhoff-fd75-4db6-9a81-a42b0f28ebca)

**arrStartIdx**: This array describes how the individually queried subindices have been stored in the buffer.  
The array index zero indicates the position in bytes at which the data of subindex zero begins in the buffer. Subsequent subindices are handled analogously.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
