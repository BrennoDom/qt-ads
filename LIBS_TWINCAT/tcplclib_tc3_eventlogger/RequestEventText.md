# RequestEventText

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# RequestEventText

![31084503](/tcplclib_tc3_eventlogger/1033/Images/png/5027217547__Web.png)

This method returns the event text.

## Syntax

```
METHOD RequestEventText : BOOL  
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

## 11325076 Inputs

| Name | Type | Description |
| --- | --- | --- |
| nLangId | DINT | Specifies the language ID  English (en-US) = 1033 German (de-DE) = 1031 … |
| sResult | REFERENCE TO STRING | Reference to a variable of the type String |
| nResultSize | UDINT | Size of the String variable in bytes |

## 34816825 Return value

| Name | Type | Description |
| --- | --- | --- |
| RequestEventText | BOOL | Returns TRUE as soon as the request has been terminated. Returns FALSE if the asynchronous request is still active. The method must be called until the return value is TRUE. |

## 44915976 Outputs

| Name | Type | Description |
| --- | --- | --- |
| bError | BOOL | Returns FALSE if the method call was successful. Returns TRUE if an error has occurred. |
| hrErrorCode | HRESULT | Returns S\_OK if the method call was successful. An error code is output in case of an error. |
