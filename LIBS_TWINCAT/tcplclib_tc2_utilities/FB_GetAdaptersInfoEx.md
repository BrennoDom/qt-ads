# FB_GetAdaptersInfoEx

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetAdaptersInfoEx

This function block can be used to read adapter information for a TwinCAT PC. The maximum number of adapter information read is limited to 64.

After a successful call, the read process is finished and the read adapter information can be copied using the Get() method.

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
    nErrorID    : UDINT;  
    nAdapters   : UINT;  
END_VAR
```

**bBusy**: If the function block is activated, this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transmission of the command, this output is set after the *bBusy* output has been reset.

**nErrorID**: Returns the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**nAdapters**: Number of local adapters found. Their adapter information has been read and can be copied using the Get() method.

## Get() method

Once the function block has been called successfully, the read operation is complete and the adapter information read can be copied using the Get() method.

It is possible to copy the information of all adapters together. Likewise, the information per adapter can be copied individually one after the other.

When called, a local array (type: [ST\_IpAdapterInfo](ms-xhelp:///?Id=beckhoff-9297-4cb6-8196-479f4d247aa4)) is specified. Each array element thus provides information of an adapter.

```
METHOD Get : BOOL  
VAR_INPUT  
    pAdapters        : POINTER TO ST_IpAdapterInfo; // pointer to array of adapter info (variable array length)  
    nAdaptersSize    : UDINT; // size in bytes of array of adapter info  
END_VAR
```

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4024 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) >= 3.3.48.0 |

See also

* [ST\_IPAdapterInfo](ms-xhelp:///?Id=beckhoff-9297-4cb6-8196-479f4d247aa4)
