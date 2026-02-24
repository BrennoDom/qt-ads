# Subscribe

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Subscribe

![39475801](/tcplclib_tc3_eventlogger/1033/Images/png/5027240587__Web.png)

The listener is subscribed for messages with this method.

## Syntax

```
METHOD Subscribe : HRESULT  
VAR_INPUT  
    ipMessageFilterConfig : POINTER TO ITcEventFilterConfig;  
    ipAlarmFilterConfig   : POINTER TO ITcEventFilterConfig;  
END_VAR
```

## 19737894 Inputs

| Name | Type | Description |
| --- | --- | --- |
| ipMessageFilterConfig | POINTER TO ITcEventFilterConfig | Pointer to ITcEventFilterConfig if a filter is to be activated. |
| ipAlarmFilterConfig | POINTER TO ITcEventFilterConfig | Pointer to ITcEventFilterConfig if a filter is to be activated. |

## 43423319 Return value

| Name | Type | Description |
| --- | --- | --- |
| Subscribe | HRESULT | Returns S\_OK if the method call was successful.  Returns ADS\_E\_EXISTS if the listener is already subscribed.  Otherwise returns HRESULT as the error code. |
