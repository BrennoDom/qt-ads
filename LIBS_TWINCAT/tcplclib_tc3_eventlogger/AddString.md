# AddString

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddString

![4739572](/tcplclib_tc3_eventlogger/1033/Images/png/5027088907__Web.png)

This method adds an argument of the type STRING.

## Syntax

```
METHOD AddString : I_TcArguments  
VAR_IN_OUT CONSTANT  
    value : STRING;  
END_VAR
```

## 42656148 Inputs

| Name | Type | Description |
| --- | --- | --- |
| value | STRING | Value to be added. |

## 48361012 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddString | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
