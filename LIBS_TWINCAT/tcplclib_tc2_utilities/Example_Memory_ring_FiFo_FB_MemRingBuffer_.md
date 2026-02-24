# Example: Memory ring FiFo (FB_MemRingBuffer)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Memory ring FiFo (FB\_MemRingBuffer)

The complete sources can be found here: [MemRingBufferExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058140683.zip)

The following example illustrates a simple application of the function block. Data sets with the same length are to be buffered (although this is not compulsory). The data sets have the following structure:

```
TYPE ST_DataSetEntry :  
STRUCT  
    bFlag  : BOOL;  
    nValue : BYTE;  
    sMsg   : STRING(20) := 'Unknown';  
END_STRUCT  
END_TYPE
```

## The interface of the FB\_Data setFifo function block:

The application-specific function block FB\_Data setFifo used in the project example uses the FB\_MemRingBuffer function block internally. This block simplifies adding/removing of data sets. In addition, the new function block provides the current percentage fill status of the buffer and an overwrite option. If the *bOverwrite* input is set and the buffer is full, the oldest entry is removed from the buffer and overwritten with the new one.

```
VAR_GLOBAL CONSTANT  
    MAX_BUFFER_SIZE : UDINT := 1000;  
END_VAR
```

```
FUNCTION_BLOCK FB_DataSetFifo  
VAR_INPUT  
    bOverwrite : BOOL;  
    in         : ST_DataSetEntry;  
END_VAR  
VAR_OUTPUT  
    bOk        : BOOL;  
    nCount     : UDINT;  
    nLoad      : UDINT;  
    out        : ST_DataSetEntry;  
END_VAR  
VAR  
    arrBuffer  : ARRAY[0..MAX_BUFFER_SIZE] OF BYTE; (* Buffer memory used by FB_MemRingBuffer function block *)  
    fbBuffer   : FB_MemRingBuffer;  
END_VAR
```

## The main program:

A rising edge at *bReset* deletes all buffer entries. If you set *bAdd* = TRUE a new data record will be written into the ring buffer, and when *bRemove* =TRUE the oldest data record is removed. A rising edge at *bGet* results in the oldest data set to be read but not removed.

```
PROGRAM MAIN  
VAR  
    fbFifo      : FB_DataSetFifo := ( bOverwrite := TRUE );  
    newEntry    : ST_DataSetEntry;  
    oldEntry    : ST_DataSetEntry;  
    bSuccess    : BOOL;  
    nCount      : UDINT;  
    nLoad       : UDINT;  
  
    bReset      : BOOL := TRUE;  
    bAdd        : BOOL := TRUE;  
    bGet        : BOOL := TRUE;  
    bRemove     : BOOL := TRUE;  
END_VAR
```

```
IF bReset THEN  
    bReset := FALSE;  
    (* reset fifo (clear all entries) *)  
    fbFifo.A_Reset( in := newEntry, bOk=>bSuccess, nCount=> nCount, nLoad => nLoad );  
END_IF  
  
IF bAdd THEN  
    bAdd := FALSE;  
  
    (* create new or modify data set entry *)  
    newEntry.bFlag  := NOT newEntry.bFlag;  
    newEntry.nValue := newEntry.nValue + 1;  
    newEntry.sMsg   := BYTE_TO_STRING(newEntry.nValue);  
  
    (* add new entry to the fifo *)  
    fbFifo.A_Add( in := newEntry, bOk=>bSuccess, nCount=> nCount, nLoad => nLoad );  
END_IF  
  
IF bGet THEN  
    bGet := FALSE;  
    (* get (but not delete) oldest entry *)  
    fbFifo.A_Get( out => oldEntry, bOk => bSuccess, nCount => nCount, nLoad => nLoad );  
END_IF  
  
IF bRemove THEN  
    bRemove:= FALSE;  
    (* remove oldest entry *)  
    fbFifo.A_Remove( out => oldEntry, bOk => bSuccess, nCount => nCount, nLoad => nLoad );  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
