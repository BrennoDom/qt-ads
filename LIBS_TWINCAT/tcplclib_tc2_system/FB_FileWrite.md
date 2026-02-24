# FB_FileWrite

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileWrite

# FB\_FileWrite

![10190321](/tcplclib_tc2_system/1033/Images/png/9007199285994763__Web.png)

The function block writes data into a file. For write access the file must have been opened in the corresponding mode, and it must be closed again for further processing by external programs.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    hFile      : UINT;  
    pWriteBuff : PVOID;  
    cbWriteLen : UDINT;  
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**hFile**: File handle, which was generated when the function block FB\_FileOpen was created.

**pWriteBuff**: Address of the buffer containing the data to be written. The buffer can be a single variable, an array or a structure, whose address can be determined with the ADR operator.

**cbWriteLen**: Number of bytes to be written.

**bExecute**: The function block is activated by a rising edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    cbWrite  : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the *bError* output is set.

**cbWrite**: Contains the number of the last successfully written data bytes. A write error indicates that the number of successfully written data bytes is less than the requested length (cbWriteLen) or zero. A write error can occur if the data storage device is full, for example. If a write error occurs, the bError and nErrID outputs are not set. Since the PLC application knows the number of data bytes to be written, it can compare the actual written length with the requested length and detect write errors. When a write error occurs, the internal file pointer has an undefined position.

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Invalid or unknown file handle. |
| 0x70E | File was opened with wrong method (e.g. with obsolete FILEOPEN function block). |

**Example of calling the block in ST:**

* [File access from the PLC](ms-xhelp:///?Id=beckhoff-2a41-4bb4-9650-b2204625dc8c)

**Example of calling the block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileWrite      : FB_FileWrite;  
    hFile            : UINT;  
    bFileWrite       : BOOL;  
    bFileWriteBusy   : BOOL;  
    bFileWriteError  : BOOL;  
    nFileWriteErrorId: UDINT;  
    nFileWriteCount  : UDINT;  
    fileData         : ARRAY[0..9] OF BYTE;  
END_VAR
```

![24604028](/tcplclib_tc2_system/1033/Images/png/31256971__en-US__Web.png)

In the example, after a rising edge at bFileWrite, 10 bytes of the array FILEDATA are written to the file.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
