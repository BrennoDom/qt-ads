# Example with AdsReadInd /AdsReadRes function blocks

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Example with AdsReadInd /AdsReadRes function blocks

# Example with AdsReadInd /AdsReadRes function blocks

The example shows the implementation of a simple ADS Server application to the PLC. The server application can process the ADSREAD requests of an ADS Client application.

In the example application, ADSREAD requests are used to increment/decrement or reset a PLC counter variable in the PLC task. If successful the value of the counter variable is returned to the ADS Client application

The complete sources of the ADS server application can be unpacked here: [AdsReadIndServerExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/9007199965315979.zip)

An ADS Client application suitable for the ADS Server can be found here: [Example with ADSREAD function block.](ms-xhelp:///?Id=beckhoff-e7c3-461f-92f2-efa7b26b5d98)

## ADS Client application

The required service in the PLC task is encoded in the index group parameter:

IG:0x80000001 → increment the counter variable;

IG:0x80000002 → decrement the counter variable;

IG:0x80000003 → set the counter variable = 0;

The index offset parameter is zero.

|  |  |
| --- | --- |
| 1907972 | So that the requests can be routed to the PLC task, the highest value bit must be set in the index group parameter. |

## PLC program

The ADSREAD requests are intercepted as indications in the PLC task by an instance of the [ADSREADIND](ms-xhelp:///?Id=beckhoff-acb7-4e42-9597-04eceb756e88) function block. Afterwards the index group and index offset parameters and the required data length and validity are checked. In the CASE instruction the desired operation with the PLC variables is carried out. If successful a response is sent back by an instance of the [ADSREADRES](ms-xhelp:///?Id=beckhoff-520f-4a5f-af41-00b24055b72d) function block to the caller with the current value of the PLC variables. In the case of an error an appropriate error message. In the next cycle the CLEAR and RESPOND flags on the function blocks are reset in order to be able to process further indications.

## Declaration Part

```
PROGRAM MAIN  
VAR  
    fbReadInd    : ADSREADIND;(* Indication function block instance *)  
    fbReadRes    : ADSREADRES;(* Response function block instance *)  
    sNetId       : T_AmsNetID;  
    nPort        : T_AmsPort;  
    nInvokeId    : UDINT;  
    nIdxGrp      : UDINT;  
    nIdxOffs     : UDINT;  
    cbLength     : UDINT;(* Requested read data/buffer byte size *)  
    cbRead       : UDINT;(* Returned read data/buffer byte size *)  
    pRead        : PVOID;(* Pointer to returned read data/buffer *)  
    nErrID       : UDINT;(* Read indication result error code *)  
    nCounter     : INT;(* Server data *)  
END_VAR
```

## Implementation

```
fbReadRes( RESPOND := FALSE );(* Reset response function block *)   
 fbReadInd( CLEAR := FALSE );(* Trigger indication function block *)   
 IF fbReadInd.VALID THEN(* Check for new indication *)   
   
      sNetID := fbReadInd.NETID;   
      nPort := fbReadInd.PORT;   
      nInvokeID := fbReadInd.INVOKEID;   
      nIdxGrp := fbReadInd.IDXGRP;   
      nIdxOffs := fbReadInd.IDXOFFS;   
      cbLength := fbReadInd.LENGTH;   
   
      cbRead := 0;   
      pRead := 0;   
      nErrID     := DEVICE_SRVNOTSUPP;   
   
        
     CASE nIdxGrp OF   
          (*------------------------------------------------------------------------------------*)   
          16#80000001:   
               CASE nIdxOffs OF   
                    0:(* Increment counter value *)   
                         IF cbLength >= SIZEOF(nCounter) THEN   
                              nCounter := nCounter + 1;   
                              cbRead := SIZEOF(nCounter);   
                              pRead := ADR(nCounter);   
                              nErrID := NOERR;   
                         ELSE (* ADS error (example): Invalid size *)   
                              nErrID := DEVICE_INVALIDSIZE;   
                         END_IF   
               ELSE (* ADS error (example): Invalid index offset *)   
                    nErrID := DEVICE_INVALIDOFFSET;   
               END_CASE   
          (*------------------------------------------------------------------------------------*)   
          16#80000002:   
               CASE nIdxOffs OF   
                    0:(* Decrement counter value *)   
                         IF cbLength >= SIZEOF(nCounter) THEN   
                              nCounter := nCounter - 1;   
                              cbRead := SIZEOF(nCounter);   
                              pRead := ADR(nCounter);   
                              nErrID := NOERR;   
                         ELSE(* ADS error (example): Invalid size *)   
                              nErrID := DEVICE_INVALIDSIZE;   
                         END_IF   
               ELSE (* ADS error (example): Invalid index offset *)   
                    nErrID := DEVICE_INVALIDOFFSET;   
               END_CASE   
          (*------------------------------------------------------------------------------------*)   
          16#80000003:   
               CASE nIdxOffs OF   
                    0:(* Reset counter value *)   
                         IF cbLength >= SIZEOF(nCounter) THEN   
                              nCounter := 0;   
                              cbRead := SIZEOF(nCounter);   
                              pRead := ADR(nCounter);   
                              nErrID := NOERR;   
                         ELSE(* ADS error (example): Invalid size *)   
                              nErrID := DEVICE_INVALIDSIZE;   
                         END_IF   
               ELSE (* ADS error (example): ervice is not supported by server *)   
                    nErrID := DEVICE_SRVNOTSUPP;   
               END_CASE   
   
     ELSE (* ADS error (example): Invalid index group *)   
          nErrID := DEVICE_INVALIDGRP;   
     END_CASE   
        
     fbReadRes(     NETID := sNetID,   
                    PORT := nPort,   
                    INVOKEID := nInvokeID,   
                    LEN := cbRead,   
                    DATAADDR := pRead,   
                    RESULT := nErrID,   
                    RESPOND := TRUE );(* Send read response *)   
                       
     fbReadInd( CLEAR := TRUE ); (* Clear indication entry *)   
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
