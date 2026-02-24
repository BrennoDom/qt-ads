# FB_GetVolumeId

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetVolumeId

![34708966](/tcplclib_tc2_utilities/1033/Images/png/2242894859__Web.png)

The function block FB\_GetVolumeId reads the System-ID and the Volume-System-ID as a GUID.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute   :   BOOL;  
    tTimeout   :   TIME;  
    sNetId     :   T_AmsNetId;  
END_VAR
```

**bExecute**: The block is activated by a positive edge at this input.

**tTimeout**: States the length of the timeout that may not be exceeded by execution of the ADS command.

**sNetId**: The AmsNetId of the TwinCAT computer whose System-ID is to be read (type: T\_AmsNetId) can be specified here. If it is to be run on the local computer, an empty string can be entered.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy       :   BOOL;  
    bError      :   BOOL;  
    nErrorId    :   UDINT;  
    stVolumeId  :   GUID;  
    stSystemId  :   GUID;      
END_VAR
```

**bBusy**: This output is set when the function block is activated, and remains set until an acknowledgement is received.

**bError**: If an error should occur during the transmission of the command, this output is set after the bBusy output has been reset.

**nErrorId**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the bError output is set.

**stVolumeId**: Supplies the Volume-System-ID as a [GUID](ms-xhelp:///?Id=beckhoff-7f71-4e6d-8084-282179f8e0ac).

**stSystemId**: Supplies the System-ID as [GUID](ms-xhelp:///?Id=beckhoff-7f71-4e6d-8084-282179f8e0ac).

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.4018 | PC or CX (x86, x64, ARM) | Tc2\_Utilities |
