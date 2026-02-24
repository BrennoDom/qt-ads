# AddBlob

## Library
tcplclib_tc3_eventlogger

## Category
Motion Control

# AddBlob

![54938922](/tcplclib_tc3_eventlogger/1033/Images/png/5026937867__Web.png)

This method adds binary data as an argument.

## Syntax

```
METHOD AddBlob : I_TcArguments  
VAR_INPUT  
    pData  : PVOID;  
    cbData : UINT;  
END_VAR
```

## 24688256 Inputs

| Name | Type | Description |
| --- | --- | --- |
| pData | PVOID | Pointer to the first byte of the binary data. |
| cbData | UINT | Length of the binary data in bytes. |

## 20867713 Return value

| Name | Type | Description |
| --- | --- | --- |
| AddBlob | [I\_TcArguments](ms-xhelp:///?Id=beckhoff-a06c-49d7-9767-f9e13553fd8b) | Returns the I\_TcArgument pointer again. |
