# Request

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Request

![38823967](/tcplclib_tc3_eventlogger/1033/Images/png/5027213707__Web.png)

Calling this method triggers the asynchronous text request.

## Syntax

```
METHOD Request : BOOL  
VAR_INPUT  
    eventClass : GUID;  
    nEventId   : UDINT;  
    nLangId    : DINT;  
    ipArgs     : I_TcArguments;  
END_VAR
```

## 13871385 Inputs

| Name | Type | Description |
| --- | --- | --- |
| eventClass | GUID | Specifies the event class. |
| nEventId | UDINT | ID of the event. |
| nLangId | DINT | Specifies the language ID  English (en-US) = 1033 German (de-DE) = 1031 … |
| ipArgs | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Optional specification of arguments. |

## 57733603 Return value

| Name | Type | Description |
| --- | --- | --- |
| Request | HRESULT | Returns possible error information. |
