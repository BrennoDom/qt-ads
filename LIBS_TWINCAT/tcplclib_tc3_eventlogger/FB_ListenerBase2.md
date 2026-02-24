# FB_ListenerBase2

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_ListenerBase2

![55642234](/tcplclib_tc3_eventlogger/1033/Images/png/8654884875__Web.png)

The function block serves as the basic implementation of an event listener.

New messages and state changes of alarms can be recognized through the overwriting of the event-driven methods.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_ListenerBase2 IMPLEMENTS I_Listener2
```

## 31018066 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| [Execute](ms-xhelp:///?Id=beckhoff-b5b2-465d-976c-25b49b57f6b8) | Local | Must be called cyclically so that the event queue can be processed. |
| [Subscribe](ms-xhelp:///?Id=beckhoff-2f04-4755-83b1-74a1154593cf) | Local | Subscribes messages. |
| [Unsubscribe](ms-xhelp:///?Id=beckhoff-4f69-4ccb-bdaa-d26c59a371a6) | Local | Unsubscribes messages. |

## 10727144 Event-driven methods (callback methods)

| Name | Definition location | Description |
| --- | --- | --- |
| [OnAlarmCleared](ms-xhelp:///?Id=beckhoff-372b-4132-a4d1-184108311531) | I\_Listener2 | Called when the state of an alarm changes from "Raised" to "Clear". |
| [OnAlarmConfirmed](ms-xhelp:///?Id=beckhoff-9329-4e6d-9dfb-da222d6af07b) | I\_Listener2 | Called when an alarm has been confirmed. |
| [OnAlarmDisposed](ms-xhelp:///?Id=beckhoff-a770-499d-a7b5-85846e31f904) | I\_Listener2 | Called when an alarm instance has been released again. |
| [OnAlarmRaised](ms-xhelp:///?Id=beckhoff-eb19-44d8-8015-a00b2180b1a1) | I\_Listener2 | Called when the state of an alarm changes from "Clear" to "Raised". |
| [OnMessageSent](ms-xhelp:///?Id=beckhoff-c262-4b95-9b4e-1c412981b99f) | I\_Listener2 | Called when a message has been sent. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |

Further Information

* [Execute](ms-xhelp:///?Id=beckhoff-b5b2-465d-976c-25b49b57f6b8)
* [OnAlarmCleared](ms-xhelp:///?Id=beckhoff-372b-4132-a4d1-184108311531)
* [OnAlarmConfirmed](ms-xhelp:///?Id=beckhoff-9329-4e6d-9dfb-da222d6af07b)
* [OnAlarmDisposed](ms-xhelp:///?Id=beckhoff-a770-499d-a7b5-85846e31f904)
* [OnAlarmRaised](ms-xhelp:///?Id=beckhoff-eb19-44d8-8015-a00b2180b1a1)
* [OnMessageSent](ms-xhelp:///?Id=beckhoff-c262-4b95-9b4e-1c412981b99f)
* [Subscribe](ms-xhelp:///?Id=beckhoff-2f04-4755-83b1-74a1154593cf)
* [Subscribe2](ms-xhelp:///?Id=beckhoff-e78a-4f27-942f-448c042d71a2)
* [Unsubscribe](ms-xhelp:///?Id=beckhoff-4f69-4ccb-bdaa-d26c59a371a6)
