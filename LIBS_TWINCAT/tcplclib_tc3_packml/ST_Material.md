# ST_Material

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. [Common](ms-xhelp:///?Id=beckhoff-b1fd-4f94-a947-c1aa38112b6b)
5. ST\_Material

# ST\_Material

This is a collection of tags that are used to describe different materials in the machine unit.

```
TYPE ST_Materials :   
STRUCT  
    RawMaterial         : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    CO2                 : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Container           : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Lubrication         : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Water               : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    ContainerClosures   : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
  
    (* 10 more unused *)  
    Unused0             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused1             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused2             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused3             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused4             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused5             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused6             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused7             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused8             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
    Unused9             : BOOL;(* ~ (OPC : 1: enabled for OPC ) *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
