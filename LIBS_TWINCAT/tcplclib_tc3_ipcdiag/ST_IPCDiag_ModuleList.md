# ST_IPCDiag_ModuleList

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Data types](ms-xhelp:///?Id=beckhoff-b9ab-473c-b827-d56bd995675b)
3. ST\_IPCDiag\_ModuleList

# ST\_IPCDiag\_ModuleList

The function block [FB\_IPCDiag\_Register](ms-xhelp:///?Id=beckhoff-40f5-4c32-904a-27fa7d3f2bab) creates a list of all modules that are active on the system. Modules are parts of the MDP (Modular Device Profile) and contain diagnostic parameters that are hereby grouped.

Each module list is valid for one target system, which is specified via the AMS Net Id.

```
TYPE ST_IPCDiag_ModuleList :  
STRUCT  
    aModules  : ARRAY[0..255] OF ST_IPCDiag_Module;    (* array idx = nModId of the module *)  
    nModules  : UINT;        (* number of all instantiated modules (max.256) *)  
    sNetId    : T_AmsNetID;  
END_STRUCT  
END_TYPE
```

Detailed information on MDP addressing can be found in the documentation on the [Beckhoff Device Manager](https://infosys.beckhoff.de/content/1033/devicemanager/99079192065129227.html).

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
