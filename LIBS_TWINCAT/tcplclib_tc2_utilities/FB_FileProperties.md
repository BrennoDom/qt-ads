# FB_FileProperties

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_FileProperties

![25482430](/tcplclib_tc2_utilities/1033/Images/png/10049080587__Web.png)

This function block outputs the file properties of a selected file.

## VAR\_INPUT

```
VAR_INPUT  
    sNetID    : T_AmsNetID;  
    sPathName : T_MaxString;  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: Here you can enter a string with the network address of the TwinCAT computer whose directory is to be searched (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**sPathName**: Here the complete file path including file name and file extension is specified as a string (type: T\_MaxString).

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy        : BOOL;  
    bError       : BOOL;  
    nErrId       : UDINT;  
    stProperties : ST_FindFileEntry;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**stProperties**: If the search was successful, this structure variable returns information on the file that was found (type: [ST\_FindFileEntry](ms-xhelp:///?Id=beckhoff-b6b8-41e0-b10e-9c982ba31f1e)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64, TC OS ARMT2) | Tc2\_Utilities (System) |
