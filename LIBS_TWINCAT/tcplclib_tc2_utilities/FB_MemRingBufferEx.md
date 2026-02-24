# FB_MemRingBufferEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_MemRingBufferEx

![12819762](/tcplclib_tc2_utilities/1033/Images/png/9007199290283275__Web.png)

The function block FB\_MemRingBufferEx can be used to write data sets with different lengths in a ring buffer or to read previously written data sets from the ring buffer. The written data sets are read in the same order as they were previously written to the ring buffer, based on the FIFO principle, i.e. the oldest entries are read first. The buffer memory is made available to the function block via the *pBuffer*/*cbBuffer* input variables. Writing/reading of data sets is controlled via action calls.

The functionality of this function block is similar to that of the [FB\_MemRingBuffer](ms-xhelp:///?Id=beckhoff-78e0-425e-87c1-cbc261e3da6c) function block. During reading of data sets the FB\_MemRingBuffer copies the data into an external buffer variable. FB\_MemRingBufferEx only provides a reference for the data set (address pointer/length). The application must then copy the data itself for further processing.

The function block features the following tasks:

* **A\_AddTail** (writes a new data set into the ring buffer.)
* **A\_GetHead** (returns a reference: address pointer/length of the oldest data set in the ring buffer, but does not remove it.)
* **A\_FreeHead** (reads and removes the oldest data set from the ring buffer. The returned address pointer/length is zero! The free memory segment is released for a new data set. )
* **A\_reset** (deletes all data sets in the ring buffer.)
* **A\_GetFreeSize** (returns the byte size of the largest free memory segment in the buffer)

## VAR\_INPUT

```
VAR_INPUT  
    pWrite   : POINTER TO BYTE;  
    cbWrite  : UDINT;  
    pBuffer  : POINTER TO BYTE;  
    cbBuffer : UDINT;  
END_VAR
```

**pWrite:** The address of the PLC variable or of a buffer variable that contains the value data that is to be written. The address can be determined with the ADR operator. The programmer is himself responsible for dimensioning the buffer variable in such a way that *cbWrite* data bytes can be taken from it.

**cbWrite**: The number of value data bytes that are to be written. (In the case of string variables this includes the final null). The size can be determined with the SIZEOF operator.

**pBuffer**: Address of a PLC variables (e.g. ARRAY[...] OF BYTES) to be used as buffer memory by the function block. The address can be determined with the ADR operator.

**cbBuffer**: Max. byte size of the PLC variable to be used as buffer memory. The size can be determined with the SIZEOF operator.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk    : BOOL;  
    pRead  : POINTER TO BYTE;  
    cbRead : UDINT;   
    nCount : UDINT;  
    cbSize : UDINT;  
    cbFree : UDINT;  
END_VAR
```

**bOk**: Returns TRUE, if a new data set was added or removed successfully. Returns FALSE in the event of a buffer overflow or if no more entries are available in the buffer.

**pRead**: After a call of the action: *A\_GetHead*, if successful (bOk=TRUE) this variable returns a reference (address pointer) for the oldest data set in the ring buffer. It returns zero if no more data sets are available in the ring buffer.

**cbRead**: After a call of the action: *A\_GetHead*, if successful (bOk=TRUE) this variable returns the length of the oldest data set in the ring buffer. It returns zero if no more data sets are available in the ring buffer.

**nCount**: Returns the current number of queued data sets.

**cbSize**: Returns the current number of assigned data bytes in the buffer. The number of assigned data bytes is always greater than the actual number of written value data. Each data set is complemented with additional information, so that it can be located later.

**cbFree**: After a call of the action: *A\_GetFreeSize*, returns the byte size of the largest free memory segment in the buffer. The data sets must use continuous addresses in the buffer memory, because the function block returns a reference for the data sets. This automatically leads to segmentation at the end of the buffer. This memory cannot be used if the new data set is greater than the free segment at the end of the buffer.

**Example:**

See: [Example: Memory ring FiFo (FB\_MemRingBufferEx)](ms-xhelp:///?Id=beckhoff-5568-4894-aa19-34091821c973).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
