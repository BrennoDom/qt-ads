# FB_TcEventLogger

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcEventLogger

![35990804](/tcplclib_tc3_eventlogger/1033/Images/png/5031426571__Web.png)

This function block represents the TwinCAT 3 EventLogger itself.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcEventLogger
```

## 55481787 Methods

| Name | Description |
| --- | --- |
| [ClearAlarms](ms-xhelp:///?Id=beckhoff-b8d7-4955-8106-1a1869721b5b) | Clears active alarms. |
| [ClearAllAlarms](ms-xhelp:///?Id=beckhoff-8089-4661-aa60-64709dd5edbc) | Calls Clear() for all alarms in the Raised state. |
| [ClearLoggedEvents](ms-xhelp:///?Id=beckhoff-38cb-4e09-b767-9b120ef13db9) | Clears logged events. |
| [ConfirmAlarms](ms-xhelp:///?Id=beckhoff-2f76-46c1-98d8-6db880d5db5f) |  |
| [ConfirmAllAlarms](ms-xhelp:///?Id=beckhoff-5c9c-4720-bf8f-7c4dd4e3d633) | Calls Confirm() for all alarms with the confirmation state WaitForConfirmation. |
| [ExportLoggedEvents](ms-xhelp:///?Id=beckhoff-bcb7-4c9c-a054-4b409c3a6f4d) | Exports logged events. |
| [GetAlarm](ms-xhelp:///?Id=beckhoff-561c-43f6-b0f3-531084b55b1b) | Returns the pointer to an existing alarm. |
| [GetAlarmEx](ms-xhelp:///?Id=beckhoff-b5af-4a01-ab97-b1c13257d8f2) | Returns the pointer to an existing alarm. |
| [IsAlarmRaised](ms-xhelp:///?Id=beckhoff-c58c-43da-ab4f-7c6ad6a7d58c) | Queries whether an alarm is in the Raised state. |
| [IsAlarmRaisedEx](ms-xhelp:///?Id=beckhoff-0eac-4817-a368-de9ce160d816) | Queries whether an alarm is in the Raised state. |
| [SendMessage](ms-xhelp:///?Id=beckhoff-47c6-4221-a7de-680868d70718) | Sends a message. |
| [SendMessage2](ms-xhelp:///?Id=beckhoff-9b57-42ec-98e5-390b1f3fbf5a) | Sends a message. |
| [SendMessageEx](ms-xhelp:///?Id=beckhoff-e15d-41e1-8492-566e27a47abb) | Sends a message. |
| [SendMessageEx2](ms-xhelp:///?Id=beckhoff-55a2-4643-808f-140391b78d83) | Sends a message. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* [ClearAlarms](ms-xhelp:///?Id=beckhoff-b8d7-4955-8106-1a1869721b5b)
* [ClearAllAlarms](ms-xhelp:///?Id=beckhoff-8089-4661-aa60-64709dd5edbc)
* [ClearLoggedEvents](ms-xhelp:///?Id=beckhoff-38cb-4e09-b767-9b120ef13db9)
* [ConfirmAlarms](ms-xhelp:///?Id=beckhoff-2f76-46c1-98d8-6db880d5db5f)
* [ConfirmAllAlarms](ms-xhelp:///?Id=beckhoff-5c9c-4720-bf8f-7c4dd4e3d633)
* [ExportLoggedEvents](ms-xhelp:///?Id=beckhoff-bcb7-4c9c-a054-4b409c3a6f4d)
* [GetAlarm](ms-xhelp:///?Id=beckhoff-561c-43f6-b0f3-531084b55b1b)
* [GetAlarmEx](ms-xhelp:///?Id=beckhoff-b5af-4a01-ab97-b1c13257d8f2)
* [IsAlarmRaised](ms-xhelp:///?Id=beckhoff-c58c-43da-ab4f-7c6ad6a7d58c)
* [IsAlarmRaisedEx](ms-xhelp:///?Id=beckhoff-0eac-4817-a368-de9ce160d816)
* [SendMessage](ms-xhelp:///?Id=beckhoff-47c6-4221-a7de-680868d70718)
* [SendMessage2](ms-xhelp:///?Id=beckhoff-9b57-42ec-98e5-390b1f3fbf5a)
* [SendMessageEx](ms-xhelp:///?Id=beckhoff-e15d-41e1-8492-566e27a47abb)
* [SendMessageEx2](ms-xhelp:///?Id=beckhoff-55a2-4643-808f-140391b78d83)
