# FB_FileLoad

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [File function blocks](ms-xhelp:///?Id=beckhoff-00e0-4838-820f-f72f4197fa14)
4. FB\_FileLoad

# FB\_FileLoad

![14981763](/tcplclib_tc2_system/1033/Images/png/7084089483__Web.png)

The contents of a file can be read out with this function block. The file is opened implicitly in binary mode, the contents are read out and the file is then closed again.

## VAR\_INPUT

```
VAR_INPUT  
    sNetId     : T_AmsNetId;  
    sPathName  : T_MaxString;  
    pReadBuff  : PVOID;  
    cbReadLen  : UDINT;  
    bExecute   : BOOL;  
    tTimeout   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: String containing the AMS network ID of the target device to which the ADS command is addressed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**sPathName:** Storage path and file name of the file to be opened. The path can only point to the local file system of the computer. Network paths cannot be specified here (type: T\_[MaxString](ms-xhelp:///?Id=beckhoff-77e0-4f6f-a54e-eec93d1cd558))

**pReadBuff**: Address of the buffer into which the data are to be read. The buffer can be a single variable, an array or a structure, whose address can be found with the ADR operator.

**cbReadLen**: Number of bytes to be read.

**bExecute**: The function block is activated by a rising edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the internal ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    cbRead : UDINT;      
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bError**: If an error occurs during command execution, this output is set, once the bBusy output has been reset.

**nErrId**: Returns the [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or the command-specific error code when the bError output is set.

**cbRead**: Number of currently read bytes.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4022.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) >= v3.4.22.0 |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
