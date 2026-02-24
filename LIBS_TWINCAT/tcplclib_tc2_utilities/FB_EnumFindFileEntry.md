# FB_EnumFindFileEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_EnumFindFileEntry

![37228582](/tcplclib_tc2_utilities/1033/Images/png/9007199290209675__Web.png)

This function block searches a directory for a file or a subdirectory whose name is similar to the specified name. Any entries found can be read individually. See also description of the FB\_EnumFindFileList function block. The input parameter *eCmd* is used for navigating through the list of entries. The *eCmd* input determines whether the first or the next input is read, for example.

**Important notes:**

A new search may be started only if the previous search has been fully completed. The function block may need to be activated several times (by a rising edge at the bExecute input) for a complete search. The search is only fully complete if bEOE =TRUE was reached or if the search was terminated prematurely with ECMD = eEnumCmd\_Abort.

For the TwinCAT system, the search may not yet be completed if the PLC application has already found the file or directory that was sought.

If not all entries are to be read (i.e. *bEOE=TRUE* is not reached), the function block subsequently has to be called with the input parameter *eCmd = eEnumCmd\_Abort*. This is necessary in order to complete the search and release all internal resources (file handles). If *bEOE=TRUE* was reached or if an error occurs, *eEnumCmd\_Abort* is automatically executed internally.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetID;  
    sPathName : T_MaxString;  
    eCmd      : E_EnumCmdType := eEnumCmd_First;  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: String containing the network address of the TwinCAT computer on which a directory search is to be executed (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sPathName**: A valid directory name or directory with file name as string (type: T\_MaxString). The string can contain ( \* and ?) as wildcards. If the path ends with a wildcard, dot or the directory name, the user must have access rights to this path and its subdirectories.

**eCmd**: Command parameter for the enumeration block (type: [E\_EnumCmdType](ms-xhelp:///?Id=beckhoff-cb91-427b-a901-37149aa7aa27)).

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrId     : UDINT;  
    bEOE       : BOOL;  
    stFindFile : ST_FindFileEntry;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**bEOE**: End of enumeration was reached. During the first attempt to read a non-existing entry this output is set to TRUE. This means that read entries are valid as long as *bEOE* = FALSE and *bError* = FALSE.

**stFindFile**: If successful this structure variable returns information about the file that was found (type: [ST\_FindFileEntry](ms-xhelp:///?Id=beckhoff-b6b8-41e0-b10e-9c982ba31f1e)).

**Example:**

[See: Example: File search (FB\_EnumFindFileEntry, FB\_EnumFindFileList).](ms-xhelp:///?Id=beckhoff-e041-4abd-baa8-9ffab43553c5)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
