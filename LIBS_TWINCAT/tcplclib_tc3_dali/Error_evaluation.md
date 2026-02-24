# Error evaluation

## Library
tcplclib_tc3_dali

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
2. [Appendix](ms-xhelp:///?Id=beckhoff-799a-4543-a757-72ecd85fb150)
3. [Commissioning and diagnosis](ms-xhelp:///?Id=beckhoff-0748-4e01-bcff-c71c095ae5b7)
4. Error evaluation

# Error evaluation

The interface pointer *ipResultMessage* of type I\_TcMessage provides information about a current event ([runtime message](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5)). The most important methods and properties are described below:

## Methods

| Name | Description |
| --- | --- |
| EqualsToEventEntryEx | Compares the event definition of the event with another event definition. |
| RequestEventText | Returns the text for the event. |

## Properties

| Name | Type | Description |
| --- | --- | --- |
| eSeverity | TcEventSeverity | Returns the severity. |
| EventClass | GUID | Returns the unique ID of the event class. |
| nEventId | UDINT | Returns the ID of the event. |
| stEventEntry | TcEventEntry | Returns the event definition. |

For details about the interface I\_TCMessage, see the documentation for the Tc3\_EventLogger library.

Each event is unambiguously described by the structure *TcEventEntry*. It contains three structure elements:

* Event-Class
* Event-ID
* Event-Severity

Several events are merged into one event class. For example, the event class for DALI and the event class for EnOcean can contain the event ID 100. The complete description of an event always consists of the event class and the event ID. Ambiguities due to the same IDs within different libraries are thus avoided.

In order to make the events accessible to the PLC, TwinCAT automatically creates a structure for each event class in the type system.

![16466658](/tcplclib_tc3_dali/1033/Images/gif/5978386315__Web.gif)

This happens for all PLC libraries that are referenced in the project. The structure *ST\_DALIEventClass* is added using the Tc3\_DALI library.

![13982202](/tcplclib_tc3_dali/1033/Images/gif/5978389259__Web.gif)

This structure contains all events of the event class for the Tc3\_DALI library. Each element of the structure is mapped by a variable of type *TcEventEntry*. The name of the element indicates the meaning of the event.

```
TYPE ST_TcDALIEventClass:  
  STRUCT  
    NoResponseFromDALITerminal: TcEventEntry := ( …  
    NoResponseFromDALIDevice: TcEventEntry := ( …  
    CommandBufferOverflow: TcEventEntry := ( …  
    […]  
  END_STRUCT  
END_TYPE
```

All event classes are stored in the global variable list *TC\_Events*, which is also generated automatically by TwinCAT.

```
VAR_GLOBAL CONSTANT  
  […]  
  TcRTimeEventClass: ST_TcRTimeEventClass;  
  Win32EventClass: ST_Win32EventClass;  
  TcDALIEventClass: ST_TcDALIEventClass;  
END_VAR
```

Thus all messages of all event classes are available in the PLC program.

## FAQ

## How can I query whether an FB returns an error?

In all libraries, the event ID for error-free execution is set to 0. Since the event ID not only outputs errors, but also notes and warnings, most function blocks have the output *bError*. This output is TRUE when an error occurs.

```
IF (fbDALI.bError) THEN  
  …  
END_IF
```

This output remains FALSE in the event of warnings or notes. Therefore it may be the case that the event ID (*fbDALI.ipResultMessage.nEventID*) is not 0, but *bError* remains FALSE.

## How can I query whether a FB returns a specific event?

The method

```
ipResultMessage.EqualsToEventEntryEx(stOther TcEventEntry)
```

compares whether the event matches the transferred event *stOther*. Since a variable of type *TcEventEntry* automatically exists for each event, the query for a certain event can be carried out as follows.

```
IF (fbDALI.ipResultMessage.EqualsToEventEntryEx(  
  TC_EVENTS.TcDALIEventClass.NoResponseFromTheDALIDevice)) THEN  
  …  
END_IF
```

Alternatively, the Event ID can also be queried directly.

```
IF (fbDALI.ipResultMessage.nEventId = 2) THEN  
  …  
END_IF
```

A structure of the data type *TcEventEntry* exists for each event. This is located inside the structure *TcDALIEventClass* (data type *ST\_TcDALIEventClass*). The meaning of the message is recognizable from the names of the individual events. The use of this structure can thus improve the readability of the PLC program:

```
IF (fbDALI.ipResultMessage.nEventId =  
  TC_EVENTS.TcDALIEventClass.NoResponseFromTheDALIDevice.nEventId) then  
  …  
END_IF
```

For a list of all events that represent an error, see [Runtime messages](ms-xhelp:///?Id=beckhoff-b989-448b-af68-d65e2e7a28f5).

## How can I query the text of an event?

The text that is output in the *TwinCAT Logged Events* window can also be queried in the PLC program using the method

```
ipResultMessage.RequestEventText(nLangId DINT, sResult REFERENCE TO STRING, nResultSize UDINT)
```

.

If an event is present, the following sample returns the event text:

```
sTxt       :  STRING(255);  
sEventText :  STRING(255);  
IF (fbDALI.ipResultMessage.RequestEventText(1031, sTxt, SIZEOF(sTxt))) THEN  
  UTF8_TO_STRING(ADR(sEventText), ADR(sTxt), SIZEOF(sTxt));  
END_IF
```

The first parameter specifies the language in which the text is to be read. The Tc3\_DALI library contains all texts in English (1033) and German (1031).

[TwinCAT 3 | PLC Library: Tc3\_DALI](ms-xhelp:///?Id=beckhoff-3b50-4f78-8721-86f9c15e9bec)
