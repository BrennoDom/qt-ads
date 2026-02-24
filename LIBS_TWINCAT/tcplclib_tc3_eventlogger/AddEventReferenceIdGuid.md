# AddEventReferenceIdGuid

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddEventReferenceIdGuid

![35093725](/tcplclib_tc3_eventlogger/1033/Images/png/5027077387__Web.png)

This method adds a reference to another event as an argument.

## Syntax

```
METHOD AddEventReferenceIdGuid : I_TcArguments  
VAR_INPUT  
    nEventId   : UDINT;  
    EventClass : GUID;  
END_VAR
```

## 47408069 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nEventId | UDINT | ID of the event. |
| EventClass | GUID | GUID of the event class. |

## 24019444 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddEventReferenceIdGuid | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
