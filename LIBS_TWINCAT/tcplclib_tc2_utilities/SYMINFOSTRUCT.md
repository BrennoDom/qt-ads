# SYMINFOSTRUCT

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# SYMINFOSTRUCT

TwinCAT PLC symbol information.

```
TYPE SYMINFOSTRUCT :  
STRUCT  
    symEntryLen  : UDINT;  
    idxGroup     : UDINT;  
    idxOffset    : UDINT;  
    byteSize     : UDINT;  
    adsDataType  : ADSDATATYPEID;  
    symDataType  : T_MaxString;  
    symComment   : T_MaxString;  
END_STRUCT  
END_TYPE
```

**symEntryLen**: The actual length in bytes of the symbol entry in the symbol table. The symbols are stored in a symbol table. The length of the individual entries is variable, and depends on the length of the symbol name, the type identifier and the comment.

**idxGroup**: The index group of the symbolic variables;

**idxOffset**: The index offset of the symbolic variables;

**byteSize**: The amount of memory, in bytes, actually occupied by the value of the symbolic variables. A boolean PLC variable, for instance, occupies one byte, while a string with 20 characters in fact occupies 21 bytes (20 bytes for characters plus one byte for the zero marking the end of the string);

**adsDataType**: The ADS data type ID. (Type: [ADSDATATYPEID](ms-xhelp:///?Id=beckhoff-c22a-46b3-835e-af266d488fc0)) This type identifier is used in ADS access to symbolic variables. All PLC structures and arrays (self-defined data types) have the ADS data type ID: ADST\_BIGTYPE and cannot be identified via this data type constant. In order to be able to identify the user-defined data types, use the *symDataType* variable, or read the base type of the individual variables in the structure.

**symDataType**: The data type identification of the symbolic variable as a string. For instance this might be the type name of a PLC data structure defined by the user (type: T\_MaxString, max. 255 characters).

**symComment**: A comment on the symbolic variable that the user has added to the PLC variable definition line (type: T\_MaxString, max. 255 characters).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
