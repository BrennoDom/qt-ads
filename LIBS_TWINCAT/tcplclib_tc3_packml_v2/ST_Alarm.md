# ST_Alarm

## Library
tcplclib_tc3_packml_v2

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
2. [Packaging Machine Tags](ms-xhelp:///?Id=beckhoff-0c75-4616-a6ff-b521c2c6af13)
3. [Data types](ms-xhelp:///?Id=beckhoff-4be9-468e-8b2f-d15744b645c5)
4. [Alarm](ms-xhelp:///?Id=beckhoff-b590-4091-9cd1-70ab440b0f58)
5. ST\_Alarm

# ST\_Alarm

Collection of tags for the description of alarm events.

```
TYPE ST_Alarm :   
STRUCT  
    Trigger             : BOOL;  
    Id                  : DINT;  
    Value               : DINT;  
    Message             : STRING;  
    Category            : DINT;  
    DateTime            : ARRAY [0..6] OF DINT;  
    AckDateTime         : ARRAY [0..6] OF DINT;  
END_STRUCT  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1 Build 4018 and higher | PC (i386) | Tc3\_PackML\_V2 |

[TwinCAT 3 | PLC Library: Tc3\_PackML\_V2](ms-xhelp:///?Id=beckhoff-962e-4424-bd3f-3a66f7e32e10)
