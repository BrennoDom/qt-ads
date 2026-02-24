# F_IOPortRead

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Functions](ms-xhelp:///?Id=beckhoff-b451-4201-bd8f-306f1c54b27f)
3. [I/O port access](ms-xhelp:///?Id=beckhoff-d412-4c54-83d8-aeba44740875)
4. F\_IOPortRead

# F\_IOPortRead

![12819762](/tcplclib_tc2_system/1033/Images/png/9007199286084363__Web.png)

A digital I/O port is usually an I/O position with a width of 1 byte, which is mapped either in the memory or as a port. If a value is written at this point, the electrical signal at the output pins is modified according to the written bits. If a value is read from the input position, the current logical level at the input pins is returned as an individual bit value.

The function F\_IOPortRead can be used to read an I/O position with a width of eSize. The function returns the read value as return parameter. See also description of the [F\_IOPortWrite](ms-xhelp:///?Id=beckhoff-2d4d-4ba4-bb8a-d9c8a7509890) function.

## FUNCTION F\_IOPortRead : DWORD

```
VAR_INPUT  
    nAddr : UDINT;  
    eSize : E_IOAccessSize;  
END_VAR
```

**nAddr**: I/O port address.

**eSize**: Number of data bytes to be read (type: [E\_IOAccessSize](ms-xhelp:///?Id=beckhoff-d76e-4614-835e-a2a0d0a0341d)).

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
