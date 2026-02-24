# E_SoE_AttribLen

## Library
tcplclib_tc2_drive

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
2. [Data types](ms-xhelp:///?Id=beckhoff-88b6-4469-8360-19ad9f778595)
3. [SERCOS](ms-xhelp:///?Id=beckhoff-4caa-4381-82bf-3f8474c57300)
4. E\_SoE\_AttribLen

# E\_SoE\_AttribLen

The enumeration E\_SoE\_AttribLen in the attribute of a parameter specifies whether the value of the parameter is a 2, 4, or 8-byte data type (single value), or whether it is a list consisting of 1, 2, 4, or 8-byte data types. List types (with eSoE\_LEN\_V...) first have the current list length in bytes (in a 16 bit value), then the maximum list length in bytes (in a 16 bit value) and the actual list in the specified data type.

**Sample:** see [ST\_SoE\_String](ms-xhelp:///?Id=beckhoff-5783-45f0-82ae-885406e451c0) of the eSoE\_LEN\_V1BYTE type.

```
TYPE E_SoE_AttribLen : (  
    eSoE_LEN_2BYTE  := 1,  
    eSoE_LEN_4BYTE  := 2,  
    eSoE_LEN_8BYTE  := 3,  
    eSoE_LEN_V1BYTE := 4,  
    eSoE_LEN_V2BYTE := 5,  
    eSoE_LEN_V4BYTE := 6,  
    eSoE_LEN_V8BYTE := 7  
    );  
END_TYPE
```

| Name | Description |
| --- | --- |
| **eSoE\_LEN\_2BYTE** | 2-byte data type (e.g. UINT, INT, WORD, IDN) |
| **eSoE\_LEN\_4BYTE** | 4-byte data type (e.g. UDINT, DINT, DWORD, REAL) |
| **eSoE\_LEN\_8BYTE** | 8-byte data type (e.g. ULINT, LINT, LREAL) |
| **eSoE\_LEN\_V1BYTE** | List of 1-byte data types (e.g. string) |
| **eSoE\_LEN\_V2BYTE** | List of 2-byte data types (e.g. IDN list) |
| **eSoE\_LEN\_V4BYTE** | List of 4-Byte data types |
| **eSoE\_LEN\_V8BYTE** | List of 8-Byte data types |

[TwinCAT 3 | PLC Library: Tc2\_Drive](ms-xhelp:///?Id=beckhoff-2e0d-4470-8b4a-e1efaef0d787)
