# FB_FileTell

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileTell

# FB\_FileTell

![18270010](/tcplclib_tc2_system/1033/Images/png/9007199285988363__Web.png)

The function block determines the current position of the file pointer. The position indicates the relative offset from the start of the file.

Note that in files opened in “Append at end of file” mode, the current position is determined by the last I/O operation, not by the position of the next write access. After a read operation, for example, the file pointer is at the position where the next read access will take place, not at the position where the next write access will take place (in append mode, the file pointer is always moved to the end before a write operation).

If no previous I/O operation was performed and the file was opened in append mode, the file pointer is at the start of the file.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy    : BOOL;  
    bError   : BOOL;  
    nErrId   : UDINT;  
    nSeekPos : DINT;(* On error, nSEEKPOS returns -1 *)  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**nSeekPos**: Returns the current position of the file pointer.

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Invalid or unknown file handle. |
| 0x70E | File was opened with wrong method (e.g. with obsolete FILEOPEN function block). |

**Example of calling the function block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileTell        : FB_FileTell;  
    hFile             : UINT;  
    bFileTell         : BOOL;  
    bFileTellBusy     : BOOL;  
    bFileTellError    : BOOL;  
    nFileTellErrorId  : UDINT;  
    nFileTellSeekPos  : DINT;  
END_VAR
```

![30212363](/tcplclib_tc2_system/1033/Images/png/31250571__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
