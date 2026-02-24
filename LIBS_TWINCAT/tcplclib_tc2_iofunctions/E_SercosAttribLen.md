# E_SercosAttribLen

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_SercosAttribLen

# E\_SercosAttribLen

```
TYPE E_SercosAttribLen : (  
    eLEN_2BYTE  := 1, (* 2 bytes, fixed length *)  
    eLEN_4BYTE  := 2, (* 4 bytes, fixed length *)  
    eLEN_8BYTE  := 3, (* 8 bytes, fixed length *)  
    eLEN_V1BYTE := 4, (* 1 bytes, variable length *)  
    eLEN_V2BYTE := 5, (* 2 bytes, variable length *)  
    eLEN_V4BYTE := 6, (* 4 bytes, variable length *)  
    eLEN_V8BYTE := 7 (* 8 bytes, variable length *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC (x86) | Sercans SCS-P ISA; Sercans SCS-P PCI; Beckhoff FC750x PCI | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
