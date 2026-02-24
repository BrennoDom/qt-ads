# FW_ObjMgr_DeleteInstance

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. FW\_ObjMgr\_DeleteInstance

# FW\_ObjMgr\_DeleteInstance

![13148517](/tcplclib_tc3_module/1033/Images/png/1900393355__Web.png)

This function puts the object in the Init state. After that the reference counter of the object is decremented, analogous to ITcUnknown.TcRelease(), and the interface pointer is set to zero at the same time.

## Interface

**Parameter**

```
VAR_INPUT  
    pipUnk : POINTER TO ITcUnknown;  
END_VAR
```

**pipUnk**: specifies the address of the interface pointer to the object. The interface pointer is checked internally for null pointers.

**Return value**

```
VAR_OUTPUT  
    FW_ObjMgr_DeleteInstance : HRESULT;  
END_VAR
```

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
