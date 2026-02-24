# FB_MDP_CPU_Read

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Specific](ms-xhelp:///?Id=beckhoff-f154-4692-ab80-393af7db6a55)
4. FB\_MDP\_CPU\_Read

# FB\_MDP\_CPU\_Read

![40962215](/tcplclib_tc2_mdp/1033/Images/gif/178803083__en-US__Web.gif)

The function block enables querying of the IPC diagnostics module CPU.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL;         (* Function block execution is triggered by a rising edge at this input.*)  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    iModIdx   : USINT := 0;   (* Index number of chosen MDP module *)  
    sAmsNetId : T_AmsNetId;   (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**iModIdx**: If several instances of an IPC diagnostics module exist, a selection can be made by means of the input iModIdx (0,...,n).

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;  
    nErrID    : UDINT;  
    iErrPos   : USINT;  
    stMDP_ModuleHeader  : ST_MDP_ModuleHeader;  
    stMDP_ModuleContent : ST_MDP_CPU;  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**iErrPos**: If an error occurred and this refers to an individual element, then this output indicates the position (subindex of the element) at which an error first occurred.

**stMDP\_ModuleHeader**: At this output the header information for the read IPC diagnostics modules is displayed in the form of the structure [ST\_MDP\_ModuleHeader](ms-xhelp:///?Id=beckhoff-fd75-4db6-9a81-a42b0f28ebca).

**stMDP\_ModuleContent**: The information from TableID 1 of the read IPC diagnostics module is displayed at this output in the form of the structure [ST\_MDP\_CPU](ms-xhelp:///?Id=beckhoff-7cf3-4ade-9a59-27559993f48a).

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
