# FB_RAIDGetInfo

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [RAID Controller](ms-xhelp:///?Id=beckhoff-f9c6-466a-a63a-c29defe3c3dc)
4. FB\_RAIDGetInfo

# FB\_RAIDGetInfo

![59224828](/tcplclib_tc2_iofunctions/1033/Images/png/9007199314261259__Web.png)

This function block returns a RAID info. containing the number of RAID controller sets and the maximum number of drives per set.

Note

The function block should be called once only in a PLC program!

The system performance can be dramatically affected by the cyclic calling of this function block.

## VAR\_INPUT

```
VAR_INPUT  
    sNETID       : T_AmsNetId;  
    bWrtRd       : BOOL;  
    nRAIDCntlrID : UDINT;  
    tTimeOut     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**sNETID:** A string containing the AMS network ID of the target device to which the ADS command is sent (type: T\_AmsNetID).

**bWrtRd:** The ADS command is triggered by the rising edge of this input.

**nRAIDCntlrID:** The RAID controller ID. (Note: can be read with FB\_RAIDCntlrFind)

**tTimeOut:** States the length of the timeout that may not be exceeded during execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    stRAIDInfo   : ST_RAIDInfo;  
    nBytesRead   : UDINT;  
    bBusy        : BOOL;  
    bError       : BOOL;  
    nErrorID     : UDINT;  
END_VAR
```

**stRAIDInfo:** Returns a RAID info. containing the number of RAID controller sets and the maximum number of drives per set (type: [ST\_RAIDInfo](ms-xhelp:///?Id=beckhoff-17ce-44e7-a5fa-438362d8ca66)).

**nBytesRead:** Number of successfully returned data bytes.

**bBusy:** This output remains TRUE until the block has executed a command, but no longer than the time present at the ‘Timeout’ input. No new command will be accepted at the inputs as long as bBusy = TRUE. Please note that it is not the execution of the service, but the time during which it be may executed that is monitored here.

**bError:** This output is set to TRUE if an error occurs during the execution of a command. The command-specific error code is located in ‘nErrorId’. If the block has an timeout error, ‘bError’ is set to TRUE and ‘nErrorId’ is 1861 (hexadecimal 0x745). It is set to FALSE if a command is executed at the inputs.

**nErrorID:** Contains the command-specific error code of the commands executed last; it is reset to 0 by a command at the inputs.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
