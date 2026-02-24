# FB_FileOpen

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileOpen

# FB\_FileOpen

![2794650](/tcplclib_tc2_system/1033/Images/png/9007199285956363__Web.png)

The function block creates a new file or opens an existing file for editing.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    sPathName  : T_MaxString;  
    nMode      : DWORD;  
    ePath      : E_OpenPath := PATH_GENERIC;  
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**sPathName**: Path and file name for the file to be opened. The path can only point to the local computer’s file system. Network paths cannot be specified here (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**nMode**: Mode in which the file is to be opened. The codes listed below are the various opening modes which are already pre-defined as constants in the library and which can accordingly be passed symbolically to the function block. The opening modes can be combined with an OR operation. The opening modes can be combined, similar to the opening modes of the fopenfunction in C or C++.

| Modes | Description |
| --- | --- |
| FOPEN\_MODEREAD | r: Opens a file for reading. An error is returned if the file cannot be found or does not exist. |
| FOPEN\_MODEWRITE | w: Opens an empty file for writing. If the file already exists, it is overwritten. |
| FOPEN\_MODEAPPEND | a: Opens a file for writing at the end of the file (append). If the file does not exist, a new file is created. |
| FOPEN\_MODEREAD OR FOPEN\_MODEPLUS | r+: Opens a file for reading and writing. The file must exist. |
| FOPEN\_MODEWRITE OR FOPEN\_MODEPLUS | w+: Opens an empty file for reading and writing. If the file already exists, it is overwritten. |
| FOPEN\_MODEAPPEND OR FOPEN\_MODEPLUS | a+: Opens a file for reading and writing at the end of the file (append). If the file does not exist, a new file is created. The memory path must be known, otherwise error 1804 will appear. All write operations are always performed at end of a file, if the file was opened in the modes "a" or "a+". The file pointer can be moved with FB\_FileSeek, although for writing it is moved to the end of the file by default, i.e. existing data cannot be overwritten. |
| FOPEN\_MODEBINARY | b: Opens the file in binary mode |
| FOPEN\_MODETEXT | t: Opens the file in text mode |

**ePath**: This input can be used to select a TwinCAT system path on the target device for opening the file (type: [E\_OpenPath](ms-xhelp:///?Id=beckhoff-3a2e-42d2-836a-1c47c911486b)).

**bExecute**: The function block is activated by a rising edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    hFile  : UINT;(* file handle *)  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**hFile**: Contains the file handle created for the file when opening has been successful. This handle is then transferred to the other file function blocks as ID for the file to be edited.

| Command-specific error code | Possible cause |
| --- | --- |
| 0x703 | Unknown or invalid nMode or ePath parameter. |
| 0x70C | File not found. Invalid file name or path. |
| 0x716 | No further free file handles. |

## Hint:

Only three parameter can be used with OR:

**Mode = [ Parameter1 ] OR [ Parameter2 ] OR [ Paramerter3 ]**

The following values are allowed for Parameter 1:

* FOPEN\_MODEREAD
* FOPEN\_MODEWRITE
* FOPEN\_MODEAPPEND

The following values are allowed for Parameter 2:

* FOPEN\_MODEPLUS

The following values are allowed for Parameter 3:

* FOPEN\_MODEBINARY
* FOPEN\_MODETEXT

If no binary or text mode is given, the file will be opened in a mode which is defined by the operating system variable. In the most cases the file will be opened in the text mode. It makes sense to declare the text or binary mode. This system variable can't be changed in the PLC!  
The following combinations are allowed:

| Text file open mode | Binary file open mode |
| --- | --- |
| FOPEN\_MODEREAD OR FOPEN\_MODETEXT | FOPEN\_MODEREAD OR FOPEN\_MODEBINARY |
| FOPEN\_MODEWRITE OR FOPEN\_MODETEXT | FOPEN\_MODEWRITE OR FOPEN\_MODEBINARY |
| FOPEN\_MODEAPPEND OR FOPEN\_MODETEXT | FOPEN\_MODEAPPEND OR FOPEN\_MODEBINARY |
| FOPEN\_MODEREAD OR FOPEN\_MODEPLUS OR FOPEN\_MODETEXT | FOPEN\_MODEREAD OR FOPEN\_MODEPLUS OR FOPEN\_MODEBINARY |
| FOPEN\_MODEWRITE OR FOPEN\_MODEPLUS OR FOPEN\_MODETEXT | FOPEN\_MODEWRITE OR FOPEN\_MODEPLUS OR FOPEN\_MODEBINARY |
| FOPEN\_MODEAPPEND OR FOPEN\_MODEPLUS OR FOPEN\_MODETEXT | FOPEN\_MODEAPPEND OR FOPEN\_MODEPLUS OR FOPEN\_MODEBINARY |

All other combinations are false. Examples for forbidden open mode:  
FOPEN\_MODEBINARY OR FOPEN\_MODETEXT  
FOPEN\_MODEWRITE OR FOPEN\_MODEAPPEND

**Example of calling the block in ST:**

* [File access from the PLC](ms-xhelp:///?Id=beckhoff-2a41-4bb4-9650-b2204625dc8c)

**Example of calling the block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileOpen      : FB_FileOpen;  
    bFileOpen       : BOOL;  
    bFileOpenBusy   : BOOL;  
    bFileOpenError  : BOOL;  
    nFileOpenErrId  : UDINT;  
    hFile           : UINT;  
END_VAR
```

![25151854](/tcplclib_tc2_system/1033/Images/png/31218571__en-US__Web.png)

This should create (or overwrite) the file *TestFile2.txt* in the root directory of drive C: in the text mode.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
