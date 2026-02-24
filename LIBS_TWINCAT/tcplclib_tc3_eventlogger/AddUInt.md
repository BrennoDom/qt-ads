# AddUInt

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddUInt

![5891777](/tcplclib_tc3_eventlogger/1033/Images/png/5027092747__Web.png)

This method adds an argument of the type INT.

## Syntax

```
METHOD AddUInt : I_TcArguments  
VAR_INPUT  
    value : UINT;  
END_VAR
```

## 53026001 Inputs

| Name | Type | Description |
| --- | --- | --- |
| value | UINT | Value to be added. |

## 7471967 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddUInt | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
