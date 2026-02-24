# FB_DynMem_Buffer

## Library
tcplclib_tc3_dynamicmemory

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-4863-40bb-a59e-143483b0643b)
3. FB\_DynMem\_Buffer

# FB\_DynMem\_Buffer

This function block provides a buffer of dynamically allocated memory. This buffer can be used for individual data or data blocks.

During the declaration, an instance of the function block [FB\_DynMem\_Manager](ms-xhelp:///?Id=beckhoff-9e17-4a0a-b6af-7ea358607ec7) is transferred to the function block, as a result of which the memory allocations are monitored.

## Declaration

```
fbMyBuffer : FB_DynMem_Buffer(ipMemMan := fbMyMemMan);
```

## Properties

**bAvailable**: TRUE if the buffer is available.

**nBufferSize**: indicates the current size of the buffer in bytes.

**pBuffer**: provides a pointer to the internal dynamically allocated buffer.

## Methods

**CreateBuffer():**

The method generates the buffer by allocating memory at runtime. In addition to the desired size in bytes, an indication is given as to whether the memory block should be zeroed during this process.  
The method returns TRUE if execution was successful.

```
METHOD CreateBuffer : BOOL  
VAR_INPUT  
    nSize    : UDINT;    // buffer size [in bytes]  
    bReset   : BOOL;     // zero the allocated memory  
END_VAR
```

**Clear():**

This method clears the buffer. The complete buffer is zeroed in the process.  
The method returns TRUE if execution was successful.

```
METHOD Clear : BOOL  
VAR_INPUT  
END_VAR
```

**Resize():**

This method changes the size of the buffer. When doing so, it is possible to specify whether the previous buffer contents should be retained.  
The method returns TRUE if execution was successful.

```
METHOD Resize : BOOL  
VAR_INPUT  
    nSize     : UDINT;   // new buffer size [in bytes]  
    bPreserve : BOOL;    // TRUE => preserve old content, FALSE=> don't preserve old content  
    bReset    : BOOL;    // zero the allocated memory (before preserving)  
END_VAR
```

|  |  |
| --- | --- |
| 32854487 | Changed pointer  If the size of the buffer changes, the address of the buffer can also change. It is therefore absolutely necessary to obtain the new address before using the buffer. |

**DeleteBuffer():**

This method deletes the buffer by releasing the allocated memory again.  
The method returns TRUE if execution was successful.

```
METHOD DeleteBuffer : BOOL  
VAR_INPUT  
END_VAR
```

|  |  |
| --- | --- |
| 27254927 | Invalid pointer  After deleting the buffer, the previously used buffer address is invalid and may no longer be used. It is recommended to explicitly set any pointer variables still existing to ZERO. |

## Example

The following sample code shows the use of FB\_DynMem\_Buffer to allocate memory during the runtime. The allocated memory is used once as a structure instance and another time as an array.

```
PROGRAM MAIN  
VAR  
    bAllocateOnce   : BOOL := TRUE;  
    fbMemMan        : FB_DynMem_Manager;  
      
    fbBuffer_Struct : FB_DynMem_Buffer(ipMemMan:=fbMemMan);  
    pStruct         : POINTER TO ST_MyStruct;  
      
    fbBuffer_Array  : FB_DynMem_Buffer(ipMemMan:=fbMemMan);  
    pArray          : POINTER TO LREAL;  
    nArrayLength    : UINT := 10;  
    bResizeArray    : BOOL;  
END_VAR
```

```
IF bAllocateOnce THEN  
    bAllocateOnce := FALSE;  
  
    fbBuffer_Struct.CreateBuffer(nSize:=SIZEOF(ST_MyStruct), bReset:=TRUE);  
    // after successfully creating the buffer fbMemMan shows an increased nAllocatedSize [bytes] and nBufferCount=1  
    pStruct := fbBuffer_Struct.pBuffer;  
  
    fbBuffer_Array.CreateBuffer(nSize:=nArrayLength*SIZEOF(LREAL), bReset:=TRUE);  
    // after successfully creating the buffer fbMemMan shows an increased nAllocatedSize [bytes] and nBufferCount=2  
    pArray := fbBuffer_Array.pBuffer;  
END_IF  
  
IF pStruct <> 0 THEN  
    pStruct^.nCtrlValue := 7;  
END_IF  
  
IF pArray <> 0 THEN  
    pArray[3] := 7.5;      
END_IF  
  
IF bResizeArray THEN  
    bResizeArray := FALSE;  
    nArrayLength := 15;  
    fbBuffer_Array.Resize(nSize:=nArrayLength*SIZEOF(LREAL), bPreserve:=TRUE, bReset:=TRUE);  
    // after successfully creating the buffer fbMemMan shows an increased nAllocatedSize [bytes] and nBufferCount=2  
    pArray := fbBuffer_Array.pBuffer;  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.7 | IPC or CX (x86, x64, ARM) | Tc3\_DynamicMemory |

[TwinCAT 3 | PLC Library: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
