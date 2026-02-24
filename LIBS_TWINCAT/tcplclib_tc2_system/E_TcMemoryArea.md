# E_TcMemoryArea

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Data types](ms-xhelp:///?Id=beckhoff-7553-4b92-b20d-33716049fde4)
3. E\_TcMemoryArea

# E\_TcMemoryArea

The [F\_CheckMemoryArea](ms-xhelp:///?Id=beckhoff-18a7-4764-b3bd-ed9fde2742c8) function returns information about the memory area in which the requested variable with the specified size is located. A return value of type E\_TcMemoryArea is used for this purpose.

```
{attribute 'qualified_only'}  
{attribute 'strict'}  
TYPE E_TcMemoryArea :  
(  
    Unknown := 0,  
    Static  := 1, // static PLC memory  
    Dynamic := 2, // dynamic memory  
    CNC     := 3  
)UDINT;  
END_TYPE
```

**Unknown**: The memory area is unknown. For example, this could be memory in a Windows context. The memory area is also output as unknown if the specified memory size results in two different memory areas being involved. Furthermore, the memory area is output as unknown if it is a stack memory.

**Static**: These are static PLC memories.

**Dynamic**: These are dynamically allocated memories, which were allocated during the runtime or during the initialization phase of the PLC.

**CNC**: These are memories of the CNC driver.

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x86, x64, ARM) | Tc2\_System (system) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
