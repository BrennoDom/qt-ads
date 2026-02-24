# FB_MDP_ReadModuleHeader

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_ReadModuleHeader

# FB\_MDP\_ReadModuleHeader

![63390755](/tcplclib_tc2_mdp/1033/Images/gif/178793483__en-US__Web.gif)

The function block enables querying of the header of an IPC diagnostics module.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute     : BOOL;  
    nDynModuleId : BYTE;             (* the dynamic module id for which the module header is requested *)  
    tTimeout     : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId    : T_AmsNetId;       (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**stMDP\_DynAddr**: The MDP addressing belonging to the selected network module is specified at this input. The dynamic Module ID must already be specified with it.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy           : BOOL;  
    bError          : BOOL;   (* indicates if Read was successfull or not *)  
    nErrID          : UDINT;  
    stMDP_ModHeader : ST_MDP_ModuleHeader;  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**stMDP\_ModuleHeader**: At this output the header information for the read IPC diagnostics modules is displayed in the form of the structure [ST\_MDP\_ModuleHeader](ms-xhelp:///?Id=beckhoff-fd75-4db6-9a81-a42b0f28ebca).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
