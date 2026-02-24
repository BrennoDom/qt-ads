# File access from the PLC

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Samples](ms-xhelp:///?Id=beckhoff-de33-4d86-9a67-3b99efbaded7)
3. File access from the PLC

# File access from the PLC

The use of the PLC function blocks for data access from the Tc2\_system library is introduced in this example. A new function block, FB\_FileCopy, is implemented with the aid of the existing function blocks. Using the FB\_FileCopy function block, binary files can be copied in the local TwinCAT system or between a local and a remote TwinCAT system.

The complete source code for the example project can be unpacked from here: [FileCopyExample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_system/Resources/zip/9007199962636171.zip)

|  |  |
| --- | --- |
| 35962059 | Network drives cannot be accessed using the FB\_FileCopy function block. |

A rising edge at the bExecute input of the FB\_FileCopy block results in execution of the following steps.

a) Open the source and destination files

b) Read the source file into a buffer

c) Write the bytes that have been read from the buffer into the destination file

d) Check whether the end of the source file has been reached. If not, then repeat b) and c). If yes, then jump to e)

e) Close the source and destination files;

The file is copied one segment at a time. In this example, the size of the buffer has been specified as 1000 bytes, but this can be modified.

## PLC program

![55223077](/tcplclib_tc2_system/1033/Images/gif/707863307__en-US__Web.gif)

## Declaration Part

```
FUNCTION_BLOCK FB_FileCopy  
VAR_INPUT  
    sSrcNetId            : T_AmsNetId;  
    sSrcPathName         : T_MaxString;  
    sDestNetId           : T_AmsNetId;  
    sDestPathName        : T_MaxString;  
    bExecute             : BOOL;  
    tTimeOut             : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR  
VAR_OUTPUT  
    bBusy                : BOOL;  
    bError               : BOOL;  
    nErrId               : UDINT;  
END_VAR  
VAR  
    fbFileOpen           : FB_FileOpen;  
    fbFileClose          : FB_FileClose;  
    fbFileRead           : FB_FileRead;  
    fbFileWrite          : FB_FileWrite;  
    hSrcFile             : UINT := 0;(* File handle of the source file *)  
    hDestFile            : UINT := 0;(* File handle of the destination file *)  
  
    Step                 : DWORD;  
    RisingEdge           : R_TRIG;  
    buffRead             : ARRAY[1..1000] OF BYTE;(* Buffer *)  
    cbReadLength         : UDINT := 0;  
END_VAR
```

## Implementation

```
RisingEdge(CLK:=bExecute);   
   
CASE Step OF   
     0:     (* Idle state *)   
          IF RisingEdge.Q THEN   
               bBusy := TRUE;   
               bError:= FALSE;   
               nErrId:=0;   
               Step := 1;   
               cbReadLength:=0;   
               hSrcFile:=0;   
               hDestFile:=0;   
          END_IF   
   
     1:     (* Open source file *)   
          fbFileOpen( bExecute := FALSE );   
          fbFileOpen( sNetId := sSrcNetId, sPathName := sSrcPathName,   
                         nMode := FOPEN_MODEREAD OR FOPEN_MODEBINARY,   
                         ePath := PATH_GENERIC, tTimeout := tTimeOut, bExecute := TRUE );   
          Step := Step + 1;   
     2:   
          fbFileOpen( bExecute := FALSE );   
          IF NOT fbFileOpen.bBusy THEN   
               IF fbFileOpen.bError THEN   
                    nErrId := fbFileOpen.nErrId;   
                    bError := TRUE;   
                    Step := 50;   
               ELSE   
                    hSrcFile := fbFileOpen.hFile;   
                    Step := Step + 1;   
               END_IF   
          END_IF   
   
     3:     (* Open destination file *)   
          fbFileOpen( bExecute := FALSE );   
          fbFileOpen( sNetId := sDestNetId, sPathName := sDestPathName,   
                         nMode := FOPEN_MODEWRITE OR FOPEN_MODEBINARY,   
                         ePath := PATH_GENERIC, tTimeout := tTimeOut, bExecute := TRUE );   
          Step := Step+1;   
     4:   
          fbFileOpen( bExecute := FALSE );   
          IF NOT fbFileOpen.bBusy THEN   
               IF fbFileOpen.bError THEN   
                    nErrId := fbFileOpen.nErrId;   
                    bError := TRUE;   
                    Step := 50;   
               ELSE   
                    hDestFile := fbFileOpen.hFile;   
                    Step := Step + 1;   
               END_IF   
          END_IF   
   
     5:     (* Read data from source file *)   
          cbReadLength := 0;   
          fbFileRead( bExecute:= FALSE );   
          fbFileRead( sNetId:=sSrcNetId, hFile:=hSrcFile,   
                         pReadBuff:= ADR(buffRead), cbReadLen:= SIZEOF(buffRead),   
                         bExecute:=TRUE, tTimeout:=tTimeOut );   
          Step := Step + 1;   
     6:   
          fbFileRead( bExecute:= FALSE );   
          IF NOT fbFileRead.bBusy THEN   
               IF fbFileRead.bError THEN   
                    nErrId := fbFileRead.nErrId;   
                    bError := TRUE;   
                    Step := 50;   
               ELSE   
                    cbReadLength := fbFileRead.cbRead;   
                    Step := Step + 1;   
               END_IF   
          END_IF   
   
     7:     (* Write data to destination file *)   
          fbFileWrite( bExecute := FALSE );   
          fbFileWrite( sNetId:=sDestNetId, hFile:=hDestFile,   
                         pWriteBuff:= ADR(buffRead), cbWriteLen:= cbReadLength,   
                         bExecute:=TRUE, tTimeout:=tTimeOut );   
          Step := Step + 1;   
     8:   
          fbFileWrite( bExecute := FALSE );   
          IF NOT fbFileWrite.bBusy THEN   
               IF fbFileWrite.bError THEN   
                    nErrId := fbFileWrite.nErrId;   
                    bError := TRUE;   
                    Step := 50;   
               ELSE   
                    IF fbFileRead.bEOF THEN (* Check if the EOF flag ist set *)   
                         Step := 50;     (* Cleanup: close the destination and source files *)   
                    ELSE   
                         Step := 5; (* Repeat reading/writing *)   
                    END_IF   
               END_IF   
          END_IF   
   
     30:     (* Close the destination file *)   
          fbFileClose( bExecute := FALSE );   
          fbFileClose( sNetId:=sDestNetId, hFile:=hDestFile, bExecute:=TRUE, tTimeout:=tTimeOut );   
          Step := Step + 1;   
     31:   
          fbFileClose( bExecute := FALSE );   
          IF NOT fbFileClose.bBusy THEN   
               IF fbFileClose.bError THEN   
                    nErrId := fbFileClose.nErrId;   
                    bError := TRUE;   
               END_IF   
               Step := 50;   
               hDestFile := 0;   
          END_IF   
   
     40: (* Close source file *)   
          fbFileClose( bExecute := FALSE );   
          fbFileClose( sNetId:=sSrcNetId, hFile:=hSrcFile, bExecute:=TRUE, tTimeout:=tTimeOut );   
          Step := Step + 1;   
     41:   
          fbFileClose( bExecute := FALSE );   
          IF NOT fbFileClose.bBusy THEN   
               IF fbFileClose.bError THEN   
                    nErrId := fbFileClose.nErrId;   
                    bError := TRUE;   
               END_IF   
               Step := 50;   
               hSrcFile := 0;   
          END_IF   
   
     50: (* Error or ready => Cleanup *)   
          IF ( hDestFile <> 0 ) THEN   
               Step := 30; (* Close the destination file*)   
          ELSIF (hSrcFile <> 0 ) THEN   
               Step := 40; (* Close the source file *)   
          ELSE   
               Step := 0;     (* Ready *)   
               bBusy := FALSE;   
          END_IF   
   
END_CASE
```

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
