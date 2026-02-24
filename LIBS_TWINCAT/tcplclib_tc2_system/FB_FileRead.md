# FB_FileRead

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileRead

# FB\_FileRead

![29123463](/tcplclib_tc2_system/1033/Images/png/9007199285969163__Web.png)

With this function block the contents of an already opened file can be read. Before a read access, the file must have been opened in the corresponding mode. In addition to `FOPEN_MODEREAD`, the desired format (`FOPEN_MODEBINARY` or `FOPEN_MODETEXT`) is also important for achieving the desired result.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    hFile      : UINT;  
    pReadBuff  : PVOID;  
    cbReadLen  : UDINT;  
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**hFile**: File handle, which was generated when the function block FB\_FileOpen was created.

**pReadBuff**: Address of the buffer into which the data are to be read. The buffer can be a single variable, an array or a structure, whose address can be determined with the ADR operator.

**cbReadLen**: Number of bytes to be read.

**bExecute**: The function block is activated by a rising edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    cbRead : UDINT;      
    bEOF   : BOOL;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**cbRead**: Contains the number of bytes currently read.

**bEOF**: This output is set if the end of the file was reached and no further data bytes could be read (cbRead=0). This output is not set if further data bytes could be read (cbRead>0).

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Invalid or unknown file handle. |
| 0x70A | No memory for read buffer. |
| 0x70E | File was opened with wrong method ( e.g. with obsolete FILEOPEN function block ). |

**Example of calling the block in ST:**

* [File access from the PLC](ms-xhelp:///?Id=beckhoff-2a41-4bb4-9650-b2204625dc8c)

**Example of calling the function block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileRead        : FB_FileRead;  
    hFile             : UINT;  
    bFileRead         : BOOL;  
    bFileReadBusy     : BOOL;  
    bFileReadError    : BOOL;  
    nFileReadErrorId  : UDINT;  
    nFileReadCount    : UDINT;  
    bFileReadEOF      : BOOL;  
    fileData          : ARRAY[0..9] OF BYTE;  
END_VAR
```

![60784581](/tcplclib_tc2_system/1033/Images/png/31231371__en-US__Web.png)

After a rising edge at bExecute and successful execution of the read instruction the currently read bytes from the file are found in FILEDATA. The parameter cbRead can be used to determine how many bytes were actually read during the last read operation.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
