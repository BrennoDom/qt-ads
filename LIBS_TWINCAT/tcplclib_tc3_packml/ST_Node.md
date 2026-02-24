# ST_Node

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine Functional Tag Description](ms-xhelp:///?Id=beckhoff-cfa1-4cf2-bed5-de71541a6707)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-9ab3-480d-a692-669d690fad49)
4. [Common](ms-xhelp:///?Id=beckhoff-b1fd-4f94-a947-c1aa38112b6b)
5. ST\_Node

# ST\_Node

This is a collection of tags that are used to describe communication command values between machines using the PackTag structure.

```
TYPE ST_Node :   
STRUCT  
    Number              : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    ControlCmdNumber    : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    CmdValue            : DINT;(* ~ (OPC : 1: enabled for OPC ) *)  
    Parameter           : ARRAY [1..iMAX_NODE_PARAMS] OF ST_Descriptor; (* ~ (OPC : 1: enabled for OPC ) *)  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
