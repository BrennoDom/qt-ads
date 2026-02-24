# GetRemotePCInfo

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# GetRemotePCInfo

![35962059](/tcplclib_tc2_utilities/1033/Images/png/9007199290347275__Web.png)

The function block "GetRemotePCInfo" can be used to read information about configured remote PCs in the TwinCAT router. After successful execution the structure "RemotePCInfo" contains the NetIDs and names of the remote PCs as strings in the order in which they were stored in the TwinCAT router. The function block allows router information relating to either a local or to a remote TwinCAT system to be read.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    START   : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: This parameter can be used to specify the AmsNetID of the TwinCAT computer whose router information is to be read via configured remote PCs (type: T\_AmsNetID). To determine the remote PCs of the local TwinCAT system, an empty string can be specified.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded by execution of the ADS command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY         : BOOL;  
    ERR          : BOOL;  
    ERRID        : UDINT;  
    RemotePCInfo : REMOTEPCINFOSTRUCT;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-e821-44ae-982a-c8b931426e8c) when the ERR output is set.

**RemotePCInfoStruct**: Structure containing information about the configured remote PCs (type: [REMOTEPCINFOSTRUCT](ms-xhelp:///?Id=beckhoff-7976-4b06-9af7-b4bb4aba335b)).

**Example:**

```
PROGRAM MAIN  
VAR  
    GetRemotePCInfo1     : GetRemotePCInfo;  
    RemotePCInfo         : REMOTEPCINFOSTRUCT;  
    bBusy                : BOOL;  
    bError               : BOOL;  
    iErrorId             : UDINT;  
    bStart               : BOOL;  
END_VAR
```

![55223077](/tcplclib_tc2_utilities/1033/Images/gif/35609483__en-US__Web.gif)

**Online View:**

NetIDs and names of the configured remote PCs.

![27245651](/tcplclib_tc2_utilities/1033/Images/gif/35612683__en-US__Web.gif)

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
