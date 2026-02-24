# E_OpenPath

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_OpenPath

# E\_OpenPath

The variable of this type selects generic or one of the TwinCAT system paths on the target device to perform the file open operation.

```
TYPE E_OpenPath :  
(  
    PATH_GENERIC :=1, (* search/open/create files in selected/generic folder *)  
    PATH_BOOTPRJ,     (* search/open/create files in the TwinCAT/Boot directory (adds the extension .wbp) *)  
    PATH_BOOTDATA,    (* reserved for future use*)  
    PATH_BOOTPATH,    (* refers to the TwinCAT/Boot directory without adding an extension (.wbp) *)  
    PATH_USERPATH1 :=11, (*reserved for future use*)  
    PATH_USERPATH2,   (*reserved for future use*)  
    PATH_USERPATH3,   (*reserved for future use*)  
    PATH_USERPATH4,   (*reserved for future use*)  
    PATH_USERPATH5,   (*reserved for future use*)  
    PATH_USERPATH6,   (*reserved for future use*)  
    PATH_USERPATH7,   (*reserved for future use*)  
    PATH_USERPATH8,   (*reserved for future use*)  
    PATH_USERPATH9    (*reserved for future use*)  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
