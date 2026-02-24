# FB_MDP_ScanModules

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_ScanModules

# FB\_MDP\_ScanModules

![33645886](/tcplclib_tc2_mdp/1033/Images/gif/178796683__en-US__Web.gif)

The function block enables searching of a device for a particular IPC diagnostics module.  
Selection can be made if several instances of the module type are present. The dynamic Module ID for the selected module type is determined by the function block.  
This is an important component of the MDP addressing, which is represented in the structure [ST\_MDP\_Addr](ms-xhelp:///?Id=beckhoff-9f09-46c2-aa87-324397489493).

## VAR\_INPUT

```
VAR_INPUT  
    bExecute    : BOOL;  
    nModuleType : WORD;             (* chosen module type out of the module type list *)  
    iModIdx     : USINT;            (* chosen index(0..n) of the demanded module type. E.g. second NIC(idx 1) of three found NICs. *)  
    tTimeout    : TIME := DEFAULT_ADS_TIMEOUT; (* States the time before the function is cancelled. *)  
    sAmsNetId   : T_AmsNetId;       (* keep empty '' for the local device *)  
END_VAR
```

**bExecute**: The function block is called by a rising edge on the input *bExecute*, if the block is not already active.

**nModuleType**: At this input is the IPC diagnostics module type is specified. The possible types are listed in the enumeration [E\_MDP\_ModuleType](ms-xhelp:///?Id=beckhoff-e384-4eb4-8d78-0369aa8dc371). ([general information on IPC diagnostics module types.)](https://infosys.beckhoff.com/content/1033/devicemanager/99079192065133835.html)

**iModIdx**: If several instances of an IPC diagnostics module exist, a selection can be made by means of the input *iModIdx* (0,...,n).  
 In the case of uncertainty concerning the selection: information about which module is explicitly concerned can be queried via the function block [FB\_MDP\_ReadModuleHeader](ms-xhelp:///?Id=beckhoff-b786-40e5-ac5e-2e01ed8b3ab5) after scanning.

**tTimeout**: Specifies a maximum length of time for the execution of the function block.

**sAmsNetId**: To execute the query on the local device, it is not necessary to specify this input variable. Alternatively, an empty string can be specified. To direct the query to another computer, its AMS Net Id (of type T\_AmsNetId) can be specified here.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy     : BOOL;  
    bError    : BOOL;     (* indicates if Scan was successfull or not *)  
    nErrID    : UDINT;  
    nDynModuleId     : BYTE;  (* Dynamic Module Id *)  
    iModuleTypeCount : USINT; (* returns the number of found modules equal the demanded module type. *)  
    iModuleCount     : USINT; (* returns the number of all detected MDP modules. *)  
END_VAR
```

**bBusy**: This output is TRUE as long as the function block is active.

**bError**: Becomes TRUE as soon as an error situation occurs.

**nErrID**: Returns an [error code](ms-xhelp:///?Id=beckhoff-dcf9-45e5-b79d-97610e81bb4a) if the bError output is set.

**nDynModuleId**: This output indicates the dynamic Module ID determined for the selected module.

**iModuleTypeCount**: The output *iModuleTypeCount* indicates the number of modules that correspond to the specified type.

**iModuleCount**: The output *iModuleCount* indicates the entire number of modules on the device.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
