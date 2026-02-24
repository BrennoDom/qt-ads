# ST_Dpv1ParamAddrEx

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_Dpv1ParamAddrEx

# ST\_Dpv1ParamAddrEx

ST\_Dpv1ParamAddrEx contains the data of a Profidrive parameter.

```
TYPE ST_Dpv1ParamAddrEx :  
STRUCT  
    iAttribute       : USINT;  
    iNumOfElements   : USINT;  
    iParameterNumber : UINT;  
    iSubIndex        : UINT;  
    iDataAddr        : PVOID;  
    iDataSize        : UDINT;  
    eFormat          : E_PD_Datatype;  
    iNumOfValues     : UINT;  
    iErrorValue      : UDINT;  
    stError          : ST_PD_Dpv1Error;  
END_STRUCT  
END_TYPE
```

**iAttribute**: 0x10: value; 0x20: description; 0x30: text; 0x80..F0: manufacturer-specific; other values are reserved.

**iNumOfElements**: 1 to 234: number of elements; 0: special functions; other values are reserved.

**iParameterNumber**: 1 to 65535: parameter number; 0: reserved.

**iSubIndex**: 0 to 65535: sub-index.

**iDataAddr**: address of the buffer/address of the PLC variables.

**iDataSize**: size of the buffer/size of the PLC variables.

**eFormat**: 0x01..0x36: data type; 0x40: ZERO; 0x41: BYTE; 0x42: WORD; 0x43: DWORD; 0x44: error; other values are reserved. (Type: [E\_PD\_Datatype](ms-xhelp:///?Id=beckhoff-353b-4a90-974c-f585e4873b7f)).

**iNumOfValues**: 0 to 234: number of values; other values are reserved.

**iErrorValue**: DPV1 error value.

**stError**: DPV1 error flag, DPV1 error enumeration type. (Type: [ST\_PD\_Dpv1Error](ms-xhelp:///?Id=beckhoff-c3bb-4ba9-b74e-9dab65c1d507)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Beckhoff FC310x PCI, CX1500-M310, EL6731, EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
