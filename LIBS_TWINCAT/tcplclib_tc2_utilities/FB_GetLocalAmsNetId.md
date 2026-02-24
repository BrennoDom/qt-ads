# FB_GetLocalAmsNetId

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetLocalAmsNetId

![57980147](/tcplclib_tc2_utilities/1033/Images/png/9007199290254475__Web.png)

This function block can be used to read the network address (AmsNetID) of a local TwinCAT PC.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  :BOOL;  
    tTimeOut  :TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bExecute**: the block is activated by a positive edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      :BOOL;  
    bError     :BOOL;  
    nErrId     :UDINT;  
    AddrString :T_AmsNetId;  
    AddrBytes  :T_AmsNetIdArr;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**AddrString**: AmsNetID of the local PC as string (type: T\_AmsNetID).

**AddrBytes**: AmsNetID of the local PC as byte array (type: T\_AmsNetIDArr).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
