# T_Arg

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# T\_Arg

Argument type for string format functions/function blocks.

```
TYPE T_Arg :  
STRUCT  
    eType : E_ArgType := ARGTYPE_UNKNOWN;  
    cbLen : UDINT     := 0;  
    pData : PVOID     := 0;  
END_STRUCT  
END_TYPE
```

**eType**: Data type ID (type: [E\_ArgType](ms-xhelp:///?Id=beckhoff-c5e7-4039-bda9-a85419af64d7)).

**cbLen**: Number of bytes allocated in the memory.

**pData**: Address pointer.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
