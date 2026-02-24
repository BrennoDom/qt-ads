# ST_IPCDiag_Module

## Library
tcplclib_tc3_ipcdiag

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
2. [Data types](ms-xhelp:///?Id=beckhoff-b9ab-473c-b827-d56bd995675b)
3. ST\_IPCDiag\_Module

# ST\_IPCDiag\_Module

The structure contains module information about a module instance. The module type, the module index (if several modules of a type exist) and the dynamically created module ID are specified.

```
TYPE ST_IPCDiag_Module :  
STRUCT  
    eModType   : E_IPCDiag_ModuleType;  
    nModId     : BYTE;     (* dynamically created module id *)  
    nModIdx    : USINT;    (* 1= first instance of this module type (= default) *)  
    nModCnt    : USINT;    (* quantity of instances of this module type in the module list *)  
END_STRUCT  
END_TYPE
```

[TwinCAT 3 | PLC Library: Tc3\_IPCDiag](ms-xhelp:///?Id=beckhoff-3a11-4a24-824c-cda994a70d48)
