# Example: File ring FIFO (FB_FileRingBuffer)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: File ring FIFO (FB\_FileRingBuffer)

The complete sources can be found here: [FileRingBufferExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058136843.zip)

The following example illustrates a simple application of the function block. The rising edge at *bOpen* opens an existing ring buffer file. If the file does not exist, a new one is created. The rising edge at *bClose* closes an open file. The rising edge at *bCreate* creates a new file. If you set *bAdd* = TRUE a new data record will be written into the ring buffer file, and when *bRemove* =TRUE the oldest data record is removed.

```
PROGRAM MAIN  
VAR  
    bOpen    : BOOL;  
    bClose   : BOOL;  
    bCreate  : BOOL;  
    bAdd     : BOOL;  
    bRemove  : BOOL;  
    bGet     : BOOL;  
    bReset   : BOOL;  
  
    fbFileBuffer    : FB_FileRingBuffer := ( sNetId     := '',  
                                             sPathName  := 'c:\temp\Data.dat',  
                                             ePath      := PATH_GENERIC,  
                                             nID        := 1,  
                                             cbBuffer   := 100, (*cbBuffer := 16#80000000, 2GB*)  
                                             bOverwrite := TRUE,  
                                             pWriteBuff := 0,  
                                             cbWriteLen := 0,  
                                             pReadBuff  := 0,  
                                             cbReadLen  := 0,  
                                             tTimeout   := t#5s );  
  
    storeData : ARRAY[1..10] OF BYTE :=[10(0)];  
    cbStore   : UDINT;  
    loadData  : ARRAY[1..10] OF BYTE :=[10(0)];  
    cbLoad    : UDINT;  
    i         : INT;  
END_VAR
```

```
fbFileBuffer( cbReturn => cbLoad );  
  
IF NOT fbFileBuffer.bBusy THEN  
  
    IF bOpen THEN  
        bOpen := FALSE;  
        fbFileBuffer.A_Open();  
    END_IF  
  
    IF bClose THEN  
        bClose := FALSE;  
        fbFileBuffer.A_Close();  
    END_IF  
      
    IF bCreate THEN  
        bCreate := FALSE;  
        fbFileBuffer.A_Create();  
    END_IF  
      
    IF bAdd THEN  
        bAdd := FALSE;  
  
        (* modify data *)  
        FOR i:=1 TO 10 BY 1 DO  
            storeData[i] := storeData[i] + 1;  
        END_FOR  
  
        cbStore := SEL( cbStore > 1, SIZEOF(storeData), cbStore - 1 ); (* modify the data chunk length *)  
        fbFileBuffer.A_AddTail( pWriteBuff := ADR(storeData), cbWriteLen := cbStore,  
                                pReadBuff := 0, cbReadLen:=0 );  
    END_IF  
  
    IF bRemove THEN  
        bRemove := FALSE;  
        fbFileBuffer.A_RemoveHead( pWriteBuff := 0, cbWriteLen := 0,  
                                    pReadBuff := ADR(loadData), cbReadLen := SIZEOF(loadData));  
    END_IF  
  
    IF bGet THEN  
        bGet := FALSE;  
        fbFileBuffer.A_GetHead( pWriteBuff := 0, cbWriteLen := 0,  
                                pReadBuff := ADR(loadData), cbReadLen := SIZEOF(loadData));  
    END_IF  
  
    IF bReset THEN  
        bReset := FALSE;  
        fbFileBuffer.A_Reset();  
    END_IF  
  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
