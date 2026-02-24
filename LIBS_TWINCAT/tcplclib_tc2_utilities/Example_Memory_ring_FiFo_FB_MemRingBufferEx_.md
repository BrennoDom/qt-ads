# Example: Memory ring FiFo (FB_MemRingBufferEx)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Memory ring FiFo (FB\_MemRingBufferEx)

Here you can unpack the complete sources: [MemRingBufferExExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058145803.zip)

A rising edge at bAdd causes new data elements (pubObj array) to be stored in the ring buffer. Via a rising edge at bGet the oldest data element can then be copied to the getObj variable.

Data elements that are not required are removed from the buffer via a rising edge at bRelease.

```
PROGRAM MAIN  
VAR  
    bReset  : BOOL := TRUE;  
    bAdd, bGet, bRelease, bGetFree : BOOL;  
    putObj  : ARRAY[0..3] OF BYTE :=[ 16#00, 16#AA, 16#BB, 16#CC];  
    getObj  : ARRAY[0..3] OF BYTE :=[ 4(0)];  
    bOk     : BOOL;  
    nCount  : UDINT;  
    cbSize  : UDINT;  
    cbFree  : UDINT;  
    fbBuffer: FB_MemRingBufferEx;  
    buffer  : ARRAY[0..30] OF BYTE;  
END_VAR
```

```
IF bReset THEN  
    bReset := FALSE;  
    fbBuffer.A_Reset( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ),  
                    bOk=>bOk,nCount=>nCount, cbSize=>cbSize, cbFree=>cbFree );  
END_IF  
  
IF bAdd THEN  
    bAdd := FALSE;  
    putObj[0] := putObj[0] + 1;(* modify data *)  
      
    fbBuffer.A_AddTail( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ),  
                        pWrite := ADR( putObj ), cbWrite := SIZEOF( putObj ),  
                        bOk=>bOk, nCount=>nCount, cbSize=>cbSize, cbFree=>cbFree );  
    IF fbBuffer.bOk THEN  
        ;(* Success *)  
    ELSE  
        ;(* Buffer overflow *)  
    END_IF  
END_IF  
  
IF bGet THEN  
    bGet := FALSE;  
    fbBuffer.A_GetHead( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ),  
                        bOk=>bOk, nCount=>nCount, cbSize=>cbSize, cbFree=>cbFree );  
    IF fbBuffer.bOk THEN  
        (* Success *)  
        MEMCPY( ADR( getObj ), fbBuffer.pRead, MIN( SIZEOF( getObj ), fbBuffer.cbRead ) );  
    ELSE  
        ;(* Buffer empty *)  
    END_IF  
  
END_IF  
  
  
IF bRelease THEN  
    bRelease := FALSE;  
    fbBuffer.A_FreeHead( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ),  
                        bOk=>bOk, nCount=>nCount, cbSize=>cbSize, cbFree=>cbFree );  
    IF fbBuffer.bOk THEN  
        ;(* Success *)  
    ELSE  
        ;(* Buffer empty *)  
    END_IF  
END_IF  
  
IF bGetFree THEN  
    bGetFree := FALSE;  
    fbBuffer.A_GetFreeSize( pBuffer := ADR( buffer ), cbBuffer := SIZEOF( buffer ),  
                            bOk=>bOk, nCount=>nCount, cbSize=>cbSize, cbFree=>cbFree );  
END_IF
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
