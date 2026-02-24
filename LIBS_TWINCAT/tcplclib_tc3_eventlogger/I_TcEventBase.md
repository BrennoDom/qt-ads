# I_TcEventBase

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# I\_TcEventBase

Methods and properties of an event are defined in this basic interface.

## 19884118 Methods

| Name | Description |
| --- | --- |
| EqualsTo | Compares the event with another instance. |
| EqualsToEventClass | Compares the event class of the event with another event class. |
| EqualsToEventEntryEx | Compares the event definition of the event with another event definition. |
| GetJsonAttribute | Returns the Json attribute. |
| RequestEventClassName | Requests the name of the event class. |
| RequestEventText | Returns the text for the event. |

## 44739342 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Get | Returns the severity. |
| EventClass | GUID | Get | Returns the GUID of the event class. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Get | Returns a pointer to the source definition. |
| nEventId | UDINT | Get | Returns the ID of the event. |
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
* RequestEventClassName
* RequestEventText
