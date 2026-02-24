# FW_ObjMgr_GetObjectInstance

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. FW\_ObjMgr\_GetObjectInstance

# FW\_ObjMgr\_GetObjectInstance

![51227795](/tcplclib_tc3_module/1033/Images/png/1900371851__Web.png)

This function returns an interface pointer to an object instance specified by means of object ID.

## Interface

**Parameter**

```
VAR_INPUT  
    oid    : OTCID;  (*OID of object*)  
    iid    : IID;  (*requested interface*)  
    pipUnk : POINTER TO ITcUnknown;  
END_VAR
```

**oid**: Object ID

**iid**: specifies the interface ID to which an interface pointer should be referenced.

**pipUnk**: returns the interface pointer to the created object.

**Return value**

```
VAR_OUTPUT  
    FW_ObjMgr_GetObjectInstance : HRESULT;  
END_VAR
```

|  |  |
| --- | --- |
| 58396974 | Necessary release of the interface pointers  All references must be explicitly released again. It is recommended to use [FW\_SafeRelease](ms-xhelp:///?Id=beckhoff-818e-43af-a421-fa6c2298170d) in order to perform a release of the interface pointer after use. Frequently the release of the references is implemented in the destructor of the object. |

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
