# MEMSET

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [Memory functions](ms-xhelp:///?Id=beckhoff-f839-4f86-a878-af33bbed7485)
4. MEMSET

# MEMSET

![53989823](/tcplclib_tc2_system/1033/Images/png/9007199286138763__Web.png)

The function MEMSET allows PLC variables in a particular memory area to be set to a particular value.

## FUNCTION MEMSET : UDINT

```
VAR_INPUT  
    destAddr : PVOID;  
    fillByte : USINT;  
    n        : UDINT;  
END_VAR
```

**destAddr**: Start address of the memory area that is to be set.

**fillByte**: Value of the filler byte.

**n**: Number of bytes to be set.

The function fills n bytes in the memory area that starts at address destAddr with the value specified by fillByte.

| Return parameter | Meaning |
| --- | --- |
| 0 | Incorrect parameter values. destAddr == 0 or n == 0 |
| > 0 | If successful, the number of bytes that have been set (n). |

**Example of a call in FBD:**

```
PROGRAM MAIN  
VAR  
    Buffer1 : ARRAY[0..3] OF BYTE;  
    SetResult : UDINT;  
END_VAR
```

![16146366](/tcplclib_tc2_system/1033/Images/png/31400971__en-US__Web.png)

In the example, 4 bytes in Buffer1 are set to the value 0xAF.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
