# FB_GetDeviceIdentification

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetDeviceIdentification

![24604028](/tcplclib_tc2_utilities/1033/Images/png/9007199290241675__Web.png)

The block reads the device ID.

|  |  |
| --- | --- |
| 20109663 | Obsolete functionality  For longer hardware model and hardware serial number strings the block [FB\_GetDeviceIdentificationEx](ms-xhelp:///?Id=beckhoff-790c-4ac0-bb96-e292c315bf69) has to be used. |

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

**sNetId**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose device ID is to be read (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrorId   : UDINT;  
    stDevIdent : ST_DeviceIdentification;  
END_VAR
```

**bBusy**: When the function block is activated this output is set. It remains set until a feedback is received.

**bError**: If an error should occur during the transfer of the command, then this output is set once the bBusy output was reset.

**nErrorId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the bError output is set.

**stDevIdent**: Provides the device ID (type: [ST\_DeviceIdentification](ms-xhelp:///?Id=beckhoff-d3fe-40fe-a084-5f0263f92422))

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
