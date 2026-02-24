# FB_TcEventFilter

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_TcEventFilter

![56026474](/tcplclib_tc3_eventlogger/1033/Images/png/10408511883__Web.png)

Provides the functionality to specify an event filter.

The filters are provided via a floating interface following a structured query language. It describes which messages should apply.

* Conditions can be linked through `.AND_OP()` and `.OR_OP()`.
* Conditions can be negated through `.NOT_OP`.
* Conditions can be defined through properties such as .`isAlarm()` or `.EventClass.EqualsTo(<EventClass>)`, for example. A complete list of properties can be found in the API documentation.
* A grouping can be formulated through `.FilterExpression(<SubCondition>)`. The `<SubCondition>` itself is a `FB_TcEventFilter` or `ITcEventFilter`.

A filter is applied once it has been compiled. To receive messages it is assigned to a recipient via `FB_ListenerBase2.subscribe()`, for example. In this way `FB_ListenerBase2` takes over the filter and provides a corresponding return value, which is described here. The filter can be amended by repeating `FB_ListenerBase2.subscribe()`.

## Sample

A filter can be assembled in the following way, for example:

```
fbFilter.Severity.GreaterThan (TcEVentSeverity.Error).AND_OP().Source.Name.Like('%Main%');
```

The [Example filter](ms-xhelp:///?Id=beckhoff-c86a-46e8-9ffe-c3c929821989) illustrates the usage.

## EtherCAT filter

The mechanism for receiving EtherCAT emergency messages is similar to that described above. The entry point in the chained method calls is `.EtherCATDevice()`, which first provides a direct query to ascertain if it was sent from an EtherCAT device (`IsEtherCATDevice()`). From here you can filter based on the manufacturer (`.VendorId()`), the product code (`.ProductCode()`) or the revision (.`RevisionNo())`.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_TcEventFilter IMPLEMENTS I_TcEventFilter, I_TcExpressionBase
```

## 34476226 Methods

| Name | Definition location | Description |
| --- | --- | --- |
| Clear | I\_TcEventFilter | Clears the previous filter expression. |
| FilterExpression | I\_TcExpressionBase | Specification of a subordinate filter definition. |
| IsAlarm | I\_TcExpressionBase | Checking whether it is an alarm. |
| IsMessage | I\_TcExpressionBase | Checking whether it is a message. |
| NOT\_OP | I\_TcExpressionBase | Negation of the subsequent statement. |

## 41850582 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| AlarmState | I\_TcAlarmFilterExpression | Get | Checking with an AlarmState |
| EtherCATDevice | I\_TcEtherCATDeviceExpression | Get | Checking whether the source is an EtherCAT device. |
| EventClass | I\_TcGuidCompare | Get | Checking with an EventClass |
| EventId | I\_TcUDIntCompare | Get | Checking with an EventId |
| JsonAttribute | I\_TcJsonAttributeExpression | Get | Checking with the JsonAttribute |
| Severity | I\_TcSeverityCompare | Get | Checking with Serverity |
| Source | I\_TcSourceInfoExpression | Get | Checking with the source |
| TimeCleared | I\_TcULIntCompare | Get | Checking of the clear time (only in the event of an alarm) |
| TimeConfirmed | I\_TcULIntCompare | Get | Checking of the confirm time (only for alarm with acknowledgement) |
| TimeRaised | I\_TcULIntCompare | Get | Checking of the sender (for messages) or the raised time (for alarms) |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |

Further Information

* [Clear](ms-xhelp:///?Id=beckhoff-8d48-4528-a61d-3db1cc236184)
* [FilterExpression](ms-xhelp:///?Id=beckhoff-f206-41a9-a4e6-c237ee7753eb)
* [IsAlarm](ms-xhelp:///?Id=beckhoff-74af-4354-9086-a7fa302284b0)
* [IsMessage](ms-xhelp:///?Id=beckhoff-3b9a-4fbd-832d-9208ec8433eb)
* [NOT\_OP](ms-xhelp:///?Id=beckhoff-6343-422d-861e-af9a4f37b484)
