# FB_TcAlarm

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcAlarm

![6206582](/tcplclib_tc3_eventlogger/1033/Images/png/5031418891__Web.png)

This function block represents an alarm of the TwinCAT 3 EventLogger.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcAlarm EXTENDS FB_TcEventBase
```

## Inheritance hierarchy

[FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49)

     FB\_TcAlarm

## 55859239 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| EqualsTo | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event with another instance. |
| EqualsToEventClass | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event class of the event with another event class. |
| EqualsToEventEntry | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event class, the event ID and the severity of the event with those of another event. |
| EqualsToEventEntryEx | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Compares the event definition of the event with another event definition. |
| GetJsonAttribute | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the Json attribute. |
| [Release](ms-xhelp:///?Id=beckhoff-e919-4f0c-bfd1-cf35d3e2227d) | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Releases the instance created by the EventLogger again. |
| RequestEventClassName | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Requests the name of the event class. |
| RequestEventText | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the text for the event. |
| [Clear](ms-xhelp:///?Id=beckhoff-4f9e-4d98-8567-8c155195c855) | Local | Sets the alarm state to "Not Raised". |
| [Confirm](ms-xhelp:///?Id=beckhoff-3958-447e-a42a-7b6d97939ec0) | Local | Confirms the alarm. |
| [Create](ms-xhelp:///?Id=beckhoff-fafb-4fdf-9088-30d637d26300) | Local | Creates an alarm instance in the EventLogger. |
| [CreateEx](ms-xhelp:///?Id=beckhoff-17d2-4b3a-9dec-bea1467ef26b) | Local | Creates an alarm instance in the EventLogger from an event definition. |
| [Raise](ms-xhelp:///?Id=beckhoff-6a43-4e53-8446-09277b6fb1f6) | Local | Sets the alarm state to "Raised". |
| SetJsonAttribute | Local | Sets the Json attribute. |

## 32971110 Properties

| Name | Type | Access | Definition location | Description |
| --- | --- | --- | --- | --- |
| eSeverity | [TcEventSeverity](ms-xhelp:///?Id=beckhoff-9031-41b6-a44a-ed04bb1bf9c5) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the severity. |
| EventClass | GUID | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the GUID of the event class. |
| [ipArguments](ms-xhelp:///?Id=beckhoff-077b-4694-8f4d-2461481f7e8f) | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the interface pointer for the arguments. |
| [ipSourceInfo](ms-xhelp:///?Id=beckhoff-dccc-4ee5-bb8b-99965ac95c92) | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | The SourceInfo is created internally as the default behavior. It then contains the symbol name of the function block that instances FB\_TcMessage as SourceName and the object ID of the PLC instance as SourceID.  If the instance of FB\_TcMessage is hidden with the attribute "hide", no symbol name can be created internally for the default behavior. |
| nEventId | nEventId | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the ID of the event. |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Get | Inherited from [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Returns the event definition. |
| bRaised | BOOL | Get | Local | Returns TRUE if the alarm is in the "raised" state. |
| bActive | BOOL | Get | Local | Returns TRUE if the alarm is in the "Raised" or "Wait For Confirmation" state. |
| eConfirmationState | [TcEventConfirmationState](ms-xhelp:///?Id=beckhoff-4715-4378-8070-61cbbdfb33aa) | Get | Local | Returns the confirmation state. |
| nTimeCleared | ULINT | Get | Local | Returns the time of the Clear. |
| nTimeConfirmed | ULINT | Get | Local | Returns the time of the Confirm. |
| nTimeRaised | ULINT | Get | Local | Returns the time of the Raise. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [Clear](ms-xhelp:///?Id=beckhoff-4f9e-4d98-8567-8c155195c855)
* [Confirm](ms-xhelp:///?Id=beckhoff-3958-447e-a42a-7b6d97939ec0)
* [Create](ms-xhelp:///?Id=beckhoff-fafb-4fdf-9088-30d637d26300)
* [CreateEx](ms-xhelp:///?Id=beckhoff-17d2-4b3a-9dec-bea1467ef26b)
* [Raise](ms-xhelp:///?Id=beckhoff-6a43-4e53-8446-09277b6fb1f6)
* SetJsonAttribute
