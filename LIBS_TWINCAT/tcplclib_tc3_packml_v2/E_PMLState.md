# E_PMLState

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Data types](ms-xhelp:///?Id=beckhoff-7fd7-46e9-b451-6cfc9a6b313e)
4. E\_PMLState

# E\_PMLState

**E\_PMLState**

```
TYPE E_PMLState :   
(  
    (* states according to PackTags v3.0 *)  
    ePMLState_Undefined     := 0,  
    ePMLState_Clearing      := 1,  
    ePMLState_Stopped       := 2,  
    ePMLState_Starting      := 3,  
    ePMLState_Idle          := 4,  
    ePMLState_Suspended     := 5,  
    ePMLState_Execute       := 6,  
    ePMLState_Stopping      := 7,  
    ePMLState_Aborting      := 8,  
    ePMLState_Aborted       := 9,  
    ePMLState_Holding       := 10,  
    ePMLState_Held          := 11,  
    ePMLState_Unholding     := 12,  
    ePMLState_Suspending    := 13,  
    ePMLState_Unsuspending  := 14,  
    ePMLState_Resetting     := 15,  
    ePMLState_Completing    := 16,  
    ePMLState_Complete      := 17  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
