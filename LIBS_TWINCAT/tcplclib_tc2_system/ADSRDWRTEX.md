# ADSRDWRTEX

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [ADS function blocks](ms-xhelp:///?Id=beckhoff-ecf7-40ce-b327-c656e302b3ef)
4. ADSRDWRTEX

# ADSRDWRTEX

![31297682](/tcplclib_tc2_system/1033/Images/png/9007199285876363__Web.png)

This block allows execution of a combined ADS write/read instruction. Data is transmitted to an ADS device (write) and its response data read with one call. Contrary to the ADSRDWRT function block ADSRDWRTEX supplies the number of actually read data bytes as parameter.

## VAR\_INPUT

```
VAR_INPUT  
    NETID    : T_AmsNetId;  
    PORT     : T_AmsPort;  
    IDXGRP   : UDINT;  
    IDXOFFS  : UDINT;  
    WRITELEN : UDINT;  
    READLEN  : UDINT;  
    SRCADDR  : PVOID;  
    DESTADDR : PVOID;  
    WRTRD    : BOOL;  
    TMOUT    : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS device (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**IDXGRP**: Index group number (32 bit, unsigned) of the requested ADS service. This value is to be found in the ADS table of the addressed device.

**IDXOFFS**: Index offset number (32 bit, unsigned) of the requested ADS service. This value is to be found in the ADS table of the addressed device.

**WRITELEN**: Number, in bytes, of the data that is to be written.

**READLEN**: Number, in bytes, of the data to be read.

**SRCADDR**: Address of the buffer from which the data to be written is to be fetched. The programmer is responsible for dimensioning the buffer such that it can accommodate WRITELEN bytes. The programmer is responsible for dimensioning the buffer such that it can accommodate WRITELEN bytes.

**DESTADDR**: Address of the buffer which is to receive the data that has been read. The programmer is responsible for dimensioning the buffer such that it can accommodate READLEN bytes. The programmer is responsible for dimensioning the buffer such that it can accommodate WRITELEN bytes.

**WRTRD**: The ADS command is triggered by a rising edge at this input.

**TMOUT**: Indicates the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY    : BOOL;  
    ERR     : BOOL;  
    ERRID   : UDINT;  
    COUNT_R : UDINT;  
END_VAR
```

**BUSY**: This output remains TRUE until the function block has executed a command, but at the longest for the duration supplied to the Timeout input. While BUSY = TRUE, no new command will be accepted at the inputs. Note that it is not the execution of the service but its acceptance whose time is monitored.

**ERR**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in ERRID. If the function block has a timeout error, ERR is TRUE and ERRID is 1861 (hexadecimal 0x745). Is reset to FALSE by the execution of a command at the inputs.

**ERRID**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

**COUNT\_R**: Number of successfully read data bytes.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
