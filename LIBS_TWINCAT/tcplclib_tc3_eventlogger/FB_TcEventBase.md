# FB_TcEventBase

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcEventBase

![19750463](/tcplclib_tc3_eventlogger/1033/Images/png/5031424651__Web.png)

This function block contains the basic implementation.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcEventBase
```

## 43536440 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| EqualsTo | Local | Compares the event with another instance. |
| EqualsToEventClass | Local | Compares the event class of the event with another event class. |
| EqualsToEventEntry | Local | Compares the event definition of the event with another event definition. |
| EqualsToEventEntryEx | Local | Compares the event definition of the event with another event definition. |
| GetJsonAttribute | Local | Returns the Json attribute. |
| [Release](ms-xhelp:///?Id=beckhoff-e919-4f0c-bfd1-cf35d3e2227d) | Local | Releases the instance created by the EventLogger again. |
| RequestEventClassName | Local | Requests the name of the event class. |
| RequestEventText | Local | Returns the text for the event. |

## 56283646 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Get | Returns the severity. |
| EventClass | GUID | Get | Returns the GUID of the event class. |
| [ipArguments](ms-xhelp:///?Id=beckhoff-077b-4694-8f4d-2461481f7e8f) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Get | Returns the interface pointer for the arguments. |
| [ipSourceInfo](ms-xhelp:///?Id=beckhoff-dccc-4ee5-bb8b-99965ac95c92) | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Get | The SourceInfo is created internally as the default behavior. It then contains the symbol name of the function block that instances FB\_TcMessage as SourceName and the object ID of the PLC instance as SourceID.  If the instance of FB\_TcMessage is hidden with the attribute "hide", no symbol name can be created internally for the default behavior. |
| nEventId | UDINT | Get | Returns the ID of the event. |
| nUniqueId | UDINT | Get | Returns the unique ID of the event. |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Get | Returns the event definition. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* EqualsTo
* EqualsToEventClass
* EqualsToEventEntry
* EqualsToEventEntryEx
* GetJsonAttribute
* [Release](ms-xhelp:///?Id=beckhoff-e919-4f0c-bfd1-cf35d3e2227d)
* RequestEventClassName
* RequestEventText
* [ipArguments](ms-xhelp:///?Id=beckhoff-077b-4694-8f4d-2461481f7e8f)
* [ipSourceInfo](ms-xhelp:///?Id=beckhoff-dccc-4ee5-bb8b-99965ac95c92)
