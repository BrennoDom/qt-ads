# AddDWord

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddDWord

![53268321](/tcplclib_tc3_eventlogger/1033/Images/png/5027073547__Web.png)

This method adds an argument of the type DWORD.

## Syntax

```
METHOD AddDWord : I_TcArguments  
VAR_INPUT  
    value : DWORD;  
END_VAR
```

## 9652842 Inputs

| Name | Type | Description |
| --- | --- | --- |
| value | DWORD | Value to be added. |

## 19766715 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddDWord | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
