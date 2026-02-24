# FB_GetDongleSystemID

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# FB\_GetDongleSystemID

![9449599](/tcplclib_tc2_utilities/1033/Images/png/4400701323__Web.png)

The function block FB\_GetDongleSystemID reads the system ID and the volume ID of the TwinCAT 3 license dongle as GUID.

## VAR\_INPUT

```
VAR_INPUT  
    bExecute  : BOOL;  
    tTimeout  : TIME;  
    sNetId    : T_AmsNetId;  
    stAmsAddr : AMSADDR;  
END_VAR
```

**bExecute**: The function block is activated by a positive edge at this input.

**tTimeout**: Timeout time that must not be exceeded when the command is executed.

**sNetId**: AmsNetId (AMS network identifier) of the TwinCAT computer whose license status is to be read (type: T\_AmsNetId). If it is to be run on the local computer, an empty string can be entered.

**stAmsAddr**: Network address (AmsNetId and port) of the license dongle (type: AMSADDR)

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy      : BOOL;  
    bError     : BOOL;  
    nErrorId   : UDINT;  
    stSystemID : GUID;  
    stVolumeID : GUID;  
END_VAR 
```

**bBusy**: TRUE, as long as the function block is active.

**bError**: TRUE if an error occurs during command execution.

**nErrorId**: Supplies the ADS error number when the bError output is set.

**stSystemID**: System ID of the license dongle (type: GUID)

**stVolumeID**: Volume ID of the license dongle (type: GUID)

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022 | PC or CX (x64, x86) | Tc2\_Utilties >= 3.3.24.0 |
