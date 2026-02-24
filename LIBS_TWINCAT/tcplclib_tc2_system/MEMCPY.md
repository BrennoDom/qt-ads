# MEMCPY

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [Memory functions](ms-xhelp:///?Id=beckhoff-f839-4f86-a878-af33bbed7485)
4. MEMCPY

# MEMCPY

![23052927](/tcplclib_tc2_system/1033/Images/png/9007199286132363__Web.png)

The function MEMCPY can be used to copy the values of PLC variables from one memory area to another.

## FUNCTION MEMCPY : UDINT

```
VAR_INPUT  
    destAddr  : PVOID;  
    srcAddr   : PVOID;  
    n         : UDINT;  
END_VAR
```

**destAddr**: Start address of the target memory area.

**srcAddr**: Start address of the source memory area.

**n**: Number of bytes to be copied.

The function copies n bytes from the memory area that starts at srcAddr to the memory area that starts at destAddr.

| Return parameter | Meaning |
| --- | --- |
| 0 | Incorrect parameter values. destAddr == 0 or srcAddr==0 or n == 0 |
| > 0 | If successful, the number of bytes copied (n). |

**Example of a call in FBD:**

```
PROGRAM MAIN  
VAR  
    Buffer1   : ARRAY[0..3] OF BYTE;  
    Buffer2   : ARRAY[0..3] OF BYTE;  
    CpyResult : UDINT;  
END_VAR
```

![6149759](/tcplclib_tc2_system/1033/Images/png/31394571__en-US__Web.png)

In the example, 4 bytes are copied from Buffer2 to Buffer1.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
