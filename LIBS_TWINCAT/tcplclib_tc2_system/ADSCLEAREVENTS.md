# ADSCLEAREVENTS

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [EventLogger function blocks](ms-xhelp:///?Id=beckhoff-a969-41f8-a1e1-6836d4d78a84)
4. ADSCLEAREVENTS

# ADSCLEAREVENTS

![38905106](/tcplclib_tc2_system/1033/Images/png/9007199286029963__Web.png)

The function block permits the sending and the acknowledge of messages to the TwinCAT EventLogger.

## VAR\_INPUT

```
VAR_INPUT  
    NETID    : T_AmsNetId;  
    bClear   : BOOL;  
    iMode    : UDINT;  
    tTimeout : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AMSNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**bClear**: With a rising edge the events are deleted.

**iMode**: Mode to delete the events. Defined in the enum [E\_TcEventClearModes](ms-xhelp:///?Id=beckhoff-de8a-49bb-8344-53ec5cc83651).

**tTimeout**: States the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    bBusy  : BOOL;  
    bErr   : BOOL;  
    iErrId : UDINT;  
END_VAR
```

**bBusy**: When the function block is activated, this output is set to TRUE and remains set until feedback is received. As long as bBusy is TRUE, no new command can be executed.

**bErr**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in iErrId. If the function block has a timeout error, bErr is TRUE and iErrId is 1861 (hexadecimal 0x745). Is reset to FALSE by the execution of a command at the inputs.

**iErrId**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the last executed command. Is reset to 0 by the execution of a command at the inputs.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
