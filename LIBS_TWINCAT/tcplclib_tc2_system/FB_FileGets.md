# FB_FileGets

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileGets

# FB\_FileGets

![618145](/tcplclib_tc2_system/1033/Images/png/9007199285949963__Web.png)

The function block reads strings from a file. The string is read up to and including the line feed character, or up to the end of the file or the maximum permitted length of sLine. The zero termination is appended automatically. The file must have been opened in text mode.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy   : BOOL;  
    bError  : BOOL;  
    nErrId  : UDINT;  
    sLine   : T_MaxString;  
    bEOF    : BOOL;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**sLine**: String that was read (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**bEOF**: This output is set if the end of the file was reached and no further data bytes could be read (cbRead=0). This output is not set if further data bytes could be read (cbRead>0).

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Invalid or unknown file handle. |
| 0x70A | No memory for read buffer. |
| 0x70E | File was opened with wrong method (e.g. with obsolete FILEOPEN function block). |

**Example of calling the function block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileGets        : FB_FileGets;  
    hFile             : UINT;  
    bFileGets         : BOOL;  
    bFileGetsBusy     : BOOL;  
    bFileGetsError    : BOOL;  
    nFileGetsErrorId  : UDINT;  
    strBuffer         : STRING;  
    bFileGetsEOF      : BOOL;  
END_VAR
```

![5563313](/tcplclib_tc2_system/1033/Images/png/31212171__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
