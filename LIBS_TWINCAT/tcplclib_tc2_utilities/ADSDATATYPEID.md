# ADSDATATYPEID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ADSDATATYPEID

ADS data type ID. This data type is used by the function block [FB\_ReadSymInfoByNameEx](ms-xhelp:///?Id=beckhoff-dc93-4828-bfe7-f2f21f6281ea), for example.

```
TYPE ADSDATATYPEID :  
(  
    ADST_VOID     := 0,  
    ADST_INT8     := 16,  
    ADST_UINT8    := 17,  
    ADST_INT16    := 2,  
    ADST_UINT16   := 18,  
    ADST_INT32    := 3,  
    ADST_UINT32   := 19,  
    ADST_INT64    := 20,  
    ADST_UINT64   := 21,  
    ADST_REAL32   := 4,  
    ADST_REAL64   := 5,  
    ADST_BIGTYPE  := 65,  
    ADST_STRING   := 30,  
    ADST_WSTRING  := 31,  
    ADST_REAL80   := 32,  
    ADST_BIT      := 33,  
    ADST_MAXTYPES  
);  
END_TYPE
```

| Value | Meaning |
| --- | --- |
| ADST\_VOID | Reserved |
| ADST\_INT8 | Signed 8 bit integer |
| ADST\_UINT8 | Unsigned 8 bit integer |
| ADST\_INT16 | Signed 16 bit integer |
| ADST\_UINT16 | Unsigned 16 bit integer |
| ADST\_INT32 | Signed 32 bit integer |
| ADST\_UINT32 | Unsigned 32 bit integer |
| ADST\_INT64 | Signed 64 bit integer |
| ADST\_UINT64 | Unsigned 64 bit integer |
| ADST\_REAL32 | 32 bit floating point number |
| ADST\_REAL64 | 64 bit floating point number |
| ADST\_BIGTYPE | Structured type |
| ADST\_STRING | String type |
| ADST\_WSTRING | Wide character type |
| ADST\_REAL80 | Reserved |
| ADST\_BIT | Bit type |
| ADST\_MAXTYPES | Max. available type |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
