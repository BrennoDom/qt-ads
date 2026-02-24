# TcSetObjectName

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59)
4. TcSetObjectName

# TcSetObjectName

![26973745](/tcplclib_tc3_module/1033/Images/png/1901910795__Web.png)

The TcSetObjectName method sets the object name of the object.

## Interface

**Parameter**

```
VAR_INPUT  
    objName : POINTER TO SINT;  
END_VAR
```

**objName**: the name to be set of the object

**Return value**

```
VAR_OUTPUT  
    TcSetObjectName : HRESULT;  
END_VAR
```

Gives information about success of the name change.

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
