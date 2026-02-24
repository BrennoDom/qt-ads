# FB_GetSystemId

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetSystemId

![65880360](/tcplclib_tc2_utilities/1033/Images/png/9007199290260875__Web.png)

The function block reads the system ID as GUID (see "About TwinCAT..." at the TwinCAT icon in the system tray).

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL;  
    tTimeout  : TIME := DEFAULT_ADS_TIMEOUT;  
    sNetId    : T_AmsNetId;  
END_VAR
```

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

**sNetId**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose system ID is to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrorId   : UDINT;  
    stSystemId : GUID;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrorId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the bError output is set.

**stSystemId**: Supplies the system ID as [GUID](ms-xhelp:///?Id=beckhoff-7f71-4e6d-8084-282179f8e0ac).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
