# FB_EOF

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_EOF

# FB\_EOF

![41459726](/tcplclib_tc2_system/1033/Images/png/9007199285930763__Web.png)

The function block can check whether the end of the file was reached.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    bEOF   : BOOL;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**bEOF**: This output is set when the end of the file is reached.

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Invalid or unknown file handle. |
| 0x70E | File was opened with wrong method (e.g. with obsolete FILEOPEN function block). |

**Example of calling the function block in FBD:**

```
PROGRAM Test  
VAR  
    fbEOF       : FB_EOF;  
    hFile       : UINT;  
    bFileEOF    : BOOL;  
    bEOFBusy    : BOOL;  
    bEOFError   : BOOL;  
    nEOFErrorId : UDINT;  
    bIsEOF      : BOOL;  
END_VAR
```

![37593218](/tcplclib_tc2_system/1033/Images/png/31192971__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
