# TcGetObjectId

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59)
4. TcGetObjectId

# TcGetObjectId

![49621912](/tcplclib_tc3_module/1033/Images/png/1902337291__Web.png)

The method TcGetObjectId saves the object ID with the help of the given OTCID reference.

## Interface

**Parameter**

```
VAR_INPUT  
    objId : REFERENCE TO OTCID;  
END_VAR
```

**objId**: Reference to OTCID value

**Return value**

```
VAR_OUTPUT  
    TcGetObjectId : HRESULT;  
END_VAR
```

Gives information about success of the OTCID query.

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
