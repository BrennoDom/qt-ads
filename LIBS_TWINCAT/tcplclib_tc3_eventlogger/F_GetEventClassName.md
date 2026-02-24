# F_GetEventClassName

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# F\_GetEventClassName

![49840382](/tcplclib_tc3_eventlogger/1033/Images/png/5026861067__Web.png)

The function triggers the asynchronous request for the name of an event class.

## Syntax

Definition:

```
FUNCTION F_GetEventClassName : HRESULT  
VAR_INPUT  
    nLangId     : DINT;  
    fbEventBase : REFERENCE TO FB_TcEventBase;  
END_VAR  
VAR_IN_OUT  
    fbResult : FB_AsyncStrResult;  
END_VAR
```

## 45910260 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nLangId | DINT | Specifies the language ID  English (en-US) = 1033 German (de-DE) = 1031 … |
| fbEventBase | REFERENCE TO [FB\_TcEventBase](ms-xhelp:///?Id=beckhoff-b9ed-473c-942e-b7a672a95e49) | Specification of an event/alarm/message object. |

## 10539156/27743545 Inputs/outputs

| Name | Type | Description |
| --- | --- | --- |
| fbResult | [FB\_AsyncStrResult](ms-xhelp:///?Id=beckhoff-9f5b-47a5-9295-1027176d6fe4) | Specification of a function block instance in order to track an asynchronous text request. |

## 48365314 Return value

| Name | Type | Description |
| --- | --- | --- |
| F\_GetEventClassName | HRESULT | Returns possible error information. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |
