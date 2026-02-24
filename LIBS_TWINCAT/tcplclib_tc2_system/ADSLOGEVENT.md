# ADSLOGEVENT

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [EventLogger function blocks](ms-xhelp:///?Id=beckhoff-a969-41f8-a1e1-6836d4d78a84)
4. ADSLOGEVENT

# ADSLOGEVENT

![20364417](/tcplclib_tc2_system/1033/Images/png/9007199286020363__Web.png)

The function block permits the sending and the acknowledgement of messages to the TwinCAT EventLogger.

## VAR\_INPUT

```
VAR_INPUT  
    NETID             : T_AmsNetId;  
    PORT              : T_AmsPort;  
    Event             : BOOL;  
    EventQuit         : BOOL;  
    EventConfigData   : TcEvent;  
    EventDataAddress  : PVOID;  
    EventDataLength   : UDINT;  
    FbCleanup         : BOOL;  
    TMOUT             : TIME := DEFAULT_ADS_TIMEOUT;  
END_VAR
```

**NETID**: String containing the AMS network identifier of the target device to which the ADS command is directed (type: [T\_AmsNetId](ms-xhelp:///?Id=beckhoff-2a14-451b-a984-12ad1d929ff2)).

**PORT**: Port number of the ADS device. The TwinCAT EventLogger has the port number 110 (type: [T\_AmsPort](ms-xhelp:///?Id=beckhoff-8526-4c85-aeea-045be9df1824)).

**Event**: With a rising edge the “coming” of the event is signaled, with a falling edge the “going” of the event.

**EventQuit**: With a rising edge the event is acknowledged.

**EventConfigData**: Data structure in the event parameters (type: [TcEvent](ms-xhelp:///?Id=beckhoff-bac3-4d2a-abb0-b049c48a76c8)).

**EventDataAddress**: Address with the data, which should be sent with the event.

**EventDataLength**: Length of the data, which should be sent with the event.

**FbCleanup**: At TRUE the function block is initialised completely.

**TMOUT**: States the time before the function is cancelled.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    EventState   : UDINT;  
    Err          : BOOL;  
    ErrId        : UDINT;  
    Quit         : BOOL;  
END_VAR
```

**EventState**: State of the events.

**Err**: This output is switched to TRUE if an error occurs during the execution of a command. The command-specific error code is contained in ErrId. If the block has a timeout error, Err is TRUE and ErrId is 1861 (hexadecimal 0x745). Is reset to FALSE by the execution of a command at the inputs.

**ErrId**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

**Quit**: The event is acknowledged.

![49062032](/tcplclib_tc2_system/1033/Images/gif/31282571__en-US__Web.gif)

The picture above shows the fundamental construction.

At non obligatory acknowledge messages, the event is reported with the rising edge at the event input of the function block and therewith active in the EventLogger. The falling edge at the event input triggers the reset. With this signal the event is cancelled again in the EventLogger.

At obligatory acknowledge messages the event is again activated wtih the rising edge at the event input. The event can be deactivated

* with a falling edge at the event input (if before an acknowledgement signal has come from the PLC with the quit input, or from the visualization) or
* with a rising edge at the quit input ( if before a reset was released by a falling edge at the event input)

If a reset occurs between event activation and occurrence of the acknowledgement, the next occurrence of the event input is called “signal”. Therewith a request is reported at already active event.

**Example for the use of the ADSLOGEVENT function block in ST:**

* [Sending/acknowledging event logger signals from the PLC](ms-xhelp:///?Id=beckhoff-ff40-4c29-ad24-5724b30d5cb0)

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
