# Send

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Send

![62271039](/tcplclib_tc3_eventlogger/1033/Images/png/5027223307__Web.png)

This method sends the message.

## Syntax

```
METHOD Send : HRESULT  
VAR_INPUT  
    nTimeStamp: ULINT;  
END_VAR
```

## 23568445 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |

## 10789421 Return value

| Name | Type | Description |
| --- | --- | --- |
| Send | FB\_ HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code |
