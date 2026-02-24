# ST_PMLSubUnitInfoRef

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine State](ms-xhelp:///?Id=beckhoff-bf11-4534-b5f5-a9e819d4a1bd)
3. [Data types](ms-xhelp:///?Id=beckhoff-7fd7-46e9-b451-6cfc9a6b313e)
4. ST\_PMLSubUnitInfoRef

# ST\_PMLSubUnitInfoRef

**ST\_PMLSubUnitInfoRef**

```
TYPE ST_PMLSubUnitInfoRef :   
STRUCT  
    pArray           : POINTER TO ST_PMLSubUnitInfo;  
    nArraySize       : UDINT;  
    nNoOfSubUnits    : UDINT;  
END_STRUCT  
END_TYPE
```

|  |  |
| --- | --- |
| pArray | Address of a one-dimensional array of the type ST\_PMLSubUnitInfo. Each array element contains the state of a subordinated machine part.  Example:  stSubUnitInfo : ARRAY[1..10] OF ST\_PMLSubUnitInfo;  pArray := ADR(stSubUnitInfo); |
| nArraySize | Memory size of the one-dimensional array, which can be determined with the SIZEOF function.  Example:  nArraySize := SIZEOF(stSubUnitInfo); |
| nNoOfSubUnits | Number of relevant subordinated machine parts. |

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
