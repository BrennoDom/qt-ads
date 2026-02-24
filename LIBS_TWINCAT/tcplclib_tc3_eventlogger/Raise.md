# Raise

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Raise

![13287175](/tcplclib_tc3_eventlogger/1033/Images/png/5027206027__Web.png)

Sets the alarm state to Raised.

If the alarm requires mandatory confirmation, the confirmation state is additionally set to WaitForConfirmation.

## Syntax

```
METHOD Raise : HRESULT  
VAR_INPUT  
    nTimeStamp : ULINT;  
END_VAR
```

## 52475719 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |

## 2519427 Return value

| Name | Type | Description |
| --- | --- | --- |
| Raise | HRESULT | Returns S\_OK if the method call was successful.  Returns ADS\_E\_INVALIDSTATE if the alarm was already in the Raised state.  Otherwise returns HRESULT as the error code |
