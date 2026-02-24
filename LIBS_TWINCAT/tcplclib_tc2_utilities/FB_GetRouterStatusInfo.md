# FB_GetRouterStatusInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetRouterStatusInfo

![52059282](/tcplclib_tc2_utilities/1033/Images/png/9007199290257675__Web.png)

The function block FB\_GetRouterStatusInfo can be used to read status information for the TwinCAT router from the PLC (available memory, number of registered ports etc.).

## VAR\_INPUT

```
VAR_INPUT  
    sNetId   : T_AmsNetID := '';  
    bExecute : BOOL;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNetId**: Here you can enter a string with the network address of the TwinCAT computer whose TwinCAT router information is to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**bExecute**: the block is activated by a positive edge at this input.

**tTimeOut**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bError : BOOL;  
    nErrId : UDINT;  
    info   : ST_TcRouterStatusInfo;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: In the event of an error during the command transfer, this output is set once the *bBusy* output has been reset.

**nErrId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the *bError* output is set.

**info**: Structure variable with TwinCAT router status information (type: [ST\_TcRouterStatusInfo](ms-xhelp:///?Id=beckhoff-f64d-49a0-9537-bc8f1e8eb2b9)).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
