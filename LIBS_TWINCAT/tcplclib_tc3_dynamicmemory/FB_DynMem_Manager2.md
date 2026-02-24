# FB_DynMem_Manager2

## Library
tcplclib_tc3_dynamicmemory

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-4863-40bb-a59e-143483b0643b)
3. FB\_DynMem\_Manager2

# FB\_DynMem\_Manager2

This function block provides the possibility to dynamically allocate memory and to release it again. Integrated counters indicate the memory consumption and thus enable an overview of the already allocated memory.

It is entirely up to the user to decide whether an instance is used across the entire application or whether several individual instances are used for different program parts. With larger applications, the latter may be advantageous in the case of diagnosis. This function block is capable of multi-tasking and an instance can thus be used from various task contexts.

If the function block determines that not all of the allocated memory has already been released when shutting down the PLC, an error message is sent as an event to the TC3 Event Logger.

The function block FB\_DynMem\_Manager2 extends FB\_DynMem\_Manager by the knowledge of the size of the allocated memory blocks. This simplifies the memory release by means of the method Free2(), because the size of the memory block does not need to be specified.

## Properties

**nAllocatedSize**: indicates the current size in bytes of memory allocated with this function block instance.

**nBufferCount**: indicates the current size of buffer allocated with this function block instance.

**nObjectCount**: - future reserved -

## Methods

**Alloc():**

This method dynamically allocates memory and returns a pointer to this memory block. If allocation fails, e.g. because no free memory is available, the method returns ZERO.

An indication is given next to the desired size in bytes as to whether the memory block should be zeroed.

```
METHOD Alloc : PVOID  
VAR_INPUT  
    nSize    : UDINT;    // requested size in bytes  
    bReset   : BOOL;     // zero the allocated memory      
END_VAR
```

**Free2():**

This method releases previously allocated memory again. The memory block must have been allocated with the same function block instance beforehand.

```
METHOD Free2  
VAR_INPUT  
    p       : REFERENCE TO PVOID; // the given pointer is reset to zero after deletion  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_DynamicMemory |

[TwinCAT 3 | PLC Library: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
