# Example with AdsWriteInd/AdsWriteRes function blocks

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. Example with AdsWriteInd/AdsWriteRes function blocks

# Example with AdsWriteInd/AdsWriteRes function blocks

The example shows the implementation of a simple ADS Server application to the PLC. The server application can process the ADSWRITE requests of an ADS Client application.

In the example application ADSWRITE requests are used to transfer arrays with integer values to the PLC task. The received data are copied in the PLC into an appropriate array variable.

The complete sources of the ADS server application can be unpacked here: [AdsWriteIndServerExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/9007199965323915.zip)

An ADS Client application suitable for the ADS Server can be found here: [Example with ADSWRITE function block.](ms-xhelp:///?Id=beckhoff-2156-4962-82ea-70e63a52a9b2)

## ADS Client application

The desired service/command from the PLC task is encoded in the index group and index offset parameters. E.g.:

IG:0x80000005 and IO:0x00000007→ copy the sent data to the array in the PLC.

|  |  |
| --- | --- |
| 17171756 | So that the requests can be routed to the PLC task, the highest value bit must be set in the index group parameter. |

## PLC program

The requests are intercepted as indications in the PLC task by an instance of the [ADSWRITEIND](ms-xhelp:///?Id=beckhoff-0914-4a6d-a6d4-7c012e1fa0bc) function block. Following this, the index group, index offset and transmitted data length parameters are checked for validity, and the desired operation is carried out on the PLC variable. The next step is for a response to be returned to the caller (including an error code, if appropriate) by an instance of the [ADSWRITERES](ms-xhelp:///?Id=beckhoff-0928-434d-a060-a06dd97eeaec)-function block. In the next cycle the CLEAR and RESPOND flags are reset in order to be able to process further indications.

|  |  |
| --- | --- |
| 20328083 | With the rising edge at the CLEAR input of the ADSWRITEIND function block the address pointer to the most recently sent data becomes invalid ( == ZERO ).  For this reason the sent data is first copied into the PLC variable before the CLEAR input is set to TRUE. |

## Declaration Part

```
PROGRAM MAIN  
VAR  
   fbWriteInd  : ADSWRITEIND;  
   fbWriteRes  : ADSWRITERES;  
   sNetId      : T_AmsNetID;  
   nPort       : T_AmsPort;  
   nInvokeId   : UDINT;  
   nIdxGrp     : UDINT;  
   nIdxOffs    : UDINT;  
   cbWrite     : UDINT;(* Byte size of written data *)  
   pWrite      : PVOID;(* Pointer to written data buffer *)  
   nResult     : UDINT;(* Write indication result error code *)  
   arrInt      : ARRAY[0..9] OF INT;(* Server data *)  
END_VAR
```

## Implementation

```
fbWriteRes( RESPOND := FALSE );(* Reset response function block *)  
fbWriteInd( CLEAR := FALSE );(* Trigger indication function block *)  
IF ( fbWriteInd.VALID ) THEN  
     
   sNetId       := fbWriteInd.NETID;  
   nPort        := fbWriteInd.PORT;  
   nInvokeId    := fbWriteInd.INVOKEID;  
   nIdxGrp      := fbWriteInd.IDXGRP;  
   nIdxOffs     := fbWriteInd.IDXOFFS;  
   cbWrite      := fbWriteInd.LENGTH;  
   pWrite       := fbWriteInd.DATAADDR;  
   nResult      := DEVICE_SRVNOTSUPP;  
  
   CASE nIdxGrp OF  
      16#80000005:  
         CASE nIdxOffs OF  
            16#00000007:  
               IF cbWrite <= SIZEOF( arrInt ) THEN  
                  MEMCPY( ADR( arrInt ), pWrite, MIN( cbWrite, SIZEOF(arrInt) ) );  
                  nResult := NOERR;  
               ELSE(* ADS error (example): Invalid size *)  
                  nResult := DEVICE_INVALIDSIZE;  
               END_IF  
         ELSE(* ADS error (example): Invalid index offset *)  
            nResult := DEVICE_INVALIDOFFSET;  
         END_CASE  
   ELSE(* ADS error (example): Invalid index group *)  
      nResult := DEVICE_INVALIDGRP;  
   END_CASE  
  
   fbWriteRes( NETID := sNetId,  
            PORT := nPort,  
            INVOKEID := nInvokeId,  
            RESULT := nResult,  
            RESPOND := TRUE ); (* Send write response *)  
  
   fbWriteInd( CLEAR := TRUE ); (* Clear indication entry *)  
END_IF
```

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
