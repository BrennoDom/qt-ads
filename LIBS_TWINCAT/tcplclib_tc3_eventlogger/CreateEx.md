# CreateEx

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# CreateEx

![36196256](/tcplclib_tc3_eventlogger/1033/Images/png/5027121547__Web.png)

This method creates an alarm instance in the EventLogger.

## Syntax

```
METHOD CreateEx : HRESULT  
VAR_INPUT  
    stEventEntry      : TcEventEntry;  
    bWithConfirmation : BOOL;  
    ipSourceInfo      : I_TcSourceInfo;  
END_VAR
```

## 57330849 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event definition. |
| bWithConfirmation | BOOL | Defines whether the alarm requires mandatory confirmation. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Interface pointer to the source information.  Default source information is created if no interface pointer is transferred. |

## 46215595 Return value

| Name | Type | Description |
| --- | --- | --- |
| CreateEx | HRESULT | Returns S\_OK if a new alarm was successfully created.  Returns ERROR\_ALREADY\_EXISTS if the alarm has already existed.  Otherwise returns HRESULT as the error code. |
