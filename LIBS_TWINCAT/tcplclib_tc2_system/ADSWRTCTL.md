# ADSWRTCTL

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [ADS function blocks](ms-xhelp:///?Id=beckhoff-ecf7-40ce-b327-c656e302b3ef)
4. ADSWRTCTL

# ADSWRTCTL

![66105898](/tcplclib_tc2_system/1033/Images/png/9007199285860363__Web.png)

This block permits the execution of an ADS control command to affect the state of an ADS device, e.g. to start, stop or reset a device.

## VAR\_INPUT

```
VAR_INPUT  
    NETID     : T_AmsNetId;  
    PORT      : T_AmsPort;  
    ADSSTATE  : UINT;  
    DEVSTATE  : UINT;  
    LEN       : UDINT;  
    SRCADDR   : PVOID;  
    WRITE     : BOOL;  
    TMOUT     : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS device (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**ADSSTATE**: State identification code of the ADS target device. The codes shown here are specified for all ADS servers:

* ADSSTATE\_IDLE = 1;
* ADSSTATE\_RESET = 2;
* ADSSTATE\_INIT = 3;
* ADSSTATE\_START = 4;
* ADSSTATE\_RUN= 5;
* ADSSTATE\_STOP = 6;
* ADSSTATE\_SAVECFG = 7;
* ADSSTATE\_LOADCFG = 8;

**DEVSTATE**: Specific state identification code of the ADS target device. The codes given here are supplementary information, which is specific to the ADS device.

**LEN**: Contains the number, in bytes, of the data that is to be written.

**SRCADDR**: Contains the address of the buffer from which the data to be written is to be fetched. The programmer is himself responsible for dimensioning the buffer to such a size that LEN bytes can be taken from it. The programmer is responsible for dimensioning the buffer such that it can accommodate WRITELEN bytes.

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

**Example of calling the block in FBD:**

![58082174](/tcplclib_tc2_system/1033/Images/png/31122571__en-US__Web.png)

In the example a reset command (ADSSTATE=2) is sent to the I/O server (Port300), along with supplementary data hex.AFFE. As a result the I/O server executes a bus reset.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
