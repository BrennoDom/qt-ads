# AddEventReferencId

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddEventReferencId

![43682709](/tcplclib_tc3_eventlogger/1033/Images/png/5027075467__Web.png)

This method adds a reference to another event as an argument.

## Syntax

```
METHOD AddEventReferenceId : I_TcArguments  
VAR_INPUT  
    nEventId : UDINT;  
END_VAR
```

## 57600065 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nEventId | UDINT | ID of the event. |

## 48638545 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddEventReferenceId | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
