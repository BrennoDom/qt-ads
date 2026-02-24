# SendMessageEx

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# SendMessageEx

![46488363](/tcplclib_tc3_eventlogger/1033/Images/png/5027229067__Web.png)

This method sends a message.

## Syntax

```
METHOD SendMessageEx : HRESULT  
VAR_INPUT  
    stEventEntry : TcEventEntry;  
    ipSourceInfo : I_TcSourceInfo := 0;  
    nTimeStamp   : ULINT := 0;  
    ipArguments  : I_TcArguments := 0;  
END_VAR
```

## 15742086 Inputs

| Name | Type | Description |
| --- | --- | --- |
| stEventEntry | [TcEventEntry](ms-xhelp:///?Id=beckhoff-4224-46b9-ab9a-b442dc50ef2a) | Event definition. |
| ipSourceInfo | [I\_TcSourceInfo](ms-xhelp:///?Id=beckhoff-11ec-4c62-aae5-5ff3ab304cf2) | Pointer to an ITcSourceInfo interface. |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |
| ipArguments | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Pointer to the ITcArguments interface. |

## 7461047 Return value

| Name | Type | Description |
| --- | --- | --- |
| SendMessageEx | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
