# ST_Dpv1ValueHeaderEx

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_Dpv1ValueHeaderEx

# ST\_Dpv1ValueHeaderEx

ST\_Dpv1ValueHeaderEx contains the data of a parameter in the DPV1 telegram and its string representation.

```
TYPE ST_Dpv1ValueHeaderEx :  
STRUCT  
    eFormat      : E_PD_Datatype;  
    iNumOfValues : USINT;  
    iOffset      : USINT;  
    iDataLen     : UINT;  
    strData      : STRING;  
END_STRUCT  
END_TYPE
```

**eFormat**: 0x01..0x36: data type; 0x40: ZERO; 0x41: BYTE; 0x42: WORD; 0x43: DWORD; 0x44: error; other values are reserved. (Type: [E\_PD\_Datatype](ms-xhelp:///?Id=beckhoff-353b-4a90-974c-f585e4873b7f)).

**iNumOfValues**: 0 to 234: number of values; other values are reserved.

**iOffset**: Offset in the DPV1 response telegram.

**iDataLen**: Data length.

**strData**: Data as STRING.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Beckhoff FC310x PCI, CX1500-M310, EL6731, EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
