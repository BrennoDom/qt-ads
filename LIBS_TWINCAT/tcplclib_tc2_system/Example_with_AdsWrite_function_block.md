# Example with AdsWrite function block

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Example with AdsWrite function block

# Example with AdsWrite function block

The example demonstrates the use of the ADSWRITE function block in an ADS Client application.

The complete sources of the ADS Client application can be unpacked here: [AdsWriteReqClientExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/9007199965327755.zip)

## Declaration Part

```
PROGRAM MAIN  
VAR  
   fbWriteReq   : ADSWRITE := ( NETID := '', PORT := 851, TMOUT := DEFAULT_ADS_TIMEOUT );  
   bWrite       : BOOL;(* Rising edge at this variable starts command execution *)  
   nState       : BYTE;  
   bBusy        : BOOL;  
   bError       : BOOL;  
   nErrID       : UDINT;  
   arrInt       : ARRAY[0..9] OF INT;(* Server data to be written *)  
   i            : INT;  
END_VAR
```

## Implementation

```
FOR i:=0 TO 9 BY 1 DO (* modify/simulate new data *)  
   arrInt[i] := arrInt[i] + 1;  
END_FOR  
  
  
CASE nState OF  
   0:  
      IF bWrite THEN  
         bWrite := FALSE;  
           
         bBusy := TRUE;  
         bError := FALSE;  
         nErrID := 0;  
           
         fbWriteReq( WRITE := FALSE );  
         fbWriteReq( IDXGRP := 16#80000005, IDXOFFS := 7,   
                  LEN := SIZEOF( arrInt ), SRCADDR := ADR( arrInt ),   
                  WRITE := TRUE );  
         nState := 1;              
      END_IF  
        
   1:  
      fbWriteReq( WRITE := FALSE, BUSY=>bBusy, ERR=>bError, ERRID=>nErrID );  
      IF NOT bBusy THEN  
         IF NOT bError THEN  
            nState := 0;(* Success *)  
         ELSE  
            nState := 100;(* Error *)  
         END_IF  
      END_IF  
  
   100:(* TODO::Implement error handler *)  
      nState := 0;  
     
END_CASE
```

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
