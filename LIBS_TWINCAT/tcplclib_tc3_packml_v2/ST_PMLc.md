# ST_PMLc

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. [Data types](ms-xhelp:///?Id=beckhoff-4be9-468e-8b2f-d15744b645c5)
4. ST\_PMLc

# ST\_PMLc

Collection of all Command tags of the PackTag structure.

```
TYPE ST_PMLc :   
STRUCT  
    UnitMode               : DINT;  
    UnitModeChangeRequest  : BOOL;  
    MachSpeed              : REAL;  
    MaterialInterlock      : DINT;  
    CntrlCmd               : DINT;  
    CmdChangeRequest       : BOOL;  
    RemoteInterface        : ARRAY [1..MaxCommandRemoteInterfaces] OF ST_Interface;  
    Parameter              : ARRAY [1..MaxCommandParameters] OF ST_Descriptor;  
    Product                : ARRAY [1..MaxCommandProducts] OF ST_Product;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
