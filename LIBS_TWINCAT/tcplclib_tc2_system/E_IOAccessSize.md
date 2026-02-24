# E_IOAccessSize

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_IOAccessSize

# E\_IOAccessSize

Byte size of I/O position (number of bytes to be written or read).

```
TYPE E_IOAccessSize :  
(  
    NoOfByte_Byte  := 1,  
    NoOfByte_Word  := 2,  
    NoOfByte_DWord := 4  
);  
END_TYPE
```

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
