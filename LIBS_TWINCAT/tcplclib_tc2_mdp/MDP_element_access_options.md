# MDP element access options

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. MDP element access options

# MDP element access options

The TwinCAT 3 PLC Tc2\_MDP library offers a wide range of function blocks to facilitate comprehensive access to MDP data.

There are two basic types of function blocks in the library.  
Firstly the **generic function blocks**. They can be used to query and set arbitrary parameters in the MDP themselves by means of discrete access.  
Furthermore, **specific function blocks** offer the possibility of accessing certain data as well as groupings of several data with one call.   
  
The function blocks have a uniform appearance.  
All function blocks are called by a positive edge on the *bExecute* input. Afterwards, cyclic calling of the function block (*bExecute* = FALSE) returns the result of the query at the output as soon as the processing of the query has been completed (*bBusy* = FALSE). Each function block must be called (*bExecute* = FALSE) for as long as it takes for the internal processing (bBusy = FALSE) to be completed. During that time, all inputs of the function block must remain unchanged.  
  
In general, the MDP is a model that describes hardware and software components in the form of modules. Information about these modules as well as about the device itself can be queried and changed.  
A module consists of one or more tables. Each table consists of a fixed number of subindices. A subindex corresponds to a concrete element that can be accessed.  
You can find more information on the setup of MDP in the [MDP Information Model](https://infosys.beckhoff.com/content/1033/devicemanager/99079192065129227.html) (Device Manager documentation). Further options for accessing the MDP are also described there.

## Generic function blocks

In order to be able to query or set an IPC diagnostics parameter, the dynamic module ID of the module in which the parameter is located must be known.  
This is determined with the aid of the function block [FB\_MDP\_ScanModules](ms-xhelp:///?Id=beckhoff-d602-4983-bfef-aeab48e864a1).

Individual parameters can now be read or written by means of [FB\_MDP\_Read](ms-xhelp:///?Id=beckhoff-ad49-4649-9ea7-8573d86221bd) and [FB\_MDP\_Write](ms-xhelp:///?Id=beckhoff-b0ad-4f66-8f40-eeb5e905e3f2). In addition to the dynamic Module ID, the number of the selected table (Table ID), the selected subindex within the table as well as further information is thereby specified for the query.

Likewise, the complete header of a module ([ST\_MDP\_ModuleHeader](ms-xhelp:///?Id=beckhoff-fd75-4db6-9a81-a42b0f28ebca)) can be queried with the function block [FB\_MDP\_ReadModuleHeader](ms-xhelp:///?Id=beckhoff-b786-40e5-ac5e-2e01ed8b3ab5).  
The complete contents of a selected table within a module can be queried with the function block [FB\_MDP\_ReadModuleContent](ms-xhelp:///?Id=beckhoff-d1b9-4dc1-8d4a-d6ba8f7859e6).

The function block [FB\_MDP\_ReadModule](ms-xhelp:///?Id=beckhoff-41df-4fcd-a4ec-addff9a1a977) bundles the above queries. The function block implicitly determines the dynamic Module ID and queries both header and table.  
The function block [FB\_MDP\_ReadElement](ms-xhelp:///?Id=beckhoff-4d16-4e37-af82-66a75badda9c) also determines the dynamic module ID implicitly. It can be used to query any individual IPC diagnostics parameter.  
Accordingly, with these two function blocks it is not necessary to call FB\_MDP\_ScanModules beforehand.

## Specific function blocks

The function blocks available here offer fast access to the most important IPC diagnostic information.

For example, it is sufficient to call the function block [FB\_MDP\_NIC\_Read](ms-xhelp:///?Id=beckhoff-cf3d-4f07-a1d7-71f6650550e0) in order to query all important information about a Network Interface Card (see Device Manager documentation [Module NIC](https://infosys.beckhoff.com/content/1033/devicemanager/54043195791459083.html)). The module header is also queried and output in each case.  
The specific function blocks likewise implicitly determine the dynamic Module ID, so that a prior call of [FB\_MDP\_ScanModules](ms-xhelp:///?Id=beckhoff-d602-4983-bfef-aeab48e864a1) is superfluous.

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
