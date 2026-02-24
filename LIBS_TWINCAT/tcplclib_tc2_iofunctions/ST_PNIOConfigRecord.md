# ST_PNIOConfigRecord

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. ST\_PNIOConfigRecord

# ST\_PNIOConfigRecord

```
TYPE ST_PNIOConfigRecord :  
STRUCT  
    iRW          : UINT;  
    iNumOfAR     : UINT;  
    iAPI         : UDINT;  
    iSlot        : UINT;  
    iSubSlot     : UINT;  
    stPNIORecord : ST_PNIORecord;  
END_STRUCT  
END_TYPE
```

**iRW**: 0: Read, 1: Write.

**iNumOfAR**: number of arguments.

**iAPI**: API number.

**iSlot**: slot number.

**iSubSlot**: sub-slot number.

**stPNIORecord**: (Type: [ST\_PNIORecord](ms-xhelp:///?Id=beckhoff-4028-486d-a5b2-cef59c9e538e)).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | Beckhoff EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
