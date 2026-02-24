# FB_MemStackBuffer

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_MemStackBuffer

![48268995](/tcplclib_tc2_utilities/1033/Images/png/9007199290292875__Web.png)

The function block FB\_MemStackBuffer can be used to write data sets with different lengths in a buffer or to read previously written data sets from the buffer. The data sets are read based on the LIFO principle (last in - first out), i.e. in the reverse order in which they were written into the buffer. In other words, the latest entries are read first. The buffer memory is made available to the function block via the *pBuffer* and *cbBuffer* input variables. Writing/reading of data sets is controlled via action calls. The function block features the following tasks:

* **A\_Push():** Writes a new data set into the buffer;
* **A\_Top():** Reads the last added/latest data set from the buffer, but does not remove it;
* **A\_Pop():** Reads and removes the last added/latest data set from the buffer;
* **A\_Reset():** Deletes all data sets from the buffer;

## VAR\_INPUT

```
VAR_INPUT  
    pWrite    : POINTER TO BYTE;  
    cbWrite   : UDINT;  
    pRead     : POINTER TO BYTE;  
    cbRead    : UDINT;  
    pBuffer   : POINTER TO BYTE;  
    cbBuffer  : UDINT;  
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

The following example illustrates a simple application of the function block. Strings of different lengths are to be buffered. A rising edge at *bReset* clears the buffer. If *bAdd* is set to TRUE, 10 new strings are written into the buffer. If *bRemove* is TRUE the string that was written last is removed from the buffer. A rising edge at *bGet* results in the string that was written last to be read but not removed.

Declaration part:

```
PROGRAM MAIN  
VAR  
    buffer   : ARRAY[0..1000] OF BYTE;  
    fbStack  : FB_MemStackBuffer;  
    bReset   : BOOL := TRUE;  
    bAdd     : BOOL := TRUE;  
    bGet     : BOOL := TRUE;  
    bRemove  : BOOL := TRUE;  
    putEntry : ARRAY[0..9] OF STRING(20) := ['Str_1', 'Str_2', 'Str_3', 'Str_4', 'Str_5', 'Str_6', 'Str_7', 'Str_8', 'Str_9', 'Str_10'];  
    getEntry : STRING;  
    i        : UDINT;  
END_VAR
```

Program code:

```
IF bReset THEN(* Clear buffer *)  
    bReset := FALSE;  
    fbStack.A_Reset( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ) );  
END_IF  
  
IF bAdd THEN(* Add entries *)  
    bAdd := FALSE;  
    FOR i:= 0 TO 9 BY 1 DO  
        fbStack.A_Push( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pWrite := ADR(putEntry[i]), cbWrite := LEN(putEntry[i]) + 1 );  
        IF fbStack.bOk THEN(* Success *)  
            ;  
        ELSE(* Buffer overflow *)  
            ;  
        END_IF  
    END_FOR  
END_IF  
  
IF bGet THEN(* Peek newest entry *)  
    bGet := FALSE;  
    fbStack.A_Top( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pRead := ADR(getEntry), cbRead := SIZEOF(getEntry) );  
    IF fbStack.bOk THEN(* Success *)  
        ;  
    ELSE(* Buffer is empty *)  
        ;  
    END_IF  
END_IF  
  
IF bRemove THEN(* Remove newest entry *)  
    bRemove := FALSE;  
    fbStack.A_Pop( pBuffer := ADR(buffer), cbBuffer := SIZEOF(buffer), pRead := ADR(getEntry), cbRead := SIZEOF(getEntry) );  
    IF fbStack.bOk THEN(* Success *)  
        ;  
    ELSE(* Buffer is empty *)  
        ;  
    END_IF  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
