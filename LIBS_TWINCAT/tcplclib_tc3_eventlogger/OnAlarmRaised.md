# OnAlarmRaised

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# OnAlarmRaised

![34639550](/tcplclib_tc3_eventlogger/1033/Images/png/5027198347__Web.png)

This method is called if the state of an alarm changes from Clear to Raised.

## Syntax

```
METHOD OnAlarmRaised : HRESULT  
VAR_INPUT  
    fbEvent : REFERENCE TO FB_TcEvent;  
END_VAR
```

If the implementation of the callback method returns a return code `<> S_OK`, further callback calls will be paused until the next execution.

## 43320496 Inputs

| Name | Type | Description |
| --- | --- | --- |
| fbEvent | REFERENCE TO [FB\_TcEvent](ms-xhelp:///?Id=beckhoff-a11b-4b93-841e-d55b75947522) | Reference to the alarm that has occurred. This reference must not be copied, e.g. through assignment. |
