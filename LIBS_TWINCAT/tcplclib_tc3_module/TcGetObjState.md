# TcGetObjState

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59)
4. TcGetObjState

# TcGetObjState

![2696221](/tcplclib_tc3_module/1033/Images/png/1902281355__Web.png)

The TcGetObjState method queries the current state of the object.

## Interface

**Parameter**

```
VAR_INPUT  
    pState : POINTER TO TCOM_STATE;  
END_VAR
```

**pState**: Pointer to the state

**Return value**

```
VAR_OUTPUT  
    TcGetObjState : HRESULT;  
END_VAR
```

Gives information about success of the state query.

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
