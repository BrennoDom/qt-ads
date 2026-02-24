# FB_SimpleAdsLogEvent

## Library
tcplclib_tc2_system

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-7333-4339-828b-5183329d95a4)
3. [EventLogger function blocks](ms-xhelp:///?Id=beckhoff-a969-41f8-a1e1-6836d4d78a84)
4. FB\_SimpleAdsLogEvent

# FB\_SimpleAdsLogEvent

![14601642](/tcplclib_tc2_system/1033/Images/png/9007200051665547__Web.png)

This function block allows the dispatch and acknowledgment of messages to the TwinCAT EventLogger. As opposed to the ADSLOGEVENT block, events cannot be parameterised from the PLC with the FB\_SimpleAdsLogEvent block; however, events can be set, reset and acknowledged in a simple manner.

## VAR\_INPUT

```
VAR_INPUT  
    SourceId   : INT;  
    EventId    : INT;  
    bSetEvent  : BOOL;  
    bQuit      : BOOL;  
END_VAR
```

**SourceId**: ID of the source. Used to clearly identify the source in the EventLogger.

**EventId**: ID of the event. Used to clearly identify the event in the EventLogger.

**bSetEvent**: The “coming” of the event is signalled with the rising edge, the “going” of the event with the falling edge.

**bQuit**: The event is acknowledged with the rising edge.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    ErrId     : UDINT;  
    Error     : BOOL;  
END_VAR
```

**ErrId**: [ADS error code](ms-xhelp:///?Id=beckhoff-102a-43b7-9885-5150d7650de4) or command-specific error code of the most recently executed command. Is reset to 0 by the execution of a command at the inputs.

**Error**: This output is switched to TRUE as soon as an error occurs during the execution of a command. The command-specific error code is contained in ErrId. If the block has a timeout error, then Error = TRUE and ErrId = 1861 (0x745 in hexadecimal). Is reset to FALSE by the execution of a command at the inputs.

![64305920](/tcplclib_tc2_system/1033/Images/png/9007200051669771__Web.png)

The upper illustration represents the general sequence.

In the case of messages not requiring acknowledgment, the event is announced with the rising edge at the Event input of the block and is thus active in the EventLogger. The falling edge at the Event input initiates the reset. This signal deletes the event in the EventLogger again.

In the case of messages requiring acknowledgment, the event is activated again with the rising edge at the Event input. The event is deactivated either

* by the falling edge at the Event input (if an acknowledgment signal had previously come from the PLC with the Quit input or from the visualisation) or
* by the rising edge at the Quit input (if a reset had previously been initiated by a falling edge at the Event input).

If a reset of the event comes between event activation and the coming of the acknowledgment, the next coming of the Event input is called “Signal”. A request is thus announced to already active events.

## Requirements

| Development environment | Target system type | PLC libraries to include (Category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_System (System) |

[TwinCAT 3 | PLC Library: Tc2\_System](ms-xhelp:///?Id=beckhoff-9909-45da-a773-a2ae0accd61a)
