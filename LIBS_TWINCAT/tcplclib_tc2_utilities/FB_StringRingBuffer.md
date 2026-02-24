# FB_StringRingBuffer

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_StringRingBuffer

![61772230](/tcplclib_tc2_utilities/1033/Images/png/9007199290324875__Web.png)

The function block FB\_StringRingBuffer can be used to write string variables into the ring buffer or read previously written string variables from the ring buffer. The written strings are read in the same order as they were previously written to the ring buffer, based on the FIFO principle, i.e. the oldest entries are read first. The buffer memory is made available to the function block via the *pBuffer*/*cbBuffer* input variables. Writing/reading of strings is controlled via action calls. The function block features the following tasks:

* **A\_AddTail** (writes a new string into the ring buffer.)
* **A\_GetHead** (reads the oldest string in the ring buffer, but does not remove it.)
* **A\_RemoveHead** (reads and removes the oldest string from the ring buffer.)
* **A\_Reset** (deletes all strings from the ring buffer.)

## VAR\_INPUT

```
VAR_INPUT  
    bOverwrite : BOOL;  
    putValue   : T_MaxString := '';  
    pBuffer    : POINTER TO BYTE;  
    cbBuffer   : UDINT;  
END_VAR
```

**bOverwrite** : If TRUE the oldest entries are overwritten in the event of a buffer overflow. If FALSE an error reported in the event of a buffer overflow (bOk = FALSE).

**putValue**: String to be written into the ring buffer (type: T\_MaxString).

**pBuffer**: Address of a PLC variables (e.g. ARRAY[...] OF BYTES) to be used as buffer memory by the function block. The address can be determined with the ADR operator.

**cbBuffer**: Max. byte size of the PLC variable to be used as buffer memory. The size can be determined with the SIZEOF operator.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bOk      : BOOL;  
    getValue : T_MaxString := '';  
    nCount   : UDINT;  
    cbSize   : UDINT;  
END_VAR
```

**bOk**: Returns TRUE, if a new string was added or removed successfully. Returns FALSE in the event of a buffer overflow or if no more entries are available in the buffer.

**getValue**: This output supplies the last string that was read from the ring buffer (type: T\_MaxString).

**nCount**: Returns the current number of queued strings.

**cbSize**: Returns the current number of assigned data bytes in the buffer. The number of assigned data bytes is always greater than the actual number of written value data. Each string is complemented with additional information, so that it can be located later.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
