# Confirm

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Confirm

![31588048](/tcplclib_tc3_eventlogger/1033/Images/png/5027110027__Web.png)

Sets the confirmation state of WaitingForConfirmation to Confirmed.

## Syntax

```
METHOD Confirm : HRESULT  
VAR_INPUT  
    nTimeStamp: ULINT;  
END_VAR
```

## 15856984 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nTimeStamp | ULINT | 0: Current time stamp is used  > 0: External time stamp in 100 nanoseconds since January 1st, 1601 (UTC). |

## 8495130 Return value

| Name | Type | Description |
| --- | --- | --- |
| Confirm | HRESULT | Returns S\_OK if the method call was successful.  Returns ADS\_E\_INVALIDSTATE if the confirmation state was not WaitConfirmation.  Otherwise returns HRESULT as the error code. |
