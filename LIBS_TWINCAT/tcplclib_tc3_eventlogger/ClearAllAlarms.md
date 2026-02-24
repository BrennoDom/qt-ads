# ClearAllAlarms

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# ClearAllAlarms

![17532027](/tcplclib_tc3_eventlogger/1033/Images/png/5027108107__Web.png)

This method calls the Clear() method for all alarms in the alarm state Raised.

## Syntax

```
METHOD ClearAllAlarms : HRESULT  
VAR_INPUT  
    nTimeStamp         : ULINT := 0;  
    bResetConfirmation : BOOL := FALSE;  
END_VAR
```

## 23570516 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |
| bResetConfirmation | BOOL | If TRUE and the confirmation state is WaitForConfirmation, the confirmation state is set to Reset.  Otherwise the confirmation state is not changed. |

## 10808059 Return value

| Name | Type | Description |
| --- | --- | --- |
| ClearAllAlarms | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code |
