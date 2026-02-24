# MEMCMP

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [Memory functions](ms-xhelp:///?Id=beckhoff-f839-4f86-a878-af33bbed7485)
4. MEMCMP

# MEMCMP

![31767774](/tcplclib_tc2_system/1033/Images/png/9007199286125963__Web.png)

The function MEMCMP allows the values of PLC variables in two different memory areas to be compared.

## FUNCTION MEMCMP : DINT

```
VAR_INPUT  
    pBuf1 : PVOID;  
    pBuf2 : PVOID;  
    n     : UDINT;  
END_VAR
```

**pBuf1**: Start address of the first memory area (the first data buffer).

**pBuf2**: Start address of the second memory area (the second data buffer).

**n**: Number of bytes to be compared.

The function compares the first n bytes in the two data buffers and returns a value that corresponds to their relationship.

| Return parameter | Relationship of the first byte that differs between the first and second data buffers |
| --- | --- |
| -1 | pBuf1 smaller than pBuf2 |
| 0 | pBuf1 identical to pBuf2 |
| 1 | pBuf1 greater than pBuf2 |
| 0xFF | Incorrect parameter values. pBuff1 = 0 or pBuff2 = 0 or n = 0 |

**Example of a call in FBD:**

```
PROGRAM MAIN  
VAR  
    Buffer1   : ARRAY[0..3] OF BYTE;  
    Buffer2   : ARRAY[0..3] OF BYTE;  
    CmpResult : DINT;  
END_VAR
```

![17474517](/tcplclib_tc2_system/1033/Images/png/31388171__en-US__Web.png)

In this example, 4 bytes of data in Buffer2 are compared with those in Buffer1. The first differing byte is larger in Buffer1 than it is in Buffer2.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
