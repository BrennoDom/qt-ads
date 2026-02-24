# GetJsonAttribute

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# GetJsonAttribute

![32218335](/tcplclib_tc3_eventlogger/1033/Images/png/5027169547__Web.png)

This method returns the JSON attribute.

## Syntax

```
METHOD GetJsonAttribute : HRESULT  
VAR_INPUT  
    sJsonAttribute : REFERENCE TO STRING;  
    nJsonAttribute : UDINT;  
END_VAR
```

## 21529561 Inputs

| Name | Type | Description |
| --- | --- | --- |
| sJsonAttribute | REFERENCE TO STRING | Reference to a variable of the type String |
| nJsonAttribute | UDINT | Length of the String variable |

## 59548322 Return value

| Name | Type | Description |
| --- | --- | --- |
| GetJsonAttribute | HRESULT | Returns S\_OK if the method call was successful.  Returns ERROR\_BAD\_LENGTH if the length of the variable is too small.  Otherwise HRESULT is returned as the error code. |
