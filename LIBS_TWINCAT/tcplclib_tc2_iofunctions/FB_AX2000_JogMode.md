# FB_AX2000_JogMode

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-a079-48d4-9b63-20dc13645a2c)
3. [AX200x Profibus](ms-xhelp:///?Id=beckhoff-348f-457a-b6d5-7c82d7b5dd86)
4. FB\_AX2000\_JogMode

# FB\_AX2000\_JogMode

![25792371](/tcplclib_tc2_iofunctions/1033/Images/gif/59398667__en-US__Web.gif)

Jogging operation.

## VAR\_IN\_OUT

```
VAR_IN_OUT  
    stPZDIN    : ST_PZD_IN;  
    stPZDOUT   : ST_PZD_OUT;  
END_VAR
```

**stPZDIN** : Data words from the drive to the PLC (type: [ST\_PZD\_IN](ms-xhelp:///?Id=beckhoff-6422-417f-94b7-09e221a421f3)).

**stPZDOUT**: Data words from the PLC to the drive (type: [ST\_PZD\_OUT](ms-xhelp:///?Id=beckhoff-260b-4dc5-bd95-54d0ad57159b)).

## VAR\_INPUT

```
VAR_INPUT  
    bStart     : BOOL;  
    bStop      : BOOL;  
    iBasicVelo : INT;(*BasicVelocity*)  
    tTimeOut   : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**bStart**: Start jogging mode.

**bStop** : Stop jogging mode.

**iBasicVelo**: Basic speed for jogging mode; the actual speed is derived from the basic speed and the "v-jogging mode" factor for the drive.

**tTimeOut**: Maximum time allowed for the execution of the command.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy       : BOOL;  
    bErr        : BOOL;  
    bTimeOutErr : BOOL;  
END_VAR
```

**bBusy**: This output remains TRUE until the block has executed a command. While Busy = TRUE, no new command will be accepted at the inputs. Please note that it is not the execution of the service but its acceptance whose time is monitored.

**bErr**: This output shows the error status.

**bTimeOutErr** : TimeOut error.

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86) | AX2000 Profibus box | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
