# E_PMLState

## Library
tcplclib_tc3_packml

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-a3d4-4ab9-9d45-3f6129419cf0)
3. [DataTypes](ms-xhelp:///?Id=beckhoff-bea2-459d-9d22-156f058cbf6e)
4. E\_PMLState

# E\_PMLState

**E\_PMLState**

```
TYPE E_PMLState : (  
    (* states according to PackTags v3.0 *)  
    ePMLState_UNDEFINED     := 0,  
    ePMLState_CLEARING      := 1,  
    ePMLState_STOPPED       := 2,  
    ePMLState_STARTING      := 3,  
    ePMLState_IDLE          := 4,  
    ePMLState_SUSPENDED     := 5,  
    ePMLState_EXECUTE       := 6,  
    ePMLState_STOPPING      := 7,  
    ePMLState_ABORTING      := 8,  
    ePMLState_ABORTED       := 9,  
    ePMLState_HOLDING       := 10,  
    ePMLState_HELD          := 11,  
    ePMLState_UNHOLDING     := 12,  
    ePMLState_SUSPENDING    := 13,  
    ePMLState_UNSUSPENDING  := 14,  
    ePMLState_RESETTING     := 15,  
    ePMLState_COMPLETING    := 16,  
    ePMLState_COMPLETE      := 17  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to be linked |
| --- | --- | --- |
| TwinCAT v3.1, build 4018 onwards | PC (i386) | Tc3\_PackML |

[TwinCAT 3 | PLC Library: Tc3\_PackML](ms-xhelp:///?Id=beckhoff-59be-4392-80fb-0b021151334d)
