# ConfirmAllAlarms

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ConfirmAllAlarms

![52152158](/tcplclib_tc3_eventlogger/1033/Images/png/5027111947__Web.png)

This method calls the Confirm() method for all alarms having the confirmation state WaitForConfirmation.

## Syntax

```
METHOD ConfirmAllAlarms : HRESULT  
VAR_INPUT  
    nTimeStamp : ULINT := 0;   
END_VAR
```

## 66716242 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |

## 63575268 Return value

| Name | Type | Description |
| --- | --- | --- |
| ConfirmAllAlarms | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
