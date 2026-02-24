# TcQueryInterface

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-c8bb-4182-8afb-4dae11b93466)
3. [TcBaseModuleRegistered](ms-xhelp:///?Id=beckhoff-f3ea-41a6-b69c-7e7d3c1e0a59)
4. TcQueryInterface

# TcQueryInterface

![24265995](/tcplclib_tc3_module/1033/Images/png/1902197131__Web.png)

Query of the reference to an implemented interface via the IID.

## Interface

**Parameter**

```
VAR_INPUT  
    iid    : REFERENCE TO IID;  
    pipItf : POINTER TO PVOID;  
END_VAR
```

**iid**: Interface ID

**pipItf**: Pointer to interface pointer. Is set when the requested interface type is available from the corresponding instance.

**Return value**

```
VAR_OUTPUT  
    TcQueryInterface : HRESULT;  
END_VAR
```

Gives information about success of the interface query.  
If the requested interface is not available, returns the ADS\_E\_NOINTERFACE method.

|  |  |
| --- | --- |
| 17067371 | Necessary release of the interface pointers  All references must be explicitly released again. It is recommended to use [FW\_SafeRelease](ms-xhelp:///?Id=beckhoff-818e-43af-a421-fa6c2298170d) in order to perform a release of the interface pointer after use. Frequently the release of the references is implemented in the destructor of the object. |

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
