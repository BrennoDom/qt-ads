# Example: File search (FB_EnumFindFileEntry, FB_EnumFindFileList)

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# Example: File search (FB\_EnumFindFileEntry, FB\_EnumFindFileList)

Here you can unpack the complete sources: [EnumFindFile.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc2_utilities/Resources/zip/9007200058081803.zip)

## Example: FB\_EnumFindFileEntry (ST)

In the local TwinCAT system all files should be listed in the following directory: C:\Windows\system32\. The file names should be written as messages into the TwinCAT XAE error list. It should be possible to cancel this process. A rising edge at the *bEnum* variable starts the listing of found files. A rising edge at the *bAbort* variables aborts the process.

```
PROGRAM P_TestEnumEntry  
VAR  
    fbEnum: FB_EnumFindFileEntry := ( sNetID := '', tTimeout := T#5s, sPathName := 'C:\Windows\System32\*.*' );  
    bEnum : BOOL;  
    bAbort: BOOL;  
    nState: BYTE;  
END_VAR
```

```
CASE nState OF  
    0:  
        IF bEnum THEN             (* flag set ? *)  
            bEnum       := FALSE;         (* reset flag *)  
            fbEnum.eCmd := eEnumCmd_First;    (* enum first entry *)  
            nState      := 1;  
        END_IF  
  
    1:    (* enum one entry *)  
        IF bAbort THEN  
            bAbort      := FALSE;  
            fbEnum.eCmd := eEnumCmd_Abort;  
        END_IF  
        fbEnum( bExecute := FALSE );  
        fbEnum( bExecute := TRUE );  
        nState     := 2;  
  
    2:    (* wait until function block not busy *)  
        fbEnum( bExecute := FALSE );  
        IF NOT fbEnum.bBusy THEN  
            IF NOT fbEnum.bError THEN  
                IF NOT fbEnum.bEOE THEN  
                    ADSLOGSTR( ADSLOG_MSGTYPE_HINT OR ADSLOG_MSGTYPE_LOG, 'FB_EnumFindFileEntry, find file name: %s', fbEnum.stFindFile.sFileName );  
                    fbEnum.eCmd := eEnumCmd_Next; (* enum next entry *)  
                    nState      := 1;  
                ELSE (* no more entries *)  
                    nState      := 0;  
                END_IF  
            ELSE (* log error *)  
                ADSLOGSTR( ADSLOG_MSGTYPE_ERROR OR ADSLOG_MSGTYPE_LOG, 'FB_EnumFindFileEntry error:%s', DWORD_TO_HEXSTR( fbEnum.nErrID, 0, FALSE ) );  
                nState     := 0;  
            END_IF  
        END_IF  
END_CASE
```

The log messages written into the TwinCAT XAE error list:

![42137138](/tcplclib_tc2_utilities/1033/Images/gif/36249483__Web.gif)

## Example: FB\_EnuFindFileList (FBD)

A rising edge at the *bFirst* variables activates the process. If successful the file names are entered in the *fileList* array variable.

```
PROGRAM P_TestEnumList  
VAR  
    fbEnum      : FB_EnumFindFileList;  
    filesList   : ARRAY[1..10] OF ST_FindFileEntry;  
    bFirst      : BOOL;  
    bNext       : BOOL;  
    bAbort      : BOOL;  
    bBusy       : BOOL;  
    bError      : BOOL;  
    nErrID      : UDINT;  
    bEOE        : BOOL;  
    nFindFiles  : UDINT;  
END_VAR
```

**Online view:**

![43689923](/tcplclib_tc2_utilities/1033/Images/gif/36252683__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
