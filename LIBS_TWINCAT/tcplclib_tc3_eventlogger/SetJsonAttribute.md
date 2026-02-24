# SetJsonAttribute

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# SetJsonAttribute

![27134857](/tcplclib_tc3_eventlogger/1033/Images/png/5027230987__Web.png)

This method sets the JSON attribute.

## Syntax

```
METHOD SetJsonAttribute : HRESULT  
VAR_IN_OUT CONSTANT  
    sJsonAttribute : STRING;  
END_VAR
```

## 42887128 Inputs

| Name | Type | Description |
| --- | --- | --- |
| sJsonAttribute | STRING | JSON string |

## 50439840 Return value

| Name | Type | Description |
| --- | --- | --- |
| SetJsonAttribute | HRESULT | Returns S\_OK if the method call was successful, otherwise an HRESULT as the error code. |
