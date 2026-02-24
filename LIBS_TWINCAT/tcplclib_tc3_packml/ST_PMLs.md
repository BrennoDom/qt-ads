# ST_PMLs

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. ST\_PMLs

# ST\_PMLs

This is the collection of all status tags in the PackTag structure.

```
TYPE ST_PMLs :   
STRUCT  
    CommandRejected                : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    UnitModeCurrent                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    UnitModeRequested              : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    UnitModeChangeInProcess        : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcModeCurrent                : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcModeRequested              : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcModeChangeInProcess        : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateCurrent                   : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateRequested                 : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateChangeInProcess           : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateChangeProgress            : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateLastCompleted             : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    SeqNumber                      : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    CurMachSpd                     : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    MatReady                       : ST_Materials;(* ~ (OPC : 1: enabled for OPC ) *)  
    MatLow                         : ST_Materials;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    MachDesignSpeed                : REAL;(* ~ (OPC : 1: enabled for OPC ) *)  
    MachCycle                      : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProdRatio                      : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Dirty                          : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Clean                          : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    TimeToDirty                    : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    EquipmentAllocatedToUnitModelID: DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    MachineReusableForUnitModelID  : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    MachineReusableTimeLeft        : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    MachineStoringProductID        : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    MachineTransferringProductID   : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    Node                           : ARRAY [1..iMAX_NODES] OF ST_Node;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcessVariables               : ARRAY [1..iMAX_PROCESS_VARS] OF ST_Descriptor;(* ~ (OPC : 1: enabled for OPC ) *)  
    Product                        : ARRAY [1..iMAX_PRODUCTS] OF ST_Product;(* ~ (OPC : 1: enabled for OPC ) *)  
    Limits                         : ARRAY [1..iMAX_LIMITS] OF ST_Descriptor;(* ~ (OPC : 1: enabled for OPC ) *)  
  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
