# GetSizeJsonStringFromSymbol

## Library
tcplclib_tc3_jsonxml

## Category
Motion Control

# GetSizeJsonStringFromSymbol

This method reads the size of the JSON representation of a symbol. The value is specified with null termination.

## Syntax

```
METHOD GetSizeJsonStringFromSymbol : UDINT  
VAR_INPUT  
  nData  :UDINT;  
  pData  :PVOID;  
END_VAR  
VAR_IN_OUT CONSTANT  
  sDatatype   : STRING;  
END_VAR  
VAR_OUTPUT  
  hrErrorCode : HRESULT;  
END_VAR
```

Sample call:

```
nLen := fbJsonDataType.GetSizeJsonStringFromSymbol('BOOL',SIZEOF(bBool),ADR(bBool));
```
