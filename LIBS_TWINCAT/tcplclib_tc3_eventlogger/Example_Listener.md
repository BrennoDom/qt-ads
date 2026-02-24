# Example Listener

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Example Listener

This sample illustrates the use of the TwinCAT 3 EventLogger in relation to messages and alarms. At the same time the reception of messages is shown in a second project.

Download: [Tc3EventLogger\_ListenerSample.zip](https://infosys.beckhoff.com/content/1033/tcplclib_tc3_eventlogger/Resources/zip/27021603052539915.zip)

## Publisher project

Single BOOL variables are used as triggers in the Publisher project:

* bSendMessage to send a message.
* bRaiseAlarm to set an alarm.
* bClearAlarm to cancel an alarm.
* bConfirmAlarm to confirm an alarm.

In addition there is an option to set the JSON attribute in order to send it with both messages.

## Listener project

The Listener project contains a function block, FB\_Listener, which extends the FB\_ListenerBase function block contained in the Tc3\_EventLogger. The function block implements the functions for receiving the messages:

* OnMessageSent: when a message has been sent the EventLogger will call this method as a callback. The method counts the number of messages.
* OnAlarmRaised/OnAlarmCleared/OnAlarmConfirmed: if the alarm changes its state the EventLogger will call this method as a callback. The methods count the number of state changes.
* To initiate receiving of messages, an Execute method is implemented at the function block.
* The text of the last received message can be retrieved.
* The function block FB\_ListenerTest uses the FB\_Listener. In doing so it registers the event class to be received once. Another event class that exists is not received to demonstrate the filter functionality.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4024.17 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger (>= v3.1.27.0) |
