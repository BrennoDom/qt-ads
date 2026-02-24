# CopyDocument

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyDocument

This method copies the contents of the DOM memory into a variable of data type STRING, which can have any length. The method returns the length of the string (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopyDocument : UDINT  
VAR_INPUT  
  nDoc : DINT;  
END_VAR  
VAR_IN_OUT CONSTANT  
  pDoc : STRING;  
END_VAR
```

Sample call:

```
nLen := fbJson.CopyDocument(sJson, SIZEOF(sJson));
```
