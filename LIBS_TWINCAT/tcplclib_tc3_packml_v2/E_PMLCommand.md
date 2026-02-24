# E_PMLCommand

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Data types](ms-xhelp:///?Id=beckhoff-7fd7-46e9-b451-6cfc9a6b313e)
4. E\_PMLCommand

# E\_PMLCommand

**E\_PMLCommand**

```
TYPE E_PMLCommand :   
(  
    (* states according to PackTags v3.0 *)  
    ePMLCommand_Undefined   := 0,  
    ePMLCommand_Reset       := 1,  
    ePMLCommand_Start       := 2,  
    ePMLCommand_Stop        := 3,  
    ePMLCommand_Hold        := 4,  
    ePMLCommand_Unhold      := 5,  
    ePMLCommand_Suspend     := 6,  
    ePMLCommand_Unsuspend   := 7,  
    ePMLCommand_Abort       := 8,  
    ePMLCommand_Clear       := 9  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
