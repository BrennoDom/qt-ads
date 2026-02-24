# Example: Communication BC/BX<->PC/CX (F_SwapRealEx)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: Communication BC/BX<->PC/CX (F\_SwapRealEx)

The example demonstrates the application of the [F\_SwapRealEx](ms-xhelp:///?Id=beckhoff-ef1b-4d8e-8681-fd98e6c7bba1) function. This example contains two components: TwinCAT 2.xx BC/BX (Bus Terminal Controller) application and TwinCAT 3.xx PC/CX (x86) application. The PC/CX application reads/writes a structure variable from/into the flag area of the BC/BX. The structure variable contains REAL elements. These have to be converted to the right format before they are used on the PC/CX or transferred to the BC/BX.

Here you can unpack the complete sources:

TwinCAT 2.xx - BC/BX (Bus Terminal Controller) application/project file: [DataExBC.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058074123.zip)

TwinCAT 3.xx - PC/CX (x86, x64, ARM) application/archive file: [DataExPC.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058077963.zip)

**System requirements:**

* TwinCAT 2.xx PLC (required for downloading the BC/BX application) + BC/BX hardware (e.g. BC9000);
* TwinCAT 3.xx engineering and runtime system (required for downloading the PC/CX application);

## Download a project

Use the TwinCAT 2.xx PLC to download the BC/BX application into the runtime system of a Bus Terminal Controller (e.g. BC9000). Create a boot project and start the PLC. In the next step use TwinCAT 3.xx to create a new XAE project. Import the archive file into TwinCAT XAE with a right mouse click on the *PLC* node, then *Add existing item*.

To enable access to the BC/BX (Bus Terminal Controller) via ADS, it has to be entered as a device in the list of TwinCAT AMS route connections (routes). Create a new static route (follow the steps shown in the diagram). The AmsNetID and IP address of the BC/BX have to be configured accordingly (remember the AmsNetID in the PLC program code).

![56877687](/tcplclib_tc2_utilities/1033/Images/gif/36246283__en-US__Web.gif)

**Important note!**

The BC/BX (Bus Terminal Controller) and PC/CX (x86, x64, ARM) have different memory alignment (data alignment). For data exchange BC/BX <-> PC/CX please define structures with 8-byte memory alignment.

* TwinCAT 2.xx + PC/CX (x86) platform => data structures have 1-byte memory alignment;
* TwinCAT 2.xx + CX (ARM) platform => data structures have 4-byte (DWORD) memory alignment;
* TwinCAT 2.xx + BC/BX (Bus Terminal Controller) platform => data structures have 2-byte (WORD) memory alignment;
* TwinCAT 3.xx + PC/CX (x86, x64, ARM) platform => data structures have 8-byte memory alignment;

The structure variable definition used on both systems:

```
(* 8 byte aligned structure, byte size := 152 byte *)  
TYPE ST_FrameData :  
STRUCT  
    nFrameSize: DWORD;(*Frame byte size, member byte size := 4 byte*)  
    nTxFrames : DWORD;(*Tx frame number, member byte size := 4 byte*)  
    nRxFrames : DWORD;(*Rx frame number, member byte size := 4 byte*)  
    nCounter  : DWORD;(*Number value, member byte size := 4 byte*)  
    fU        : REAL;(*Floating point number, member byte size := 4 byte*)  
    fV        : REAL;(*Floating point number, member byte size := 4 byte*)  
    fW        : REAL;(*Floating point number, member byte size := 4 byte*)  
    aFloats   : ARRAY[0..9] OF REAL;(* Array of floating point numbers, array byte size := 40 byte*)  
    sMsg      : STRING;(*String variable, member byte size := 81 byte incl. String null delimiter*)  
    bEnable   : BOOL;(*Boolean flag, member byte size := 1 byte*)  
    nRsv0     : BYTE;(*Reserved byte to meet the 8 byte alignment, member byte size := 1 byte*)  
    nCRC      : BYTE;(*CRC checksum byte, member byte size := 1 byte*)  
END_STRUCT  
END_TYPE
```

**BC/BX (Bus Terminal Controller) application**

After each write access from the PC/CX the data length and checksum is checked. New random values for read access are then generated, which are also associated with a simple checksum.

```
PROGRAM MAIN  
VAR  
    stRxFrame AT%MB500   : ST_FrameData;(* Data transported from PC/CX (x86) to BC/BX (Bus Terminal Controller) *)  
    stTxFrame AT%MB0     : ST_FrameData;(* Data transported from BC/BX (Bus Terminal Controller) to PC/CX (x86) *)  
    nReceivedFrame       : UDINT;  
    i                    : INT;  
    nRxErrors            : UDINT;  
END_VAR
```

```
(* New frame from PC/CX received? *)  
IF stRxFrame.nTxFrames <> nReceivedFrame THEN  
    (* Frame length OK? *)  
    IF stRxFrame.nFrameSize = SIZEOF( stRxFrame) THEN  
        (* Checksum OK? *)  
        IF stRxFrame.nCRC = F_CheckSum( ADR( stRxFrame), SIZEOF( stRxFrame) - 1 ) THEN (* => OK *)  
            (* Create/modify the tx data *)  
            stTxFrame.nFrameSize  := SIZEOF( stTxFrame);(* Set frame byte size *)  
            stTxFrame.nTxFrames   := stTxFrame.nTxFrames + 1;(* Increment the send frame number *)  
            stTxFrame.nRxFrames   := stRxFrame.nTxFrames;(* Report the received frame number *)  
            stTxFrame.bEnable     := NOT stRxFrame.bEnable;(* Toggle bool flag *)  
            stTxFrame.nCounter    := stTxFrame.nCounter + 1;(* Send some counter value *)  
            stTxFrame.sMsg        := CONCAT( 'Message from BC/BX, counter:', DWORD_TO_STRING( stTxFrame.nCounter ) );(* Create any string message *)  
            stTxFrame.fU          := stRxFrame.fU + 10.0;(* Modify some floating point values *)  
            stTxFrame.fV          := stRxFrame.fV + 100.0;  
            stTxFrame.fW          := stRxFrame.fW + 1000.0;  
            FOR i:= 0 TO 9 DO  
                stTxFrame.aFloats[i] := stTxFrame.aFloats[i] + i + 3.141592;  
            END_FOR  
            stTxFrame.nCRC        := F_CheckSum( ADR( stTxFrame), SIZEOF( stTxFrame) - 1 );(* Create checksum *)  
        ELSE(* => Checksum error *)  
            nRxErrors := nRxErrors + 1;  
        END_IF  
    ELSE(* => Invalid frame length *)  
        nRxErrors := nRxErrors + 1;  
    END_IF  
    nReceivedFrame := stRxFrame.nTxFrames;  
END_IF
```

**PC/CX (x86, x64, ARM) application**

A rising edge at bWrite starts the write process. The REAL elements are converted to BC/BX format before the write operation. The data length and checksum is determined and set. A rising edge at bRead starts the read process. After a successful read operation the data length is checked, then a simple checksum. The REAL elements are then converted to PC/CX format.

```
PROGRAM MAIN  
VAR  
    bWrite        : BOOL;(* Rising edge at this variable writes data to the BC/BX (Bus Terminal Controller) *)  
    bRead         : BOOL;(* Rising edge at this variable reads data from BC/BX (Bus Terminal Controller) *)  
    stTxFrame     : ST_FrameData; (* Data transported from PC/CX (x86) to BC/BX (Bus Terminal Contoroller) *)  
    stRxFrame     : ST_FrameData; (* Data transported from BC/BX (Bus Terminal Controller) to PC/CX (x86) *)  
    fbWrite       : ADSWRITE :=  ( NETID := '172.17.61.50.1.1', PORT := 800, IDXGRP := 16#4020, IDXOFFS := 500, TMOUT := DEFAULT_ADS_TIMEOUT );  
    fbRead        : ADSREAD :=  ( NETID := '172.17.61.50.1.1', PORT := 800, IDXGRP := 16#4020, IDXOFFS := 0, TMOUT := DEFAULT_ADS_TIMEOUT );  
    (* Temporary used variables *)  
    stTxToBC      : ST_FrameData;  
    stRxFromBC    : ST_FrameData;  
    i             : INT;  
    nTxState      : UDINT;  
    nRxState      : UDINT;  
    nTxErrors     : UDINT;  
    nRxErrors     : UDINT;  
END_VAR
```

```
(*##########################################################################################*)  
CASE nTxState OF  
    0:  
        IF bWrite THEN(* Write BC/BX data *)  
            bWrite := FALSE;  
  
            (* Prepare/modify tx data *)  
            stTxFrame.nFrameSize    := SIZEOF( stTxFrame );(* Set frame byte size *)  
            stTxFrame.nTxFrames    := stTxFrame.nTxFrames + 1;(* Increment the send frame number *)  
            stTxFrame.nRxFrames     := stRxFrame.nTxFrames;(* Report the received frame number *)  
            stTxFrame.bEnable    := NOT stTxFrame.bEnable;(* Toggle bool flag *)  
            stTxFrame.nCounter     := stTxFrame.nCounter + 1;(* Increment counter value *)  
            stTxFrame.sMsg         := CONCAT( 'Message from PC/CX, counter: ', DWORD_TO_STRING( stTxFrame.nCounter ) );(* Create some string message *)  
            stTxFrame.fU            := stTxFrame.fU + 1.2;(* Modify some floating point values *)  
            stTxFrame.fV            := stTxFrame.fV + 3.4;  
            stTxFrame.fW            := stTxFrame.fW + 5.6;  
            FOR i:= 0 TO 9 DO  
                stTxFrame.aFloats[i] := stTxFrame.aFloats[i] + i;  
            END_FOR  
            stTxFrame.nCRC         := 0;  
  
            (* Create temporary copy of tx data *)  
            stTxToBC := stTxFrame;  
  
            (* Swap REAL variables to BC/BX (Bus Terminal Controller) format *)  
            F_SwapRealEx( stTxToBC .fU );  
            F_SwapRealEx( stTxToBC .fV );  
            F_SwapRealEx( stTxToBC .fW );  
            FOR i:= 0 TO 9 DO  
                F_SwapRealEx( stTxToBC .aFloats[i] );  
            END_FOR  
      
            (* Create CRC check number *)  
            stTxToBC .nCRC     := F_CheckSum( ADR( stTxToBC ), SIZEOF( stTxToBC ) - 1 );  
      
            (* Send *)  
            fbWrite( WRITE := FALSE );  
            fbWrite( LEN := SIZEOF( stTxToBC ), SRCADDR := ADR( stTxToBC ), WRITE := TRUE );  
            nTxState := 1;  
        END_IF  
  
    1:(* Wait until ads write command not busy *)  
        fbWrite( WRITE := FALSE );  
        IF NOT fbWrite.BUSY THEN  
            IF NOT fbWrite.ERR THEN  
                nTxState := 0;  
            ELSE(* Ads error *)  
                nTxState := 100;  
            END_IF  
        END_IF  
  
    100: (* TODO: Error state, add error handling *)  
        nTxErrors := nTxErrors + 1;  
        nTxState := 0;  
  
END_CASE  
  
(*##########################################################################################*)  
CASE nRxState OF  
    0:  
        IF bRead THEN(* Read BC/BX data *)  
            bRead := FALSE;  
  
            fbRead( READ := FALSE );  
            fbRead( LEN := SIZEOF( stRxFromBC ), DESTADDR := ADR( stRxFromBC ), READ := TRUE );  
            nRxState := 1;  
        END_IF  
  
    1:(* Wait until ads read command not busy *)  
        fbRead( READ := FALSE );  
        IF NOT fbRead.BUSY THEN  
            IF NOT fbRead.ERR THEN  
                (* Perform simple frame length check *)  
                IF stRxFromBC.nFrameSize = SIZEOF( stRxFromBC ) THEN (* Check frame length *)  
                    (* Perform simple CRC check *)  
                    IF stRxFromBC.nCRC = F_CheckSum( ADR( stRxFromBC ), SIZEOF( stRxFromBC ) - 1 ) THEN  
  
                        (* Swap REAL variables to PC/CX (x86) format *)  
                        F_SwapRealEx( stRxFromBC.fU );  
                        F_SwapRealEx( stRxFromBC.fV );  
                        F_SwapRealEx( stRxFromBC.fW );  
                        FOR i:= 0 TO 9 DO  
                            F_SwapRealEx( stRxFromBC.aFloats[i] );  
                        END_FOR  
  
                        stRxFrame := stRxFromBC;  
                        nRxState     := 0;  
  
                    ELSE(* => Checksum error *)  
                        nRxState := 100;  
                    END_IF  
                ELSE(* => Invalid frame length *)  
                    nRxState := 100;  
                END_IF  
            ELSE(* => Ads error *)  
                nRxState := 100;  
            END_IF  
        END_IF  
  
    100: (* TODO: Error state, add error handling *)  
        nRxErrors := nRxErrors + 1;  
        nRxState := 0;  
  
END_CASE
```

## Application test

Open the PC/CX application and write TRUE to the bWrite variable. In the next step write TRUE to the bRead variable.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
