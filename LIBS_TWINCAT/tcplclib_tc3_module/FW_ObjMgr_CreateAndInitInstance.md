# FW_ObjMgr_CreateAndInitInstance

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. FW\_ObjMgr\_CreateAndInitInstance

# FW\_ObjMgr\_CreateAndInitInstance

![963478](/tcplclib_tc3_module/1033/Images/png/1900464779__Web.png)

This function generates an instance of the class specified by means of Class-ID and at the same time return an interface pointer to this object. In addition the object name and state into which the object is to be put, as well as optionally also initialization parameters can be specified.

## Interface

**Parameter**

```
VAR_INPUT  
    clsId     : CLSID;  
    iid       : IID;  
    pipUnk    : POINTER TO ITcUnknown;  
    objId     : UDINT;  
    parentId  : UDINT;  
    name      : REFERENCE TO STRING;  
    state     : UDINT;  
    pInitData : POINTER TO TComInitDataHdr;  
END_VAR
```

**clsId**: specifies the class from which an object should be created.

**iid**: specifies the interface ID to which an interface pointer should be referenced.

**pipUnk**: returns the interface pointer to the created object.

**objId**: specifies the object ID for the newly created object. If the global constant OTCID\_CreateNewId is entered here a new object ID is generated internally.

**parentId**: object ID of the parent object (optional). Here the object ID of the PLC instance can be specified from which this function is called. (TwinCAT\_SystemInfoVarList.\_AppInfo.ObjId).

**name**: specifies the object name which should be assigned for the newly created object.

**state**: specifies the state into which the newly created object should be put. Typically Operational (TCOM\_STATE.TCOM\_STATE\_OP) is specified.

**pInitData**: Pointer to initialization parameter (optional)

**Return value**

```
VAR_OUTPUT  
    FW_ObjMgr_CreateAndInitInstance : HRESULT;  
END_VAR
```

|  |  |
| --- | --- |
| 8671305 | Necessary deletion of the object  A generated object must be explicitly deleted again. There is no Garbage-Collector as in .Net. It is recommended to use [FW\_ObjMgr\_DeleteInstance](ms-xhelp:///?Id=beckhoff-56ac-4d20-9507-131f65649bed), in order to delete the generated instance at the latest in the destructor of the object which created the instance. |

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
