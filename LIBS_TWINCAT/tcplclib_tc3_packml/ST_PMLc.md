# ST_PMLc

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. ST\_PMLc

# ST\_PMLc

This is the collection of all command tags in the PackTag structure.

```
TYPE ST_PMLc :   
STRUCT  
    UnitMode                       : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    UnitModeChangeRequest          : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcMode                       : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcModeChangeRequest          : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    CurMachSpeed                   : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    MatReady                       : ST_Materials;(* ~ (OPC : 1: enabled for OPC ) *)  
    MatLow                         : ST_Materials;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    State                          : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    StateChangeRequest             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    CntrlCmd                       : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Node                           : ARRAY [1..iMAX_NODES] OF ST_Node;(* ~ (OPC : 1: enabled for OPC ) *)  
    ProcessVariables               : ARRAY [1..iMAX_PROCESS_VARS] OF ST_Descriptor;(* ~ (OPC : 1: enabled for OPC ) *)  
    Product                        : ARRAY [1..iMAX_PRODUCTS] OF ST_Product;(* ~ (OPC : 1: enabled for OPC ) *)  
    Limits                         : ARRAY [1..iMAX_LIMITS] OF ST_Descriptor;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    TargetDownstreamNodeID         : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    TargetUpstreamNodeID           : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ChangeNodeServicedUpstream     : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ChangeNodeServicedDownstream   : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
