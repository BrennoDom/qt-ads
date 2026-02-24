# FB_GetAdaptersInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetAdaptersInfo

![33256841](/tcplclib_tc2_utilities/1033/Images/png/9007199290238475__Web.png)

This function block can be used to read adapter information for a TwinCAT PC. The maximum number of adapter data that can be read is currently limited to MAX\_LOCAL\_ADAPTERS + 1 (default = 6).

## VAR\_INPUT

```
VAR_INPUT  
    sNetID   : T_AmsNetId;  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose adapter information is to be read. For the local PC an empty string may be specified (type: T\_AmsNetID).

**bExecute**: the block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy       : BOOL;  
    bError      : BOOL;  
    nErrID      : UDINT;  
    arrAdapters : ARRAY[0..MAX_LOCAL_ADAPTERS] OF ST_IpAdapterInfo;  
    nCount      : UDINT;  
    nGet        : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**arrAdapters**: Array variable containing the last read adapter information. Each array element provides information for one adapter (type: [ST\_IpAdapterInfo](ms-xhelp:///?Id=beckhoff-9297-4cb6-8196-479f4d247aa4)).

**nCount**: Maximum number of local adapters that were found.

**nGet**: Number of valid entries in the *arrAdapters* output variable.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (WES7/Win7/Win10: TC RT x86/x64, WEC6/7: TC RT x86, WEC7: TC CE7 ARMV7, TC/BSD: TC RT x64) | Tc2\_Utilities (System) |
