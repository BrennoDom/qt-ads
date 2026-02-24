# F_IPCDiag_GetMdpIdx

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-3319-4dd0-851e-d5ecb0f774ff)
3. [Access by index specification](ms-xhelp:///?Id=beckhoff-ecbf-4c31-85ef-3a2175d6c259)
4. F\_IPCDiag\_GetMdpIdx

# F\_IPCDiag\_GetMdpIdx

The MDP (Modular Device Profile) information model lists all parameters with the help of areas, modules and tables. As the generic access to each parameter, an addressing is defined whose main component is the MDP index (2 bytes).

Details can be found in the documentation on the [Beckhoff Device Manager](https://infosys.beckhoff.com/content/1033/devicemanager/90071992810335755.html).

The function returns the MDP index for parameters from the MDP Configuration Area in order to enable parameter access via the MDP index ([FB\_IPCDiag\_ReadParameterByMdpIdx](ms-xhelp:///?Id=beckhoff-7291-42af-8929-9c46437e415b)).

Selection can be made by means of `nModuleIdx` if several instances of the module type exist. Internally, the function determines the dynamic module ID and appends it to the MDP index.

## VAR\_INPUT

```
VAR_INPUT  
    eModuleType   : E_IPCDiag_ModuleType;  
    nModuleIdx    : USINT; (* 1= first instance of this module type (= default) *)  
    nTableID      : BYTE;  
END_VAR  
VAR_IN_OUT  
    fbRegister    : FB_IPCDiag_Register;  
END_VAR
```

**eModuleType.** At this input is the IPC diagnostics module type is specified. The possible types are listed in the enumeration [E\_IPCDiag\_ModuleType](ms-xhelp:///?Id=beckhoff-4b54-4ecb-881a-a46d4f3ce88e). (Overview of the module types: (https://infosys.beckhoff.de/content/1031/devicemanager/99079192065133835.html))

**nModuleIdx.** Because there can be several instances of a module type in the system, the module index beginning with 1 is specified at this input.

**nTableID:** The table ID in which the parameter exists is specified at this input.

**fbRegister:** The instance of [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab) must be transferred so that the function can use the available information for the IPC diagnostic configuration on the target system.   
This instance must have been called beforehand. Otherwise an error is output.

## Return value

The function returns the determined MDP index.

In the event of an error, if the requested module is not available, the function returns a value of 0.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_IPCDiag |

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
