# FW_SafeRelease

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Functions](ms-xhelp:///?Id=beckhoff-c644-4e9d-b511-07e59f8f2d08)
3. FW\_SafeRelease

# FW\_SafeRelease

![55810719](/tcplclib_tc3_module/1033/Images/png/1900251915__Web.png)

This function decrements the reference counter of the object, analogous to ITcUnknown.TcRelease(), and at the same time sets the interface pointer to zero.

## Interface

**Parameter**

```
VAR_INPUT  
    pipUnk : POINTER TO ITcUknown;  
END_VAR
```

**pipUnk**: specifies the address of the interface pointer to the object. The interface pointer is checked internally for null pointers.

**Return value**

```
VAR_OUTPUT  
    FW_SafeRelease : HRESULT;  
END_VAR
```

## Sample

This function can for example be called in the destructor of the object family, which holds an interface pointer to another object.

```
METHOD FB_exit : BOOL  
VAR_INPUT  
    bInCopyCode : BOOL; // if TRUE, the exit method is called for exiting an instance that is copied afterwards (online change).  
END_VAR  
-----------------------------------------------------------------------
```

```
IF NOT bInCopyCode THEN // no online change  
    FW_SafeRelease(ADR(ipItf));  
END_IF
```

## Requirements

| TwinCAT Version | Hardware | Libraries to be integrated |
| --- | --- | --- |
| TwinCAT 3.1, Build 4020 | x86, x64, ARM | Tc3\_Module |

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
