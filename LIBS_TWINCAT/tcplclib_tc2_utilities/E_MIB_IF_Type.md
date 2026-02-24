# E_MIB_IF_Type

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_MIB\_IF\_Type

Management information base interface type.

```
TYPE E_MIB_IF_Type :  
(  
    MIB_IF_TYPE_OTHER      := 1,  
    MIB_IF_TYPE_ETHERNET   := 6,  
    MIB_IF_TYPE_TOKENRING  := 9,  
    MIB_IF_TYPE_FDDI       := 15,  
    MIB_IF_TYPE_PPP        := 23,  
    MIB_IF_TYPE_LOOPBACK   := 24,  
    MIB_IF_TYPE_SLIP       := 28  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
