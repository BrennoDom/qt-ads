# FB_MemRingBuffer

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_MemRingBuffer

![1424418](/tcplclib_tc2_utilities/1033/Images/png/9007199290280075__Web.png)

The function block FB\_MemRingBuffer can be used to write data sets with different lengths in a ring buffer or to read previously written data sets from the ring buffer. The written data sets are read in the same order as they were previously written to the ring buffer, based on the FIFO principle, i.e. the oldest entries are read first. The buffer memory is made available to the function block via the *pBuffer*/*cbBuffer* input variables. Writing/reading of data sets is controlled via action calls. The function block features the following tasks:

* **A\_AddTail** (writes a new data set into the ring buffer.)
* **A\_GetHead** (reads the oldest data set in the ring buffer, but does not remove it.)
* **A\_RemoveHead** (reads and removes the oldest data set from the ring buffer.)
* **A\_reset** (deletes all data sets in the ring buffer.)

## VAR\_INPUT

```
VAR_INPUT  
    pWrite  : POINTER TO BYTE;  
    cbWrite : UDINT;  
    pRead   : POINTER TO BYTE;  
    cbRead  : UDINT;  
    pBuffer : POINTER TO BYTE;  
    cbBuffer: UDINT;  
END_VAR
```

**pWrite:** The address of the PLC variable or of a buffer variable that contains the value data that is to be written. The address can be determined with the ADR operator. The programmer is himself responsible for dimensioning the buffer variable in such a way that *cbWrite* data bytes can be taken from it.

**cbWrite**: The number of value data bytes that are to be written. (In the case of string variables this includes the final null).

**pRead**: The address of the PLC variables or of a buffer variable into which the value data that has been read is to be copied. The address can be determined with the ADR operator. The programmer is himself responsible for dimensioning the buffer variable in such a way that it can accept cbRead data bytes. The size of the buffer variables in bytes must be greater than or equal to the size of the data record that is to be read.

**cbRead**: The number of value data bytes to be read. If the buffer size is too small, data is not copied. The function block reports a buffer underflow error (bOk = FALSE), and the buffer size required for the next data record that is to be read is returned at the *cbReturn* output.

**pBuffer**: Address of a PLC variables (e.g. ARRAY[...] OF BYTES) to be used as buffer memory by the function block. The address can be determined with the ADR operator.

**cbBuffer**: Max. byte size of the PLC variable to be used as buffer memory. The size can be determined with the SIZEOF operator.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk      : BOOL;  
    nCount   : UDINT;  
    cbSize   : UDINT;  
    cbReturn : UDINT;  
END_VAR
```

**bOk**: Returns TRUE, if a new data set was added or removed successfully. Returns FALSE in the event of a buffer overflow or if no more entries are available in the buffer.

**nCount**: Returns the current number of queued data sets.

**cbSize**: Returns the current number of assigned data bytes in the buffer. The number of assigned data bytes is always greater than the actual number of written value data. Each data set is complemented with additional information, so that it can be located later.

**cbReturn**: The number of value data bytes successfully read. If a read buffer underflow error has occurred, this output supplies the necessary read buffer size in bytes. In this case is the *cbRead* length is too small.

**Example:**

See:  [Example: Memory ring FiFo (FB\_MemRingBuffer).](ms-xhelp:///?Id=beckhoff-1b67-4b62-9010-652936467fbc)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
