# FB_TcMessage

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcMessage

![29567523](/tcplclib_tc3_eventlogger/1033/Images/png/5031428491__Web.png)

This function block represents a message from the TwinCAT 3 EventLogger.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcMessage EXTENDS FB_TcEventBase IMPLEMENTS I_TcMessage
```

## Inheritance hierarchy

[FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49)

     FB\_TcMessage

## 64781122 Interfaces

| Type | Description |
| --- | --- |
| [I\_TcMessage](ms-xhelp:///?Id=beckhoff-c2ea-49ed-9691-499e02304917) | Provides methods and properties for the message handling. |

## 46159188 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| EqualsTo | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event with another instance. |
| EqualsToEventClass | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event class of the event with another event class. |
| EqualsToEventEntry | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event definition of the event with another event definition. |
| EqualsToEventEntryEx | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event definition of the event with another event definition. |
| GetJsonAttribute | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the Json attribute. |
| [Release](ms-xhelp:///?Id=beckhoff-e919-4f0c-bfd1-cf35d3e2227d) | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Releases the instance created by the EventLogger again. |
| RequestEventClassName | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Requests the name of the event class. |
| RequestEventText | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the text for the event. |
| [Create](ms-xhelp:///?Id=beckhoff-15fd-4326-b87e-e9f7621e75bd) | Local | Creates a message instance in the EventLogger. |
| [CreateEx](ms-xhelp:///?Id=beckhoff-8049-4c6e-9b7e-d6cbe7eb47b0) | Local | Creates a message instance in the EventLogger from an event definition. |
| SetJsonAttribute | Local | Sets the Json attribute. |
| [Send](ms-xhelp:///?Id=beckhoff-93dd-47d3-8e88-bbfed4d9efd3) | [I\_TcMessage](ms-xhelp:///?Id=beckhoff-c2ea-49ed-9691-499e02304917) | Sends a message. |

## 12779516 Properties

| Name | Type | Access | Definition location | Description |
| --- | --- | --- | --- | --- |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the severity. |
| EventClass | GUID | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the GUID of the event class. |
| [ipArguments](ms-xhelp:///?Id=beckhoff-077b-4694-8f4d-2461481f7e8f) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the interface pointer for the arguments. |
| [ipSourceInfo](ms-xhelp:///?Id=beckhoff-dccc-4ee5-bb8b-99965ac95c92) | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | The SourceInfo is created internally as the default behavior. It then contains the symbol name of the function block that instances FB\_TcMessage as SourceName and the object ID of the PLC instance as SourceID.  If the instance of FB\_TcMessage is hidden with the attribute "hide", no symbol name can be created internally for the default behavior. |
| nEventId | nEventId | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the ID of the event. |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the event definition. |
| nTimeSent | ULINT | Get | Local | Returns the time of the Send. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [Create](ms-xhelp:///?Id=beckhoff-15fd-4326-b87e-e9f7621e75bd)
* [CreateEx](ms-xhelp:///?Id=beckhoff-8049-4c6e-9b7e-d6cbe7eb47b0)
* SetJsonAttribute
