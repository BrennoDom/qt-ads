# AddBase64

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# AddBase64

This method adds a value of the data type Base64 to a property. Usually, a corresponding property was created beforehand with the method [AddKey()](ms-xhelp:///?Id=beckhoff-60aa-4221-b3cc-a3999a39c931).

## Syntax

```
METHOD AddBase64  
VAR_INPUT  
  pBytes : Pointer TO BYTE;  
  nBytes : DINT;  
END_VAR
```
