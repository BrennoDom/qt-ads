# Introduction

## Library
tcplclib_tc3_dynamicmemory

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
2. Introduction

# Introduction

The PLC library Tc3\_DynamicMemory simplifies the use of dynamic memory in the PLC. The memory allocations avail themselves of the TwinCAT Router memory.

Function blocks are available for creating buffers for the most diverse data. They also automatically take care of the necessary release of the memory at the end of runtime.

In addition, your own memory allocations can be monitored with a memory manager, which offers methods analogous to the operators \_\_NEW() and \_\_DELETE(). When using the library, therefore, you can and should refrain from using the two operators named above.

This results in a better overview of the size of memory already allocated when using this PLC library.

## Advantages of dynamically allocated memory in the TwinCAT real-time

Only the size of memory required at runtime needs to be allocated. The previous creation of large reserves is no longer necessary.

It is possible to react during the runtime to an unexpectedly high memory requirement, e.g. during data exchange via a communication interface, and if necessary to make the memory available only temporarily.

|  |  |
| --- | --- |
| 3650498 | Disadvantages of dynamically allocated memory in the TwinCAT real-time  - A memory allocation during the runtime is computationally intensive.  - A memory allocation can fail if no block of an appropriate size is free in the memory.  - Fragmentations in the TwinCAT Router memory are possible.  - Explicit memory releases are necessary.  - A type change of a dynamically allocated instance by Online Change is not possible.  >>> Memory should be allocated dynamically in the TwinCAT real-time only in the case of high benefit and where there is no sensible alternative. |

## System requirements

|  |  |
| --- | --- |
| Target System | Win7, WES7, WEC7, Win10 IPC or CX (x86, x64, ARM) |
| Min. TwinCAT version | 3.1.4024.7 |
| Min. TwinCAT level | TC1200 TC3 PLC |

[TwinCAT 3 | PLC Library: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
