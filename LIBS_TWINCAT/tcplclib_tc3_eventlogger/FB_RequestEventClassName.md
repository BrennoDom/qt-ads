# FB_RequestEventClassName

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# FB\_RequestEventClassName

![9150720](/tcplclib_tc3_eventlogger/1033/Images/png/5026918027__Web.png)

This function block enables the asynchronous request for the name of an event class.

## Syntax

Definition:

```
FUNCTION_BLOCK FB_RequestEventClassName
```

## 15247616 Methods

| Name | Description |
| --- | --- |
| GetString | As soon as bBusy is FALSE and provided no error has occurred (bError = FALSE), the requested text can be fetched with this method. |
| [Request](ms-xhelp:///?Id=beckhoff-d75b-49d5-a21b-2fdfda38d0b1) | Calling this method triggers the asynchronous text request. |

## 3010817 Properties

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
* [Request](ms-xhelp:///?Id=beckhoff-d75b-49d5-a21b-2fdfda38d0b1)
