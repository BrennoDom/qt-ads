# OnMessageSent

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# OnMessageSent

![54340147](/tcplclib_tc3_eventlogger/1033/Images/png/5027204107__Web.png)

This method is called when a message has been sent.

## Syntax

```
METHOD OnMessageSent : HRESULT  
VAR_INPUT  
    fbEvent : REFEENCE TO FB_TcEvent;  
END_VAR
```

If the implementation of the callback method returns a return code `<> S_OK`, further callback calls will be paused until the next execution.

## 19299281 Inputs

| Name | Type | Description |
| --- | --- | --- |
| fbEvent | REFERENCE TO [FB\_TcEvent](ms-xhelp:///?Id=beckhoff-a11b-4b93-841e-d55b75947522) | Reference to the event that has occurred. This reference must not be copied, e.g. through assignment. |
