# FB_AsyncStrResult

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_AsyncStrResult

![11736974](/tcplclib_tc3_eventlogger/1033/Images/png/5026916107__Web.png)

This function block enables the asynchronous request for a text.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_AsyncStrResult
```

## 38523909 Methods

| Name | Description |
| --- | --- |
| GetString | As soon as bBusy is FALSE and provided no error has occurred (bError = FALSE), the requested text can be fetched with this method. |

## 11170862 Properties

| Name | Type | Access | Description |
| --- | --- | --- | --- |
| bBusy | BOOL | Get | TRUE as long as the processing is not yet completed. |
| bError | BOOL | Get | TRUE when an error occurs. |
| hrErrorCode | HRESULT | Get | Outputs the error information if bError is TRUE. |

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.4022.20 | PC or CX (x64, x86, ARM) | Tc3\_EventLogger |

Further Information

* GetString
