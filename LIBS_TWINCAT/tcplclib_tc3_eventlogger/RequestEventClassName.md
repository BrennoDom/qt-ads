# RequestEventClassName

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# RequestEventClassName

![38668280](/tcplclib_tc3_eventlogger/1033/Images/png/5027215627__Web.png)

This method returns the name of the event class.

## Syntax

```
METHOD RequestEventClassName : BOOL  
VAR_INPUT  
    nLangId     : DINT;  
    sResult     : REFERENCE TO STRING;  
    nResultSize : UDINT;  
END_VAR  
VAR_OUTPUT  
    bError      : BOOL;  
    hrErrorCode : HRESULT;  
END_VAR
```

## 12470207 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nLangId | DINT | Specifies the language ID  English (en-US) = 1033 German (de-DE) = 1031 … |
| sResult | REFERENCE TO STRING | Reference to a variable of the type String |
| nResultSize | UDINT | Size of the String variable in bytes |

## 45123001 Return value

| Name | Type | Description |
| --- | --- | --- |
| RequestEventClassName | BOOL | Returns TRUE as soon as the request has been terminated. Returns FALSE if the asynchronous request is still active. The method must be called until the return value is TRUE. |

## 3453833 Outputs

| Name | Type | Description |
| --- | --- | --- |
| bError | BOOL | Returns FALSE if the method call was successful. Returns TRUE if an error has occurred. |
| hrErrorCode | HRESULT | Returns S\_OK if the method call was successful. An error code is output in case of an error. |
