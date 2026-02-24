# Example with AdsRead function block

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Example with AdsRead function block

# Example with AdsRead function block

The example demonstrates the use of the ADSREAD function block in an ADS Client application.

The complete sources of the ADS Client application can be unpacked here: [AdsReadReqClientExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/9007199965319819.zip)

## Declaration Part

```
PROGRAM MAIN  
VAR  
    fbReadReq  : ADSREADEX := ( NETID := '', PORT := 851, TMOUT := DEFAULT_ADS_TIMEOUT );  
    bIncrement : BOOL;(* Rising edge at this variable starts command execution *)  
    bDecrement : BOOL;(* Rising edge at this variable starts command execution *)  
    bReset     : BOOL;(* Rising edge at this variable starts command execution *)  
    bOther     : BOOL;(* Rising edge at this variable starts command execution *)  
      
    nState     : BYTE;  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrID     : UDINT;  
    cbRead     : UDINT;  
      
    nCounter   : INT;(* Server data to be read *)  
END_VAR
```

## Implementation

```
CASE nState OF  
    0:  
        IF bIncrement OR bDecrement OR bReset OR bOther THEN  
            bBusy := TRUE;  
            bError := FALSE;  
            nErrID := 0;  
              
            fbReadReq( READ := FALSE );  
  
            IF bIncrement THEN(* Incement counter value *)  
                bIncrement := FALSE;  
                fbReadReq( IDXGRP := 16#80000001, IDXOFFS := 0, LEN := SIZEOF(nCounter), DESTADDR := ADR(nCounter), READ := TRUE );  
            ELSIF bDecrement THEN(* Decrement counter value *)  
                bDecrement := FALSE;  
                fbReadReq( IDXGRP := 16#80000002, IDXOFFS := 0, LEN := SIZEOF(nCounter), DESTADDR := ADR(nCounter), READ := TRUE );  
            ELSIF bReset THEN(* Reset counter value *)  
                bReset := FALSE;  
                fbReadReq( IDXGRP := 16#80000003, IDXOFFS := 0, LEN := SIZEOF(nCounter), DESTADDR := ADR(nCounter), READ := TRUE );  
            ELSIF bOther THEN(* Call unsupported function *)  
                bOther := FALSE;  
                fbReadReq( IDXGRP := 16#80000004, IDXOFFS := 0, LEN := SIZEOF(nCounter), DESTADDR := ADR(nCounter), READ := TRUE );  
            END_IF  
              
            nState := 1;  
        END_IF  
    1:  
        fbReadReq( READ := FALSE, BUSY=>bBusy, ERR=>bError, ERRID=>nErrID, COUNT_R=>cbRead );  
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
