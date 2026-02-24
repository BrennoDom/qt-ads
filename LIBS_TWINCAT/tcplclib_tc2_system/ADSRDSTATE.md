# ADSRDSTATE

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [ADS function blocks](ms-xhelp:///?Id=beckhoff-ecf7-40ce-b327-c656e302b3ef)
4. ADSRDSTATE

# ADSRDSTATE

![13243689](/tcplclib_tc2_system/1033/Images/png/9007199285853963__Web.png)

This block permits the state of an ADS device to be requested.

## VAR\_INPUT

```
VAR_INPUT  
    NETID   : T_AmsNetId;  
    PORT    : T_AmsPort;  
    RDSTATE : BOOL;  
    TMOUT   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS device (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**RDSTATE**: The ADS command is triggered by a rising edge at this input.

**TMOUT**: Indicates the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    BUSY      : BOOL;  
    ERR       : BOOL;  
    ERRID     : UDINT;  
    ADSSTATE  : UINT;  
    DEVSTATE  : UINT;  
END_VAR
```

**BUSY**: This output remains TRUE until the function block has executed a command, but at the longest for the duration supplied to the Timeout input. While BUSY = TRUE, no new command will be accepted at the inputs. Note that it is not the execution of the service but its acceptance whose time is monitored.

**ERR**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in ERRID. If the function block has a timeout error, ERR is TRUE and ERRID is 1861 (hexadecimal 0x745). Is reset to FALSE by the execution of a command at the inputs.

**ERRID**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

**ADSSTATE**:

Contains the state identification code of the ADS target device. The codes returned here are specified for all ADS servers:

* ADSSTATE\_INVALID = 0;
* ADSSTATE\_IDLE = 1;
* ADSSTATE\_RESET = 2;
* ADSSTATE\_INIT = 3;
* ADSSTATE\_START = 4;
* ADSSTATE\_RUN = 5;
* ADSSTATE\_STOP = 6;
* ADSSTATE\_SAVECFG = 7;
* ADSSTATE\_LOADCFG = 8;
* ADSSTATE\_POWERFAILURE = 9;
* ADSSTATE\_POWERGOOD = 10;
* ADSSTATE\_ERROR = 11;
* ADSSTATE\_SHUTDOWN = 12;
* ADSSTATE\_SUSPEND = 13;
* ADSSTATE\_RESUME = 14;
* ADSSTATE\_CONFIG = 15;
* ADSSTATE\_RECONFIG = 16;
* ADSSTATE\_STOPPING = 17;
* ADSSTATE\_INCOMPATIBLE = 18;
* ADSSTATE\_EXCEPTION = 19;

**DEVSTATE**: Specific state identification code of the ADS target device. The codes returned here are supplementary information specific to the ADS device.

**Example for the function block call in FBD:**

![52084342](/tcplclib_tc2_system/1033/Images/png/31116171__en-US__Web.png)

In this example the PLC run-time system 1 (port no. 801) on the computer with network address 1.1.1.2.7.1 is asked about its state. The answer is adsState = 1 (IDLE) without supplementary code devState=0.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
