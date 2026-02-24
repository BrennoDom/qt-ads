# EqualsTo

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# EqualsTo

![51305376](/tcplclib_tc3_eventlogger/1033/Images/png/5027125387__Web.png)

This method carries out a comparison with another event specified at the input.

## Syntax

```
METHOD EqualsTo : BOOL  
VAR_INPUT  
    ipOther : I_TcEventBase;  
END_VAR
```

## 59095202 Inputs

| Name | Type | Description |
| --- | --- | --- |
| ipOther | [I\_TcEventBase](ms-xhelp:///?Id=beckhoff-b26b-4fc5-88db-90fbdaac9a6e) | Event to be compared |

## 62094776 Return value

| Name | Type | Description |
| --- | --- | --- |
| EqualsTo | BOOL | Returns TRUE if the events match. |
