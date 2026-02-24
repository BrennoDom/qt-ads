# ADSWRITE

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [ADS function blocks](ms-xhelp:///?Id=beckhoff-ecf7-40ce-b327-c656e302b3ef)
4. ADSWRITE

# ADSWRITE

![9875225](/tcplclib_tc2_system/1033/Images/png/9007199285841163__Web.png)

Block for executing an ADS write command for transferring data to an ADS device.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    PORT    : T_AmsPort;  
    IDXGRP  : UDINT;  
    IDXOFFS : UDINT;  
    LEN     : UDINT;  
    SRCADDR : PVOID;  
    WRITE   : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS device (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**IDXGRP**: Index group number (32 bit, unsigned) of the requested ADS service. This value is to be found in the ADS table of the addressed device.

**IDXOFFS**: Index offset number (32 bit, unsigned) of the requested ADS service. This value is to be found in the ADS table of the addressed device.

**LEN**: Number, in bytes, of the data to be read.

**SRCADDR**: Address of the buffer from which the data to be written is to be fetched. The programmer is himself responsible for dimensioning the buffer to such a size that LEN bytes can be taken from it. The buffer can be a single variable, an array or a structure, whose address can be determined with the ADR operator.

**WRITE**: The ADS command is triggered by a rising edge at this input.

**TMOUT**: Indicates the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
END_VAR
```

**BUSY**: This output remains TRUE until the function block has executed a command, but at the longest for the duration supplied to the Timeout input. While BUSY = TRUE, no new command will be accepted at the inputs. Note that it is not the execution of the service but its acceptance whose time is monitored.

**ERR**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in ERRID. If the function block has a timeout error, ERR is TRUE and ERRID is 1861 (hexadecimal 0x745). Is reset to FALSE by the execution of a command at the inputs.

**ERRID**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

**Example of calling the block in ST:**

* [Example with AdsWrite function block](ms-xhelp:///?Id=beckhoff-2156-4962-82ea-70e63a52a9b2)

**Example of calling the block in FBD**

![21768161](/tcplclib_tc2_system/1033/Images/png/31103371__en-US__Web.png)

NC axis no. 1 is here deactivated through a write instruction with IDXGRP 00004201 (hex) and the IDXOFFS 00000050 (hex). To activate the axis another write instruction with the IDXOFFS 00000051 (hex) must be given. Since this write instruction does not require any parameters, the inputs LEN and SRCADDR have no significance, but must nevertheless be set to zero.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
