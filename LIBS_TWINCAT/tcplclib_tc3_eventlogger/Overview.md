# Overview

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Overview

The PLC library contains functions and function blocks for using the TwinCAT 3 EventLogger.

See also: [Dokumentation TwinCAT 3 EventLogger](ms-xhelp:///?Id=beckhoff-85cb-409d-a1c9-49baae09848d)

**Function blocks for using the TC3 EventLogger**

|  |  |
| --- | --- |
| [FB\_ListenerBase2](ms-xhelp:///?Id=beckhoff-52e0-47f7-8fa5-32bde735ccac) | Basic implementation of an event listener. |
| [FB\_TcAlarm](ms-xhelp:///?Id=beckhoff-6b09-4b64-be2e-d6258f05d173) | Represents an alarm of the TwinCAT 3 EventLogger. |
| [FB\_TcArguments](ms-xhelp:///?Id=beckhoff-e563-47d4-97ff-25b2f5d5af58) | Defines arguments of an event. |
| [FB\_TcEventLogger](ms-xhelp:///?Id=beckhoff-2155-405c-8a41-d56a9e1e15e8) | Represents the TwinCAT 3 EventLogger itself. |
| [FB\_TcMessage](ms-xhelp:///?Id=beckhoff-5a40-4d1e-975f-4dfeb1552d2a) | Represents a message from the TwinCAT 3 EventLogger. |
| [FB\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-76ce-4796-8052-67b98cb1b2fd) | Defines the source information of an event. |

**Asynchronous text requests**

|  |  |
| --- | --- |
| [F\_GetEventClassName](ms-xhelp:///?Id=beckhoff-6d5d-4af8-be62-af3291cdccf5) | Triggers the asynchronous request for the name of an event class. |
| [F\_GetEventText](ms-xhelp:///?Id=beckhoff-0d63-4318-a5f0-7c45282d8f86) | Triggers the asynchronous request for an event text. |
| [FB\_AsyncStrResult](ms-xhelp:///?Id=beckhoff-9f5b-47a5-9295-1027176d6fe4) | Enables the asynchronous request for a text. |
| [FB\_RequestEventClassName](ms-xhelp:///?Id=beckhoff-f078-4c77-8cbb-77b1142a38f5) | Enables the asynchronous request for the name of an event class. |
| [FB\_RequestEventText](ms-xhelp:///?Id=beckhoff-2d87-49af-9281-69cf366bf057) | Enables the asynchronous request for an event text in the desired language. |

**EventEntry conversion**

|  |  |
| --- | --- |
| [AdsErr\_TO\_TcEventEntry](ms-xhelp:///?Id=beckhoff-4e2b-46b3-8437-3f21a5eaa53e) | Converts a standard ADS error into a TcEventEntry. |
| [HRESULTAdsErr\_TO\_TcEventEntry](ms-xhelp:///?Id=beckhoff-3a97-4f54-b8fe-cf8e9d3eab49) | Converts a standard ADS error (HRESULT) into a TcEventEntry. |
| [TcEventEntry\_TO\_AdsErr](ms-xhelp:///?Id=beckhoff-af6d-4277-94ba-e0a921b33b08) | Converts a TcEventEntry into a standard ADS error. |
| [TcEventEntry\_TO\_HRESULTAdsErr](ms-xhelp:///?Id=beckhoff-ea87-4293-8ef9-6c7b53e1a109) | Converts a TcEventEntry into a standard ADS error (HRESULT). |
