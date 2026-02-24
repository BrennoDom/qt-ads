# Samples

## Library
tcplclib_tc3_dynamicmemory

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
2. Samples

# Samples

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

[TwinCAT 3 | PLC Library: Tc3\_DynamicMemory](ms-xhelp:///?Id=beckhoff-3968-471f-a4e1-78dc2dc627fe)
