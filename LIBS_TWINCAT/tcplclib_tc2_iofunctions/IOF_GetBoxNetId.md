# IOF_GetBoxNetId

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [General IO FBs](ms-xhelp:///?Id=beckhoff-45cd-441d-a862-564f8b5fb3d0)
4. IOF\_GetBoxNetId

# IOF\_GetBoxNetId

![50695543](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314030859__Web.png)

Some boxes (slave modules) can be assigned an AmsNetId during the configuration in TwinCAT. The AmsNetId can then be used to execute firmware functions on the box. The IOF\_GetBoxNetId function block determines the TwinCAT network address, knowing the device ID of the master and the fieldbus address or logical address in the fieldbus. The device IDs are specified by the TwinCAT system during the configuration and cannot be configured by the user.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    DEVICEID  : UDINT;  
    BOXARDDR  : WORD;  
    START     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: The network address of the TwinCAT computer on which the function is to be executed can be entered here (type: T\_AmsNetID). If it is to be run on the local computer, an empty string can be entered.

**DEVICEID**: The master's device ID.

**BOXADDR**: The fieldbus address, or the logical address of the box (slave module)whose AmsNetId is to be read.

**START**: the block is activated by a positive edge at this input.

**TMOUT**: States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY     : BOOL;  
    ERR      : BOOL;  
    ERRID    : UDINT;  
    BoxNetId : T_AmsNetId;  
END_VAR
```

**BUSY**: When the function block is activated this output is set. It remains set until a feedback is received.

**ERR**: If an error should occur during the transfer of the command, then this output is set once the BUSY output was reset.

**ERRID**: Supplies the [ADS error number](ms-xhelp:///?Id=beckhoff-721e-4655-8e94-3548ed43349a) when the ERR output is set.

**BoxNetId**: The TwinCAT network address of the box as a string (type: T\_AmsNetID).

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | All IO devices | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
