# Execute

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# Execute

![29435437](/tcplclib_tc3_eventlogger/1033/Images/png/5027136907__Web.png)

This method must be called cyclically so that the event queue can be processed.

## Syntax

```
METHOD Execute : HRESULT
```

## 63592346 Return value

| Name | Type | Description |
| --- | --- | --- |
| Execute | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
