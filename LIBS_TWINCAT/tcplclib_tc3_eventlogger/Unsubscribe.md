# Unsubscribe

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Unsubscribe

![23274750](/tcplclib_tc3_eventlogger/1033/Images/png/5027250187__Web.png)

The listener is unsubcribed with this method.

## Syntax

```
METHOD Unsubscribe : HRESULT
```

## 8146160 Return value

| Name | Type | Description |
| --- | --- | --- |
| Unsubscribe | HRESULT | Returns S\_OK if the method call was successful.  Returns ADS\_E\_NOTFOUND if the listener was not subscribed.  Otherwise returns HRESULT as the error code. |
