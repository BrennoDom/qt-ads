# E_SeekOrigin

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_SeekOrigin

# E\_SeekOrigin

A variable of this type shows the origin point by moving the pointer.

```
TYPE E_SeekOrigin :  
(  
    SEEK_SET   := 0, (* Seek from beginning of file *)  
    SEEK_CUR,        (* Seek from current position of file pointer *)  
    SEEK_END         (* Seek from the end of file *)  
);  
END_TYPE
```

| Value | Description |
| --- | --- |
| SEEK\_SET | Seek from beginning of file |
| SEEK\_CUR | Seek from current position of file pointer |
| SEEK\_END | Seek from the end of file |

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
