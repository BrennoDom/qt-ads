# CopyJsonStringFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# CopyJsonStringFromSymbol

This method generates the JSON representation of a symbol and copies it into a variable of the data type STRING, which can be of any length. The method returns the length of the string (including null termination). If the target buffer is too small, it is emptied by a null termination and returned as length 0.

## Syntax

```
METHOD CopyJsonStringFromSymbol : UDINT  
VAR_INPUT  
  nData : UDINT;  
  nDoc  : UDINT;  
  pData : PVOID;  
END_VAR  
VAR_IN_OUT CONSTANT  
  pDoc      : STRING;  
  sDatatype : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
nLen := fbJsonDataType.CopyJsonStringFromSymbol('ST_Test',SIZEOF(stTest),ADR(stTest),sString,SIZEOF(sString));
```
