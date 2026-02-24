# FB_FileRename

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileRename

# FB\_FileRename

![13105749](/tcplclib_tc2_system/1033/Images/png/9007199285975563__Web.png)

This function block can be used to rename a file.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetId;  
    sOldName : T_MaxString;  
    sNewName : T_MaxString;  
    ePath    : E_OpenPath := PATH_GENERIC;     (* Default: generic file path*)  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**sOldName**: Old file name (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**sNewName**: New file name (type: [T\_MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558)).

**ePath**: This input can be used to select a TwinCAT system path on the target device for opening the file (type: [E\_OpenPath](ms-xhelp:///?Id=beckhoff-3a2e-42d2-836a-1c47c911486b)).

**bExecute**: The function block is activated by a rising edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

| Command-specific error code | Possible cause |
| --- | --- |
| 0x70C | File not found. Invalid sOldName, sNewName or ePath parameter. |

**Example of calling the function block in FBD:**

```
PROGRAM Test  
VAR  
    fbFileRename      : FB_FileRename;  
    bFileRename       : BOOL;  
    bFileRenameBusy   : BOOL;  
    bFileRenameError  : BOOL;  
    nFileRenameErrId  : UDINT;  
END_VAR
```

![50842877](/tcplclib_tc2_system/1033/Images/png/31237771__en-US__Web.png)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
