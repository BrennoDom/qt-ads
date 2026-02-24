# E_ArgType

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# E\_ArgType

Internal argument type ID. This type is used by string format functions/function blocks.

```
TYPE E_ArgType :  
(  
    ARGTYPE_UNKNOWN     := 0,  
    ARGTYPE_BYTE,  
    ARGTYPE_WORD,  
    ARGTYPE_DWORD,  
    ARGTYPE_REAL,  
    ARGTYPE_LREAL,  
    ARGTYPE_SINT,  
    ARGTYPE_INT,  
    ARGTYPE_DINT,  
    ARGTYPE_USINT,  
    ARGTYPE_UINT,  
    ARGTYPE_UDINT,  
    ARGTYPE_STRING,  
    ARGTYPE_BOOL,  
    ARGTYPE_BIGTYPE,  
    ARGTYPE_ULARGE,  
    ARGTYPE_UHUGE,  
    ARGTYPE_LARGE,  
    ARGTYPE_HUGE,  
    ARGTYPE_LWORD  
);  
END_TYPE
```

| Value | Corresponding PLC data type |
| --- | --- |
| ARGTYPE\_UNKNOWN | Type is unknown or not initialized |
| ARGTYPE\_BYTE | BYTE (8 bits) |
| ARGTYPE\_WORD | WORD (16 bits) |
| ARGTYPE\_DWORD | DWORD (32 bits) |
| ARGTYPE\_REAL | REAL |
| ARGTYPE\_LREAL | LREAL |
| ARGTYPE\_SINT | SINT |
| ARGTYPE\_INT | INT |
| ARGTYPE\_DINT | DINT |
| ARGTYPE\_USINT | USINT |
| ARGTYPE\_UINT | UINT |
| ARGTYPE\_UDINT | UDINT |
| ARGTYPE\_STRING | String of type: T\_MaxString |
| ARGTYPE\_BOOL | BOOL |
| ARGTYPE\_BIGTYPE | Any data structure or byte buffer |
| ARGTYPE\_ULARGE | T\_ULARGE\_INTEGER or ULINT (unsigned 64-bit integer) |
| ARGTYPE\_UHUGE | T\_UHUGE\_INTEGER (unsigned 128 bit integer) |
| ARGTYPE\_LARGE | T\_LARGE\_INTEGER or LINT (signed 64 bit integer) |
| ARGTYPE\_HUGE | T\_HUGE\_INTEGER (signed 128 bit integer) |
| ARGTYPE\_LWORD | LWORD (64 bits) |

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
